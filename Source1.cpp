#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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


class Favorite
{
    public:
        string username;
        string institution;
        Favorite*nextAdd;
        Favorite*prevAdd;
        DoubleLinkedList<Favorite>favDLL;

        Favorite(string name, string institution) {
            this -> username = name;
            this -> institution = institution;
            this -> nextAdd = NULL;
            this -> prevAdd = NULL;
        }

        Favorite(){
            this -> username = "";
            this -> institution = "";
            this -> nextAdd = NULL;
            this -> prevAdd = NULL;
        }


    void addToFavorite(string username, string institution) {
    Favorite* newNodeData = new Favorite(username, institution);
    DoubleLinkedList<Favorite>::Node* newNode = new DoubleLinkedList<Favorite>::Node(newNodeData);
    favDLL.InsertEnd(newNode);
    }

        void addToFile() {
            ofstream file("favorite.csv", std::ios::app);
            if (file.is_open()) {
                DoubleLinkedList<Favorite>::Node* current = favDLL.head;
                while (current != nullptr) {
                    cout << "Name: " << current->data.username << endl;
                    cout << "Favourited Institutions: " << current->data.institution << endl;

                    file << current->data.username << ',';
                    file << current->data.institution << endl;

                    current = current->nextAdd;
                }
                cout << "Update file" << endl;
            }
            file.close();
        }

        
        void display() 
        {
            cout<< left << this -> username << ":";
            cout<< this -> institution << endl;
        }

        void display_fav()
        {
            favDLL.Display();
        }

        void header()
        {
            cout<< left << this -> username << ":";
            cout<< this -> institution << endl;
        }
};

class Feedback
{
    public:
    string FbId;
    string username;
    string institution;
    string feedback;
    string fbdate;
    string fbreply;
    string fbreply_date;
    Feedback* nextAdd;
    Feedback* prevAdd;
    DoubleLinkedList<Feedback> fbDLL;

    Feedback()
    {
        this->FbId = "";
        this->username = "";
        this->institution = "";
        this->feedback = "";
        this->fbdate = "";
        this->nextAdd = NULL;
        this->prevAdd = NULL;
        this->fbreply = "";
        this->fbreply_date = "";
    }

    Feedback(string FbId, string username, string institution, string feedback, string fbdate, string fbreply, string fbreply_date)
    {
        this->FbId = FbId;
        this->username = username;
        this->institution = institution;
        this->feedback = feedback;
        this->fbdate = fbdate;
        this->nextAdd = NULL;
        this->prevAdd = NULL;
        this->fbreply = "N/A";
        this->fbreply_date = "N/A";
    }

    void setfbreply() 
    {
        this->fbreply = fbreply;
    }

    string getfbreply()
    {
        return this->fbreply;
    }

    void setfbreply_date()
    {
        this->fbreply_date = fbreply_date;
    }

    string getfbreply_date()
    {
        return this->fbreply_date;
    }

    void generateFeedbackID(int& counter, std::string& feedbackID)
    {
    feedbackID = "FB" + std::to_string(counter);
    feedbackID = feedbackID.insert(2, std::string(3 - std::to_string(counter).length(), '0'));
    counter++;
    }
  
    std::string fbtime()
    {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::tm* currentTm = std::localtime(&currentTime);
        
        int day = currentTm->tm_mday;
        int month = currentTm->tm_mon + 1; 
        int year = currentTm->tm_year + 1900; 
        int hour = currentTm->tm_hour;
        int minute = currentTm->tm_min;
        int second = currentTm->tm_sec;

        std::stringstream buffer;
        buffer << std::setfill('0');
        buffer << std::setw(2) << day << '/' << std::setw(2) << month << '/' << year << ' ';
        buffer << std::setw(2) << hour << ':' << std::setw(2) << minute << ':' << std::setw(2) << second;
        
        return buffer.str();
    }

    void addfb(string& feedbackID, string username, string institution, string feedback)
    {
        int counter = 1;
        generateFeedbackID(counter, feedbackID);
        string FbId = feedbackID;
        string fbdate = fbtime();
        addToList(FbId, username, institution, feedback, fbdate, this->fbreply, this->fbreply_date);
    }
    void addToList(string FbId, string username, string institution, string feedback, string fbdate, string fbreply, string fbreply_date)
    {
        DoubleLinkedList<Feedback>::Node* newNode = new DoubleLinkedList<Feedback>::Node(Feedback(FbId, username, institution, feedback, fbdate, fbreply, fbreply_date));
        fbDLL.InsertEnd(newNode);
    }
    void addToFile()
    {
        ofstream file("feedback.csv", std::ios::app);
        if (file.is_open()) {
            DoubleLinkedList<Feedback>::Node* current = fbDLL.head;
            while (current != nullptr) {
                cout << "Feedback ID: " << current->data.FbId << endl;
                cout << "Username: " << current->data.username << endl;
                cout << "Institution: " << current->data.institution << endl;
                cout << "Feedback: " << current->data.feedback << endl;
                cout << "Feedback Date: " << current->data.fbdate << endl;
                cout << "Reply: " << current->data.fbreply << endl;
                cout << "Reply Date: " << current->data.fbreply_date << endl;

                file << current->data.FbId << ',';
                file << current->data.username << ',';
                file << current->data.institution << ',';
                file << current->data.feedback << ',';
                file << current->data.fbdate << ',';
                file << current->data.fbreply << ',';
                file << current->data.fbreply_date << endl;

                current = current->nextAdd;
            }
            cout << "Update file" << endl;
        }
        file.close();
    }
    void display() 
        {
            cout<< left << this->FbId << ":";
            cout<< this->username << ":";
            cout<< this->institution << ":";
            cout<< this->feedback << ":";
            cout<< this->fbdate << ":";
            cout<< this->fbreply << ":";
            cout<< this->fbreply_date << endl;
        }
    void display_feedback()
        {
            fbDLL.Display();
        }

    void header()
        {
            cout<< left << this->FbId << ":";
            cout<< this->username << ":";
            cout<< this->institution << ":";
            cout<< this->feedback << ":";
            cout<< this->fbdate << ":";
            cout<< this->fbreply << ":";
            cout<< this->fbreply_date << endl;
        }
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
	// SingleLinkedList<University> univSLL;
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
    void InsertToEndList(string rank, string institution, string LocationCode, string Location, string ArScore, string ArRank,
		string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, string IsrScore,
		string IsrRank, string IrnSCore, string IrnRank, string GerScore, string GerRank, string ScoreScaled);
    void Binary_Search();
    void Inter_Search();
    void Reg_Binary_Search();
    void Reg_Inter_Search();
    void Merge_Sort();
    void Quick_Sort();
    void display_univinfo();
    void display();
    bool compareAttributes();

};

void University :: InsertToEndList(string rank, string institution, string LocationCode, string Location, string ArScore, string ArRank,
		string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, 
        string IsrScore, string IsrRank, string IrnScore, string IrnRank, string GerScore, string GerRank, string ScoreScaled)
{
    int new_rank, new_ArRank, new_ErRank, new_FsrRank, new_CpfRank, new_IfrRank, new_IsrRank, new_IrnRank, new_GerRank;
    double new_ArScore, new_ErScore, new_FsrScore, new_CpfScore, new_IfrScore, new_IsrScore, new_IrnScore, new_GerScore, new_ScoreScaled;
    try
    {
        new_rank = stoi(rank);
    }
    catch(...)
    {
        new_rank = -1;
    }
    try
    {
        new_ArRank = stoi(ArRank);
    }
    catch(...)
    {
        new_ArRank = -1;
    }
    try
    {
        new_ErRank = stoi(ErRank);
    }
    catch(...)
    {
        new_ErRank = -1;
    }
    try
    {
        new_FsrRank = stoi(FsrRank);
    }
    catch(...)
    {
        new_FsrRank = -1;
    }
    try
    {
        new_CpfRank = stoi(CpfRank);
    }
    catch(...)
    {
        new_CpfRank = -1;
    }
    try
    {
        new_IfrRank = stoi(IfrRank);
    }
    catch(...)
    {
        new_IfrRank = -1;
    }
    try
    {
        new_IsrRank = stoi(IsrRank);
    }
    catch(...)
    {
        new_IsrRank = -1;
    }
    try
    {
        new_IrnRank = stoi(IrnRank);
    }
    catch(...)
    {
        new_IrnRank = -1;
    }
    try
    {
        new_GerRank = stoi(GerRank);
    }
    catch(...)
    {
        new_GerRank = -1;
    }
    try
    {
        new_ArScore = stod(ArScore);
    }
    catch(...)
    {
        new_ArScore = -1;
    }
    try
    {
        new_ErScore = stod(ErScore);
    }
    catch(...)
    {
        new_ErScore = -1;
    }
    try
    {
        new_FsrScore = stod(FsrScore);
    }
    catch(...)
    {
        new_FsrScore = -1;
    }
    try
    {
        new_CpfScore = stod(CpfScore);
    }
    catch(...)
    {
        new_CpfScore = -1;
    }
    try
    {
        new_IfrScore = stod(IfrScore);
    }
    catch(...)
    {
        new_IfrScore = -1;
    }
    try
    {
        new_IsrScore = stod(IsrScore);
    }
    catch(...)
    {
        new_IsrScore = -1;
    }
    try
    {
        new_IrnScore = stod(IrnScore);
    }
    catch(...)
    {
        new_IrnScore = -1;
    }
    try
    {
        new_GerScore = stod(GerScore);
    }
    catch(...)
    {
        new_GerScore = -1;
    }
    try
    {
        new_ScoreScaled = stod(ScoreScaled);
    }
    catch(...)
    {
        new_ScoreScaled = -1;
    }
    
    University* newNode = new University(new_rank, institution, LocationCode, Location, new_ArScore, new_ArRank, new_ErScore,
    new_ErRank, new_FsrScore, new_FsrRank, new_CpfScore, new_CpfRank, new_IfrScore, new_IfrRank, new_IsrScore,
    new_IsrRank, new_IrnScore, new_IrnRank, new_GerScore, new_GerRank, new_ScoreScaled);

    DoubleLinkedList<University>::Node* newListNode = new DoubleLinkedList<University>::Node(newNode);
    univDLL.InsertEnd(newListNode);


}

// void University :: Binary_Search()
// {
//     string target;
		
// 		cout << "Welcome to the Binary Search Menu!";
// 		cout << "Please enter the university name: ";
// 		cin.clear();
// 		cin.ignore(numeric_limits<streamsize>::max(),'\n');
// 		getline(cin, target);
// 		NormalBinarySearch(univDLL.head, target)
// };

void University :: Reg_Binary_Search()
{
    //
}

void University :: Inter_Search()
{
    //
}

void University :: Reg_Inter_Search()
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

// bool University :: compareAttributes()
// {
//     //
// }

void University :: display()
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
    cout << "Score Scaled: " << GerScore << endl << endl;
}

void University :: display_univinfo()
{
    univDLL.Display();
}

void mergeSortFromDLLUserData(){
    const string filename = "userdata.csv";
        performDLLMergeSort(filename);
}

void mergeSortFromDLLUserFeedback(){
    const string filename = "feedback.csv";
        performDLLMergeSort(filename);
}
void mergeSortFromDLLUserFav(){
    const string filename = "favorite.csv";
        performDLLMergeSort(filename);
}

void populateDLLFromFile(DoubleLinkedList<int>& dll, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string valueStr;
            while (std::getline(ss, valueStr, ',')) {
                int value = std::stoi(valueStr);
                dll.InsertEnd(new typename DoubleLinkedList<int>::Node(value));
            }
        }
        file.close();
    }
}


void quickSortFromDLLUserData() {
    DoubleLinkedList<int> dll; // Replace 'int' with the appropriate type for your DLL

    std::string filename = "userdata.csv"; // Replace with the actual filename and path of your CSV file

    populateDLLFromFile(dll, filename); // Populate the DLL from the CSV file

    quickSort(dll);

    cout << "\nSorted list is:" << endl;
    dll.Display();
}

void quickSortFromDLLUserFeedback() {
    DoubleLinkedList<int> dll; // Replace 'int' with the appropriate type for your DLL

    std::string filename = "feedback.csv"; // Replace with the actual filename and path of your CSV file

    populateDLLFromFile(dll, filename); // Populate the DLL from the CSV file

    quickSort(dll);

    cout << "\nSorted list is:" << endl;
    dll.Display();
}

void quickSortFromDLLUserFav() {
    DoubleLinkedList<int> dll; // Replace 'int' with the appropriate type for your DLL

    std::string filename = "favorite.csv"; // Replace with the actual filename and path of your CSV file

    populateDLLFromFile(dll, filename); // Populate the DLL from the CSV file

    quickSort(dll);

    cout << "\nSorted list is:" << endl;
    dll.Display();
}
class Admin {
public:
    void adminmenu() {
        int choice;
        int userCount = 0;
        int userFavCount = 0;

        do {
            std::cout << "University Ranking System\n" << std::endl;
            std::cout << "What would you like to do? \n\n" << std::endl;
            std::cout << "==========================================\n" << std::endl;
            std::cout << "1. View user details" << std::endl;
            std::cout << "2. View users feedback" << std::endl;
            std::cout << "3. View customers favourite universities" << std::endl;
            std::cout << "4. Generate Report" << std::endl;
            std::cout << "5. Logout\n" << std::endl;
            std::cout << "==========================================\n" << std::endl;
            std::cout << "Please select an option (1-4): " << std::endl;
            std::cin >> choice;

            switch (choice) {
                case 1: //view user details
                    int sortchoice;

                    std::cout << "1. Merge Sort\n" << std::endl;
                    std::cout << "2. Quick Sort\n\n" << std::endl;
                    std::cout << "How would you like to sort the user details?: " << std::endl;
                    std::cin >> sortchoice;

                    switch (sortchoice) {
                        case 1:
                            mergeSortFromDLLUserData();
                            break;
                            

                        case 2:
                            quickSortFromDLLUserData();
                            break;

                        default:
                            std::cout << "Invalid input!" << std::endl;
                            adminmenu();
                            break;
                    }

                    int userchoice;

                    std::cout << "1. Change password\n" << std::endl;
                    std::cout << "2. Back\n\n" << std::endl;
                    std::cout << "What would you like to do next?" << std::endl;
                    std::cin >> userchoice;

                    switch (sortchoice){
                        case 1:
                            void updatePassword();
                            break;
                        
                        case 2:
                            adminmenu();
                            break;;
                        case 3:
                            std::cout << "Invalid input!" << std::endl;
                            adminmenu();
                            break;
                    }

                    
                case 2: //view user feedback
                    int sortchoice2;

                    std::cout << "1. Merge Sort\n" << std::endl;
                    std::cout << "2. Quick Sort\n\n" << std::endl;
                    std::cout << "How would you like to sort the user feedback?: " << std::endl;
                    std::cin >> sortchoice2;

                    switch(sortchoice2){
                        case 1:
                            
                            mergeSortFromDLLUserFeedback();
                            break;
                        case 2: 
                            quickSortFromDLLUserFeedback();
                            break;
                        default:
                            std::cout << "Invalid input!" << std::endl;
                            adminmenu();
                            break;
                    }       
                    break;
                case 3: //view customers favorite unis
                    int sortchoice3;

                    std::cout << "1. Merge Sort\n" << std::endl;
                    std::cout << "2. Quick Sort\n\n" << std::endl;
                    std::cout << "How would you like to sort the user's favorite universities?: " << std::endl;
                    std::cin >> sortchoice3;

                    switch(sortchoice3){
                        case 1:
                            mergeSortFromDLLUserFav();
                            break;
                        case 2: 
                            quickSortFromDLLUserFav();
                            break;
                        default:
                            std::cout << "Invalid input!" << std::endl;
                            adminmenu();
                            break;
                    }
                    break;
                case 4:
                    //
                    break;
                case 5:
                    void UserMainMenu();
                    break;
                default:
                    std::cout << "Invalid choice, please try again" << std::endl;
                    break;
            }
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
    }
   
};

struct UserNode {
    string name;
    string password;
};

void updatePassword(const string& filename) {
    DoubleLinkedList<UserNode> userNodeDLL;
    ifstream file(filename);

    if (!file) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    UserNode userNode;
    string line;

    // Read and parse the file
    while (getline(file, line)) {
        size_t pos = line.find(", ");
        if (pos != string::npos) {
            userNode.name = line.substr(0, pos);
            userNode.password = line.substr(pos + 2);
            DoubleLinkedList<UserNode>::Node* newNode = new DoubleLinkedList<UserNode>::Node(userNode); // Create a new Node object with UserNode data
            userNodeDLL.pushBack(newNode);
        }
    }

    file.close();

    // Ask for the name of the user to update
    string nameToUpdate;
    cout << "Enter the name of the user to update: ";
    getline(cin, nameToUpdate);

    // Find the user to update
    bool found = false;
    for (DoubleLinkedList<UserNode>::Node* u = userNodeDLL.begin(); u != userNodeDLL.end(); u = userNodeDLL.next(u)) {
        if (u->data.name == nameToUpdate) {
            found = true;
            cout << "Enter the new password for " << u->data.name << ": ";
            getline(cin, u->data.password);
            break;
        }
    }

    if (!found) {
        cout << "User not found." << endl;
        return;
    }

    // Write the updated users to the file
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    for (DoubleLinkedList<UserNode>::Node* u = userNodeDLL.begin(); u != userNodeDLL.end(); u = userNodeDLL.next(u)) {
        outFile << u->data.name << ", " << u->data.password << endl;
    }

    outFile.close();

    // Clean up memory
    for (DoubleLinkedList<UserNode>::Node* u = userNodeDLL.begin(); u != userNodeDLL.end(); u = userNodeDLL.next(u)) {
        delete u;
    }

    cout << "File updated successfully." << endl;
}

void changeUserPassword() {
    const string filename = "userdata.txt";
    updatePassword(filename);
}



void performDLLMergeSort(const string& filename) {
    DoubleLinkedList<string> dll;  // Create a DoubleLinkedList object

    // Read the contents of the file and insert into the DoubleLinkedList
    ifstream file(filename);
    if (!file) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        DoubleLinkedList<string>::Node* newNode = new DoubleLinkedList<string>::Node(line);
        dll.InsertEnd(newNode);
    }

    file.close();

    // Call the merge sort function
    searchDLLMergeSort(dll);
}


class RegisteredUser {
public:
    void displayMenu(University * uni, Admin * admin, Favorite * Favorite, Feedback * feedb) {
        int choice;

        do {
            std::cout << "=== Main Menu ===" << std::endl;
            std::cout << "1. Display University Academic Ranking" << std::endl;
            std::cout << "2. Display University Faculty and Student Ratio Score" << std::endl;
            std::cout << "3. Display University Employee Reputation Score" << std::endl;
            std::cout << "4. Search University" << std::endl;
            // std::cout << "5. Logout" << std::endl;
            std::cout << "6. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                int op;
                cout << "Choose a sorting algorithm" << endl;
                cout << "1. Merge Sort" << endl;
                cout << "2. Quick Sort" << endl;
                cin >> op;
                switch (op)
                {
                    //
                }
            case 2:
                int opt;
                cout << "Choose a sorting algorithm" << endl;
                cout << "1. Merge Sort" << endl;
                cout << "2. Quick Sort" << endl;
                cin >> opt;
                switch (opt)
                {
                    //
                }
            case 3:
                int option;
                cout << "Choose a sorting algorithm" << endl;
                cout << "1. Merge Sort" << endl;
                cout << "2. Quick Sort" << endl;
                cin >> option;
                switch (option)
                {
                    //
                }
            case 4:
                uni->Reg_Inter_Search();
                break;
            // case 5:
            //     // user->UserMainMenu();
            //     // break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (choice != 5);
    }

private:
    // Function to check login credentials
    // void login() {
    //     std::string username, password;

    //     std::cout << "=== Login ===" << std::endl;
    //     std::cout << "Username: ";
    //     std::cin >> username;
    //     std::cout << "Password: ";
    //     std::cin >> password;

    //     if (validateCredentials(username, password)) {
    //         std::cout << "Login successful!" << std::endl;
    //         // Perform additional actions after successful login
    //     }
    //     else {
    //         std::cout << "Invalid username or password." << std::endl;
    //     }
    // }

    // bool validateCredentials(const std::string& username, const std::string& password) {
    //     std::ifstream file("credentials.csv");
    //     if (!file) {
    //         std::cout << "Error opening file." << std::endl;
    //         return false;
    //     }

    //     std::string line;
    //     while (std::getline(file, line)) {
    //         std::vector<std::string> tokens = split(line, ',');
    //         if (tokens.size() >= 2 && tokens[0] == username && tokens[1] == password) {
    //             file.close();
    //             return true;
    //         }
    //     }

    //     file.close();
    //     return false;
    // }

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
        int Choice;
        std::cout << "\n " << std::endl;


    }

    void static InterpolationSearch() {
        int choice;
        std::cout << "\n" << std::endl;

    }

};
class User{

private:

	string username;
	string password;

public:
	

	void static SignUp() {

		string UserUsername, UserPassword;


		cout << "Welcome Future Member!" << endl;
		cout << "Please Enter Your Desired Username: " << endl;
		cin >> UserUsername;
		cout << "Please Enter Your Desired Password: " << endl;
		cin >> UserPassword;

		ofstream file("userdata.csv", ios::app);
		if (file.is_open()) {

			file << UserUsername << "," << UserPassword << "\n";
			file.close();
			cout << "The Sign Up is Successful, Welcome New Member!" << endl;

		}

		else {
			cerr << "The Sign Up Process is Unsuccessful, Please Try Again!" << endl;

		}

	}

	void static Login() {

		string UsernameEntered, PasswordEntered;
		cout << "Welcome to the Login Menu! Please Enter Your Credentials!" << endl;
		cout << "Please Enter Your Username: ";
		cin >> UsernameEntered;
		cout << "Please Enter Your Password: ";
		cin >> PasswordEntered;

		ifstream file("userdata.csv");
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				stringstream ss(line);
				string Username, Password;
				getline(ss, Username, ',');
				getline(ss, Password, ',');

				if (UsernameEntered == Username && PasswordEntered == Password) {
					file.close();
					return;
				}

			}
			file.close();

		}
        else if (UsernameEntered == "Admin" && PasswordEntered == "Password") {
            Admin admin;
            admin.adminmenu();
            file.close();

        }
		else {
			cerr << "Login Failed!Please Re-Enter the Credentials!" << endl;
		}

		return;

	}

};

void UserMainMenu(University * uni, User * user, RegisteredUser * reguser, Admin * admin, Favorite * Favorite, Feedback * feedb) {
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
				user->SignUp();
				break;

			case 2:
				user->Login();
				break;

			case 3:
				uni->display_univinfo();
				break;

			case 4:
				int option;
                cout << "Choose a searching algorithm" << endl;
                cout << "1. Binary Search" << endl;
                cout << "2. Interpolation Search" << endl;
                cin >> option;
                switch (option)
                {
                    case 1:
                        uni -> Binary_Search();
                        break;
                    case 2:
                        uni -> Inter_Search();
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                        break;
                }

			case 5:
                int choice;
                cout << "Choose a sorting algorithm" << endl;
                cout << "1. Merge Sort" << endl;
                cout << "2. Quick Sort" << endl;
                cin >> choice;
                switch (choice)
                {
                    case 1:
                        //
                        break;
                    case 2:
                        //
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                        break;
                }

			case 6:
				cout << "Thank You for Visiting the Universities Ranking System, Have a Nice Day!" << endl;
				return;

			default:
				cout << "The Selection is Invalid, Please Select other Options" << endl;

		}

	}

int main()
{
    string rank, institution, locationCode, location, arScore, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, 
            cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled;
    string username, password;
    //
    University * uni = new University();
    User * user = new User();
    RegisteredUser * reguser = new RegisteredUser();
    Admin * admin = new Admin();
    Favorite * fav = new Favorite();
    Feedback * feedb = new Feedback();
    fstream file;
    file.open("2023 QS World University Rankings.csv", ios::in);
    if (file.is_open()) 
    {
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
            getline(file, irnScore,',');
            getline(file, irnRank, ',');
            getline(file, gerScore, ',');
            getline(file, gerRank, ',');
            getline(file, scoreScaled);
            // if (rank == "Rank")
            // {
            //     continue;
            // }
            // else if (rank == "")
            // {
            //     break;
            // }
            uni-> InsertToEndList(rank, institution, locationCode, location, arScore, arRank, erScore, erRank, fsrScore, 
            fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled);

        }
    }


    UserMainMenu(uni, user, reguser, admin, fav, feedb);

    // cout << "2023 QS WORLD UNIVERSITY RANKINGS ARE AS SHOWN BELOW: \n\n" << endl << string(50, '=') << endl;
    // void display_univinfo();
    // cout << endl;
    // return 0;

}