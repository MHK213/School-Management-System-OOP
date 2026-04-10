#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsTeacher.h"

using namespace std;

class clsShowTeacherListBySpeciality : protected clsScreen
{
private:
	static clsTeacher::enSpeciality _ReadSpeciality() {

		cout << "\nChoose Speciality:\n";
		cout << "[0] All\n";
		cout << "[1] Math\n";
		cout << "[2] Physics\n";
		cout << "[3] Computer Science\n";
		cout << "[4] English\n";
		cout << "[5] Arabic\n";
		cout << "[6] History\n";

		short choice = clsInputValidate::ReadShortNumberBetween(0, 6, "\nInvalid number!! Enter a number between 1 and 6");

		return (clsTeacher::enSpeciality)choice;
	}

	static void _PrintTeacherRecordLine(clsTeacher Teacher) {

		cout << "| " << left << setw(5) << Teacher.ID;
		cout << "| " << left << setw(25) << Teacher.FullName();
		cout << "| " << left << setw(25) << Teacher.Email;
		cout << "| " << left << setw(12) << Teacher.Phone;
		cout << "| " << left << setw(20) << clsTeacher::SpecialityToString(Teacher.Speciality);
	}

public:
	static void ShowTeacherListBySpeciality() {

		clsTeacher::enSpeciality sp = _ReadSpeciality();

		vector<clsTeacher> vTeachers =
			clsTeacherService::GetTeachersBySpeciality(sp);

		_DrawScreenHeader("\t\t  Teacher List Screen");

		cout << "\n\t\t\t\t\tTeachers List (" + to_string(vTeachers.size()) + ") Teacher(s).";

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;
		cout << "| " << left << setw(5) << "ID";
		cout << "| " << left << setw(25) << "Teacher Name";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Speciality";
		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;

		if (vTeachers.size() == 0) {
			cout << "\t\t\t\tNo Teachers Available In the System!";
		}
		else {
			for (clsTeacher& Teacher : vTeachers) {
				_PrintTeacherRecordLine(Teacher);
				cout << endl;
			}
		}

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n";
	}
};