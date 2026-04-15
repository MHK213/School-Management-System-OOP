#pragma once

#include <iostream>
#include "clsEnrollment.h"
#include "clsEnrollmentData.h"
#include "clsCourse.h"
#include "clsCourseService.h"
#include <map>

using namespace std;

class clsEnrollmentService
{
private:
	static clsEnrollment _GetEmptyEnrollmentObject() {
		return clsEnrollment(clsEnrollment::enMode::EmptyMode, 0, 0, 0, "", "", clsEnrollment::enStatus::EmptyS);
	}

	static clsCourse _GetEmptyCourseObject() {
		return clsCourse(clsCourse::enMode::EmptyMode, 0, "", 0, 0, 0);
	}

	static void _EnrollStudent(clsEnrollment Enrollment) {
		clsEnrollmentData::AddDataLineToFile(clsEnrollmentData::ConvertEnrollmentObjectToLine(Enrollment));
	}

	static void _Update(clsEnrollment Enrollment) {
		vector <clsEnrollment> vEnrollments = clsEnrollmentData::LoadEnrollmentsDataFromFile();

		for (clsEnrollment& E : vEnrollments) {
			if (E.EnrollmentID == Enrollment.EnrollmentID) {
				E = Enrollment;
				break;
			}
		}

		clsEnrollmentData::SaveEnrollmentsDataToFile(vEnrollments);
	}

	static int _NumberOfStudentInCourse(int CourseID) {
		vector <clsEnrollment> vEnrollments = clsEnrollmentData::LoadEnrollmentsDataFromFile();
		int Count = 0;
		for (clsEnrollment& E : vEnrollments) {
			if (E.CourseID == CourseID && E.Status == clsEnrollment::enStatus::Active) {
				Count++;
			}
		}

		return Count;
	}

public:
	static clsEnrollment Find(int EnrollmentID) {
		vector <clsEnrollment> vEnrollments = clsEnrollmentData::LoadEnrollmentsDataFromFile();

		for (clsEnrollment& E : vEnrollments) {
			if (E.EnrollmentID == EnrollmentID) {
				return E;
			}
		}

		return _GetEmptyEnrollmentObject();
	}

	static clsEnrollment Find(int CourseID, int StudentID) {
		vector <clsEnrollment> vEnrollments = clsEnrollmentData::LoadEnrollmentsDataFromFile();

		for (clsEnrollment& E : vEnrollments) {
			if (E.CourseID == CourseID && E.StudentID == StudentID) {
				return E;
			}
		}

		return _GetEmptyEnrollmentObject();
	}

	static bool IsEnrollmentIDExist(int EnrollmentID) {
		clsEnrollment Enrollment = clsEnrollmentService::Find(EnrollmentID);

		return (!Enrollment.IsEmpty());
	}

	static bool IsStudentEnrolled(int StudentID, int CourseID) {
		clsEnrollment Enrollment = clsEnrollmentService::Find(CourseID, StudentID);

		return (!Enrollment.IsEmpty());
	}

	static bool DropEnrollment(clsEnrollment& Enrollment) {
		vector <clsEnrollment> vEnrollments = clsEnrollmentData::LoadEnrollmentsDataFromFile();

		for (clsEnrollment& E : vEnrollments) {
			if (E.EnrollmentID == Enrollment.EnrollmentID) {
				if (E.Status == clsEnrollment::enStatus::Dropped) return false;

				E.Status = clsEnrollment::enStatus::Dropped;
				E.Grade = "NULL";
				break;
			}
		}

		clsEnrollmentData::SaveEnrollmentsDataToFile(vEnrollments);

		Enrollment.Status = clsEnrollment::enStatus::Dropped;
		Enrollment.Grade = "NULL";

		return true;
	}

	static clsEnrollment GetAddNewEnrollmentObject(int EnrollmentID, int StudentID, int CourseID) {
		return clsEnrollment(clsEnrollment::enMode::AddNewMode, EnrollmentID, StudentID, CourseID, "", "", 
			clsEnrollment::enStatus::EmptyS);
	}

	static vector<clsEnrollment> GetEnrollmentsByStudent(int StudentID) {

		vector<clsEnrollment> vAll = clsEnrollmentData::LoadEnrollmentsDataFromFile();
		vector<clsEnrollment> vResult;

		for (clsEnrollment& E : vAll) {

			if (E.StudentID == StudentID)
			{
				vResult.push_back(E);
			}
		}

		return vResult;
	}

	static vector<clsEnrollment> GetEnrollmentsByCourse(int CourseID) {

		vector<clsEnrollment> vAll = clsEnrollmentData::LoadEnrollmentsDataFromFile();
		vector<clsEnrollment> vResult;

		for (clsEnrollment& E : vAll) {

			if (E.CourseID == CourseID)
			{
				vResult.push_back(E);
			}
		}

		return vResult;
	}

	static vector<clsEnrollment> GetCompletedEnrollments() {

		vector<clsEnrollment> vAll = clsEnrollmentData::LoadEnrollmentsDataFromFile();
		vector<clsEnrollment> vResult;

		for (clsEnrollment& E : vAll) {

			if (E.Status == clsEnrollment::enStatus::Completed && E.Grade == "NULL")
			{
				vResult.push_back(E);
			}
		}

		return vResult;
	}

	static int NumberOfActiveEnrollments() {
		vector<clsEnrollment> vAll = clsEnrollmentData::LoadEnrollmentsDataFromFile();
		int Count = 0;

		for (clsEnrollment& E : vAll) {

			if (E.Status == clsEnrollment::enStatus::Active)
			{
				Count++;
			}
		}

		return Count;
	}

	static int NumberOfCompletedEnrollments() {
		vector<clsEnrollment> vAll = clsEnrollmentData::LoadEnrollmentsDataFromFile();
		int Count = 0;

		for (clsEnrollment& E : vAll) {

			if (E.Status == clsEnrollment::enStatus::Completed)
			{
				Count++;
			}
		}

		return Count;
	}

	static int NumberOfDroppedEnrollments() {
		vector<clsEnrollment> vAll = clsEnrollmentData::LoadEnrollmentsDataFromFile();
		int Count = 0;

		for (clsEnrollment& E : vAll) {

			if (E.Status == clsEnrollment::enStatus::Dropped)
			{
				Count++;
			}
		}

		return Count;
	}

	static clsEnrollment FindCompletedEnrollmentByID(int EnrollmentID) {
		vector<clsEnrollment> vCompletedEnrollments = clsEnrollmentService::GetCompletedEnrollments();

		for (clsEnrollment& E : vCompletedEnrollments) {
			if (E.EnrollmentID == EnrollmentID) {
				return E;
			}
		}

		return _GetEmptyEnrollmentObject();
	}

	static vector <clsEnrollment> GetAllEnrollments() {
		return clsEnrollmentData::LoadEnrollmentsDataFromFile();
	}

	static bool IsCourseFull(int CourseID) {
		clsCourse Course = clsCourseService::Find(CourseID);

		return (Course.MaxStudents <= _NumberOfStudentInCourse(CourseID));
	}

	static pair<clsCourse, int> GetMostPopularCourseWithCount() {

		vector<clsEnrollment> vEnrollments = clsEnrollmentService::GetAllEnrollments();

		map<int, int> CourseCount;

		for (clsEnrollment& E : vEnrollments) {
			if (E.Status == clsEnrollment::Active || E.Status == clsEnrollment::Completed)
				CourseCount[E.CourseID]++;
		}

		int MaxCourseID = -1;
		int MaxCount = 0;

		for (auto& pair : CourseCount) {
			if (pair.second > MaxCount) {
				MaxCount = pair.second;
				MaxCourseID = pair.first;
			}
		}

		if (MaxCourseID == -1)
			return { _GetEmptyCourseObject(), 0 };

		return { clsCourseService::Find(MaxCourseID), MaxCount };
	}

	static int GetNumberOfFullCourses() {

		vector<clsCourse> vCourses = clsCourseData::LoadCoursesDataFromFile();
		vector<clsEnrollment> vEnrollments = clsEnrollmentService::GetAllEnrollments();

		map<int, int> CourseCount;

		for (clsEnrollment& E : vEnrollments) {
			if (E.Status == clsEnrollment::Active || E.Status == clsEnrollment::Completed)
				CourseCount[E.CourseID]++;
		}

		int FullCourses = 0;

		for (clsCourse& C : vCourses) {
			if (CourseCount[C.CourseID] >= C.MaxStudents)
				FullCourses++;
		}

		return FullCourses;
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svStudentAlreadyEnrolled = 2, svCourseFull = 3 };

	static enSaveResults Save(clsEnrollment Enrollment) {
		switch (Enrollment.Mode) {
		case clsEnrollment::enMode::EmptyMode: {
			return enSaveResults::svFaildEmptyObject;
		}
		case clsEnrollment::enMode::UpdateMode: {
			_Update(Enrollment);
			return enSaveResults::svSucceeded;
		}
		case clsEnrollment::enMode::AddNewMode: {
			if (clsEnrollmentService::IsStudentEnrolled(Enrollment.StudentID, Enrollment.CourseID))
				return enSaveResults::svStudentAlreadyEnrolled;
			else if (clsEnrollmentService::IsCourseFull(Enrollment.CourseID))
				return enSaveResults::svCourseFull;
			else {
				_EnrollStudent(Enrollment);
				Enrollment.Mode = clsEnrollment::enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
		}
	}
};