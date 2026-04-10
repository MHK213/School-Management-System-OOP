#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsCourse.h"
#include "clsString.h"

using namespace std;

class clsCourse;

class clsCourseData
{
public:
	static clsCourse ConvertCourseLineToCourseObject(string Line, string Seprator = "#//#") {
		vector <string> vCourses = clsString::Split(Line, Seprator);

		return clsCourse(clsCourse::enMode::UpdateMode, stoi(vCourses[0]), vCourses[1], stoi(vCourses[2]), stoi(vCourses[3]),
			(short)stoi(vCourses[4]));
	}

	static vector <clsCourse> LoadCoursesDataFromFile() {

		vector <clsCourse> _vCourses;

		fstream MyFile;
		MyFile.open("Courses.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsCourse Course = ConvertCourseLineToCourseObject(Line);
				_vCourses.push_back(Course);
			}

			MyFile.close();
		}

		return _vCourses;
	}

	static void AddDataLineToFile(string Line, string FileName = "Courses.txt") {

		fstream DataFile;
		DataFile.open(FileName, ios::out | ios::app);

		if (DataFile.is_open()) {
			DataFile << Line << endl;
			DataFile.close();
		}
	}

	static string ConvertCourseObjectToLine(clsCourse Course, string Seprator = "#//#") {

		string stCourseRecord = "";

		stCourseRecord += to_string(Course.CourseID) + Seprator;
		stCourseRecord += Course.CourseName + Seprator;
		stCourseRecord += to_string(Course.TeacherID) + Seprator;
		stCourseRecord += to_string(Course.CreditHours) + Seprator;
		stCourseRecord += to_string(Course.MaxStudents);

		return stCourseRecord;
	}

	static void SaveCoursesDataToFile(vector <clsCourse> vCourses) {

		fstream MyFile;
		MyFile.open("Courses.txt", ios::out);

		string DataLine;

		if (MyFile.is_open()) {

			for (clsCourse& C : vCourses) {
				if (C.MarkForDelete != true) {
					DataLine = ConvertCourseObjectToLine(C, "#//#");
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}
};