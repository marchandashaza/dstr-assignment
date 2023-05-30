#include <iostream>
using namespace std;

template <typename T>
class DoubleLinkedList {
public:

    
    struct Node {
        T data;
        University* data;
        string data;
        Node* nextAdd;
        Node* prevAdd;

        Node(const T& value) : data(value), nextAdd(nullptr), prevAdd(nullptr) {}
        Node(University* value) : data(value), nextAdd(nullptr), prevAdd(nullptr) {}
        Node(T* value) : data(*value), nextAdd(nullptr), prevAdd(nullptr) {}
    };

    Node* head;
    Node* tail;

    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void InsertFront(Node* newNode) {
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->nextAdd = head;
            head->prevAdd = newNode;
            head = newNode;
        }

        size++;
    }

    void InsertEnd(Node* newNode) {
        if (head == nullptr) {
            head = tail = newNode;
        } else {
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

    void remove(const string& value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->nextAdd;
            if (head != nullptr) {
                head->prevAdd = nullptr;
            }
            delete temp;
            return;
        }

        Node* current = head;
        while (current->nextAdd != nullptr) {
            if (current->nextAdd->data == value) {
                Node* temp = current->nextAdd;
                current->nextAdd = current->nextAdd->nextAdd;
                if (current->nextAdd != nullptr) {
                    current->nextAdd->prevAdd = current;
                }
                delete temp;
                return;
            }
            current = current->nextAdd;
        }
    }

    void Display() {
        Node* current = head;
        while (current != nullptr) {
            current->display();
            current = current->nextAdd;
        }
        cout << "List ends" << endl;
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
