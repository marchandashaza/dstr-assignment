template <typename T>
void quickSort(DoubleLinkedList<T>& dll);

template <typename T>
typename DoubleLinkedList<T>::Node* partition(DoubleLinkedList<T>& dll);

template <typename T>
typename DoubleLinkedList<T>::Node* quickSortRecur(typename DoubleLinkedList<T>::Node* head, typename DoubleLinkedList<T>::Node* end);

template <typename T>
void readDLLQuickSort(DoubleLinkedList<T>& dll);

template <typename T>
void quickSort(DoubleLinkedList<T>& dll)
{
    partition(dll);
}

template <typename T>
typename DoubleLinkedList<T>::Node* partition(DoubleLinkedList<T>& dll)
{
    typename DoubleLinkedList<T>::Node* newHead = nullptr;
    typename DoubleLinkedList<T>::Node* newEnd = nullptr;
    typename DoubleLinkedList<T>::Node* pivot = dll.tail;
    typename DoubleLinkedList<T>::Node* prev = nullptr;
    typename DoubleLinkedList<T>::Node* cur = dll.head;
    typename DoubleLinkedList<T>::Node* tail = pivot;
    typename DoubleLinkedList<T>::Node* head = dll.head;
    tail = dll.tail; // Remove duplicate declaration

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (newHead == nullptr) {
                newHead = cur;
            }
            prev = cur;
            cur = cur->nextAdd;
        }
        else {
            if (prev) {
                prev->nextAdd = cur->nextAdd;
            }
            typename DoubleLinkedList<T>::Node* tmp = cur->nextAdd;
            cur->nextAdd = nullptr;
            tail->nextAdd = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (newHead == nullptr) {
        newHead = pivot;
    }

    newEnd = tail;
    head = quickSortRecur(head, tail);
    pivot->nextAdd = quickSortRecur(pivot->nextAdd, newEnd);

    dll.head = head;
    dll.tail = tail;

    return pivot;
}

template <typename T>
typename DoubleLinkedList<T>::Node* quickSortRecur(typename DoubleLinkedList<T>::Node* head, typename DoubleLinkedList<T>::Node* end)
{
    if (!head || head == end)
        return head;

    typename DoubleLinkedList<T>::Node* newHead = nullptr;
    typename DoubleLinkedList<T>::Node* newEnd = nullptr;
    typename DoubleLinkedList<T>::Node* pivot = partition(head, end, newHead, newEnd);

    if (newHead != pivot) {
        typename DoubleLinkedList<T>::Node* tmp = newHead;
        while (tmp->nextAdd != pivot)
            tmp = tmp->nextAdd;
        tmp->nextAdd = nullptr;

        newHead = quickSortRecur(newHead, tmp);

        tmp = dll.getTail(newHead); // Assuming dll is an instance of DoubleLinkedList<T> in readDLLQuickSort function
        tmp->nextAdd = pivot;
    }

    pivot->nextAdd = quickSortRecur(pivot->nextAdd, newEnd);

    return newHead;
}

template <typename T>
void readDLLQuickSort(DoubleLinkedList<T>& dll)
{
    quickSort(dll);

    cout << "\nSorted list is:" << endl;
    dll.Display();
}

void quickSortFromDLLUserData()
{
    DoubleLinkedList<string> dll; // Replace 'string' with the appropriate type for your DLL
    quickSort(dll);

    cout << "\nSorted list is:" << endl;
    dll.Display();
    readDLLQuickSort(dll);
}

