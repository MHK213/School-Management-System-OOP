#pragma once

#include <iostream>
#include "clsCourse.h"
#include "clsCourseData.h"
#include "clsString.h"

using namespace std;

class clsCourseService
{
private:
	static clsCourse _GetEmptyCourseObject() {
		return clsCourse(clsCourse::enMode::EmptyMode, 0, "", 0, 0, 0);
	}

	static void _AddNew(clsCourse Course) {
		clsCourseData::AddDataLineToFile(clsCourseData::ConvertCourseObjectToLine(Course));
	}

	static void _Update(clsCourse Course) {
		vector <clsCourse> vCourses = clsCourseData::LoadCoursesDataFromFile();

		for (clsCourse& C : vCourses) {
			if (C.CourseID == Course.CourseID) {
				C = Course;
				break;
			}
		}

		clsCourseData::SaveCoursesDataToFile(vCourses);
	}

public:
	static clsCourse Find(int CourseID) {
		vector <clsCourse> vCourses = clsCourseData::LoadCoursesDataFromFile();

		for (clsCourse& C : vCourses) {
			if (C.CourseID == CourseID) {
				return C;
			}
		}

		return _GetEmptyCourseObject();
	}

	static clsCourse Find(int CourseID, string CourseName) {
		vector <clsCourse> vCourses = clsCourseData::LoadCoursesDataFromFile();

		for (clsCourse& C : vCourses) {
			if (C.CourseID == CourseID && C.CourseName == CourseName) {
				return C;
			}
		}

		return _GetEmptyCourseObject();
	}

	static bool IsCourseExist(int CourseID) {
		clsCourse Course = clsCourseService::Find(CourseID);

		return (!Course.IsEmpty());
	}

	static bool DeleteCourse(clsCourse& Course) {
		vector <clsCourse> vCourses = clsCourseData::LoadCoursesDataFromFile();

		for (clsCourse& C : vCourses) {
			if (C.CourseID == Course.CourseID) {
				C.MarkForDelete = true;
				break;
			}
		}

		clsCourseData::SaveCoursesDataToFile(vCourses);
		Course = _GetEmptyCourseObject();

		return true;
	}

	static clsCourse GetAddNewCourseObject(int CourseID) {
		return clsCourse(clsCourse::enMode::AddNewMode, CourseID, "", 0, 0, 0);
	}

	static vector <clsCourse> GetCoursesList() {
		return clsCourseData::LoadCoursesDataFromFile();
	}

	static vector<clsCourse> GetCoursesListByTeacherID(int TeacherID) {

		vector<clsCourse> vAll = clsCourseData::LoadCoursesDataFromFile();
		vector<clsCourse> vResult;

		for (clsCourse& C : vAll) {

			if (TeacherID == 0 ||
				C.TeacherID == TeacherID)
			{
				vResult.push_back(C);
			}
		}

		return vResult;
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svIDCourseExists = 2 };

	static enSaveResults Save(clsCourse Course) {
		switch (Course.Mode) {
		case clsCourse::enMode::EmptyMode: {
			return enSaveResults::svFaildEmptyObject;
		}
		case clsCourse::enMode::UpdateMode: {
			_Update(Course);
			return enSaveResults::svSucceeded;
		}
		case clsCourse::enMode::AddNewMode: {
			if (clsCourseService::IsCourseExist(Course.CourseID)) return enSaveResults::svIDCourseExists;
			else {
				_AddNew(Course);
				Course.Mode = clsCourse::enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
		}
	}
};