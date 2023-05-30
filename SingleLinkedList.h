// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// using namespace std;

// // Node class represents a single node in the linked list
// template <class Node>
// // LinkedList class represents the singly linked list
// class SingleLinkedList {
// private:
//     Node* head;
//     Node* tail;
// public:
//     // Constructor
//     SingleLinkedList() {
//         head = nullptr;
//     }

//     // Insert at the front
//     void insertFront(Node * newNode) {
// 		if (head == NULL)
// 		{
// 			head = newNode;
// 		}
// 		else
// 		{
// 			newNode->nextAdd = head;
// 			head = newNode;
// 		}

// 		size++;
// 	}

//     // Insert at the end
// 	void insertEnd(Node * newNode) {
// 		if (head == NULL)
// 		{
// 			head = newNode;
// 		}
// 		else
// 		{
// 			Node* current = head;
// 			while (current->nextAdd != NULL)
// 			{
// 				current = current->nextAdd;
// 			}

// 			current->nextAdd = newNode;
// 		}

// 		size++;
// 	}
//     // Display the elements in the list
//     void display() {
//         Node* current = head;
//         while (current != nullptr)
//         {
//             current->display();
// 			cout << "" << endl;
// 			current = current->nextAdd;
//         }
//         cout << "List ends" << endl;
//     }

// private:
//     int size;
// };