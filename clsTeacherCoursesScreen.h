#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCourse.h"
#include "clsCourseService.h"
#include "clsTeacher.h"
#include "clsTeacherService.h"

using namespace std;

class clsTeacherCoursesScreen : protected clsScreen
{
private:
	static int _ReadTeacherID() {

		cout << "\nEnter Teacher ID : ";

		return clsInputValidate::ReadIntNumber();
	}

	static void _PrintCourseRecordLine(clsCourse Course) {

		cout << "| " << left << setw(8) << Course.CourseID;
		cout << "| " << left << setw(28) << Course.CourseName;
		cout << "| " << left << setw(12) << Course.TeacherID;
		cout << "| " << left << setw(14) << Course.CreditHours;
		cout << "| " << left << setw(14) << Course.MaxStudents;
	}

	static void _PrintTeacher(clsTeacher Teacher) {
		cout << "\nTeacher Card :";
		cout << "\n________________________________________";
		cout << "\nID           : " << Teacher.ID;
		cout << "\nFirst Name   : " << Teacher.FirstName;
		cout << "\nLast Name    : " << Teacher.LastName;
		cout << "\nFull Name    : " << Teacher.FullName();
		cout << "\nEmail        : " << Teacher.Email;
		cout << "\nPhone        : " << Teacher.Phone;
		cout << "\nSpeciality   : " << clsTeacher::SpecialityToString(Teacher.Speciality);
		cout << "\n________________________________________" << endl;
	}

public:
	static void ShowTeacherCoursesList() {

		_DrawScreenHeader("\t\t  Teacher Courses Screen");

		int TeacherID = _ReadTeacherID();

		clsTeacher Teacher = clsTeacherService::Find(TeacherID);

		if (!Teacher.IsEmpty()) {
			cout << "\nTeacher was Found :-)\n";
			_PrintTeacher(Teacher);
		}
		else {
			cout << "\nTeacher was Not Found :-(\n";
			return;
		}

		vector<clsCourse> vCourses =
			clsCourseService::GetCoursesListByTeacherID(TeacherID);

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