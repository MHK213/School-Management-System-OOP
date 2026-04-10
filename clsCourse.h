#pragma once

#include <iostream>

using namespace std;

class clsCourse
{
public:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

private:
	int _CourseID;
	string _CourseName;
	int _TeacherID;
	int _CreditHours;
    short _MaxStudents;
    enMode _Mode;
    bool _MarkForDelete = false;

public:
    clsCourse(enMode Mode, int CourseID, string CourseName, int TeacherID, int Credit, short MaxStudents)
    {
        _Mode = Mode;
        _CourseID = CourseID;
        _CourseName = CourseName;
        _TeacherID = TeacherID;
        _CreditHours = Credit;
        _MaxStudents = MaxStudents;
    }

    bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

    int GetCourseID() { return _CourseID; }
    __declspec(property(get = GetCourseID)) int CourseID;

    void   SetCourseName(string CourseName) { _CourseName = CourseName; }
    string GetCourseName() { return _CourseName; }
    __declspec(property(get = GetCourseName, put = SetCourseName)) string CourseName;

    void SetTeacherID(int TeacherID) { _TeacherID = TeacherID; }
    int  GetTeacherID() { return _TeacherID; }
    __declspec(property(get = GetTeacherID, put = SetTeacherID)) int TeacherID;

    void SetCreditHours(int CreditHours) {
        if (CreditHours > 0)
            _CreditHours = CreditHours;
    }
    int  GetCreditHours() { return _CreditHours; }
    __declspec(property(get = GetCreditHours, put = SetCreditHours)) int CreditHours;

    void SetMaxStudents(int MaxStudents) {
        if (MaxStudents >= 0)
            _MaxStudents = MaxStudents;
    }
    int  GetMaxStudents() { return _MaxStudents; }
    __declspec(property(get = GetMaxStudents, put = SetMaxStudents)) int MaxStudents;

    void SetMarkForDelete(bool MarkForDelete) { _MarkForDelete = MarkForDelete; }
    bool GetMarkForDelete() { return _MarkForDelete; }
    __declspec(property(get = GetMarkForDelete, put = SetMarkForDelete)) bool MarkForDelete;

    void SetMode(enMode Mode) { _Mode = Mode; }
    enMode GetMode() { return _Mode; }
    __declspec(property(get = GetMode, put = SetMode)) enMode Mode;

    void Print() {
        cout << "\nCourse Card :";
        cout << "\n________________________________________";
        cout << "\nCourse ID    : " << _CourseID;
        cout << "\nCourse Name  : " << _CourseName;
        cout << "\nTeacher ID   : " << _TeacherID;
        cout << "\nCredit Hours : " << _CreditHours;
        cout << "\nMax Students  : " << _MaxStudents;
        cout << "\n________________________________________\n";
    }
};