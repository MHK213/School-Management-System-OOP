#pragma once

#include <iostream>
#include "clsPerson.h"

using namespace std;

class clsTeacher : public clsPerson
{
public:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

private:
	int _ID;
	string _Speciality;
	bool _MarkForDelete = false;
	enMode _Mode;

public:

	clsTeacher(enMode Mode, int ID, string FirstName, string LastName, string Email, string Phone, string Speciality)
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

	void SetSpeciality(string Speciality) { _Speciality = Speciality; }
	string GetSpeciality() { return _Speciality; }
	__declspec(property(get = GetSpeciality, put = SetSpeciality)) string Speciality;

	void SetMarkForDelete(bool MarkForDelete) { _MarkForDelete = MarkForDelete; }
	bool GetMarkForDelete() { return _MarkForDelete; }
	__declspec(property(get = GetMarkForDelete, put = SetMarkForDelete)) bool MarkForDelete;

	bool IsEmpty() { return (_Mode == enMode::EmptyMode); }
};