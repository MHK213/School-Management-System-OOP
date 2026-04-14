#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsStudentService.h"
#include "clsInputValidate.h"
#include "clsCourseService.h"
#include "clsEnrollmentService.h"

using namespace std;

class clsEnrollStudentScreen : protected clsScreen
{
private:
	static int _ReadStudentID() {
		int StudentID = clsInputValidate::ReadIntNumber("Please Enter StudentID : ");
		while (!clsStudentService::IsStudentExist(StudentID)) {
			StudentID = clsInputValidate::ReadIntNumber("\nStudentID Not exist. Enter another one: ");
		}

		return StudentID;
	}

	static int _ReadCourseID() {
		int CourseID = clsInputValidate::ReadIntNumber("\nPlease Enter CourseID : ");
		while (!clsCourseService::IsCourseExist(CourseID)) {
			CourseID = clsInputValidate::ReadIntNumber("\nCourseID Not exist. Enter another one: ");
		}

		return CourseID;
	}

	static void _ReadEnrollmentInfo(clsEnrollment& Enrollment) {
		cout << "\nEnter Grade (NULL if he is dropped): ";
		Enrollment.Grade = clsInputValidate::ReadString();

		cout << "\nEnter Enroll Date (DD/MM/YYYY) : ";
		Enrollment.EnrollDate = clsInputValidate::ReadString();

		cout << "\nEnter Status (1: Active / 2: Dropped / 3: Completed): ";
		Enrollment.Status = clsEnrollment::enStatus(clsInputValidate::ReadShortNumber());
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
	static void ShowEnrollStudentScreen() {
		_DrawScreenHeader("\t\t  Enroll Student Screen");

		int EnrollmentID = clsInputValidate::ReadIntNumber("\nPlease Enter EnrollmentID: ");

		while (clsEnrollmentService::IsEnrollmentIDExist(EnrollmentID)) {
			EnrollmentID = clsInputValidate::ReadIntNumber("\nEnrollmentID already exist.Enter another one : ");
		}

		int StudentID = _ReadStudentID();
		int CourseID = _ReadCourseID();

		clsEnrollment NewEnrollment = clsEnrollmentService::GetAddNewEnrollmentObject(EnrollmentID, StudentID, CourseID);

		_ReadEnrollmentInfo(NewEnrollment);

		clsEnrollmentService::enSaveResults SaveResult;
		SaveResult = clsEnrollmentService::Save(NewEnrollment);

		switch (SaveResult) {
		case clsEnrollmentService::enSaveResults::svSucceeded: {
			cout << "\nStudent Enrolled Successfuly\n";
			_PrintEnrollmentInfo(NewEnrollment);
			break;
		}
		case clsEnrollmentService::enSaveResults::svFaildEmptyObject: {
			cout << "\nError Enrollment was not saved because it's Empty";
			break;
		}
		case clsEnrollmentService::enSaveResults::svStudentAlreadyEnrolled: {
			cout << "\nError Enrollment was not saved because Student aleardy Enrolled";
			break;
		}
		case clsEnrollmentService::enSaveResults::svCourseFull: {
			cout << "\nError Enrollment was not saved because Course is full";
			break;
		}
		}
	}
};