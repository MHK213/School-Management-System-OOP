#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsTeacherService.h"
#include "clsTeacher.h"

using namespace std;

class clsDeleteTeacherScreen : protected clsScreen
{
private:
	static void _PrintTeacher(clsTeacher Teacher) {
		cout << "\nTeacher Card :";
		cout << "\n________________________________________";
		cout << "\nID           : " << Teacher.ID;
		cout << "\nFirst Name   : " << Teacher.FirstName;
		cout << "\nLast Name    : " << Teacher.LastName;
		cout << "\nFull Name    : " << Teacher.FullName();
		cout << "\nEmail        : " << Teacher.Email;
		cout << "\nPhone        : " << Teacher.Phone;
		cout << "\nSpeciality   : " << clsTeacher::SpecialityToString(Teacher.Speciality);
		cout << "\n________________________________________" << endl;
	}

public:
	static void ShowDeleteTeacherScreen() {
		_DrawScreenHeader("\t\t  Delete Teacher Screen");

		int IDTeacher = clsInputValidate::ReadIntNumber("Please Enter Teacher ID : ");

		while (!clsTeacherService::IsTeacherExist(IDTeacher)) {
			IDTeacher = clsInputValidate::ReadIntNumber("\nTeacher ID Not Found, Enter another one: ");
		}

		clsTeacher Teacher = clsTeacherService::Find(IDTeacher);
		_PrintTeacher(Teacher);

		char Answer = 'n';

		cout << "Are you Sure you want to delete this teacher (y/n) ? ";
		cin >> Answer;

		if (tolower(Answer) == 'y') {
			if (clsTeacherService::DeleteTeacher(Teacher)) cout << "\nTeacher deleted successfully";
			else cout << "\nTeacher was not deleted";
		}
	}
};