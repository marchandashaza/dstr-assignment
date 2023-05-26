int main()
{
    head = NULL;

    string rank, institution, locationCode, location, arScore, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, gerScore, gerRank, scoreScaled;
    ifstream file("2023 QS World University Rankings.csv");

    while (file.good())
    {
        getline(file, rank, ',');
        getline(file, institution, ',');
        getline(file, locationCode, ',');
        getline(file, location, ',');
        getline(file, arScore, ',');
        getline(file, arRank, ',');
        getline(file, erScore, ',');
        getline(file, erRank, ',');
        getline(file, fsrScore, ',');
        getline(file, fsrRank, ',');
        getline(file, cpfScore, ',');
        getline(file, cpfRank, ',');
        getline(file, ifrScore, ',');
        getline(file, ifrRank, ',');
        getline(file, isrScore, ',');
        getline(file, isrRank, ',');
        getline(file, gerScore, ',');
        getline(file, gerRank, ',');
        getline(file, scoreScaled);
        if (rank == "Rank")
        {
            continue;
        }
        else if (rank == "")
        {
            break;
        }
        InsertToTheFrontOfList(stoi(rank), institution, locationCode, location, stod(arScore), stoi(arRank), stod(erScore), stoi(erRank), stod(fsrScore), stoi(fsrRank), stod(cpfScore), stoi(cpfRank), stod(ifrScore), stoi(ifrRank), stod(isrScore), stoi(isrRank), stod(gerScore), stoi(gerRank), stod(scoreScaled));
    }


    cout << "2023 QS WORLD UNIVERSITY RANKINGS ARE AS SHOWN BELOW: \n\n" << endl << string(50, '=') << endl;
    displayUniversityInfo();
    cout << endl;
    return 0;






    int counter = 0;
    int arr[5], i, elem;
    cout << "Enter 5 Array Elements: ";
    for (i = 0; i < 5; i++)
        cin >> arr[i];

    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}