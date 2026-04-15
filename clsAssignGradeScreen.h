#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsEnrollment.h"
#include "clsEnrollmentService.h"
#include "clsEnrollmentData.h"

using namespace std;

class clsAssignGradeScreen : protected clsScreen
{
private:
	static void _PrintCompletedEnrollmentRecordLine(clsEnrollment Enrollment) {
		cout << "| " << left << setw(10) << Enrollment.EnrollmentID;
		cout << "| " << left << setw(10) << Enrollment.StudentID;
		cout << "| " << left << setw(10) << Enrollment.CourseID;
		cout << "| " << left << setw(14) << Enrollment.EnrollDate;
		cout << "| " << left << setw(10) << Enrollment.Grade;
		cout << "| " << left << setw(12) << Enrollment.StatusToString();
	}

	static void _PrintCompletedEnrollmentsList(vector<clsEnrollment> vCompletedEnrollments) {
		cout << "\n\t\tCompleted Enrollments List (" + to_string(vCompletedEnrollments.size()) + ") Enrollment(s).";

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;
		cout << "| " << left << setw(10) << "EnrollID";
		cout << "| " << left << setw(10) << "StudentID";
		cout << "| " << left << setw(10) << "CourseID";
		cout << "| " << left << setw(14) << "Enroll Date";
		cout << "| " << left << setw(10) << "Grade";
		cout << "| " << left << setw(12) << "Status";
		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;

		for (clsEnrollment& Enrollment : vCompletedEnrollments) {
			_PrintCompletedEnrollmentRecordLine(Enrollment);
			cout << endl;
		}

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n";
	}

	static void _PrintEnrollmentInfo(clsEnrollment Enrollment) {
		cout << "\nEnrollment Card :";
		cout << "\n________________________________________";
		cout << "\nEnrollmentID : " << Enrollment.EnrollmentID;
		cout << "\nStudentID    : " << Enrollment.StudentID;
		cout << "\nCourseID     : " << Enrollment.CourseID;
		cout << "\nEnroll Date  : " << Enrollment.EnrollDate;
		cout << "\nGrade        : " << Enrollment.Grade;
		cout << "\nStatus       : " << Enrollment.StatusToString();
		cout << "\n________________________________________" << endl;
	}

public:
	static void ShowAssignGradeScreen() {
		_DrawScreenHeader("\t\t  Assign Grade Screen");

		vector<clsEnrollment> vAllEnrollments = clsEnrollmentData::LoadEnrollmentsDataFromFile();
		vector<clsEnrollment> vCompletedEnrollments = clsEnrollmentService::GetCompletedEnrollments();

		if (vAllEnrollments.size() == 0) {
			cout << "\nNo Enrollments Available In the System!";
			return;
		}

		if (vCompletedEnrollments.size() == 0) {
			cout << "\nNo Completed Enrollments Available To Assign Grade!";
			return;
		}

		_PrintCompletedEnrollmentsList(vCompletedEnrollments);

		int EnrollmentID = clsInputValidate::ReadIntNumber("\nPlease Enter Completed Enrollment ID : ");

		clsEnrollment Enrollment = clsEnrollmentService::FindCompletedEnrollmentByID(EnrollmentID);

		while (Enrollment.IsEmpty()) {
			EnrollmentID = clsInputValidate::ReadIntNumber("\nEnrollment ID Not Found in Completed Enrollments, Enter another one: ");

			Enrollment = clsEnrollmentService::FindCompletedEnrollmentByID(EnrollmentID);
		}

		_PrintEnrollmentInfo(Enrollment);

		cout << "\nEnter Grade: ";
		Enrollment.Grade = clsInputValidate::ReadString();

		clsEnrollmentService::enSaveResults SaveResult;
		SaveResult = clsEnrollmentService::Save(Enrollment);

		switch (SaveResult) {
		case clsEnrollmentService::enSaveResults::svSucceeded: {
			cout << "\nGrade Assigned Successfuly\n";
			_PrintEnrollmentInfo(Enrollment);
			break;
		}
		case clsEnrollmentService::enSaveResults::svFaildEmptyObject: {
			cout << "\nError Enrollment was not saved because it's Empty";
			break;
		}
		}
	}
};