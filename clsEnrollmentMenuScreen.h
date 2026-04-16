#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsEnrollStudentScreen.h"
#include "clsDropEnrollmentScreen.h"
#include "clsUpdateEnrollmentScreen.h"
#include "clsStudentCoursesScreen.h"
#include "clsCourseStudentsScreen.h"
#include "clsAssignGradeScreen.h"
#include "clsEnrollmentsListScreen.h"

using namespace std;

class clsEnrollmentMenuScreen : protected clsScreen
{
private:
	enum enEnrollmentMenuOption {
		enEnrollmentsList = 1, enEnrollStudent = 2, enDropEnrollment = 3, enUpdateEnrollment = 4, enStudentCourses = 5,
		enCourseStudents = 6, enAssignGrade = 7, enBack = 8
	};

	static enEnrollmentMenuOption _ReadEnrollmentMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 8] ? ";
		short EnrollmentMenuChoice = clsInputValidate::ReadShortNumberBetween(1, 8, "Enter a Number between 1 and 8? ");

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

	static void _ShowStudentCoursesScreen() {
		clsStudentCoursesScreen::ShowStudentCoursesScreen();
	}

	static void _ShowCourseStudentsScreen() {
		clsCourseStudentsScreen::ShowCourseStudentsScreen();
	}

	static void _ShowAssignGradeScreen() {
		clsAssignGradeScreen::ShowAssignGradeScreen();
	}

	static void _ShowAllEnrollmentsList() {
		clsEnrollmentsListScreen::ShowEnrollmentsListScreen();
	}

	static void _PerformEnrollmentMenuOption(enEnrollmentMenuOption EnrollmentMenuOption) {
		switch (EnrollmentMenuOption) {
		case enEnrollmentsList: {
			system("cls");
			_ShowAllEnrollmentsList();
			_GoBackToMenuScreen();
			break;
		}
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
			_ShowStudentCoursesScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enCourseStudents: {
			system("cls");
			_ShowCourseStudentsScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enAssignGrade: {
			system("cls");
			_ShowAssignGradeScreen();
			_GoBackToMenuScreen();
			break;
		}
		case enBack: {}
		}
	}

public:
	static void ShowEnrollmentMenu() {
		if (!CheckAccessRights(clsUser::enPermissions::pManageEnrollments)) {
			return;
		}

		system("cls");
		_DrawScreenHeader("\t\tEnrollment Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tEnrollment Menu Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Enrollments List.\n";
		cout << setw(37) << left << "" << "\t[2] Enroll Student.\n";
		cout << setw(37) << left << "" << "\t[3] Drop Enrollment.\n";
		cout << setw(37) << left << "" << "\t[4] Update Enrollment.\n";
		cout << setw(37) << left << "" << "\t[5] Student Courses.\n";
		cout << setw(37) << left << "" << "\t[6] Course Students.\n";
		cout << setw(37) << left << "" << "\t[7] Assign Grade.\n";
		cout << setw(37) << left << "" << "\t[8] Back To Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================" << endl;

		_PerformEnrollmentMenuOption(_ReadEnrollmentMenuOption());
	}
};