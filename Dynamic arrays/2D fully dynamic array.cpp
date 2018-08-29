// 2D fully dynamic array (non jagged) - where 
// number of rows and columns are dynamic
// Another option: Same thing could be done
// more elegantly with a vector inside a vector

#include <iostream>
using namespace std;

int main()
{
	//create a 2d array
	int rowCount, colCount;

	int ** b;  // b is a pointer to a dynamic array, 
				// where each cell points to another dynamic array (particular row)

	//ask the user for number of rows and columns
	cout << "Enter the number of rows and columns: " << endl;
	cin >> rowCount >> colCount;
	
	b = new int*[rowCount];	// create an array of pointers to point to rowCount number of rows
							//serves as a place holder for rowCount number of rows

	for ( int i = 0;  i < rowCount;  ++i )  
	   { 
			b[i] = new int[colCount];  // assign a row of width colCount to each pointer
			for ( int j = 0;  j < colCount;  ++j )  
				b[i][j] = 0; 
	}

	//you may write more code here that does something with your array, like printing, etc.

	//cleanup
	for ( int i = 0;  i < rowCount;  ++i )  
	{
		delete [] b[i];	//delete each row
		b[i] = NULL;
	}

	delete [] b; //don't forget to delete the array of pointers
	b = NULL;

	return	0;
}