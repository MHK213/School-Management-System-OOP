#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCourseService.h"
#include "clsCourse.h"
#include "clsTeacherService.h"

using namespace std;

class clsAddNewCourseScreen : protected clsScreen
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
	static void ShowAddNewCourseScreen() {
		_DrawScreenHeader("\t\t  Add new Course Screen");

		int IDCourse = clsInputValidate::ReadIntNumber("Please Enter Course ID : ");

		while (clsCourseService::IsCourseExist(IDCourse)) {
			IDCourse = clsInputValidate::ReadIntNumber("\nCourse ID already exist. Enter another one: ");
		}

		clsCourse NewCourse = clsCourseService::GetAddNewCourseObject(IDCourse);

		_ReadCourseInfo(NewCourse);

		clsCourseService::enSaveResults SaveResult;
		SaveResult = clsCourseService::Save(NewCourse);

		switch (SaveResult) {
		case clsCourseService::enSaveResults::svSucceeded: {
			cout << "\nAccount Added Successfuly\n";
			_PrintCourse(NewCourse);
			break;
		}
		case clsCourseService::enSaveResults::svFaildEmptyObject: {
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsCourseService::enSaveResults::svIDCourseExists: {
			cout << "\nError account was not saved because IDCourse aleardy used";
			break;
		}
		}
	}
};