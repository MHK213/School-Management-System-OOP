#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCourseService.h"
#include "clsCourse.h"

using namespace std;

class clsFindCourseScreen : protected clsScreen
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
	static void ShowFindCourseScreen() {

		_DrawScreenHeader("\t\t  Find Course Screen");

		int IDCourse = clsInputValidate::ReadIntNumber("Please Enter Course ID : ");

		clsCourse Course = clsCourseService::Find(IDCourse);

		if (!Course.IsEmpty())
			cout << "\nClient was Found :-)\n";
		else
			cout << "\nClient was Not Found :-(\n";

		_PrintCourse(Course);
	}
};