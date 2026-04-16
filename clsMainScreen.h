#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsStudentsListScreen.h"
#include "clsAddNewStudentScreen.h"
#include "clsDeleteStudentScreen.h"
#include "clsUpdateStudentScreen.h"
#include "clsFindStudentScreen.h"
#include "clsTeacherMenuScreen.h"
#include "clsCourseMenuScreen.h"
#include "clsEnrollmentMenuScreen.h"
#include "clsReportScreen.h"
#include "clsManageUserScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenuOption {
		enShowStudentsList = 1, enAddNewStudent = 2, enDeleteStudent = 3, enUpdateStudent = 4,
		enFindStudent = 5, enManageTeachers = 6, enManageCourses = 7, enManageEnrollments = 8, enReports = 9,
		enManageUsers = 10, enLogout = 11 };

	static enMainMenuOption _ReadMainMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 11] ? ";
		short MainMenuChoice = clsInputValidate::ReadShortNumberBetween(1, 11, "Enter a Number between 1 and 11? ");

		return enMainMenuOption(MainMenuChoice);
	}

	static void _GoBackToMainMenu() {
		cout << "\n\nPress any key to back to Main Menu..." << endl;
		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowAllStudentsScreen() {
		clsStudentsListScreen::ShowStudentsList();
	}

	static void _ShowAddNewStudentScreen() {
		clsAddNewStudentScreen::ShowAddNewStudentScreen();
	}

	static void _ShowDeleteStudentScreen() {
		clsDeleteStudentScreen::ShowDeleteStudentScreen();
	}

	static void _ShowUpdateStudentScreen() {
		clsUpdateStudentScreen::ShowUpdateStudentScreen();
	}

	static void _ShowFindStudentScreen() {
		clsFindStudentScreen::ShowFindStudentScreen();
	}

	static void _ShowTeacherMenuScreen() {
		clsTeacherMenuScreen::ShowTeacherMenu();
	}

	static void _ShowCourseMenuScreen() {
		clsCourseMenuScreen::ShowCourseMenu();
	}

	static void _ShowEnrollmentMenuScreen() {
		clsEnrollmentMenuScreen::ShowEnrollmentMenu();
	}

	static void _ShowReportScreen() {
		clsReportScreen::ShowReportScreen();
	}

	static void _ShowManageUserScreen() {
		clsManageUserScreen::ShowManageUsersMenu();
	}

	static void _PerformMainMenuOption(enMainMenuOption MainMenuOption) {
		switch (MainMenuOption) {
		case enShowStudentsList: {
			system("cls");
			_ShowAllStudentsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enAddNewStudent: {
			system("cls");
			_ShowAddNewStudentScreen();
			_GoBackToMainMenu();
			break;
		}
		case enDeleteStudent: {
			system("cls");
			_ShowDeleteStudentScreen();
			_GoBackToMainMenu();
			break;
		}
		case enUpdateStudent: {
			system("cls");
			_ShowUpdateStudentScreen();
			_GoBackToMainMenu();
			break;
		}
		case enFindStudent: {
			system("cls");
			_ShowFindStudentScreen();
			_GoBackToMainMenu();
			break;
		}
		case enManageTeachers: {
			system("cls");
			_ShowTeacherMenuScreen();
			_GoBackToMainMenu();
			break;
		}
		case enManageCourses: {
			system("cls");
			_ShowCourseMenuScreen();
			_GoBackToMainMenu();
			break;
		}
		case enManageEnrollments: {
			system("cls");
			_ShowEnrollmentMenuScreen();
			_GoBackToMainMenu();
			break;
		}
		case enReports: {
			system("cls");
			_ShowReportScreen();
			_GoBackToMainMenu();
			break;
		}
		case enManageUsers: {
			system("cls");
			_ShowManageUserScreen();
			_GoBackToMainMenu();
			break;
		}
		case enLogout: {
			system("cls");
			cout << "Logout Screen will be here\n";
			_GoBackToMainMenu();
			break;
		}
		default: {
			break;
		}
		}

	}

public:
	static void ShowMainMenu() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tMain Menu Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Students List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Student.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Student.\n";
		cout << setw(37) << left << "" << "\t[4] Update Student Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Student.\n";
		cout << setw(37) << left << "" << "\t[6] Manage Teachers.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Courses.\n";
		cout << setw(37) << left << "" << "\t[8] Manage Enrollments.\n";
		cout << setw(37) << left << "" << "\t[9] Reports.\n";
		cout << setw(37) << left << "" << "\t[10] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[11] Logout.\n";
		cout << setw(37) << left << "" << "===========================================" << endl;

		_PerformMainMenuOption(_ReadMainMenuOption());
	}
};