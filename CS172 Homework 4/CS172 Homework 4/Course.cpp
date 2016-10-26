#include"Course.h"

using namespace std;

// constructor initializes the number of students to start a class to 0, names the course based on input and sets the capacity equal to a given value
Course::Course(const string& courseName, int capacity)
{
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}

// destructor deletes the array
Course::~Course()
{
	delete[] students;
}

// returns the course name 
string Course::getCourseName() const
{
	return courseName;
}

// adds a student to the class
string* Course::addStudent(const string& name, int& capacity, string* list)
{
	// if there is room left within the array, fill the next empty spot with the input name and return this new list
	if (numberOfStudents < capacity)
	{
		list[numberOfStudents] = name;
		// increment the number of students, as one has been added
		numberOfStudents++;
		return list;
	}
	// if there is no room left in the course, create room by making a new array and copying the old one into it
	else
	{
		// increase the capacity of the class
		capacity++;
		// dynamically allocate the new array with the new capacity
		string* temp = new string[capacity];
		// copy the old array into it
		for (int i = 0; i < numberOfStudents; i++)
		{
			temp[i]=list[i];
		}
		// give the empty slot the next name
		temp[numberOfStudents] = name;
		// delete the old array
		delete[]list;
		// increment the number of students, as one has added the class
		numberOfStudents++;
		// return the new array
		return temp;
	}
}

void Course::dropStudent(const string& name, string* list)
{
	// find a name that matches that which is being dropped
	for (int i = 0; i < numberOfStudents; i++)
	{
		// check for equality
		if (list[i] == name)
		{
			// if the student is being dropped, write over his name with the name from the right, and continue this down the line until there are no more names
			for (int j = i; j < numberOfStudents - 1; j++)
			{
				list[j] = list[j + 1];
			}
			// overwrite the last slot to be empty, as the last name will show up twice
			list[numberOfStudents-1] = "";
		}
	}
	// decrement the number of students, as one has left
	numberOfStudents--;
}

// returns the array of students in the class
string* Course::getStudents() const
{
	return students;
}

// returns the number of students enrolled
int Course::getNumberOfStudents() const
{
	return numberOfStudents;
}

// rewrites all values in the arary to be 0  (this function causes a problem when the addStudent function has to add extra spots to the array and I'm not sure why)
void Course:: clear(string* list)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		list[i] = "";
	}
}