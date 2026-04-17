#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsUserService.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private:
	static int _ReadPermissions() {

		char Answer = 'n';
		int Permissions = 0;

		do {
			cout << "\nDo you want to give full access? Y/N? ";
			cin >> Answer;
		} while (toupper(Answer) != 'Y' && toupper(Answer) != 'N');

		if (toupper(Answer) == 'Y')
			return clsUser::eAll;

		cout << "\nSelect Permissions:\n";

		// Students
		cout << "\nAccess Students List? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pListStudents;

		cout << "\nAdd Student? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pAddStudent;

		cout << "\nDelete Student? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pDeleteStudent;

		cout << "\nUpdate Student? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pUpdateStudent;

		cout << "\nFind Student? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pFindStudent;

		// Modules
		cout << "\nManage Teachers? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pManageTeachers;

		cout << "\nManage Courses? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pManageCourses;

		cout << "\nManage Enrollments? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pManageEnrollments;

		cout << "\nView Reports? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pViewReports;

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pManageUsers;

		cout << "\nLogin Register? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permissions |= clsUser::pLoginRegister;

		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User) {

		cout << "\nEnter First Name? ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name? ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Email? ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Phone? ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter Password? ";
		User.Password = clsInputValidate::ReadString();

		User.Permissions = _ReadPermissions();
	}

	static void _PrintUser(clsUser User) {
		cout << "\nUser Card :";
		cout << "\n________________________________________";
		cout << "\nFirst Name   : " << User.FirstName;
		cout << "\nLast Name    : " << User.LastName;
		cout << "\nFull Name    : " << User.FullName();
		cout << "\nEmail        : " << User.Email;
		cout << "\nPhone        : " << User.Phone;
		cout << "\nUserName     : " << User.UserName;
		cout << "\nPassword     : " << User.Password;
		cout << "\nPermissions  : " << User.Permissions;
		cout << "\n________________________________________" << endl;
	}

public:
	static void ShowUpdateUserScreen() {

		_DrawScreenHeader("\t\tUpdate User Screen");

		string UserName = "";
		cout << "\nEnter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUserService::IsUserExist(UserName)) {
			cout << "\nUserName is not found, Enter another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUserService::FindUser(UserName);
		_PrintUser(User);

		cout << "\n\nUpdate User Info: ";
		cout << "\n________________________";

		_ReadUserInfo(User);

		clsUserService::enSaveResults SaveResult;
		SaveResult = clsUserService::Save(User);

		switch (SaveResult) {
		case clsUserService::svSucceeded:
			cout << "\nAccount Updated Succesfully\n";
			_PrintUser(User);
			break;
		case clsUserService::svFaildEmptyObject:
			cout << "\nError! Account was not Saved because it's Empty\n";
			break;
		}
	}
};