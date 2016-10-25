#include<iostream>
#include"Rectangle2D.h"

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
	determineSize(nums);
	int* list = allocatearray(nums);
	fillarray(list, nums);
	displayList(list, nums);
	cout << endl;
	double average = calculateAverage(list, nums);
	cout << "Average is " << average << "." << endl;
	int count = countAboveAverage(list, nums, average);
	cout << "There are " << count << " numbers above the average." << endl;

	list = doubleCapacity(list, nums);
	displayList(list, nums);
	cout << endl;
	delete list;
	int* secondlist = allocatearray(8);
	int values[8] = {1,2,4,5,10,100,2,-22};
	fillarray(secondlist, 8, values);
	int smallest = findSmallestElement(secondlist, 8);
	cout << "The smallest value out of 1, 2, 4, 5, 10, 100, 2 and -22 is " << smallest << "." << endl;
	return 0;
}

void determineSize(int& value)
{
	cout << "How many values in the list?" << endl;
	cin >> value;
}

int* allocatearray(int size)
{
	int* pntrarray = new int[size];
	for (int i = 0; i < size; i++)
	{
		pntrarray[i] = NULL;
	}
	return pntrarray;
}

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

void fillarray(int* pntrarray, int size, int numbers[])
{
	int i = 0;
	for (int* curr = pntrarray; curr<pntrarray+size; curr ++)
	{
		*curr = numbers[i];
		i++;
	}
}

double calculateAverage(int* pntrarray, int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += *(pntrarray+i);
	}
	return sum / size;
}

int countAboveAverage(int* pntrarray, int size, int average)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		count += (*(pntrarray+i) > average ? 1 : 0);
	}
	return count;
}

int* doubleCapacity(const int* list, int& size)
{
	int* newList = new int[2 * size];
	for (int i = 0; i < size; i++)
	{
		*(newList + i) = *(list + i);
	}
	for (int i = size; i < 2 * size; i++)
	{
		newList[i] = NULL;
	}
	size *= 2;
	delete list;
	return newList;
}

void displayList(int* list, int nums)
{
	for (int i = 0; i < nums; i++)
	{
		if (list[i] == NULL)
			cout << "Invalid ";
		else
			cout << *(list + i) << " ";
	}
}

int findSmallestElement(int* pntrarray, int size)
{
	int smallest = *pntrarray;
	for (int i = 1; i < size; i++)
	{
		if (*(pntrarray + i) < smallest)
			smallest = *(pntrarray + i);
	}
	return smallest;
}