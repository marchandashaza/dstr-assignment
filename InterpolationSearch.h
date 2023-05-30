void InterpolationSearch() {
    string input;
    int opt, type;
    cout << "\nWelcome to the Interpolation Search Menu" << endl;
    cout << "\nHow do you want to search the universities?" << endl;
    cout << "1. Rank" << endl;
    cout << "2. Institution" << endl;
    cout << "3. Location Code" << endl;
    cout << "4. Location" << endl;
    cout << "5. Academic Reputation Rank" << endl;
    cout << "6. Employer Reputation Rank" << endl;
    cin >> opt;
    cin.clear();

    if (opt == 1) {
        type = 1;
    }
    else if (opt == 2) {
        type = 2;
    }
    else if (opt == 3) {
        type = 3;
    }
    else if (opt == 4) {
        type = 4;
    }
    else if (opt == 5) {
        type = 5;
    }
    else if (opt == 6) {
        type = 6;
    }
    else {
        cout << "ERROR" << endl;
        return;
    }

    cout << "Enter what to search: ";
    cin.clear();
    cin.ignore();
    getline(cin, input);

    University* result = InterpolationSearch(univDLL.head, input, type);

    if (result != nullptr) {
        result->display();
    }
    else {
        cout << "UNIVERSITY NOT FOUND" << endl;
    }
}

template <typename T>
T* InterpolationSearch(T* head, string target, int type) {
    T* start = head;
    T* end = nullptr;

    switch (type) {
    case 1:
    case 5:
    case 6:
        while (start != end) {
            T* mid = InterpolationMidPoint(start, end, stoi(target), type);
            if (mid->rank == stoi(target)) {
                return mid;
            }
            else if (mid->rank > stoi(target)) {
                end = mid;
            }
            else {
                start = mid->nextAdd;
            }
        }
        break;

    case 2:
    case 3:
    case 4:
        while (start != end) {
            T* mid = InterpolationMidPoint(start, end, target, type);
            if (mid->institution == target) {
                return mid;
            }
            else if (mid->institution > target) {
                end = mid;
            }
            else {
                start = mid->nextAdd;
            }
        }
        break;

    default:
        return nullptr;
    }

    return nullptr;
}

template <typename T>
T* InterpolationMidPoint(T* start, T* end, int target, int type) {
    double valueRange = 0.0;
    double fraction = 0.0;

    switch (type) {
    case 1:
    case 5:
    case 6:
        valueRange = static_cast<double>(end->rank - start->rank);
        fraction = static_cast<double>(target - start->rank) / valueRange;
        break;

    default:
        return nullptr;
    }

    T* current = start;
    while (current != end) {
        double currentFraction = 0.0;
        switch (type) {
        case 1:
        case 5:
        case 6:
            currentFraction = static_cast<double>(current->rank - start->rank) / valueRange;
            break;

        default:
            return nullptr;
        }

        if (currentFraction >= fraction) {
            return current;
        }

        current = current->nextAdd;
    }

    return current;
}
