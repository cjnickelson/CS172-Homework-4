#include<iostream>

using namespace std;

void determineSize(int&);
int* allocatearray(int);
void fillarray(int*, int);
double calculateAverage(int*,int);
int countAboveAverage(int*, int, int);

int main()
{
	int nums;
	determineSize(nums);
	int* list = allocatearray(nums);
	fillarray(list, nums);
	for (int i = 0; i < nums; i++)
	{
		cout << *(list + i) << " ";
	}
	cout << endl;
	double average = calculateAverage(list, nums);
	cout << "Average is " << average << "." << endl;
	int count = countAboveAverage(list, nums, average);
	cout << "There are " << count << " numbers above the average." << endl;
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