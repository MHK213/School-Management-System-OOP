#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCoursesListScreen.h"
#include "clsAddNewCourseScreen.h"
#include "clsDeleteCourseScreen.h"
#include "clsUpdateCourseScreen.h"
#include "clsFindCourseScreen.h"
#include "clsCourseListByTeacherID.h"


using namespace std;

class clsCourseMenuScreen : protected clsScreen
{
private:
	enum enCourseMenuOption {
		enShowCoursesList = 1, enAddNewCourse = 2, enDeleteCourse = 3, enUpdateCourse = 4,
		enFindCourse = 5, enCourseListByTeacherID = 6, enBack = 7
	};

	static enCourseMenuOption _ReadCourseMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 7] ? ";
		short CourseMenuChoice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter a Number between 1 and 7? ");

		return enCourseMenuOption(CourseMenuChoice);
	}

	static void _GoBackToMenuScreen() {
		cout << "\n\nPress any key to back to Course Menu..." << endl;
		system("pause>0");
		ShowCourseMenu();
	}

	static void _ShowCoursesListScreen() {
		clsCoursesListScreen::ShowCoursesList();
	}

	static void _ShowAddNewCourseScreen() {
		clsAddNewCourseScreen::ShowAddNewCourseScreen();
	}

	static void _ShowDeleteCourseScreen() {
		clsDeleteCourseScreen::ShowDeleteCourseScreen();
	}

	static void _ShowUpdateCourseScreen() {
		clsUpdateCourseScreen::ShowUpdateCourseScreen();
	}

	static void _ShowFindCourseScreen() {
		clsFindCourseScreen::ShowFindCourseScreen();
	}

	static void _ShowCoursesListByTeacherId() {
		clsCourseListByTeacherID::ShowCourseListByTeacherID();
	}

	static void _PerformCourseMenuOption(enCourseMenuOption TeacherMenuOption) {
		switch (TeacherMenuOption) {
		case enShowCoursesList: {
			system("cls");
			_ShowCoursesListScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enAddNewCourse: {
			system("cls");
			_ShowAddNewCourseScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enDeleteCourse: {
			system("cls");
			_ShowDeleteCourseScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enUpdateCourse: {
			system("cls");
			_ShowUpdateCourseScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enFindCourse: {
			system("cls");
			_ShowFindCourseScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enCourseListByTeacherID: {
			system("cls");
			_ShowCoursesListByTeacherId();
			_GoBackToMenuScreen();
			break;
		}
		case enBack: {}
		}
	}

public:
	static void ShowCourseMenu() {

		system("cls");

		_DrawScreenHeader("\t\tCourse Menu Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCourse Menu Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Courses List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Course.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Course.\n";
		cout << setw(37) << left << "" << "\t[4] Update Course Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Course.\n";
		cout << setw(37) << left << "" << "\t[6] Show Courses List By Teacher ID.\n";
		cout << setw(37) << left << "" << "\t[7] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================" << endl;

		_PerformCourseMenuOption(_ReadCourseMenuOption());
	}
};