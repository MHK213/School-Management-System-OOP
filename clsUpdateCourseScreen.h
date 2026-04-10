#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCourseService.h"
#include "clsCourse.h"
#include "clsTeacherService.h"

using namespace std;

class clsUpdateCourseScreen : protected clsScreen
{
private:
	static void _ReadCourseInfo(clsCourse& Course) {
		cout << "\nEnter Course Name: ";
		Course.CourseName = clsInputValidate::ReadString();

		cout << "\nEnter Teacher ID: ";
		Course.TeacherID = clsInputValidate::ReadIntNumber();
		while (!clsTeacherService::IsTeacherExist(Course.TeacherID)) {
			Course.TeacherID = clsInputValidate::ReadIntNumber("\nTeacher ID Not exist. Enter another one: ");
		}

		cout << "\nEnter Credit Hours: ";
		Course.CreditHours = clsInputValidate::ReadIntNumber();

		cout << "\nEnter Max Students: ";
		Course.MaxStudents = clsInputValidate::ReadShortNumber();
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

public:
	static void ShowUpdateCourseScreen() {
		_DrawScreenHeader("\t\t  Update Course Screen");

		int IDCourse = clsInputValidate::ReadIntNumber("Please Enter Course ID : ");

		while (!clsCourseService::IsCourseExist(IDCourse)) {
			IDCourse = clsInputValidate::ReadIntNumber("\nCourse ID Not Found, Enter another one: ");
		}

		clsCourse Course = clsCourseService::Find(IDCourse);
		_PrintCourse(Course);

		cout << "\n\nUpdate Course Info:";
		cout << "\n______________________";

		_ReadCourseInfo(Course);

		clsCourseService::enSaveResults SaveResult;
		SaveResult = clsCourseService::Save(Course);

		switch (SaveResult) {
		case clsCourseService::enSaveResults::svSucceeded: {
			cout << "\nAccount Updated Successfuly\n";
			_PrintCourse(Course);
			break;
		}
		case clsCourseService::enSaveResults::svFaildEmptyObject: {
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		}
	}
};