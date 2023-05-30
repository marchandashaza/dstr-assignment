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
}

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSortascending(string* array, int const begin, int const end)
{
    if (begin <= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSortascending(array, begin, mid);
    mergeSortascending(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void mergeSortdescending(string* array, int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSortdescending(array, begin, mid);
    mergeSortdescending(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(string* array, int size)
{
    for (auto i = 0; i < size; i++)
        cout << array[i] << endl;
}

void readCSVMergeSort(const string& filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    const int MAX_SIZE = 100;
    string values[MAX_SIZE];
    string line;
    int i = 0;

    while (getline(file, line) && i < MAX_SIZE)
    {
        stringstream ss(line);
        string value;

        getline(ss, value, ',');
        values[i] = value;

        i++;
    }

    file.close();

    auto arr_size = i;

    mergeSortascending(values, 0, arr_size - 1);


    cout << "\nSorted contents are:\n";
    printArray(values, arr_size);
}
