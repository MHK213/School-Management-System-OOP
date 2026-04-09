#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsTeacher.h"
#include "clsTeacherService.h"
#include "clsInputValidate.h"

using namespace std;

class clsTeachersListScreen : protected clsScreen
{
private:
	static void _PrintTeacherRecordLine(clsTeacher Teacher) {

		cout << "| " << left << setw(5) << Teacher.ID;
		cout << "| " << left << setw(25) << Teacher.FullName();
		cout << "| " << left << setw(25) << Teacher.Email;
		cout << "| " << left << setw(12) << Teacher.Phone;
		cout << "| " << left << setw(20) << clsTeacher::SpecialityToString(Teacher.Speciality);
	}

public:
	static void ShowTeachersList() {

		vector <clsTeacher> vTeachers = clsTeacherService::GetTeachersList();

		string Title = "\t\t  Teacher List Screen";
		string SubTitle = "\t\t   (" + to_string(vTeachers.size()) + ") Teacher(s)";

		_DrawScreenHeader(Title, SubTitle);

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