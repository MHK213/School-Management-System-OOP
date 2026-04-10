#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCourseService.h"
#include "clsCourse.h"

using namespace std;

class clsDeleteCourseScreen : protected clsScreen
{
private:
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

public:
	static void ShowDeleteCourseScreen() {
		_DrawScreenHeader("\t\t  Delete Course Screen");

		int IDCourse = clsInputValidate::ReadIntNumber("Please Enter Course ID : ");

		while (!clsCourseService::IsCourseExist(IDCourse)) {
			IDCourse = clsInputValidate::ReadIntNumber("\nCourse ID Not Found, Enter another one: ");
		}

		clsCourse Course = clsCourseService::Find(IDCourse);
		_PrintCourse(Course);

		char Answer = 'n';

		cout << "Are you Sure you want to delete this course (y/n) ? ";
		cin >> Answer;

		if (tolower(Answer) == 'y') {
			if (clsCourseService::DeleteCourse(Course)) cout << "\nCourse deleted successfully";
			else cout << "\nCourse was not deleted";
		}
	}
};