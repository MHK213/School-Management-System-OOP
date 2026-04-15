#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsStudent.h"
#include "clsStudentService.h"
#include "clsCourse.h"
#include "clsCourseService.h"
#include "clsEnrollment.h"
#include "clsEnrollmentService.h"
#include "clsEnrollmentData.h"

using namespace std;

class clsStudentCoursesScreen : protected clsScreen
{
private:
	static int _ReadStudentID() {

		cout << "\nEnter Student ID : ";

		return clsInputValidate::ReadIntNumber();
	}

	static void _PrintStudent(clsStudent Student) {
		cout << "\nStudent Card :";
		cout << "\n________________________________________";
		cout << "\nID           : " << Student.ID;
		cout << "\nFirst Name   : " << Student.FirstName;
		cout << "\nLast Name    : " << Student.LastName;
		cout << "\nFull Name    : " << Student.FullName();
		cout << "\nEmail        : " << Student.Email;
		cout << "\nPhone        : " << Student.Phone;
		cout << "\nAge          : " << Student.Age;
		cout << "\nGender       : " << Student.stGender();
		cout << "\nLevel        : " << Student.Level;
		cout << "\nStatus       : " << Student.stStatus();
		cout << "\n________________________________________" << endl;
	}

	static void _PrintEnrollmentCourseRecordLine(clsEnrollment Enrollment) {

		clsCourse Course = clsCourseService::Find(Enrollment.CourseID);

		cout << "| " << left << setw(8) << Enrollment.EnrollmentID;
		cout << "| " << left << setw(8) << Enrollment.CourseID;
		cout << "| " << left << setw(24) << (Course.IsEmpty() ? "Unknown" : Course.CourseName);
		cout << "| " << left << setw(12) << Enrollment.EnrollDate;
		cout << "| " << left << setw(10) << Enrollment.Grade;
		cout << "| " << left << setw(12) << Enrollment.StatusToString();
	}

public:
	static void ShowStudentCoursesScreen() {

		_DrawScreenHeader("\t\t  Student Courses Screen");

		int StudentID = _ReadStudentID();

		clsStudent Student = clsStudentService::Find(StudentID);

		if (!Student.IsEmpty()) {
			cout << "\nStudent was Found :-)\n";
			_PrintStudent(Student);
		}
		else {
			cout << "\nStudent was Not Found :-(\n";
			return;
		}

		vector<clsEnrollment> vEnrollments = clsEnrollmentService::GetEnrollmentsByStudent(StudentID);

		cout << "\n\t\t\tStudent Courses List (" + to_string(vEnrollments.size()) + ") Course(s).";

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;
		cout << "| " << left << setw(8) << "EnrollID";
		cout << "| " << left << setw(8) << "CourseID";
		cout << "| " << left << setw(24) << "Course Name";
		cout << "| " << left << setw(12) << "Enroll Date";
		cout << "| " << left << setw(10) << "Grade";
		cout << "| " << left << setw(12) << "Status";
		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;

		if (vEnrollments.size() == 0) {
			cout << "\t\t\tNo Courses Available For This Student!";
		}
		else {
			for (clsEnrollment& Enrollment : vEnrollments) {
				_PrintEnrollmentCourseRecordLine(Enrollment);
				cout << endl;
			}
		}

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n";
	}
};