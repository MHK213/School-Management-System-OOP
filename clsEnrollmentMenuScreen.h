#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsEnrollStudentScreen.h"
#include "clsDropEnrollmentScreen.h"
#include "clsUpdateEnrollmentScreen.h"

using namespace std;

class clsEnrollmentMenuScreen : protected clsScreen
{
private:
	enum enEnrollmentMenuOption {
		enEnrollStudent = 1, enDropEnrollment = 2, enUpdateEnrollment = 3, enStudentCourses = 4,
		enCourseStudents = 5, enAssignGrade = 6, enBack = 7
	};

	static enEnrollmentMenuOption _ReadEnrollmentMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 7] ? ";
		short EnrollmentMenuChoice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter a Number between 1 and 7? ");

		return enEnrollmentMenuOption(EnrollmentMenuChoice);
	}

	static void _GoBackToMenuScreen() {
		cout << "\n\nPress any key to back to Enrollment Menu..." << endl;
		system("pause>0");
		ShowEnrollmentMenu();
	}

	static void _ShowEnrollStudentScreen() {
		clsEnrollStudentScreen::ShowEnrollStudentScreen();
	}

	static void _ShowDropEnrollmentScreen() {
		clsDropEnrollmentScreen::ShowDropEnrollmentScreen();
	}

	static void _ShowUpdateEnrollmentScreen() {
		clsUpdateEnrollmentScreen::ShowUpdateEnrollmentScreen();
	}

	static void _PerformEnrollmentMenuOption(enEnrollmentMenuOption EnrollmentMenuOption) {
		switch (EnrollmentMenuOption) {
		case enEnrollStudent: {
			system("cls");
			_ShowEnrollStudentScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enDropEnrollment: {
			system("cls");
			_ShowDropEnrollmentScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enUpdateEnrollment: {
			system("cls");
			_ShowUpdateEnrollmentScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enStudentCourses: {
			system("cls");

			_GoBackToMenuScreen();
			break;
		}
		case enCourseStudents: {
			system("cls");

			_GoBackToMenuScreen();
			break;
		}
		case enAssignGrade: {
			system("cls");

			_GoBackToMenuScreen();
			break;
		}
		case enBack: {}
		}
	}

public:
	static void ShowEnrollmentMenu() {
		system("cls");
		_DrawScreenHeader("\t\tEnrollment Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tEnrollment Menu Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Enroll Student.\n";
		cout << setw(37) << left << "" << "\t[2] Drop Enrollment.\n";
		cout << setw(37) << left << "" << "\t[3] Update Enrollment.\n";
		cout << setw(37) << left << "" << "\t[4] Student Courses.\n";
		cout << setw(37) << left << "" << "\t[5] Course Students.\n";
		cout << setw(37) << left << "" << "\t[6] Assign Grade.\n";
		cout << setw(37) << left << "" << "\t[7] Back To Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================" << endl;

		_PerformEnrollmentMenuOption(_ReadEnrollmentMenuOption());
	}
};