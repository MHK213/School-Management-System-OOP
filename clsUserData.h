#pragma once

#include <iostream>
#include "clsUser.h"
#include <string>
#include "clsUtil.h"

using namespace std;

class clsUserData
{
private:
	static string _PrepareLogInRecord(clsUser User, string Seperator = "#//#") {
		string LoginRecord = "";
		LoginRecord = clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += User.UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(User.Password) + Seperator;
		LoginRecord += to_string(User.Permissions);

		return LoginRecord;
	}

	static clsUser::stLoginRegisterRecord _ConvertLoginRegisterToRecord(string Line, string Seprator = "#//#") {

		clsUser::stLoginRegisterRecord LoginRegisterRecord;

		vector <string> vUsers = clsString::Split(Line, Seprator);

		LoginRegisterRecord.DateTime = vUsers[0];
		LoginRegisterRecord.UserName = vUsers[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(vUsers[2]);
		LoginRegisterRecord.Permissions = stoi(vUsers[3]);

		return LoginRegisterRecord;
	}

public:
	static clsUser ConvertLineToUserObject(string Line, string Seprator = "#//#") {

		vector <string> vUsers;
		vUsers = clsString::Split(Line, Seprator);

		return clsUser(clsUser::enMode::UpdateMode, vUsers[0], vUsers[1], vUsers[2], vUsers[3], vUsers[4],
			clsUtil::DecryptText(vUsers[5]), stod(vUsers[6]));
	}

	static string ConvertUserObjectToLine(clsUser User, string Seprator = "#//#") {

		string stUserRecord = "";

		stUserRecord += User.FirstName + Seprator;
		stUserRecord += User.LastName + Seprator;
		stUserRecord += User.Email + Seprator;
		stUserRecord += User.Phone + Seprator;
		stUserRecord += User.UserName + Seprator;
		stUserRecord += clsUtil::EncryptText(User.Password) + Seprator;
		stUserRecord += to_string(User.Permissions);

		return stUserRecord;
	}

	static vector <clsUser> LoadUsersDataFromFile() {

		vector <clsUser> _vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsUser User = ConvertLineToUserObject(Line);
				_vUsers.push_back(User);
			}

			MyFile.close();
		}

		return _vUsers;
	}

	static void SaveUserDataToFile(vector <clsUser> vUsers) {

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		string DataLine;

		if (MyFile.is_open()) {

			for (clsUser& U : vUsers) {
				if (U.MarkForDelete != true) {
					DataLine = ConvertUserObjectToLine(U, "#//#");
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}

	static void AddDataLineToFile(string Line, string FileName = "Users.txt") {

		fstream DataFile;
		DataFile.open(FileName, ios::out | ios::app);

		if (DataFile.is_open()) {
			DataFile << Line << endl;
			DataFile.close();
		}
	}

	static void RegisterLogIn(clsUser User) {
		string stDataLine = _PrepareLogInRecord(User);

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open()) {
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	static vector <clsUser::stLoginRegisterRecord> LoginRegistersList() {

		vector <clsUser::stLoginRegisterRecord> vLoginRegistersRecord;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			clsUser::stLoginRegisterRecord LoginRegisterRecord;

			while (getline(MyFile, Line)) {

				LoginRegisterRecord = _ConvertLoginRegisterToRecord(Line);
				vLoginRegistersRecord.push_back(LoginRegisterRecord);
			}

			MyFile.close();
		}

		return vLoginRegistersRecord;
	}
};