#pragma once

#include <iostream>
#include "clsTeacher.h"
#include "clsTeacherData.h"
#include "clsString.h"

using namespace std;

class clsTeacherService
{
private:
	static clsTeacher _GetEmptyTeacherObject() {
		return clsTeacher(clsTeacher::enMode::EmptyMode, 0, "", "", "", "", "");
	}

	static void _AddNew(clsTeacher Teacher) {
		clsTeacherData::AddDataLineToFile(clsTeacherData::ConvertTeacherObjectToLine(Teacher));
	}

	static void _Update(clsTeacher Teacher) {
		vector <clsTeacher> vTeachers = clsTeacherData::LoadTeachersDataFromFile();

		for (clsTeacher& T : vTeachers) {
			if (T.ID == Teacher.ID) {
				T = Teacher;
				break;
			}
		}

		clsTeacherData::SaveTeachersDataToFile(vTeachers);
	}

public:
	static clsTeacher Find(int ID) {
		vector <clsTeacher> vTeachers = clsTeacherData::LoadTeachersDataFromFile();

		for (clsTeacher& T : vTeachers) {
			if (T.ID == ID) {
				return T;
			}
		}

		return _GetEmptyTeacherObject();
	}

	static clsTeacher Find(int ID, string Speciality) {
		vector <clsTeacher> vTeachers = clsTeacherData::LoadTeachersDataFromFile();

		for (clsTeacher& T : vTeachers) {
			if (T.ID == ID && T.Speciality == Speciality) {
				return T;
			}
		}

		return _GetEmptyTeacherObject();
	}

	static bool IsTeacherExist(int ID) {
		clsTeacher Teacher = clsTeacherService::Find(ID);

		return (!Teacher.IsEmpty());
	}

	static bool DeleteTeacher(clsTeacher& Teacher) {
		vector <clsTeacher> vTeachers = clsTeacherData::LoadTeachersDataFromFile();

		for (clsTeacher& T : vTeachers) {
			if (T.ID == Teacher.ID) {
				T.MarkForDelete = true;
				break;
			}
		}

		clsTeacherData::SaveTeachersDataToFile(vTeachers);
		Teacher = _GetEmptyTeacherObject();

		return true;
	}

	static clsTeacher GetAddNewTeacherObject(int ID) {
		return clsTeacher(clsTeacher::enMode::AddNewMode, ID, "", "", "", "", "");
	}

	static vector <clsTeacher> GetTeachersList() {
		return clsTeacherData::LoadTeachersDataFromFile();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svIDTeacherExists = 2 };

	static enSaveResults Save(clsTeacher Teacher) {
		switch (Teacher.Mode) {
		case clsTeacher::enMode::EmptyMode: {
			return enSaveResults::svFaildEmptyObject;
		}
		case clsTeacher::enMode::UpdateMode: {
			_Update(Teacher);
			return enSaveResults::svSucceeded;
		}
		case clsTeacher::enMode::AddNewMode: {
			if (clsTeacherService::IsTeacherExist(Teacher.ID)) return enSaveResults::svIDTeacherExists;
			else {
				_AddNew(Teacher);
				Teacher.Mode = clsTeacher::enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
		}
	}
};