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
extern bool searchInCSV(const std::string& filename, const std::string& searchItem);



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
            Favorite* newNode = new Favorite(name, institution);
            favDLL.InsertEnd(newNode);
        }

        void addToFile(){
            ofstream file("favorite.csv",std::ios::app);
            if (file.is_open()){
                Favorite*current = favDLL.tail;
                while (current != NULL)
                {
                    cout << "Name: " << current->name << endl;
                    cout << "Favourited Institutions: " << current->institution <<endl;

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
};

    //call using 
    //generateid generator; 
    //std::string feedbackID = generator.generatefeedbackid();
    //std::cout << feedbackID << std::end1;
    class generateid
    {
        private:
            int counter;

        public:
            generateid():counter(1){}
            std::string generatefeedbackid(){
                std::string feedbackID = "FB" + std::to_string(counter);
                feedbackID = feedbackID.insert(2, std::string(3-std::to_string(counter).length(), '0'));
                counter++;
                return feedbackID;
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
        univDLL.InsertEnd(newNode);
}

void University :: Binary_Search()
{
    //
}

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

bool University :: compareAttributes()
{
    //
}

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
    cout << "Score Scaled: " << GerScore << endl; 
}

void University :: display_univinfo()
{
    univDLL.display();
}


class User{

private:

	string username;
	string password;

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


struct User {
    string name;
    string password;
};

void updatePassword(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    
    if (!file) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }
    
    User user;
    string line;
    
    // Read and parse the file
    while (getline(file, line)) {
        size_t pos = line.find(", ");
        if (pos != string::npos) {
            user.name = line.substr(0, pos);
            user.password = line.substr(pos + 2);
            users.push_back(user);
        }
    }
    
    file.close();
    
    // Ask for the name of the user to update
    string nameToUpdate;
    cout << "Enter the name of the user to update: ";
    getline(cin, nameToUpdate);
    
    // Find the user to update
    bool found = false;
    for (User& u : users) {
        if (u.name == nameToUpdate) {
            found = true;
            cout << "Enter the new password for " << u.name << ": ";
            getline(cin, u.password);
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
    
    for (const User& u : users) {
        outFile << u.name << ", " << u.password << endl;
    }
    
    outFile.close();
    
    cout << "File updated successfully." << endl;
}

void changeUserPassword(){
    const string filename = "userdata.txt";
    updatePassword(filename);
}


void displayMergeSortedUserData(){
    const string filename = "userdata.csv";
    readCSVMergeSort(filename);
}

void displayQuickSortedUserData(){
    string filename = "userdata.csv";
    readCSVQuickSort(filename);
}

void displayMergeSortedUserFeedback(){
    const string filename = "feedback.csv";
    readCSVMergeSort(filename);
}

void displayQuickSortedUserFeedback(){
    const string filename = "feedback.csv";
    readCSVQuickSort(filename);
}

void displayMergeSortedUserFav(){
    const string filename = "favorite.csv";
    readCSVMergeSort(filename);
}

void displayQuickSortedUserFav(){
    const string filename = "favorite.csv";
    readCSVQuickSort(filename);
}

void displayInterpolationSearchUserData(){
    string filename = "userdata.csv";
    string searchItem;

    cout << "Enter the item you want to search: ";
    cin >> searchItem;

    if (!searchInCSV(filename, searchItem)) {
        cout << "Item not found in the CSV file." << endl;
    }

}

void displayInterpolationSearchUserFav()
{
    string filename = "favorite.csv";
    string searchItem;

    cout << "Enter the item you want to search: ";
    cin >> searchItem;

    if (!interpolationSearch(filename, searchItem)) {
        cout << "Item not found in the CSV file." << endl;
    }
}


void deleteUserFromFile(const string& filename, const string& usernameToDelete)
{
    ifstream inputFile(filename);
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile) {
        cout << "Failed to open file." << endl;
        return;
    }

    string line;
    bool userDeleted = false;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string username, password;

        getline(ss, username, ',');
        getline(ss, password, ',');

        if (username != usernameToDelete) {
            tempFile << line << endl;
        } else {
            userDeleted = true;
        }
    }

    inputFile.close();
    tempFile.close();

    if (userDeleted) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
        cout << "User deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "User not found in the file." << endl;
    }

    
}

void deleteUser(){
    string filename = "userdata.txt";
    string usernameToDelete;

    cout << "Enter the username you want to delete: ";
    cin >> usernameToDelete;

    deleteUserFromFile(filename, usernameToDelete);
    Admin();
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
                    std::cout << "2. Quick Sort\n" << std::endl;
                    std::cout << "3. Edit User Details\n" << std::endl;
                    std::cout << "4. Back\n\n" << std::endl;
                    std::cout << "What would you like to do?: " << std::endl;
                    std::cin >> sortchoice;

                    switch (sortchoice) {
                        case 1:
                            displayMergeSortedUserData();
                            break;
                        case 2:
                            displayQuickSortedUserData();
                            break;
                        case 3:
                            int userchoice;

                            std::cout << "1. Change Password\n" << std::endl;
                            std::cout << "2. Delete User\n" << std::endl;
                            std::cout << "3. Back\n\n" << std::endl;
                            std::cout << "What would you like to do next?" << std::endl;
                            std::cin >> userchoice;

                            switch (sortchoice){
                                case 1:
                                    void updatePassword();
                                    break;

                                case 2:
                                    void deleteUser();
                                    break;
                                case 3:
                                    adminmenu();
                                    break;
                                default:
                                    std::cout << "Invalid input!" << std::endl;
                                    adminmenu();
                                    break;
                            }                    

                        case 4:
                            adminmenu();
                            break;
                        default:
                            std::cout << "Invalid input!" << std::endl;
                            adminmenu();
                            break;
                    }
                    
                case 2: //view user feedback
                    int sortchoice;

                    std::cout << "1. Merge Sort\n" << std::endl;
                    std::cout << "2. Quick Sort\n\n" << std::endl;
                    std::cout << "How would you like to sort the user feedback?: " << std::endl;
                    std::cin >> sortchoice;

                    switch(sortchoice){
                        case 1:
                            displayMergeSortedUserFeedback();
                            break;
                        case 2: 
                            displayQuickSortedUserFeedback();
                            break;
                        default:
                            std::cout << "Invalid input!" << std::endl;
                            adminmenu();
                            break;
                    }
                    break;
                case 3: //view customers favorite unis
                    int sortchoice;

                    std::cout << "1. Merge Sort\n" << std::endl;
                    std::cout << "2. Quick Sort\n\n" << std::endl;
                    std::cout << "How would you like to sort the user's favorite universities?: " << std::endl;
                    std::cin >> sortchoice;

                    switch(sortchoice){
                        case 1:
                            displayMergeSortedUserFav();
                            break;
                        
                        case 2: 
                            displayQuickSortedUserFav();
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

int main()
{
    string rank, institution, locationCode, location, arScore, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, 
            cpfRank, ifrScore, ifrRank, isrScore, isrRank, gerScore, gerRank, scoreScaled;
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
            InsertToTheFrontOfList(stoi(rank), institution, locationCode, location, stod(arScore), stoi(arRank), stod(erScore), stoi(erRank), stod(fsrScore), 
            stoi(fsrRank), stod(cpfScore), stoi(cpfRank), stod(ifrScore), stoi(ifrRank), stod(isrScore), stoi(isrRank), stod(gerScore), stoi(gerRank), stod(scoreScaled));
        }
    }


    cout << "2023 QS WORLD UNIVERSITY RANKINGS ARE AS SHOWN BELOW: \n\n" << endl << string(50, '=') << endl;
    void display_univinfo();
    cout << endl;
    return 0;

}