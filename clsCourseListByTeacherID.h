#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCourse.h"
#include "clsCourseService.h"

using namespace std;

class clsCourseListByTeacherID : protected clsScreen
{
private:
	static int _ReadTeacherID() {

		cout << "\nEnter Teacher ID (0 for All): ";

		return clsInputValidate::ReadIntNumber();
	}

	static void _PrintCourseRecordLine(clsCourse Course) {

		cout << "| " << left << setw(8) << Course.CourseID;
		cout << "| " << left << setw(28) << Course.CourseName;
		cout << "| " << left << setw(12) << Course.TeacherID;
		cout << "| " << left << setw(14) << Course.CreditHours;
		cout << "| " << left << setw(14) << Course.MaxStudents;
	}

public:
	static void ShowCourseListByTeacherID() {

		int TeacherID = _ReadTeacherID();

		vector<clsCourse> vCourses =
			clsCourseService::GetCoursesListByTeacherID(TeacherID);

		_DrawScreenHeader("\t\t  Course List Screen");

		cout << "\n\t\t\t\t\tCourses List (" + to_string(vCourses.size()) + ") Course(s).";

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;
		cout << "| " << left << setw(8) << "CourseID";
		cout << "| " << left << setw(28) << "Course Name";
		cout << "| " << left << setw(12) << "Teacher ID";
		cout << "| " << left << setw(14) << "Credit Hours";
		cout << "| " << left << setw(14) << "Max Students";
		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;

		if (vCourses.size() == 0) {
			cout << "\t\t\t\tNo Courses Available In the System!";
		}
		else {
			for (clsCourse& Course : vCourses) {
				_PrintCourseRecordLine(Course);
				cout << endl;
			}
		}

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n";
	}
};