#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCourse.h"
#include "clsCourseService.h"
#include "clsStudent.h"
#include "clsStudentService.h"
#include "clsEnrollment.h"
#include "clsEnrollmentService.h"
#include "clsEnrollmentData.h"

using namespace std;

class clsCourseStudentsScreen : protected clsScreen
{
private:
	static int _ReadCourseID() {

		cout << "\nEnter Course ID : ";

		return clsInputValidate::ReadIntNumber();
	}

	static void _PrintCourse(clsCourse Course) {
		cout << "\nCourse Card :";
		cout << "\n________________________________________";
		cout << "\nCourse ID    : " << Course.CourseID;
		cout << "\nCourse Name  : " << Course.CourseName;
		cout << "\nTeacher ID   : " << Course.TeacherID;
		cout << "\nCredit Hours : " << Course.CreditHours;
		cout << "\nMax Students : " << Course.MaxStudents;
		cout << "\n________________________________________" << endl;
	}

	static void _PrintEnrollmentStudentRecordLine(clsEnrollment Enrollment) {

		clsStudent Student = clsStudentService::Find(Enrollment.StudentID);

		cout << "| " << left << setw(8) << Enrollment.EnrollmentID;
		cout << "| " << left << setw(8) << Enrollment.StudentID;
		cout << "| " << left << setw(24) << (Student.IsEmpty() ? "Unknown" : Student.FullName());
		cout << "| " << left << setw(12) << Enrollment.EnrollDate;
		cout << "| " << left << setw(10) << Enrollment.Grade;
		cout << "| " << left << setw(12) << Enrollment.StatusToString();
	}

public:
	static void ShowCourseStudentsScreen() {

		_DrawScreenHeader("\t\t  Course Students Screen");

		int CourseID = _ReadCourseID();

		clsCourse Course = clsCourseService::Find(CourseID);

		if (!Course.IsEmpty()) {
			cout << "\nCourse was Found :-)\n";
			_PrintCourse(Course);
		}
		else {
			cout << "\nCourse was Not Found :-(\n";
			return;
		}

		vector<clsEnrollment> vEnrollments = clsEnrollmentService::GetEnrollmentsByCourse(CourseID);

		cout << "\n\t\t\tCourse Students List (" + to_string(vEnrollments.size()) + ") Student(s).";

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;
		cout << "| " << left << setw(8) << "EnrollID";
		cout << "| " << left << setw(8) << "StudentID";
		cout << "| " << left << setw(24) << "Student Name";
		cout << "| " << left << setw(12) << "Enroll Date";
		cout << "| " << left << setw(10) << "Grade";
		cout << "| " << left << setw(12) << "Status";
		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;

		if (vEnrollments.size() == 0) {
			cout << "\t\t\tNo Students Available For This Course!";
		}
		else {
			for (clsEnrollment& Enrollment : vEnrollments) {
				_PrintEnrollmentStudentRecordLine(Enrollment);
				cout << endl;
			}
		}

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n";
	}
};