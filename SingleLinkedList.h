#include <iostream>

// Node class represents a single node in the linked list
template <class Node>
// LinkedList class represents the singly linked list
class SingleLinkedList {
private:
    Node* head;

public:
    // Constructor
    SingleLinkedList() {
        head = nullptr;
    }

    // Insert a new node at the beginning of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        std::cout << "Inserted element: " << value << std::endl;
    }

    // Display the elements in the list
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* currNode = head;
        std::cout << "List elements: ";
        while (currNode != nullptr) {
            std::cout << currNode->data << " ";
            currNode = currNode->next;
        }
        std::cout << std::endl;
    }
};