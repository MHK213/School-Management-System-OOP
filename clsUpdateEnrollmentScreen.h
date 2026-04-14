#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsEnrollmentService.h"
#include "clsEnrollment.h"

using namespace std;

class clsUpdateEnrollmentScreen : protected clsScreen
{
private:
	static void _ReadEnrollmentInfo(clsEnrollment& Enrollment) {
		cout << "\nEnter Enroll Date (DD/MM/YYYY) : ";
		Enrollment.EnrollDate = clsInputValidate::ReadString();

		cout << "\n(Grade will be cleared automatically if status is Dropped.) \nEnter Status (1: Active / 2: Dropped / 3: Completed) : ";
		Enrollment.Status = clsEnrollment::enStatus(clsInputValidate::ReadShortNumber());

		if (Enrollment.Status == clsEnrollment::enStatus::Dropped) {
			Enrollment.Grade = "NULL"; 
		}
		else {
			cout << "\nEnter Grade: ";
			Enrollment.Grade = clsInputValidate::ReadString();
		}
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
	static void ShowUpdateEnrollmentScreen() {
		_DrawScreenHeader("\t\t  Update Enrollment Screen");

		int EnrollmentID = clsInputValidate::ReadIntNumber("Please Enter Enrollment ID : ");

		while (!clsEnrollmentService::IsEnrollmentIDExist(EnrollmentID)) {
			EnrollmentID = clsInputValidate::ReadIntNumber("\nEnrollment ID Not Found, Enter another one: ");
		}

		clsEnrollment Enrollment = clsEnrollmentService::Find(EnrollmentID);
		_PrintEnrollmentInfo(Enrollment);

		cout << "\n\nUpdate Enrollment Info:";
		cout << "\n______________________";

		_ReadEnrollmentInfo(Enrollment);

		clsEnrollmentService::enSaveResults SaveResult;
		SaveResult = clsEnrollmentService::Save(Enrollment);

		switch (SaveResult) {
		case clsEnrollmentService::enSaveResults::svSucceeded: {
			cout << "\nEnrollment Updated Successfuly\n";
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