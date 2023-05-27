#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <chrono>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "BinarySearch.h"
#include "InterpolationSearch.h"
#include "MergeSort.h"
#include "QuickSort.h"
#pragma once
using namespace std;


class Favorite{
    public:
        string name;
        string institution;
        Favorite*nextAdd;
        Favorite*prevAdd;
        DoubleLinkedList<Favorite>favDLL;

        Favorite(string name, string institution) {
            this -> name = name;
            this -> institution = institution;
            this -> nextAdd = NULL;
            this -> prevAdd = NULL;
        }

        Favorite(){
            this -> name = "";
            this -> institution = "";
            this -> nextAdd = NULL;
            this -> prevAdd = NULL;
        }

        void addToFavorite(string name, string institution){
            Favorite* newnode = new Favorite(name, institution);
            favDLL.insertEnd(newnode);
        }

        void addToFile(){
            ofstream file("favorite.csv",std::ios::app);
            if (file.is_open()){
                Favorite*current = favDLL.tail;
                while (current != NULL)
                {
                    cout << "Name: " << current->name << endl;
                    cout << "Favourited Institutions: " current->institution <<endl;

                    file << current -> name << ',';
                    file << current -> institution << endl;

                    current = current -> nextAdd;
                }
                cout << "End of favourited institutions" << endl;
            }
        }
};

class Feedback
{
    //
};

class University 
{
    University * head; University * tail;

public:
    int rank;
	string institution;
	string LocationCode;
	string Location;
	double ArScore;
	int ArRank;
	double ErScore;
	int ErRank;
	double FsrScore;
	int FsrRank;
	double CpfScore;
	int CpfRank;
	double IfrScore;
	int IfrRank;
	double IsrScore;
	int IsrRank;
	double IrnScore;
	int IrnRank;
	double GerScore;
	int GerRank;
	double ScoreScaled;
	University* nextAdd;
	University* prevAdd;
	SingleLinkedList<University> univSLL;
	DoubleLinkedList<University> univDLL;

    University(int rank, string institution, string LocationCode, string Location, double ArScore, int ArRank,
		double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore,
		int IsrRank, double IrnSCore, int IrnRank, double GerScore, int GerRank, double ScoreScaled) 
    {
		this->rank = rank;
		this->institution = institution;
		this->LocationCode = LocationCode;
		this->Location = Location;
		this->ArScore = ArScore;
		this->ArRank = ArRank;
		this->ErScore = ErScore;
		this->ErRank = ErRank;
		this->FsrScore = FsrScore;
		this->FsrRank = FsrRank;
		this->CpfScore = CpfScore;
		this->CpfRank = CpfRank;
		this->IfrScore = IfrScore;
		this->IfrRank = IfrRank;
		this->IsrScore = IsrScore;
		this->IsrRank = IsrRank;
		this->IrnScore = IrnSCore;
		this->IrnRank = IrnRank;
		this->GerScore = GerScore;
		this->GerRank = GerRank;
		this->ScoreScaled = ScoreScaled;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}
    University() 
    {
		this->rank = NULL;
		this->institution = "";
		this->LocationCode = "";
		this->Location = "";
		this->ArScore = NULL;
		this->ArRank = NULL;
		this->ErScore = NULL;
		this->ErRank = NULL;
		this->FsrScore = NULL;
		this->FsrRank = NULL;
		this->CpfScore = NULL;
		this->CpfRank = NULL;
		this->IfrScore = NULL;
		this->IfrRank = NULL;
		this->IsrScore = NULL;
		this->IsrRank = NULL;
		this->IrnScore = NULL;
		this->IrnRank = NULL;
		this->GerScore = NULL;
		this->GerRank = NULL;
		this->ScoreScaled = NULL;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}
    void insertToEndList(string rank, string institution, string LocationCode, string Location, string ArScore, string ArRank,
		string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, string IsrScore,
		string IsrRank, string IrnSCore, string IrnRank, string GerScore, string GerRank, string ScoreScaled);
    void Binary_Search();
    void Inter_Search();
    void Merge_Sort();
    void Quick_Sort();
    void display_univinfo();
    void display_uni();
    bool compareAttributes();

};

void University :: Binary_Search()
{
    //
}

void University :: Inter_Search()
{
    //
}

void University :: Merge_Sort()
{
    //
}

void University :: Quick_Sort()
{
    //
}

bool University :: compareAttributes()
{
    //
}

void University :: display_uni()
{
    cout << "Rank: " << rank << endl;
    cout << "Institution: " << institution << endl;
    cout << "Location Code: " << LocationCode << endl;
    cout << "Location: " << Location << endl;
    cout << "Academic Reputation Score: " << ArScore << endl;
    cout << "Academic Reputation Rank: " << ArRank << endl;
    cout << "Employer Reputation Score: " << ErScore << endl;
    cout << "Employer Reputation Rank: " << ErRank << endl;
    cout << "Faculty/Student Reputation Score: " << FsrScore << endl;
    cout << "Faculty/Student Reputation Rank: " << FsrRank << endl;
    cout << "Citations per Faculty Score: " << CpfScore << endl;
    cout << "Citations per Faculty Rank: " << CpfRank << endl;
    cout << "International Faculty Ratio Score: " << IfrScore << endl;
    cout << "International Faculty Ratio Rank: " << IfrRank << endl;
    cout << "International Student Ratio Score: " << IsrScore << endl;
    cout << "International Student Ratio Rank: " << IsrRank << endl;
    cout << "International Research Network Score: " << IrnScore << endl;
    cout << "International Research Network Rank: " << IrnRank << endl;
    cout << "Employment Outcome Score: " << GerScore << endl;
    cout << "Employment Outcome Rank: " << GerRank << endl;
    cout << "Score Scaled: " << GerScore << endl; 
}

void University :: display_univinfo()
{
    univDLL.display();
}


class User{

public:
	
	void static UserMainMenu() {
		int Menu;
		cout << "\n Hello New User, Welcome to the University Ranking System!" << endl;
		cout << "\n\n\n\n Please Select the Menu from the Main Menu ;) " << endl;
		cout << "\n ===========================================================" << endl;
		cout << "\n 1. Sign Up" << endl;
		cout << "\n 2. Log In" << endl;
		cout << "\n 3. View Universities" << endl;
		cout << "\n 4. Search University" << endl;
		cout << "\n 5. Sort Universities" << endl;
		cout << "\n 6. Exit" << endl;
		cout << "\n Please Input your Selection (1-5):  " << endl;
		cin >> Menu;


		switch(Menu) {
			case 1:
				void SignUp();
				break;

			case 2:
				void Login();
				break;
			case 3:
				void ViewUniversities();
				break;

			case 4:
				void SearchUniversity();
				break;

			case 5:
				void SortUniversities();
				break;

			case 6:
				cout << "Thank You for Visiting the Universities Ranking System, Have a Nice Day!" << endl;
				return;

			default:
				cout << "The Selection is Invalid, Please Select other Options" << endl;

		}

	}
};


class RegisteredUser {
public:
    void displayMenu() {
        int choice;
        do {
            std::cout << "=== Main Menu ===" << std::endl;
            std::cout << "1. Login" << std::endl;
            std::cout << "2. Display University Academic Ranking" << std::endl;
            std::cout << "3. Display University Faculty and Student Ratio Score" << std::endl;
            std::cout << "4. Display University Employee Reputation Score" << std::endl;
            std::cout << "5. Search University" << std::endl;
            std::cout << "6. Logout" << std::endl;
            std::cout << "7. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 4:
                option4();
                break;
            case 5:
                option5();
                break;
            case 6:
                option6();
                break;
            case 7:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (choice != 4);
    }

private:
    // Function to check login credentials
    void login() {
        std::string username, password;

        std::cout << "=== Login ===" << std::endl;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        if (validateCredentials(username, password)) {
            std::cout << "Login successful!" << std::endl;
            // Perform additional actions after successful login
        }
        else {
            std::cout << "Invalid username or password." << std::endl;
        }
    }

    bool validateCredentials(const std::string& username, const std::string& password) {
        std::ifstream file("credentials.csv");
        if (!file) {
            std::cout << "Error opening file." << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens.size() >= 2 && tokens[0] == username && tokens[1] == password) {
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }

    void option1() {
        
    }
    void option2() {
        std::cout << "Option 2 selected." << std::endl;
        // Add your logic for Option 2 here
    }

    void option3() {
        std::cout << "Option 3 selected." << std::endl;
        // Add your logic for Option 3 here
    }

    void option4() {
        std::cout << "Option 4 selected." << std::endl;
        // Add your logic for Option 3 here
    }

    void option5() {
        std::cout << "Option 5 selected." << std::endl;
        // Add your logic for Option 3 here
    }

    void option6() {
        std::cout << "Option 6 selected." << std::endl;
        // Add your logic for Option 3 here
    }
};

class userData {

    userData * head; userData * tail;

public:
    string username;
    string password; 
	userData* nextAdd;
	userData* prevAdd;
	SingleLinkedList<userData> univSLL;
	DoubleLinkedList<userData> univDLL;

    userData(string username, string password) 
    {
		this->username = username;
        this->password = password;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}
    userData() 
    {
		this->username = NULL;
		this->password = NULL;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}
    void insertToEndList(string username, string password);
    }

};

class userFav {
    
    userFav * head; userFav * tail;

public:
    string name;
    string institution; 
	userFav* nextAdd;
	userFav* prevAdd;
	SingleLinkedList<userFav> univSLL;
	DoubleLinkedList<userFav> univDLL;

    userFav(string name, string institution) 
    {
		this->name = name;
        this->institution = institution;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}
    userFav() 
    {
		this->name = NULL;
		this->institution = NULL;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}
    void insertToEndList(string name, string institution);
    }
};



class Admin
{
public:

    void adminmenu() {
        int choice;
        do
        {
            cout << "University Ranking System\n" << endl;
            cout << "What would you like to do? \n\n" << endl;
            cout << "==========================================\n" << endl;
            cout << "1. View user details" << endl;
            cout << "2. View users feedback" << endl;
            cout << "3. View customers favourite universities" << endl;
            cout << "4. Logout\n" << endl;
            cout << "==========================================\n" << endl;
            cout << "Please select an option (1-4): " << endl;
            cin >> choice;

            switch (choice)
            {
                case 1:
                    void userData();
                    break;
                case 2:
                    //view user feedback
                    break;
                case 3:   
                    void userFav();
                    break;
                case 4:
                    void UserMainMenu();
                    break;
                default:
                    cout << "Invalid choice, please try again" << endl;
                    break;             
            }
        }
        while (opt != 4);

        
    }; 
    Admin* login(string ID, string password) {
        // Admin * current = adminDLL.head;
        while (current != NULL) {
            if (ID == current -> ID && password) {
                cout << "Welcome " << current-> name << endl;
                return current;
            }
            cout << "Invalid credentials" << endl;
            return NULL;
        }
                                        
    }

}

int main()
{
    string head = NULL;

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
    display_univinfo();
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