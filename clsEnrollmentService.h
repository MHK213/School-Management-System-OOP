#pragma once

#include <iostream>
#include "clsEnrollment.h"
#include "clsEnrollmentData.h"
#include "clsCourse.h"
#include "clsCourseService.h"

using namespace std;

class clsEnrollmentService
{
private:
	static clsEnrollment _GetEmptyEnrollmentObject() {
		return clsEnrollment(clsEnrollment::enMode::EmptyMode, 0, 0, 0, "", "", clsEnrollment::enStatus::EmptyS);
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

	static vector <clsEnrollment> GetAllEnrollments() {
		return clsEnrollmentData::LoadEnrollmentsDataFromFile();
	}

	static bool IsCourseFull(int CourseID) {
		clsCourse Course = clsCourseService::Find(CourseID);

		return (Course.MaxStudents <= _NumberOfStudentInCourse(CourseID));
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