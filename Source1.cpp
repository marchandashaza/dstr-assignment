#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//step 1: identify how your node structure look like?
struct UniversityNode
{
	uniInfo = 
	int uniRank;
	string uniInstitution;
	string uniLocation;
	double arScore;
	double erScore;
	string erRank;
	double fsrScore;
	int fsrRank;
	double cpfScore;
	int cpfRank
	double ifrScore;
	string ifrRank;
	double isrScore;
	int isrRank;
	double irnScore;
	int irnRank;
	double gerScore;
	int gerRank;
	double scoreScaled;

	EmployeeNode* NextAdd; //pointer-> store for next item address
} *head;

//step 2: learn how to build a single node
UniversityNode* createNewNode(string EmpID, string EmpName, double EmpSal)
{
	//create a empty new node first
	EmployeeNode* newnode = new EmployeeNode;
	newnode->EmpID = EmpID;
	newnode->EmpName = EmpName;
	newnode->EmpSal = EmpSal;
	newnode->NextAdd = NULL;

	return newnode; //newnode address
}

//step 3: insert the created new node to the linked list (choose algorithm - insert to the end of list)
//(queue concept)
void InsertToTheEndOfList(string EmpID, string EmpName, double EmpSal)
{
	//3.1. call the create function to build a new single node first
	EmployeeNode* newnode = createNewNode(EmpID, EmpName, EmpSal);

	//3.2. attach your node to the end of the list
	if (head == NULL) //list is the empty, always the newnode will be first node in list
	{
		head = newnode;
	}
	else //if not empty list, just bring to the end of the list.
	{
		EmployeeNode* current = head; // to help us find the last item in the list

		while (current->NextAdd != NULL) //if not yet last node, move to next point again
		{
			current = current->NextAdd; //Big O - O(n)
		}

		//if found the last node, attach the new node after the last node
		current->NextAdd = newnode;
	}
}

//step 4: how to display values from the nodes in the linked list
void displayEmployeeInformation() //Big O - O(n)
{
	EmployeeNode* current = head;

	while (current != NULL) //means still not the end of the list
	{
		cout << "Employee ID: " << current->EmpID << endl;
		cout << "Employee Name: " << current->EmpName << endl;
		cout << "Employee Salary: " << current->EmpSal << endl << endl;
		current = current->NextAdd; //if you forgot this, will become a infinity loop
	}
	cout << "List is ended here! " << endl;
}

//step 5: insert the created new node to the front of the linked list (stack concept)
void InsertToTheFrontOfList(string EmpID, string EmpName, double EmpSal)
{
	EmployeeNode* newnode = createNewNode(EmpID, EmpName, EmpSal);

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->NextAdd = head; //big o notation = O(1)
		head = newnode;
	}
}
//edit