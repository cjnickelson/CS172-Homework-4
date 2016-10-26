#include"Course.h"

using namespace std;


Course::Course(const string& courseName, int capacity)
{
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}

Course::~Course()
{
	delete[] students;
}

string Course::getCourseName() const
{
	return courseName;
}

string* Course::addStudent(const string& name, int& capacity, string* list)
{
	if (numberOfStudents < capacity)
	{
		list[numberOfStudents] = name;
		numberOfStudents++;
		return list;
	}
	else
	{
		capacity++;
		string* temp = new string[capacity];
		for (int i = 0; i < numberOfStudents; i++)
		{
			temp[i]=list[i];
		}
		temp[numberOfStudents] = name;
		delete[]list;
		numberOfStudents++;
		return temp;
	}
}

void Course::dropStudent(const string& name, string* list)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		if (list[i] == name)
		{
			for (int j = i; j < numberOfStudents - 1; j++)
			{
				list[j] = list[j + 1];
			}
			list[numberOfStudents-1] = "";
		}
	}
	numberOfStudents--;
}

string* Course::getStudents() const
{
	return students;
}

int Course::getNumberOfStudents() const
{
	return numberOfStudents;
}

void Course:: clear(string* list)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		list[i] = "";
	}
}