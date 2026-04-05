#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"

using namespace std;

class clsStudent : public clsPerson
{
public:
	enum enGender { Male = 1, Female = 2, EmptyG = 3 };
	enum enStatus { Active = 1, Inactive = 2, Graduated = 3, EmptyS = 4 };
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

private:
	int _ID;
	int _Age;
	string _Level;
	enGender _Gender;
	enStatus _Status;
	bool _MarkForDelete = false;
	enMode _Mode;

public:
	clsStudent(enMode Mode, int ID, string FirstName, string LastName,
		int Age, string Email, string Phone, enGender Gender,
		string Level, enStatus Status) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_ID = ID;
		_Age = Age;
		_Gender = Gender;
		_Level = Level;
		_Status = Status;
	}

	bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

	int GetID() { return _ID; }

	__declspec(property(get = GetID)) int ID;
	
	void SetAge(int age) { _Age = age; }
	int GetAge() { return _Age; }

	__declspec(property(get = GetAge, put = SetAge)) int Age;

	void SetGender(enGender gender) { _Gender = gender; }
	enGender GetGender() { return _Gender; }

	__declspec(property(get = GetGender, put = SetGender)) enGender Gender;

	void SetLevel(string Level) { _Level = Level; }
	string  GetLevel() { return _Level; }

	__declspec(property(get = GetLevel, put = SetLevel)) string Level;

	void SetStatus(enStatus Status) { _Status = Status; }
	enStatus GetStatus() { return _Status; }

	__declspec(property(get = GetStatus, put = SetStatus)) enStatus Status;

	void SetMarkForDelete(bool MarkForDelete) { _MarkForDelete = MarkForDelete; }
	bool GetMarkForDelete() { return _MarkForDelete; }
	__declspec(property(get = GetMarkForDelete, put = SetMarkForDelete)) bool MarkForDelete;

	void SetMode(enMode Mode) { _Mode = Mode; }
	enMode GetMode() { return _Mode; }
	__declspec(property(get = GetMode, put = SetMode)) enMode Mode;

	string stGender() {
		switch (_Gender) {
		case Male: return "Male";
		case Female: return "Female";
		default: return "Unknown";
		}
	}

	string stStatus() {
		switch (_Status) {
		case Active: return "Active";
		case Inactive: return "Inactive";
		case Graduated: return "Graduated";
		default: return "Unknown";
		}
	}

	static enGender stringToGender(string Gender) {
		if (Gender == "Male") return enGender::Male;
		if (Gender == "Female") return enGender::Female;
		return enGender::EmptyG;
	}

	static enStatus stringToStatus(string Status) {
		if (Status == "Active") return enStatus::Active;
		if (Status == "Inactive") return enStatus::Inactive;
		if (Status == "Graduated") return enStatus::Graduated;
		return enStatus::EmptyS;
	}
};