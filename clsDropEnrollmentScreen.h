#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsEnrollment.h"
#include "clsInputValidate.h"
#include "clsEnrollmentService.h"

using namespace std;

class clsDropEnrollmentScreen : protected clsScreen
{
private:
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
	static void ShowDropEnrollmentScreen() {
		_DrawScreenHeader("\t\t  Drop Enrollment Screen");

		int EnrollmentID = clsInputValidate::ReadIntNumber("Please Enter Enrollment ID : ");

		while (!clsEnrollmentService::IsEnrollmentIDExist(EnrollmentID)) {
			EnrollmentID = clsInputValidate::ReadIntNumber("\nEnrollment ID Not Found, Enter another one: ");
		}

		clsEnrollment Enrollment = clsEnrollmentService::Find(EnrollmentID);
		_PrintEnrollmentInfo(Enrollment);

		char Answer = 'n';

		cout << "Are you Sure you want to drop this Enrollment (y/n) ? ";
		cin >> Answer;

		if (tolower(Answer) == 'y') {
			if (clsEnrollmentService::DropEnrollment(Enrollment)) {
				cout << "\nEnrollment dropped successfully";
				_PrintEnrollmentInfo(Enrollment);
			}
			else cout << "\nEnrollment was not dropped";
		}
	}
};