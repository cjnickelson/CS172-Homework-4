#pragma once
#include<string>

using namespace std;

class Course
{
	string courseName;
	string* students;
	int numberOfStudents;
	int capacity;
public:
	Course(const string& courseName, int capacity);
	~Course();
	string getCourseName() const;
	string* addStudent(const string& name, int& capacity, string* list);
	void dropStudent(const string& name, string*);
	string* getStudents() const;
	int getNumberOfStudents() const;
	void clear(string*);
};

/*
                UML Diagram
________________________________________________
- string coursename
- string* students
- int numberOfStudents
- int capacity
________________________________________________
+ Course(const string& courseName, int capacity)
+ ~Course()
+ string getCourseName() const
+ void addStudent(const string& name)
+ void dropStudent(const string& name)
+ string* getStudents() const
+ int getNumberOfStudents() const
_______________________________________________
*/