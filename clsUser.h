#pragma once

#include <iostream>
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsUser : public clsPerson
{
public:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClients = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64, pLoginRegister = 128
	};
private:
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkForDelete = false;

public:
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password,
		int Permissions) : clsPerson(FirstName, LastName, Email, Phone) 
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

	void SetMarkForDelete(bool MarkForDelete) { _MarkForDelete = MarkForDelete; }
	bool GetMarkForDelete() { return _MarkForDelete; }
	__declspec(property(get = GetMarkForDelete, put = SetMarkForDelete)) bool MarkForDelete;

	void SetMode(enMode Mode) { _Mode = Mode; }
	enMode GetMode() { return _Mode; }
	__declspec (property(get = GetMode, put = SetMode)) enMode Mode;

	void SetUserName(string UserName) { _UserName = UserName; }
	string GetUserName() { return _UserName; }
	__declspec (property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password) { _Password = Password; }
	string GetPassword() { return _Password; }
	__declspec (property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions) { _Permissions = Permissions; }
	int GetPermissions() { return _Permissions; }
	__declspec (property(get = GetPermissions, put = SetPermissions)) int Permissions;
};