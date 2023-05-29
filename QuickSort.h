#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

bool isNumeric(const string& value)
{
    try
    {
        size_t pos;
        stoi(value, &pos);
        return pos == value.size();  // Check if the entire string was converted to a number
    }
    catch (const exception&)
    {
        return false;
    }
}

template <typename T>
int partition(T array[], int low, int high) {
    T pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);
    return i + 1;
}

template <typename T>
void quickSort(T array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);

        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

void printArray(const string array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

void readCSVQuickSort(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    const int MAX_SIZE = 100;
    string values[MAX_SIZE];
    string line;
    int i = 0;

    while (getline(file, line) && i < MAX_SIZE) {
        stringstream ss(line);
        string value;
        getline(ss, value, ',');
        values[i] = value;
        i++;
    }

    file.close();

    int arrSize = i;

    bool isNumericArray = true;
    for (int j = 0; j < arrSize; j++) {
        if (!isNumeric(values[j])) {
            isNumericArray = false;
            break;
        }
    }

    quickSort(values, 0, arrSize - 1);

    cout << "\nSorted contents are:\n";
    printArray(values, arrSize);
}

int main() {
    string filename = "file.txt"; // Replace with the actual filename

    readCSVQuickSort(filename);

    return 0;
}