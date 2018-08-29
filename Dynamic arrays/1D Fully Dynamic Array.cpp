// Practice to be deleted.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int * Arr1D;
	int W;
	cout << "Tell me the width:  ";
	cin >> W;
	Arr1D = new int[W];

	for (int j = 0; j < W; j++)
	{
		Arr1D[j] = j + 1;
	}
	cout << endl << endl;
	cout << "The 1D array:" << endl << endl;     
	for (int j = 0; j < W; j++)
	{
		cout << Arr1D[j] << "\t";
	}
	cout << endl << endl;
	delete[] Arr1D;

	system("PAUSE");
	return 0;
}