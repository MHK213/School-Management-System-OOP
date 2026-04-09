#pragma once

#include <iostream>
#include "clsPerson.h"

using namespace std;

class clsTeacher : public clsPerson
{
public:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	enum enSpeciality {
		spAll = 0,
		spMath = 1,
		spPhysics = 2,
		spComputerScience = 3,
		spEnglish = 4,
		spArabic = 5,
		spHistory = 6,
		spEmpty = 7
	};

private:
	int _ID;
	enSpeciality _Speciality;
	bool _MarkForDelete = false;
	enMode _Mode;

public:

	clsTeacher(enMode Mode, int ID, string FirstName, string LastName, string Email, string Phone, enSpeciality Speciality)
		: clsPerson(FirstName, LastName, Email, Phone) 
	{
		_Mode = Mode;
		_ID = ID;
		_Speciality = Speciality;

	}

	void SetMode(enMode Mode) { _Mode = Mode; }
	enMode GetMode() { return _Mode; }
	__declspec(property(get = GetMode, put = SetMode)) enMode Mode;

	int GetID() { return _ID; }
	__declspec(property(get = GetID)) int ID;

	void SetSpeciality(enSpeciality Speciality) { _Speciality = Speciality; }
	enSpeciality GetSpeciality() { return _Speciality; }
	__declspec(property(get = GetSpeciality, put = SetSpeciality)) enSpeciality Speciality;

	void SetMarkForDelete(bool MarkForDelete) { _MarkForDelete = MarkForDelete; }
	bool GetMarkForDelete() { return _MarkForDelete; }
	__declspec(property(get = GetMarkForDelete, put = SetMarkForDelete)) bool MarkForDelete;

	bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

	static string SpecialityToString(enSpeciality sp) {
		switch (sp) {
		case spMath: return "Math";
		case spPhysics: return "Physics";
		case spComputerScience: return "ComputerScience";
		case spEnglish: return "English";
		case spArabic: return "Arabic";
		case spHistory: return "History";
		default: return "All";
		}
	}

	static enSpeciality StringToSpeciality(string sp) {
		if (sp == "Math") return spMath;
		if (sp == "Physics") return spPhysics;
		if (sp == "ComputerScience") return spComputerScience;
		if (sp == "English") return spEnglish;
		if (sp == "Arabic") return spArabic;
		if (sp == "History") return spHistory;

		return spAll;
	}
};