#ifndef _MYSTATS_H_
#define _MYSTATS_H_

#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

// GLOBAL VARIABLES
const int rowSize = 10;
const int colSize = 10;

template <class T>
class MyStats
{
private:
	T arrStat[rowSize][colSize];
	T temp;
public:
	//CONSTRUCTOR
	MyStats();

	//DESTRUCTOR
	~MyStats();

	// MUTATORS
	void setArrStat(int, int, T);
	void setTemp(T);

	// ACCESSORS
	T getArrStat(int, int) const;
	T getTemp();

	// WILL INITIALIZE THE VALUES OF THE ELEMENTS IN THE ARRAY
	void init();

	// WILL PRINT THE INDIVIDUAL ELEMENTS IN THE ARRAY
	void print();
	void print(ofstream&) const;

	// WILL CALCULATE FOR THE AVERAGE VALUE OF ALL ELEMENTS IN THE ARRAY
	T average();

	// WILL LOOK FOR THE LARGEST VALUE IN THE ARRAY
	T findLargest();

	// WILL LOOK FOR THE SMALLEST VALUE IN THE ARRAY
	T findSmallest();
};

#include "MyStats.cpp"

#endif
//
//template <class T>
//MyStats<T>::MyStats()
//{
//	//constructor
//	init();
//}
//
//template <class T>
//MyStats<T>::~MyStats()
//{
//	//destructor
//}
//
//template <class T>
//void MyStats<T>::setArrStat(int row, int col, T val)
//{
//	//modifies the value orders in the array
//	arrStat[row][col] = val;
//}
//
//template <class T>
//T MyStats<T>::getArrStat(int row, int col) const
//{
//	//returns an array value
//	int result;
//
//	result = arrStat[row][col];
//
//	return result;
//}
//
//template <class T>
//void MyStats<T>::setTemp(T temp)
//{
//	//to be used for the temporary variable
//	//this class modifies the temp value
//	this->temp = temp;
//}
//
//template <class T>
//T MyStats<T>::getTemp()
//{
//	//to be used for the temporary variable
//	//this class returns the temp value
//	return temp;
//}
//
//template <class T>
//void MyStats<T>::init()
//{
//	//This class initializes all the values in the array ranging from -128 to 127
//	srand(time(NULL));
//
//	for (int row = 0; row < rowSize; row++)
//	{
//		for (int col = 0; col < colSize; col++)
//		{
//			setArrStat(row, col, (rand() % (0 + 256)) - 128);
//		}
//	}
//}
//
//template <class T>
//void MyStats<T>::print()
//{
//	//Prints the values in the array
//	for (int row = 0; row < rowSize; row++)
//	{
//		for (int col = 0; col < colSize; col++)
//		{
//			cout << setw(5) << getArrStat(row, col) << " ";
//		}
//		cout << endl;
//	}
//}
//
//template <class T>
//void MyStats<T>::print(ofstream& outFile) const
//{
//	//Prints the values in the array
//	for (int row = 0; row < rowSize; row++)
//	{
//		for (int col = 0; col < colSize; col++)
//		{
//			outFile << setw(5) << getArrStat(row, col) << " ";
//		}
//		outFile << endl;
//	}
//}
//
//template <class T>
//T MyStats<T>::average()
//{
//	//This class gets the average for all the values in the array
//	T result = 0;
//
//	for (int row = 0; row < rowSize; row++)
//	{
//		for (int col = 0; col < colSize; col++)
//		{
//			result += getArrStat(row, col);
//		}
//	}
//
//	return (result / static_cast<T>(rowSize*colSize));
//}
//
//template <class T>
//T MyStats<T>::findLargest()
//{
//	//this class will look for the largest value in the array
//	for (int y = 0; y < rowSize; y++)
//	{
//		for (int x = 0; x < colSize; x++)
//		{
//			if (x < colSize - 1)
//			{
//				if (getArrStat(y, x) > getArrStat(y, x + 1))
//				{
//					setTemp(getArrStat(y, x + 1));
//					setArrStat(y, x + 1, getArrStat(y, x));
//					setArrStat(y, x, getTemp());
//				}
//			}
//			else if (x == colSize - 1)
//			{
//				if (y < rowSize - 1)
//				{
//					if (getArrStat(y, x) > getArrStat(y + 1, 0))
//					{
//						setTemp(getArrStat(y + 1, 0));
//						setArrStat(y + 1, 0, getArrStat(y, x));
//						setArrStat(y, x, getTemp());
//					}
//				}
//			}
//		}
//	}
//	return getArrStat(rowSize - 1, colSize - 1);
//}
//
//template <class T>
//T MyStats<T>::findSmallest()
//{
//	//this class will look for the smallest value in the array
//	for (int y = rowSize - 1; y >= 0; y--)
//	{
//		for (int x = colSize - 1; x >= 0; x--)
//		{
//			if (x > 0)
//			{
//				if (getArrStat(y, x) < getArrStat(y, x - 1))
//				{
//					setTemp(getArrStat(y, x - 1));
//					setArrStat(y, x - 1, getArrStat(y, x));
//					setArrStat(y, x, getTemp());
//				}
//			}
//			else if (x == 0)
//			{
//				if (y > 0)
//				{
//					if (getArrStat(y, x) < getArrStat(y - 1, colSize - 1))
//					{
//						setTemp(getArrStat(y - 1, colSize - 1));
//						setArrStat(y - 1, colSize - 1, getArrStat(y, x));
//						setArrStat(y, x, getTemp());
//					}
//				}
//			}
//		}
//	}
//	return getArrStat(0, 0);
//}