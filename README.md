# 🎓 School Management System (C++)

## 📌 Overview
This is a console-based School Management System built using C++.

The system allows managing:
- Students
- Teachers
- Courses
- Enrollments
- Users (with authentication and permissions)
- Reports and statistics

It also includes a login system with encrypted passwords and a login/register tracking system.

---

## 🏗️ Project Architecture

The project follows a layered architecture:

- **Core Layer (Entities)**
  - Represents system objects (Student, Course, etc.)

- **Data Layer**
  - Handles file storage and conversion

- **Service Layer**
  - Contains business logic and rules

- **UI Layer (Screens)**
  - Handles user interaction

- **Global Layer**
  - Stores shared application state (e.g., CurrentUser)

---

## ⚙️ Features

### 👨‍🎓 Student Management
- Add, update, delete, find students
- View student list

### 📚 Course Management
- Add, update, delete courses
- Track course capacity

### 🧑‍🏫 Teacher Management
- Manage teacher records

### 📝 Enrollment System
- Enroll students in courses
- Drop enrollments
- Assign grades
- Track status (Active / Completed / Dropped)

### 📊 Reports System
- Total number of students, teachers, courses, enrollments
- Most popular course
- Most active student
- Full courses report

### 🔐 Authentication System
- Login / Logout
- Password encryption
- User permissions system (RBAC)
- Access control for screens
- Login attempt limit (max 3 tries)
- Temporary account lock after multiple failed login attempts

### 📜 Login Register
- Stores login history (date, username, encrypted password)

---

## 🧠 Design Concepts Used

- Object-Oriented Programming (OOP)
- Encapsulation
- Separation of concerns (Layered architecture)
- File handling (persistent storage)
- Enum-based state management
- Role-based access control (RBAC)
- Operator overloading (if used in your project)
- Static service classes

---

## 🗂️ Project Structure

```
📁 School Management System (C++)
│
├── 📁 Core
│   ├── clsPerson.h (Base Class)
│   ├── clsStudent.h
│   ├── clsTeacher.h
│   ├── clsCourse.h
│   ├── clsEnrollment.h
│   └── clsUser.h
│
├── 📁 Data
│   ├── clsStudentData.h
│   ├── clsTeacherData.h
│   ├── clsCourseData.h
│   ├── clsEnrollmentData.h
│   └── clsUserData.h
│
├── 📁 Service
│   ├── clsStudentService.h
│   ├── clsTeacherService.h
│   ├── clsCourseService.h
│   ├── clsEnrollmentService.h
│   └── clsUserService.h
│
├── 📁 UI - Screens
│   │
│   ├── 📁 Course
│   │   ├── clsAddNewCourseScreen.h
│   │   ├── clsCourseListByTeacherID.h
│   │   ├── clsCourseMenuScreen.h
│   │   ├── clsCoursesListScreen.h
│   │   ├── clsDeleteCourseScreen.h
│   │   ├── clsFindCourseScreen.h
│   │   └── clsUpdateCourseScreen.h
│   │
│   ├── 📁 Enrollment
│   │   ├── clsAssignGradeScreen.h
│   │   ├── clsCourseStudentsScreen.h
│   │   ├── clsDropEnrollmentScreen.h
│   │   ├── clsEnrollmentMenuScreen.h
│   │   ├── clsEnrollmentListScreen.h
│   │   ├── clsEnrollStudentScreen.h
│   │   ├── clsStudentCoursesScreen.h
│   │   └── clsUpdateEnrollmentScreen.h
│   │
│   ├── 📁 Student
│   │   ├── clsAddNewStudentScreen.h
│   │   ├── clsDeleteStudentScreen.h
│   │   ├── clsFindStudentScreen.h
│   │   ├── clsStudentsListScreen.h
│   │   └── clsUpdateStudentScreen.h
│   │
│   ├── 📁 Teacher
│   │   ├── clsAddNewTeacherScreen.h
│   │   ├── clsDeleteTeacherScreen.h
│   │   ├── clsFindTeacherScreen.h
│   │   ├── clsShowTeacherListBySpeciality.h
│   │   ├── clsTeacherCoursesScreen.h
│   │   ├── clsTeacherMenuScreen.h
│   │   ├── clsTeacherListScreen.h
│   │   └── clsUpdateTeacherScreen.h
│   │
│   ├── 📁 User
│   │   ├── clsAddNewUserScreen.h
│   │   ├── clsDeleteUserScreen.h
│   │   ├── clsFindUserScreen.h
│   │   ├── clsListUsersScreen.h
│   │   ├── clsManageUserScreen.h
│   │   └── clsUpdateUserScreen.h
│   │
│   ├── clsLoginScreen.h
│   ├── clsLoginRegisterScreen.h
│   ├── clsMainScreen.h
│   ├── clsReportScreen.h
│   └── clsScreen.h
│
├── 📁 Global
│   └── Global.h
│
├── 📁 Lib
│   ├── clsDate.h
│   ├── clsInputValidate.h
│   ├── clsString.h
│   └── clsUtil.h
│
└── 📄 main.cpp
```


---

## 🚀 How to Run

1. Open project in Visual Studio (or any C++ compiler)
2. Make sure all `.h` files are included
3. Build the project
4. Run `main.cpp`
5. Login with a valid user

---

## 📸 Screenshots (optional)

- Login Screen
- Main Menu
- Reports Screen
- Enrollment System

*(images will be here later)*

---

## 🔮 Future Improvements

- Add GUI version (Qt / SFML / Web UI)
- Database integration (MySQL / SQLite)
- Export reports to PDF/Excel
- Advanced analytics dashboard
- Multi-language support
- REST API version

---

## 👨‍💻 Author: 
- Madi Abdelheq

- Developed in C++ as a learning and system design project
- Focus: OOP, file handling, and system architecture