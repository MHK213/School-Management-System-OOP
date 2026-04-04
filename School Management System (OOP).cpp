#include <iostream>
#include "clsStudent.h"
#include "clsStudentService.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

void ReadStudentInfo(clsStudent& Student) {
	cout << "\nEnter FirstName: ";
	Student.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter LastName: ";
	Student.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Age: ";
	Student.Age = clsInputValidate::ReadIntNumber();

	cout << "\nEnter Email; ";
	Student.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Student.Phone = clsInputValidate::ReadString();

	cout << "\nEnter Gender (1: Male / 2: Female): ";
	Student.Gender = clsStudent::enGender(clsInputValidate::ReadShortNumber());

	cout << "\nEnter Level: ";
	Student.Level = clsInputValidate::ReadString();

	cout << "\nEnter Status (1: Active / 2: Inactive / 3: Graduated): ";
	Student.Status = clsStudent::enStatus(clsInputValidate::ReadShortNumber());
}

void PrintStudentRecordLine(clsStudent Student) {

	cout << "| " << left << setw(5) << Student.ID;
	cout << "| " << left << setw(20) << Student.FullName();
	cout << "| " << left << setw(5) << Student.Age;
	cout << "| " << left << setw(25) << Student.Email;
	cout << "| " << left << setw(12) << Student.Phone;
	cout << "| " << left << setw(12) << Student.stGender();
	cout << "| " << left << setw(8) << Student.Level;
	cout << "| " << left << setw(12) << Student.stStatus();
}

void UpdateStudent() {
	int IDStudent = clsInputValidate::ReadIntNumber("Please Enter Student ID : ");

	while (!clsStudentService::IsStudentExist(IDStudent)) {
		IDStudent = clsInputValidate::ReadIntNumber("\nStudent ID Not Found, Enter another one: ");
	}

	clsStudent Student = clsStudentService::Find(IDStudent);
	Student.Print();

	cout << "\n\nUpdate Student Info:";
	cout << "\n______________________";

	ReadStudentInfo(Student);

	clsStudentService::enSaveResults SaveResult;
	SaveResult = clsStudentService::Save(Student);

	switch (SaveResult) {
	case clsStudentService::enSaveResults::svSucceeded: {
		cout << "\nAccount Updated Successfuly\n";
		Student.Print();
		break;
	}
	case clsStudentService::enSaveResults::svFaildEmptyObject: {
		cout << "\nError account was not saved because it's Empty";
		break;
	}
	}
}

void AddNewStudent() {
	int IDStudent = clsInputValidate::ReadIntNumber("Please Enter Student ID : ");

	while (clsStudentService::IsStudentExist(IDStudent)) {
		IDStudent = clsInputValidate::ReadIntNumber("\nStudent ID already exist. Enter another one: ");
	}

	clsStudent NewStudent = clsStudentService::GetAddNewStudentObject(IDStudent);

	ReadStudentInfo(NewStudent);

	clsStudentService::enSaveResults SaveResult;
	SaveResult = clsStudentService::Save(NewStudent);

	switch (SaveResult) {
	case clsStudentService::enSaveResults::svSucceeded: {
		cout << "\nAccount Added Successfuly\n";
		NewStudent.Print();
		break;
	}
	case clsStudentService::enSaveResults::svFaildEmptyObject: {
		cout << "\nError account was not saved because it's Empty";
		break;
	}
	case clsStudentService::enSaveResults::svIDStudentExists: {
		cout << "\nError account was not saved because IDStudent aleardy used";
		break;
	}
	}
}

void DeleteClient() {
	int IDStudent = clsInputValidate::ReadIntNumber("Please Enter Student ID : ");

	while (!clsStudentService::IsStudentExist(IDStudent)) {
		IDStudent = clsInputValidate::ReadIntNumber("\nStudent ID Not Found, Enter another one: ");
	}

	clsStudent Student = clsStudentService::Find(IDStudent);
	Student.Print();

	char Answer = 'n';

	cout << "Are you Sure you want to delete this student (y/n) ? ";
	cin >> Answer;

	if (tolower(Answer) == 'y') {
		if (clsStudentService::DeleteStudent(Student)) cout << "\nStudent deleted successfully";
		else cout << "\nStudent was not deleted";
	}
}

void ShowStudentsList(){
	vector <clsStudent> vStudents = clsStudentService::GetStudentsList();

	cout << "\n\t\t\t\t\tStudents List (" + to_string(vStudents.size()) + ") Student(s).";

	cout << "\n_______________________________________________________";
	cout << "______________________________________________________\n" << endl;
	cout << "| " << left << setw(5) << "ID";
	cout << "| " << left << setw(20) << "Student Name";
	cout << "| " << left << setw(5) << "Age";
	cout << "| " << left << setw(25) << "Email";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Gender";
	cout << "| " << left << setw(8) << "Level";
	cout << "| " << left << setw(12) << "Status";
	cout << "\n_______________________________________________________";
	cout << "______________________________________________________\n" << endl;

	if (vStudents.size() == 0) {
		cout << "\t\t\t\tNo Students Available In the System!";
	}
	else {
		for (clsStudent& Student : vStudents) {
			PrintStudentRecordLine(Student);
			cout << endl;
		}
	}

	cout << "\n_______________________________________________________";
	cout << "______________________________________________________\n" << endl;
}

int main()
{
	ShowStudentsList();

	return 0;
}