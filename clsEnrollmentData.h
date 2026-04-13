#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsEnrollment.h"
#include "clsString.h"

using namespace std;

class clsEnrollment;

class clsEnrollmentData
{
public:
	static clsEnrollment ConvertEnrollmentLineToEnrollmentObject(string Line, string Seprator = "#//#") {
		vector <string> vEnrollment = clsString::Split(Line, Seprator);

		return clsEnrollment(clsEnrollment::enMode::UpdateMode, stoi(vEnrollment[0]), stoi(vEnrollment[1]), stoi(vEnrollment[2]), 
			vEnrollment[3], vEnrollment[4], clsEnrollment::stStatus(vEnrollment[5]));
	}

	static vector <clsEnrollment> LoadEnrollmentsDataFromFile() {

		vector <clsEnrollment> _vEnrollments;

		fstream MyFile;
		MyFile.open("Enrollments.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsEnrollment Enrollment = ConvertEnrollmentLineToEnrollmentObject(Line);
				_vEnrollments.push_back(Enrollment);
			}

			MyFile.close();
		}

		return _vEnrollments;
	}

	static void AddDataLineToFile(string Line, string FileName = "Enrollments.txt") {

		fstream DataFile;
		DataFile.open(FileName, ios::out | ios::app);

		if (DataFile.is_open()) {
			DataFile << Line << endl;
			DataFile.close();
		}
	}

	static string ConvertEnrollmentObjectToLine(clsEnrollment& Enrollment, string Seprator = "#//#") {

		string stEnrollmentRecord = "";

		stEnrollmentRecord += to_string(Enrollment.EnrollmentID) + Seprator;
		stEnrollmentRecord += to_string(Enrollment.StudentID) + Seprator;
		stEnrollmentRecord += to_string(Enrollment.CourseID) + Seprator;
		stEnrollmentRecord += Enrollment.EnrollDate + Seprator;
		stEnrollmentRecord += Enrollment.Grade + Seprator;
		stEnrollmentRecord += Enrollment.StatusToString();

		return stEnrollmentRecord;
	}

	static void SaveEnrollmentsDataToFile(vector <clsEnrollment>& vEnrollments) {

		fstream MyFile;
		MyFile.open("Enrollments.txt", ios::out);

		string DataLine;

		if (MyFile.is_open()) {

			for (clsEnrollment& E : vEnrollments) {
				if (E.MarkForDelete != true) {
					DataLine = ConvertEnrollmentObjectToLine(E, "#//#");
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}
};