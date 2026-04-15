#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsStudentData.h"
#include "clsTeacherData.h"
#include "clsCourseData.h"
#include "clsEnrollmentData.h"
#include "clsEnrollmentService.h"
#include "clsStudentService.h"

using namespace std;

class clsReportScreen : protected clsScreen
{
private:
	static int _StudentsNumber() {
		return clsStudentData::LoadStudentsDataFromFile().size();
	}

	static int _TeachersNumber() {
		return clsTeacherData::LoadTeachersDataFromFile().size();
	}

	static int _CoursesNumber() {
		return clsCourseData::LoadCoursesDataFromFile().size();
	}

	static int _EnrollmentsNumber() {
		return clsEnrollmentData::LoadEnrollmentsDataFromFile().size();
	}

public:
	static void ShowReportScreen() {
		_DrawScreenHeader("\t\t  System Report Screen");

		cout << "\n\n-------------- System Report --------------";
		cout << "\nStudents       : " << _StudentsNumber();
		cout << "\nTeachers       : " << _TeachersNumber();
		cout << "\nCourses        : " << _CoursesNumber();
		cout << "\nEnrollments    : " << _EnrollmentsNumber();

		cout << "\n\n--------------- Enrollment ----------------";
		cout << "\nActive         : " << clsEnrollmentService::NumberOfActiveEnrollments();
		cout << "\nCompleted      : " << clsEnrollmentService::NumberOfCompletedEnrollments();
		cout << "\nDropped        : " << clsEnrollmentService::NumberOfDroppedEnrollments();

		cout << "\n\n----------------- Courses -----------------";
		cout << "\nMost popular   : " << clsEnrollmentService::GetMostPopularCourseWithCount().first.CourseName << " ( " <<
			clsEnrollmentService::GetMostPopularCourseWithCount().second << " students)";
		cout << "\nFull Courses   : " << clsEnrollmentService::GetNumberOfFullCourses();

		cout << "\n\n----------------- Students ----------------";
		cout << "\nMost Active    : " << clsStudentService::GetMostActiveStudentWithCount().first.FullName() << " (" << 
			clsStudentService::GetMostActiveStudentWithCount().second << " course(s)";
	}
};