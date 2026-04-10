#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsCourse.h"
#include "clsCourseService.h"

using namespace std;

class clsCoursesListScreen : protected clsScreen
{
private:
	static void _PrintCourseRecordLine(clsCourse Course) {

		cout << "| " << left << setw(8) << Course.CourseID;
		cout << "| " << left << setw(28) << Course.CourseName;
		cout << "| " << left << setw(12) << Course.TeacherID;
		cout << "| " << left << setw(14) << Course.CreditHours;
		cout << "| " << left << setw(14) << Course.MaxStudents;
	}

public:
	static void ShowCoursesList() {

		vector <clsCourse> vCourses = clsCourseService::GetCoursesList();

		string Title = "\t\t  Course List Screen";
		string SubTitle = "\t\t   (" + to_string(vCourses.size()) + ") Course(s)";

		_DrawScreenHeader(Title, SubTitle);

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