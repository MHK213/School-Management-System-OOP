#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsStudent.h"
#include "clsStudentService.h"

using namespace std;

class clsStudentsListScreen : protected clsScreen
{
private:
	static void _PrintStudentRecordLine(clsStudent Student) {

		cout << "| " << left << setw(5) << Student.ID;
		cout << "| " << left << setw(20) << Student.FullName();
		cout << "| " << left << setw(5) << Student.Age;
		cout << "| " << left << setw(25) << Student.Email;
		cout << "| " << left << setw(12) << Student.Phone;
		cout << "| " << left << setw(12) << Student.stGender();
		cout << "| " << left << setw(8) << Student.Level;
		cout << "| " << left << setw(12) << Student.stStatus();
	}
public:
	static void ShowStudentsList() {
		vector <clsStudent> vStudents = clsStudentService::GetStudentsList();

		string Title = "\t\t  Student List Screen";
		string SubTitle = "\t\t   (" + to_string(vStudents.size()) + ") Student(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t\t\t\t\tStudents List (" + to_string(vStudents.size()) + ") Student(s).";

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;
		cout << "| " << left << setw(5) << "ID";
		cout << "| " << left << setw(20) << "Student Name";
		cout << "| " << left << setw(5) << "Age";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Gender";
		cout << "| " << left << setw(8) << "Level";
		cout << "| " << left << setw(12) << "Status";
		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n" << endl;

		if (vStudents.size() == 0) {
			cout << "\t\t\t\tNo Students Available In the System!";
		}
		else {
			for (clsStudent& Student : vStudents) {
				_PrintStudentRecordLine(Student);
				cout << endl;
			}
		}

		cout << "\n_______________________________________________________";
		cout << "______________________________________________________\n";
	}
};