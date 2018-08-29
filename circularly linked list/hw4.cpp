//Code to get you started on Homework 4
#include <iostream>
using namespace std;

class NodeType
{
public:
	int info;
	NodeType * next; //points to the next node in the list
	NodeType(int value = 0,
				NodeType *ptr = NULL) 	//default constructor
	{
		info = value;
		next = ptr;
	}
};

class CLinkedList
{
	NodeType *cursor;

public:
	CLinkedList() { cursor = NULL; } //default constructor: creates an empty list
	~CLinkedList(); //destructor: delete all nodes in a list
	void printList();
	void insert(int value); //insert a node with info field set to value
	void deleteInRange(int min, int max);
	void split(CLinkedList & list);
};

void CLinkedList::printList()
{
	if(cursor == NULL) 
	{
		cout << "List is empty." << endl;
		return;
	}

	NodeType *ptr = cursor;
	cout << "List: ";
	
	while(ptr->next != cursor)
	{
		cout << ptr->info << ' ';
		ptr = ptr->next;
	}
	cout << ptr->info << endl;
	ptr = NULL;
}

int main()
{
	CLinkedList first; //creates an empty list with cursor set to NULL

	//adding nodes to the list
	//first.insert(10);
	//first.insert(20);
	//first.insert(30);
	first.printList();
	
	/* code for testing split
		CLinkedList second; //create a second list as empty
		first.split(second); // split the first into two lists: first and second
		first.printList();
		second.printList();
	/*

	return 0;
}