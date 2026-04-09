#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsTeacher.h"
#include "clsString.h"

using namespace std;

class clsTeacher;

class clsTeacherData
{
public:
	static clsTeacher ConvertTeacherLineToTeacherObject(string Line, string Seprator = "#//#") {
		vector <string> vTeacher = clsString::Split(Line, Seprator);

		return clsTeacher(clsTeacher::enMode::UpdateMode, stoi(vTeacher[0]), vTeacher[1], vTeacher[2], vTeacher[3], vTeacher[4],
			clsTeacher::StringToSpeciality(vTeacher[5]));
	}

	static vector <clsTeacher> LoadTeachersDataFromFile() {

		vector <clsTeacher> _vTeachers;

		fstream MyFile;
		MyFile.open("Teachers.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsTeacher Teacher = ConvertTeacherLineToTeacherObject(Line);
				_vTeachers.push_back(Teacher);
			}

			MyFile.close();
		}

		return _vTeachers;
	}

	static void AddDataLineToFile(string Line, string FileName = "Teachers.txt") {

		fstream DataFile;
		DataFile.open(FileName, ios::out | ios::app);

		if (DataFile.is_open()) {
			DataFile << Line << endl;
			DataFile.close();
		}
	}

	static string ConvertTeacherObjectToLine(clsTeacher Teacher, string Seprator = "#//#") {

		string stTeacherRecord = "";

		stTeacherRecord += to_string(Teacher.ID) + Seprator;
		stTeacherRecord += Teacher.FirstName + Seprator;
		stTeacherRecord += Teacher.LastName + Seprator;
		stTeacherRecord += Teacher.Email + Seprator;
		stTeacherRecord += Teacher.Phone + Seprator;
		stTeacherRecord += clsTeacher::SpecialityToString(Teacher.Speciality);

		return stTeacherRecord;
	}

	static void SaveTeachersDataToFile(vector <clsTeacher> vTeachers) {

		fstream MyFile;
		MyFile.open("Teachers.txt", ios::out);

		string DataLine;

		if (MyFile.is_open()) {

			for (clsTeacher& T : vTeachers) {
				if (T.MarkForDelete != true) {
					DataLine = ConvertTeacherObjectToLine(T, "#//#");
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}
};