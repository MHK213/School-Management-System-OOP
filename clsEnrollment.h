#pragma once

#include <iostream>
#include "clsDate.h"

using namespace std;

class clsEnrollment
{
public:
	enum enStatus { Active = 1, Dropped = 2, Completed = 3, EmptyS = 4 };
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

private:
	int _EnrollmentID;
	int _StudentID;
	int _CourseID;
	string _EnrollDate;
	string _Grade;
	enStatus _Status;
	bool _MarkForDelete = false;
	enMode _Mode;


public:
	clsEnrollment(enMode Mode, int EnrollmentID, int StudentID, int CourseID, string EnrollDate, string Grade, enStatus Status) {
		_Mode = Mode;
		_EnrollmentID = EnrollmentID;
		_StudentID = StudentID;
		_CourseID = CourseID;
		_EnrollDate = EnrollDate;
		_Grade = Grade;
		_Status = Status;
	}

	bool IsEmpty() { return _Mode == enMode::EmptyMode; }

	int GetEnrollmentID() { return _EnrollmentID; }
	__declspec(property(get = GetEnrollmentID)) int EnrollmentID;

	void SetStudentID(int StudentID) { _StudentID = StudentID; }
	int GetStudentID() { return _StudentID; }
	__declspec(property(get = GetStudentID, put = SetStudentID)) int StudentID;

	void SetCourseID(int CourseID) { _CourseID = CourseID; }
	int GetCourseID() { return _CourseID; }
	__declspec(property(get = GetCourseID, put = SetCourseID)) int CourseID;

	void SetEnrollDate(string EnrollDate) { 
		if (clsDate::IsValidDate(clsDate(EnrollDate))) {
			_EnrollDate = EnrollDate;
		}
	 }
	string GetEnrollDate() { return _EnrollDate; }
	__declspec(property(get = GetEnrollDate, put = SetEnrollDate)) string EnrollDate;

	void SetGrade(string Grade) { _Grade = Grade; }
	string GetGrade() { return _Grade; }
	__declspec(property(get = GetGrade, put = SetGrade)) string Grade;

	void SetMarkForDelete(bool MarkForDelete) { _MarkForDelete = MarkForDelete; }
	bool GetMarkForDelete() { return _MarkForDelete; }
	__declspec(property(get = GetMarkForDelete, put = SetMarkForDelete)) bool MarkForDelete;

	void SetStatus(enStatus Status) { _Status = Status; }
	enStatus GetStatus() { return _Status; }
	__declspec(property(get = GetStatus, put = SetStatus)) enStatus Status;

	void SetMode(enMode Mode) { _Mode = Mode; }
	enMode GetMode() { return _Mode; }
	__declspec(property(get = GetMode, put = SetMode)) enMode Mode;

	string StatusToString() {
		switch (_Status) {
		case Active: return "Active";
		case Dropped: return "Dropped";
		case Completed: return "Completed";
		default: return "Unknown";
		}
	}

	static enStatus stStatus(string Status) {
		if (Status == "Active") return enStatus::Active;
		if (Status == "Dropped") return enStatus::Dropped;
		if (Status == "Completed") return enStatus::Completed;
		return enStatus::EmptyS;
	}
};