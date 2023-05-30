#include <iostream>
using namespace std;

template <class Node>
class DoubleLinkedList {
public:
    Node* head;
    Node* tail;
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void InsertFront(Node* newNode) { 
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->nextAdd = head;
			head->prevAdd = newNode;
			head = newNode;
		}

		size++;
	}

	void InsertEnd(Node* newNode) {
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			tail->nextAdd = newNode;
			newNode->prevAdd = tail;
			tail = newNode;
		}

		size++;
	}

    void pushBack(Node* newNode) {
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->nextAdd = newNode;
            newNode->prevAdd = tail;
            tail = newNode;
        }
    }
    
    void remove(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                if (current->next != nullptr) {
                    current->next->prev = current;
                }
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void Display() {
        Node* current = head;
        while (current != nullptr) 
        {
            current->display();
			current = current->nextAdd;
        }
        std::cout << "List ends" << std::endl;
    }

    Node* begin() const {
        return head;
    }

    Node* end() const {
        return nullptr;
    }

    Node* next(Node* node) const {
        return node->nextAdd;
    }

    Node* toNodePtr(Node& node) {
        return &node;
    }

private:
    int size;

};