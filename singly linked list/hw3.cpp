//Code to get you started on Homework 3
//Below code is a modified version of an example on 
//pages 1039-1043, Chapter 17 of your Early objects book, 8th Ed.
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

class SinglyLinkedList
{
	NodeType *head;

public:
	SinglyLinkedList() { head = NULL; } //default constructor: creates an empty list
	~SinglyLinkedList(); //destructor: delete all nodes in a list
	void addAtFront(int value); //creates a node with info field set to value
						//adds this newly created node to the front of the list
	void printList();
	void absorb(SinglyLinkedList & list);	
	void insert(int value, int position);
	void remove(int position);
	void reverse();
	bool search(int searchInfo);
};

SinglyLinkedList::~SinglyLinkedList()
{
	NodeType * ptr = head;
	while (ptr != NULL)
	{
		NodeType * nodeToDelete = ptr;
		ptr = ptr->next;
		delete nodeToDelete;
	}
}

void SinglyLinkedList::addAtFront(int value)
{
	NodeType *ptr = new NodeType(value);
	ptr->next = head;
	head = ptr;
	ptr = NULL; //not needed but safe approach
}

int main()
{
	SinglyLinkedList first; //creates an empty list with head set to NULL

	//adding nodes to the list
	first.addAtFront(15);
	first.addAtFront(20);
	first.addAtFront(5);

	return 0;
}