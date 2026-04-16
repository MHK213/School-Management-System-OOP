#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsStudentService.h"
#include "clsStudent.h"

using namespace std;

class clsAddNewStudentScreen : protected clsScreen
{
private:
	static void _ReadStudentInfo(clsStudent& Student) {
		cout << "\nEnter FirstName: ";
		Student.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Student.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Age: ";
		Student.Age = clsInputValidate::ReadIntNumber();

		cout << "\nEnter Email; ";
		Student.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Student.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Gender (1: Male / 2: Female): ";
		Student.Gender = clsStudent::enGender(clsInputValidate::ReadShortNumber());

		cout << "\nEnter Level: ";
		Student.Level = clsInputValidate::ReadString();

		cout << "\nEnter Status (1: Active / 2: Inactive / 3: Graduated): ";
		Student.Status = clsStudent::enStatus(clsInputValidate::ReadShortNumber());
	}

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
	static void ShowAddNewStudentScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pAddStudent)) {
			return;
		}

		_DrawScreenHeader("\t\t  Add new Student Screen");

		int IDStudent = clsInputValidate::ReadIntNumber("Please Enter Student ID : ");

		while (clsStudentService::IsStudentExist(IDStudent)) {
			IDStudent = clsInputValidate::ReadIntNumber("\nStudent ID already exist. Enter another one: ");
		}

		clsStudent NewStudent = clsStudentService::GetAddNewStudentObject(IDStudent);

		_ReadStudentInfo(NewStudent);

		clsStudentService::enSaveResults SaveResult;
		SaveResult = clsStudentService::Save(NewStudent);

		switch (SaveResult) {
		case clsStudentService::enSaveResults::svSucceeded: {
			cout << "\nAccount Added Successfuly\n";
			_PrintStudent(NewStudent);
			break;
		}
		case clsStudentService::enSaveResults::svFaildEmptyObject: {
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsStudentService::enSaveResults::svIDStudentExists: {
			cout << "\nError account was not saved because IDStudent aleardy used";
			break;
		}
		}
	}
};