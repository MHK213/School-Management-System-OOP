#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsStudentService.h"
#include "clsStudent.h"

using namespace std;

class clsFindStudentScreen : protected clsScreen
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
	static void ShowFindStudentScreen() {

		_DrawScreenHeader("\t\t  Find Student Screen");

		int IDStudent = clsInputValidate::ReadIntNumber("Please Enter Student ID : ");

		clsStudent Student = clsStudentService::Find(IDStudent);

		if (!Student.IsEmpty())
			cout << "\nClient was Found :-)\n";
		else
			cout << "\nClient was Not Found :-(\n";

		_PrintStudent(Student);
	}
};