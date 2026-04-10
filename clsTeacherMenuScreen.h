#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsTeachersListScreen.h"
#include "clsAddNewTeacherScreen.h"
#include "clsDeleteTeacherScreen.h"
#include "clsUpdateTeacherScreen.h"
#include "clsFindTeacherScreen.h"
#include "clsShowTeacherListBySpeciality.h"

using namespace std;

class clsTeacherMenuScreen : protected clsScreen
{
private:
	enum enTeacherMenuOption {enShowTeachersList = 1, enAddNewTeacher = 2, enDeleteTeacher = 3, enUpdateTeacher = 4,
		enFindTeacher = 5, enTeacherListBySpeciality = 6, enBack = 7};

	static enTeacherMenuOption _ReadTeacherMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 7] ? ";
		short TeacherMenuChoice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter a Number between 1 and 7? ");

		return enTeacherMenuOption(TeacherMenuChoice);
	}

	static void _GoBackToMenuScreen() {
		cout << "\n\nPress any key to back to Teacher Menu..." << endl;
		system("pause>0");
		ShowTeacherMenu();
	}

	static void _ShowTeachersListScreen() {
		clsTeachersListScreen::ShowTeachersList();
	}

	static void _ShowAddNewTeacherSecreen() {
		clsAddNewTeacherScreen::ShowAddNewTeacherScreen();
	}

	static void _ShowDeleteTeacherScreen() {
		clsDeleteTeacherScreen::ShowDeleteTeacherScreen();
	}

	static void _ShowUpdateTeacherScreen() {
		clsUpdateTeacherScreen::ShowUpdateTeacherScreen();
	}

	static void _ShowFindTeacherScreen() {
		clsFindTeacherScreen::ShowFindTeacherScreen();
	}
	
	static void _ShowTeacherListBySpeciality() {
		clsShowTeacherListBySpeciality::ShowTeacherListBySpeciality();
	}

	static void _PerformTeacherMenuOption(enTeacherMenuOption TeacherMenuOption) {
		switch (TeacherMenuOption) {
		case enShowTeachersList: {
			system("cls");
			_ShowTeachersListScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enAddNewTeacher: {
			system("cls");
			_ShowAddNewTeacherSecreen();
			_GoBackToMenuScreen();
			break;
		}
		case enDeleteTeacher: {
			system("cls");
			_ShowDeleteTeacherScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enUpdateTeacher: {
			system("cls");
			_ShowUpdateTeacherScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enFindTeacher: {
			system("cls");
			_ShowFindTeacherScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enTeacherListBySpeciality: {
			system("cls");
			_ShowTeacherListBySpeciality();
			_GoBackToMenuScreen();
			break;
		}
		case enBack: {}
		}
	}
public:
	static void ShowTeacherMenu() {
		system("cls");
		_DrawScreenHeader("\t\tTeacher Menu Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTeacher Menu Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Teachers List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Teacher.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Teacher.\n";
		cout << setw(37) << left << "" << "\t[4] Update Teacher Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Teacher.\n";
		cout << setw(37) << left << "" << "\t[6] Show Teachers List By Speciality.\n";
		cout << setw(37) << left << "" << "\t[7] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================" << endl;

		_PerformTeacherMenuOption(_ReadTeacherMenuOption());
	}
};