#include <iostream>
#include <fstream>
#include <sstream>

class MainMenu {
public:
    void displayMenu() {
        int choice;
        do {
            std::cout << "=== Main Menu ===" << std::endl;
            std::cout << "1. Display University Academic Ranking" << std::endl;
            std::cout << "2. Display University Faculty and Student Ratio Score" << std::endl;
            std::cout << "3. Display University Employee Reputation Score" << std::endl;
            std::cout << "4. Search University" << std::endl;
            std::cout << "5. Logout" << std::endl;
            std::cout << "6. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                SortUniversities();
                break;
            case 2:
                SortUniversities();
                break;
            case 3:
                SortUniversities();
                break;
            case 4:
                SearchUniversities();
                break;
            case 5:
                UserMainMenu();
                break;
            case 7:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (choice != 5);
    }

private:
    void static SortUniversities() {

        int sort;
        std::cout << "\n Hello, welcome to the sort menu!" << std::endl;
        std::cout << "\n Please choose which sort algorithm you wanted to use!" << std::endl;
        std::cout << "\n 1. Merge Sort Algorithm" << std::endl;
        std::cout << "\n 2. Quick Sort Algorithm" << std::endl;
        std::cin >> sort;

        if (sort == 1) {
            void MergeSort();
        }

        else if (sort == 2) {
            void QuickSort();
        }

        else {
            std::cout << "\n The number you inserted is invalid!" << std::endl;
            std::cout << "\n please re - enter your choice!" << std::endl;

            void SortUniversities();
        }


    }

    void static MergeSort() {



    }

    void static QuickSort() {



    }

    void static SearchUniversities() {

        int search;
        std::cout << "\n Hello, welcome to the search menu!" << std::endl;
        std::cout << "\n Please choose which search algorithm you wanted to use!" << std::endl;
        std::cout << "\n 1. Binary Search Algorithm" << std::endl;
        std::cout << "\n 2. Interpolation Search Algorithm" << std::endl;
        std::cin >> search;

        if (search == 1) {
            void BinarySearch();
        }

        else if (search == 2) {
            void InterpolationSearch();
        }

        else {
            std::cout << "\n The number you inserted is invalid!" << std::endl;
            std::cout << "\n please re - enter your choice!" << std::endl;
            void SearchUniversities();
        }

    }

    void static BinarySearch() {
	    string input;
	    int opt, type;
	    cout << "\n Welcome to the Binary Search Menu" << endl;
	    cout << "\n How do you want to search the universities?" << endl;
	    cout << " 1. Rank " << endl;
	    cout << " 2. Institution " << endl;
	    cout << " 3. Location Code " << endl;
	    cout << " 4. Location " << endl;
	    cout << " 5. Academic Reputation Rank " << endl;
	    cout << " 6. Employee Reputation Rank " << endl;
            cin >> opt;
            cin.clear();

        if (opt == 1){
            type = 1;
        }
        else if(opt == 2){
            type = 2;
        }
        else if(opt == 3){
            type = 3;
        }
        else if(opt == 4){
            type = 4;
        }
        else if(opt == 5){
            type = 5;
        }
        else if(opt == 6){
            type = 6;
        }
        else
        {
            cout << "ERROR" << endl;
        }


        //check 1
        cout << "check 1" << endl;
        cout << type << endl;

        if (type == 1 || type == 5 || type == 6){
            cout << "Enter what to search: ";
            cin.clear();
            cin >> input;
        }
        else if(type == 2 || type == 3 || type == 4){
            cout << "Enter what to search: ";
            cin.clear();
            getline(cin, input);
        }

        //check 2
        cout << "check 2" << endl;
        cout << type << endl;
        cout << input << endl;


        University* point = MemberBinarySearch(univDLL.head, input, type)

        if (point != NULL){
            point->displau();
        }
        else{
            cout << "UNIVERSITY NOT EXIST" << endl;

        }
    }

    void static InterpolationSearch() {
        int choice;
        std::cout << "\n" << std::endl;

    }


    int main() {
        MainMenu menu;
        menu.displayMenu();

        return 0;
    }
