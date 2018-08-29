// Assignment 2.cpp : Defines the entry point for the console application.
//



#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
//#include <stack>

using namespace std;



//computes the value of arithmetic
//expression given in postfix format

/************************************************************
* Stack to store operands of postfix expression            *
************************************************************/
class OperandStack
{
private:
	double * s;  //pointer to 1D dynamic array for storing stack elements
	int capacity,  //stack capacity
		t;  //index of the top element on stack
	void growStack(int newCapacity);  //increases the stack if it is full
	//must be called from the push function if the stack is full

public:
	int operation(int a, int b, char opr);
	int calculatePostfix();
	OperandStack(int capacity)
	{
		this->capacity = capacity;
		s = new double[capacity];
	}
	OperandStack()
	{
		t = -1;
	}
	~OperandStack()
	{
		if (capacity == 0)
			return;
		delete[] s;
	}
	int size() const
	{
		return t + 1;
	}//return the number of elements in the stack
	bool isFull() const
	{
		if (t + 1 == capacity)
			return true;
		else
			return false;
	}
	bool isEmpty() const
	{
		if (t == -1)
			return true;
		else
			return false;
	}
	double top() const
	{
		return s[t];
	}
	//returns the element at the top of the stack
	//without removing it from the stack
	void push(double x)
	{
		if (s == NULL)
		{
			s = new double[5];
		}
		else if (isFull())
		{
			growStack(capacity);
		}
		t++;
		s[t] = x;
	}
	void pop()
	{
		if (!isEmpty())
		{
			t--;
		}
		//else
		//cout << "Stack is Empty" << endl;
	}
};

void OperandStack::growStack(int newCapacity)
{
	double *newStack = new double[newCapacity + 5];
	for (int i = 0; i < capacity; i++)
	{
		newStack[i] = s[i];
	}
	delete[] s;
	s = newStack;
	capacity = newCapacity + 5;
}




/**********************************
* End of class. Beginning of main *
**********************************/


double operation(double a, double b, char opr);
string postfixExpr(istream & inputStream);
void solvePostfix(string postfixExp);

int main()
{
	string input;
	do
	{
		cout << "Enter a postfix expression to be calculated: ";

		cin >> input;
		if (input == "1")
		{
			break;
		}
		solvePostfix(input);
	} while (input != "1");//input 1 to break away from loop
	system("PAUSE");
	return 0;
}

//write additional helper functions as needed


/*******************************************
* operation will perform an operation      *
* depending on which operator is sent.     *
* Either +, -, *, or /.                    *
* Inputs: double a and b, both numbers     *
* between 0 and 9 input by the user. char, *
* an operator called opr which carries an  *
* operator input by the user.              *
* Return: result                           *
*                                          *
*******************************************/
double operation(double a, double b, char opr)
{
	switch (opr)
	{
	case '+':return a + b;
	case '-':return b - a;
	case '*':return a*b;
	case '/':return b / a;
	default: return 0;
	}// performs operation and resurns result
}

/*******************************************
* solvePostfix will take a postfix         *
*  expression and solve it for an answer.  *
* Inputs: postfixExp, a string, is the     *
* postfix expression input by the user to  *
*  be solved.                              *
* Return: nothing                          *
*                                          *
*******************************************/
void solvePostfix(string postfixExp)
{
	OperandStack stack;
	int index = 0;
	int num = 0;
	int op = 0;
	while (postfixExp[index] != '\0')
	{
		if (isdigit(postfixExp[index]))
		{
			stack.push(postfixExp[index] - '0');
			num++;
		}
		else
		{
			double x = stack.top();
			stack.pop();
			double y = stack.top();
			stack.pop();
			double result = operation(x, y, postfixExp[index]);//performs operation function
			stack.push(result);//pushes the result of operation into the stack
			op++;
		}
		index++;
	}
	if (num != op + 1)//if the number of operators is anything
	{//other than 1 less than quantity of numbers.
		cout << "Result: error - malformed expression" << endl << endl << endl;
		return; //will use continue when running a total of 5 times with do while loop.
		       // or return and do while loop is in main to run as much as user wants.
	}
	cout << "Result: " << stack.top() << endl << endl << endl;
	stack.pop();
}
//computes the value of arithmetic
//expression given in postfix format
