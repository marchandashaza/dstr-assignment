#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertNode(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*head);
    (*head) = newNode;
}

// Function to perform interpolation search on a linked list
Node* interpolationSearch(Node* head, int target) {
    Node* start = head;
    Node* end = NULL;

    while (start != end && target >= start->data && target <= end->data) {
        // Estimate the position of the target value
        double position = start->data + ((double)(target - start->data) / (end->data - start->data)) * (end - start);

        // Convert position to an integer index
        int index = static_cast<int>(position);

        // Traverse to the estimated position
        Node* current = start;
        for (int i = 0; i < index; i++) {
            if (current == NULL)
                break;
            current = current->next;
        }

        if (current == NULL)
            return NULL;

        if (current->data == target)
            return current;

        if (current->data < target)
            start = current->next;
        else
            end = current->next;
    }

    return NULL; // Return NULL if target is not found
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Insert elements into the linked list
    insertNode(&head, 2);
    insertNode(&head, 5);
    insertNode(&head, 8);
    insertNode(&head, 12);
    insertNode(&head, 16);
    insertNode(&head, 18);

    cout << "Linked List: ";
    printList(head);

    int target = 12;
    Node* result = interpolationSearch(head, target);

    if (result != NULL)
        cout << "Element " << target << " found in the linked list." << endl;
    else
        cout << "Element " << target << " not found in the linked list." << endl;

    return 0;
}