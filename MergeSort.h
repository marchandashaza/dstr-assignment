void searchDLLMergeSort(DoubleLinkedList<string>& dll)
{
    // Ask for the value to search
    string valueToSearch;
    cout << "Enter the value to search: ";
    getline(cin, valueToSearch);

    DoubleLinkedList<string>::Node* current = dll.begin();  // Use fully qualified type
    bool found = false;

    while (current != nullptr) {
        if (current->data == valueToSearch) {
            found = true;
            break;
        }
        current = dll.next(current);
    }

    if (found) {
        cout << "Value found in the DLL." << endl;
    } else {
        cout << "Value not found in the DLL." << endl;
    }
};