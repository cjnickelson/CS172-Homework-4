#include<iostream>
#include"Rectangle2D.h"
#include"Course.h"

using namespace std;

void determineSize(int&);
int* allocatearray(int);
void fillarray(int*, int);
void fillarray(int*, int, int[]);
double calculateAverage(int*,int);
void displayList(int*, int);
int countAboveAverage(int*, int, int);
// for exercise 2
int* doubleCapacity(const int*, int&);
// for exercise 3
int findSmallestElement(int*, int);



int main()
{
	int nums;
	// set the size of the array with the determineSize function
	determineSize(nums);
	// allocate an array of that size
	int* list = allocatearray(nums);
	// fill the array with values input by the user
	fillarray(list, nums);
	// display that array to the screen
	displayList(list, nums);
	cout << endl;
	// calculate the average of the array and display it
	double average = calculateAverage(list, nums);
	cout << "Average is " << average << "." << endl;
	// count the numbers in the array which exceed that average, and display that amount
	int count = countAboveAverage(list, nums, average);
	cout << "There are " << count << " numbers above the average." << endl;

	// double the size of the list using the function
	list = doubleCapacity(list, nums);
	// display that new array to the screen
	displayList(list, nums);
	cout << endl;
	// delete array, as it is no longer used
	delete list;
	// make a new list of size 8 for the test program
	int* secondlist = allocatearray(8);
	int values[8] = {1,2,4,5,10,100,2,-22};
	// fill the array using the overloaded fillarray function and the array of values shown above
	fillarray(secondlist, 8, values);
	// find and display the smallest value in the list with the function
	int smallest = findSmallestElement(secondlist, 8);
	cout << "The smallest value out of 1, 2, 4, 5, 10, 100, 2 and -22 is " << smallest << "." << endl;

	// create the three rectangles specified for the test program in exercise 4
	Rectangle2D r1(2,2,5.5,4.9), r2(4,5,10.5,3.2),r3(3,5,2.3,5.4);
	// display the area and pperimeter using the functions
	cout << "The area of r1 is " << r1.getArea() << " and its perimter is " << r1.getPerimeter() << "." << endl;
	// determine whether r1 contains a point, contains r2, or overlaps r3 with each respective function, displaying the results
	bool containspoint = r1.contains(3,3);
	cout << "r1 " << (containspoint == true ? "contains " : "does not contain ") << "the point (3,3)." << endl;
	bool containsrectangle = r1.contains(r2);
	cout << "r1 " << (containsrectangle == true ? "contains " : "does not contain ") << "the rectangle r2." << endl;
	bool overlapsrectangle = r1.overlaps(r3);
	cout << "r1 " << (overlapsrectangle == true ? "overlaps " : "does not overlap ") << "the rectangle r3." << endl;

	// get a maximum course capacity from the user
	cout << "What is the maximum number of people who can take this class?" << endl;
	int capacity;
	cin >> capacity;
	// create a Course class called biology with capacity specified by user
	Course biology("biology", capacity);
	// add each of 3 students to the roster
	string* roster = biology.addStudent("Haley",capacity, biology.getStudents());
	roster = biology.addStudent("Bill", capacity, roster);
	roster = biology.addStudent("Carl", capacity, roster);
	// drop bill from the roster
	biology.dropStudent("Bill", roster);
	// display the roster
	for (int i = 0; i < biology.getNumberOfStudents(); i++)
	{
		cout << roster[i]<<" ";
	}
	// clear the roster (causes some issues, as shown in Course.cpp
	biology.clear(roster);
	return 0;
}

// sets user input to capacity
void determineSize(int& value)
{
	cout << "How many values in the list?" << endl;
	cin >> value;
}

// dynamically allocates and returns an array and sets each value to null
int* allocatearray(int size)
{
	int* pntrarray = new int[size];
	for (int i = 0; i < size; i++)
	{
		pntrarray[i] = NULL;
	}
	return pntrarray;
}

// fills the array with each value selected by the user
void fillarray(int* pntrarray, int size)
{
	int i = 0;
	for (int* curr = pntrarray; curr < pntrarray + size; curr++)
	{
		i++;
		cout << "Enter value #" << i << "." << endl;
		cin >> *curr;
	}
}

// overloaded function, this version fills the array with values from another array already in existance
void fillarray(int* pntrarray, int size, int numbers[])
{
	int i = 0;
	for (int* curr = pntrarray; curr<pntrarray+size; curr ++)
	{
		*curr = numbers[i];
		i++;
	}
}

// calculates and returns the average value of the members of the array
double calculateAverage(int* pntrarray, int size)
{
	double sum = 0;
	// for each value, adds that number to the sum
	for (int i = 0; i < size; i++)
	{
		sum += *(pntrarray+i);
	}
	// divides the sum by the number of elements to determine the average
	return sum / size;
}

// counts the number of elements above the average
int countAboveAverage(int* pntrarray, int size, int average)
{
	int count = 0;
	// for each member, if it is larger than the average, increment the count
	for (int i = 0; i < size; i++)
	{
		count += (*(pntrarray+i) > average ? 1 : 0);
	}
	return count;
}

// creates a new array twice the size of the old one, copying the old values into the new
int* doubleCapacity(const int* list, int& size)
{
	// create a new array of size 2*size
	int* newList = new int[2 * size];
	// copy the values or the original array into the new one
	for (int i = 0; i < size; i++)
	{
		*(newList + i) = *(list + i);
	}
	// set the empty values to null
	for (int i = size; i < 2 * size; i++)
	{
		newList[i] = NULL;
	}
	// double the size variable
	size *= 2;
	// get rid of the old list
	delete [] list;
	return newList;
}

// displays a given array
void displayList(int* list, int nums)
{
	// for each element, if it is not null, is displays to screen
	for (int i = 0; i < nums; i++)
	{
		// if it is null, it displays empty
		if (list[i] == NULL)
			cout << "empty";
		else
			cout << *(list + i) << " ";
	}
}

// identifies and returns the smallest element of an array
int findSmallestElement(int* pntrarray, int size)
{
	// set the first elements equal to the "smallest" variable
	int smallest = *pntrarray;
	// for each ensuing element, determine if it is smaller than "smallest"
	for (int i = 1; i < size; i++)
	{
		// if it is, overwrite smallest to be the new value
		if (*(pntrarray + i) < smallest)
			smallest = *(pntrarray + i);
	}
	// return the smallest element
	return smallest;
}