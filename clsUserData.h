#pragma once

#include <iostream>
#include "clsUser.h"
#include <string>

using namespace std;

class clsUserData
{
public:
	static clsUser ConvertLineToUserObject(string Line, string Seprator = "#//#") {

		vector <string> vUsers;
		vUsers = clsString::Split(Line, Seprator);

		return clsUser(clsUser::enMode::UpdateMode, vUsers[0], vUsers[1], vUsers[2], vUsers[3], vUsers[4],
			vUsers[5], stod(vUsers[6]));
	}

	static string ConvertUserObjectToLine(clsUser User, string Seprator = "#//#") {

		string stUserRecord = "";

		stUserRecord += User.FirstName + Seprator;
		stUserRecord += User.LastName + Seprator;
		stUserRecord += User.Email + Seprator;
		stUserRecord += User.Phone + Seprator;
		stUserRecord += User.UserName + Seprator;
		stUserRecord += User.Password + Seprator;
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
};