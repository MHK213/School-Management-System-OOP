#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsTeacherService.h"
#include "clsTeacher.h"

using namespace std;

class clsFindTeacherScreen : protected clsScreen
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
		cout << "\nSpeciality   : " << Teacher.Speciality;
		cout << "\n________________________________________" << endl;
	}

public:
	static void ShowFindTeacherScreen() {

		_DrawScreenHeader("\t\t  Find Teacher Screen");

		int IDTeacher = clsInputValidate::ReadIntNumber("Please Enter Teacher ID : ");

		clsTeacher Teacher = clsTeacherService::Find(IDTeacher);

		if (!Teacher.IsEmpty())
			cout << "\nClient was Found :-)\n";
		else
			cout << "\nClient was Not Found :-(\n";

		_PrintTeacher(Teacher);
	}
};