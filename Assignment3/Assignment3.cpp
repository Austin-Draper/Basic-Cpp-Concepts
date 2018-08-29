//start up code for Assignment 3
#include <iostream>
using namespace std;

/************************************************************
 * PriorityQueue class to store the task list               *
 ************************************************************/
class PriorityQueue
{
private:
	/************************************************************
	 * Task node class                                          *
	 ************************************************************/
	class NodeType
	{
	public:
		string task;	//name of the task
		int priority;		// priority of the task
		NodeType * next;  //points to the next task on the queue
			 
		NodeType(string task = "", int priority = -1,
					NodeType * next = NULL)  //default constructor
		{
			this->task = task;  this->priority = priority;
			this->next = next;
		}
	};

 public:
	PriorityQueue() 
	{  //default constructor: creates an empty queue
		head = NULL; taskCount = 0; } 
	~PriorityQueue();  //destructor: delete all tasks from the queue

	bool isEmpty() const;  //checks for the queue being empty

	int size() const;  //returns the number of tasks in the queue
	
	void insert(string taskName, int priority); 
				//creates a task and inserts it in order of priority
	
	void min() const; //prints the task and its priority (the one with the 
					//highest priority)
					
	void removeMin();  //removes the highest priority task 
						//from the queue

private:
	NodeType *head;  //head pointer to the list
	int taskCount;  //count of the number of tasks on the list
	
	void goNext(NodeType * & curr) const; //moves the pointer to point to
											//the next task
};

int main()
{
	return 0;
}

//write additional helper functions as needed

