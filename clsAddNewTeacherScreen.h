#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsTeacherService.h"
#include "clsTeacher.h"

using namespace std;

class clsAddNewTeacherScreen : protected clsScreen
{
private:
	static void _ReadTeacherInfo(clsTeacher& Teacher) {
		cout << "\nEnter FirstName: ";
		Teacher.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Teacher.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email; ";
		Teacher.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Teacher.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Speciality: ";
		Teacher.Speciality = clsInputValidate::ReadString();
	}

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
	static void ShowAddNewTeacherScreen() {
		_DrawScreenHeader("\t\t  Add new Teacher Screen");

		int IDTeacher = clsInputValidate::ReadIntNumber("Please Enter Teacher ID : ");

		while (clsTeacherService::IsTeacherExist(IDTeacher)) {
			IDTeacher = clsInputValidate::ReadIntNumber("\nTeacher ID already exist. Enter another one: ");
		}

		clsTeacher NewTeacher = clsTeacherService::GetAddNewTeacherObject(IDTeacher);

		_ReadTeacherInfo(NewTeacher);

		clsTeacherService::enSaveResults SaveResult;
		SaveResult = clsTeacherService::Save(NewTeacher);

		switch (SaveResult) {
		case clsTeacherService::enSaveResults::svSucceeded: {
			cout << "\nAccount Added Successfuly\n";
			_PrintTeacher(NewTeacher);
			break;
		}
		case clsTeacherService::enSaveResults::svFaildEmptyObject: {
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsTeacherService::enSaveResults::svIDTeacherExists: {
			cout << "\nError account was not saved because IDTeacher aleardy used";
			break;
		}
		}
	}
};