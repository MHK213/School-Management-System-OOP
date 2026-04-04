#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsStudent.h"
#include "clsString.h"

using namespace std;

class clsStudent;

class clsStudentData
{
public:
	static clsStudent ConvertStudentLineToStudentObject(string Line, string Seprator = "#//#") {
		vector <string> vStudent = clsString::Split(Line, Seprator);

		return clsStudent(clsStudent::enMode::UpdateMode, stoi(vStudent[0]), vStudent[1], vStudent[2], stoi(vStudent[3]),
			vStudent[4], vStudent[5], clsStudent::stringToGender(vStudent[6]), 
			vStudent[7], clsStudent::stringToStatus(vStudent[8]));
	}

	static vector <clsStudent> LoadStudentsDataFromFile() {

		vector <clsStudent> _vStudents;

		fstream MyFile;
		MyFile.open("Students.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsStudent Student = ConvertStudentLineToStudentObject(Line);
				_vStudents.push_back(Student);
			}

			MyFile.close();
		}

		return _vStudents;
	}

	static void AddDataLineToFile(string Line, string FileName = "Students.txt") {

		fstream DataFile;
		DataFile.open(FileName, ios::out | ios::app);

		if (DataFile.is_open()) {
			DataFile << Line << endl;
			DataFile.close();
		}
	}

	static string ConvertStudentObjectToLine(clsStudent Student, string Seprator = "#//#") {

		string stStudentRecord = "";

		stStudentRecord += to_string(Student.ID) + Seprator;
		stStudentRecord += Student.FirstName + Seprator;
		stStudentRecord += Student.LastName + Seprator;
		stStudentRecord += to_string(Student.Age) + Seprator;
		stStudentRecord += Student.Email + Seprator;
		stStudentRecord += Student.Phone + Seprator;
		stStudentRecord += Student.stGender() + Seprator;
		stStudentRecord += Student.Level + Seprator;
		stStudentRecord += Student.stStatus();

		return stStudentRecord;
	}

	static void SaveStudentsDataToFile(vector <clsStudent> vStudents) {

		fstream MyFile;
		MyFile.open("Students.txt", ios::out);

		string DataLine;

		if (MyFile.is_open()) {

			for (clsStudent& S : vStudents) {
				if (S.MarkForDelete != true) {
					DataLine = ConvertStudentObjectToLine(S, "#//#");
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}
};