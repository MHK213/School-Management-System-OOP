#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsStudentService.h"
#include "clsStudent.h"

using namespace std;

class clsDeleteStudentScreen : protected clsScreen
{
private:
	static void _PrintStudent(clsStudent Student) {
		cout << "\nStudent Card :";
		cout << "\n________________________________________";
		cout << "\nID           : " << Student.ID;
		cout << "\nFirst Name   : " << Student.FirstName;
		cout << "\nLast Name    : " << Student.LastName;
		cout << "\nFull Name    : " << Student.FullName();
		cout << "\nEmail        : " << Student.Email;
		cout << "\nPhone        : " << Student.Phone;
		cout << "\nAge          : " << Student.Age;
		cout << "\nGender       : " << Student.stGender();
		cout << "\nLevel        : " << Student.Level;
		cout << "\nStatus       : " << Student.stStatus();
		cout << "\n________________________________________" << endl;
	}
public:
	static void ShowDeleteStudentScreen() {
		_DrawScreenHeader("\t\t  Delete Student Screen");

		int IDStudent = clsInputValidate::ReadIntNumber("Please Enter Student ID : ");

		while (!clsStudentService::IsStudentExist(IDStudent)) {
			IDStudent = clsInputValidate::ReadIntNumber("\nStudent ID Not Found, Enter another one: ");
		}

		clsStudent Student = clsStudentService::Find(IDStudent);
		_PrintStudent(Student);

		char Answer = 'n';

		cout << "Are you Sure you want to delete this student (y/n) ? ";
		cin >> Answer;

		if (tolower(Answer) == 'y') {
			if (clsStudentService::DeleteStudent(Student)) cout << "\nStudent deleted successfully";
			else cout << "\nStudent was not deleted";
		}
	}
};