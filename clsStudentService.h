#pragma once

#include <iostream>
#include "clsStudent.h"
#include "clsStudentData.h"
#include "clsString.h"

using namespace std;

class clsStudentService
{
private:
	static clsStudent _GetEmptyStudentObject() {
		return clsStudent(clsStudent::enMode::EmptyMode, 0, "", "", 0, "", "", 
			clsStudent::enGender::EmptyG, "", clsStudent::enStatus::EmptyS);
	}

	static void _AddNew(clsStudent Student) {
		clsStudentData::AddDataLineToFile(clsStudentData::ConvertStudentObjectToLine(Student));
	}

	static void _Update(clsStudent Student) {
		vector <clsStudent> vStudents = clsStudentData::LoadStudentsDataFromFile();

		for (clsStudent& S : vStudents) {
			if (S.ID == Student.ID) {
				S = Student;
				break;
			}
		}

		clsStudentData::SaveStudentsDataToFile(vStudents);
	}

public:
	static clsStudent Find(int ID) {
		vector <clsStudent> vStudents = clsStudentData::LoadStudentsDataFromFile();

		for(clsStudent& S : vStudents){
			if (S.ID == ID) {
				return S;
			}
		}

		return _GetEmptyStudentObject();
	}

	static clsStudent Find(int ID, string Level) {
		vector <clsStudent> vStudents = clsStudentData::LoadStudentsDataFromFile();

		for (clsStudent& S : vStudents) {
			if (S.ID == ID && S.Level == Level) {
				return S;
			}
		}

		return _GetEmptyStudentObject();
	}

	static bool IsStudentExist(int ID) {
		clsStudent Student = clsStudentService::Find(ID);

		return (!Student.IsEmpty());
	}

	static bool DeleteStudent(clsStudent& Student) {
		vector <clsStudent> vStudents = clsStudentData::LoadStudentsDataFromFile();

		for (clsStudent& S : vStudents) {
			if (S.ID == Student.ID) {
				S.MarkForDelete = true;
				break;
			}
		}

		clsStudentData::SaveStudentsDataToFile(vStudents);
		Student = _GetEmptyStudentObject();

		return true;
	}

	static clsStudent GetAddNewStudentObject(int ID) {
		return clsStudent(clsStudent::enMode::AddNewMode, ID, "", "", 0, "", "",
			clsStudent:: enGender::EmptyG, "", clsStudent::enStatus::EmptyS);
	}

	static vector <clsStudent> GetStudentsList() {
		return clsStudentData::LoadStudentsDataFromFile();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svIDStudentExists = 2 };

	static enSaveResults Save(clsStudent Student) {
		switch (Student.Mode) {
		case clsStudent::enMode::EmptyMode: {
			return enSaveResults::svFaildEmptyObject;
		}
		case clsStudent::enMode::UpdateMode: {
			_Update(Student);
			return enSaveResults::svSucceeded;
		}
		case clsStudent::enMode::AddNewMode: {
			if (clsStudentService::IsStudentExist(Student.ID)) return enSaveResults::svIDStudentExists;
			else {
				_AddNew(Student);
				Student.Mode = clsStudent::enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
		}
	}
};