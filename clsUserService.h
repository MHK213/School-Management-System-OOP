#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsUserData.h"

using namespace std;

class clsUserService
{
private:
	static clsUser _GetEmptyUserObject() {
		return clsUser(clsUser::enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static void _Update(clsUser User) {

		vector <clsUser> _vUsers;
		_vUsers = clsUserData::LoadUsersDataFromFile();

		for (clsUser& U : _vUsers) {
			if (U.UserName == User.UserName) {
				U = User;
				break;
			}
		}
		clsUserData::SaveUserDataToFile(_vUsers);
	}

	static void _AddNew(clsUser User) {
		clsUserData::AddDataLineToFile(clsUserData::ConvertUserObjectToLine(User));
	}

public:
	static clsUser GetAddNewUserObject(string UserName) {
		return clsUser(clsUser::enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static clsUser FindUser(string UserName) {
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUser User = clsUserData::ConvertLineToUserObject(Line);

				if (User.UserName == UserName) {
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser FindUser(string UserName, string Password) {
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUser User = clsUserData::ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.Password == Password) {
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName) {
		clsUser User = clsUserService::FindUser(UserName);
		return (!User.IsEmpty());
	}

	static bool Delete(clsUser& User) {
		vector <clsUser> vUsers;
		vUsers = clsUserData::LoadUsersDataFromFile();

		for (clsUser& U : vUsers) {
			if (U.UserName == User.UserName) {
				U.MarkForDelete = true;
				break;
			}
		}

		clsUserData::SaveUserDataToFile(vUsers);

		User = _GetEmptyUserObject();

		return true;
	}

	static vector <clsUser> GetUsersList() {
		return clsUserData::LoadUsersDataFromFile();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExist = 2 };

	static enSaveResults Save(clsUser User) {
		switch (User.Mode) {
		case clsUser::UpdateMode:
			_Update(User);
			return enSaveResults::svSucceeded;
		case clsUser::AddNewMode:
			if (clsUserService::IsUserExist(User.UserName))
				return svFaildUserNameExist;
			else {
				_AddNew(User);
				User.Mode = clsUser::enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		case clsUser::EmptyMode:
			return enSaveResults::svFaildEmptyObject;
		}
	}
};