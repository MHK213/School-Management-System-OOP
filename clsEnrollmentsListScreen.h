#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsEnrollment.h"
#include "clsEnrollmentService.h"
#include "clsEnrollmentData.h"

using namespace std;

class clsEnrollmentsListScreen : protected clsScreen
{
private:
	static void _PrintEnrollmentRecordLine(clsEnrollment Enrollment) {

		cout << "| " << left << setw(10) << Enrollment.EnrollmentID;
		cout << "| " << left << setw(10) << Enrollment.StudentID;
		cout << "| " << left << setw(10) << Enrollment.CourseID;
		cout << "| " << left << setw(14) << Enrollment.EnrollDate;
		cout << "| " << left << setw(10) << Enrollment.Grade;
		cout << "| " << left << setw(12) << Enrollment.StatusToString();
	}

public:
	static void ShowEnrollmentsListScreen() {

		vector <clsEnrollment> vEnrollments = clsEnrollmentService::GetAllEnrollments();

		if (vEnrollments.size() == 0) {
			vEnrollments = clsEnrollmentData::LoadEnrollmentsDataFromFile();
		}

		string Title = "\t\t  Enrollment List Screen";
		string SubTitle = "\t\t   (" + to_string(vEnrollments.size()) + ") Enrollment(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t\t\t\tEnrollments List (" + to_string(vEnrollments.size()) + ") Enrollment(s).";

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

		if (vEnrollments.size() == 0) {
			cout << "\t\t\tNo Enrollments Available In the System!";
		}
		else {
			for (clsEnrollment& Enrollment : vEnrollments) {
				_PrintEnrollmentRecordLine(Enrollment);
				cout << endl;
			}
		}

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n";
	}
};