#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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

void merge(string* array, int const left, int const mid, int const right, bool isNumericArray)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto* leftArray = new string[subArrayOne];
    auto* rightArray = new string[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0;
    auto indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (isNumericArray)
        {
            if (stoi(leftArray[indexOfSubArrayOne]) <= stoi(rightArray[indexOfSubArrayTwo]))
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
        }
        else
        {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(string* array, int const begin, int const end, bool isNumericArray)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid, isNumericArray);
    mergeSort(array, mid + 1, end, isNumericArray);
    merge(array, begin, mid, end, isNumericArray);
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

    bool isNumericArray = true;
    for (int j = 0; j < arr_size; j++)
    {
        if (!isNumeric(values[j]))
        {
            isNumericArray = false;
            break;
        }
    }

    mergeSort(values, 0, arr_size - 1, isNumericArray);

    cout << "\nSorted contents are:\n";
    printArray(values, arr_size);
}


int main() {
    string filename = "file.txt"; // Replace with the actual filename

    readCSVMergeSort(filename);

    return 0;
}