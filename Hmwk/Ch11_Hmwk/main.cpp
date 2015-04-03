/* 
 * File:   main.cpp
 * Author: Tri Le
 * Ch. 11 Hmwk Problems
 * Created on March 31, 2015, 2:51 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

struct Bureau{
    string name;
    int tele;
    string topic;
    float fee;
};
struct MovieData{
    string title;
    string directr;
    unsigned short year;
    unsigned short time;
    float cost;
    float revenue;
};

MovieData* info(MovieData*, int);
void print(MovieData*, int);
Bureau* fill(Bureau*, int);
void output(Bureau*, int);
void ch11_1_2();
void ch11_9();

int main(int argc, char** argv) {

    char menu;
    int choice;
    do{
    do{
        cout << "Enter [1] to display Chapter 11 Problems 1 and 2: " << endl;
        cout << "Enter [2] to display Chapter 11 Problem 9: " << endl;
        cout << "Enter [3] to exit the program: " << endl;
        cin >> choice;
        cin.clear();
        cin.ignore();
        do{
        if(choice != 1 && choice != 2 && choice != 3)
        {
            cout << "Invalid input, please enter again: ";
            cin >> choice;
            cin.clear();
            cin.ignore();
        }
        }while(choice != 1 && choice != 2 && choice != 3);
        cout << endl;
    }while(choice != 1 && choice != 2 && choice != 3);
    if(choice == 1){
        ch11_1_2();
    }
    else if(choice == 2){
        ch11_9();
    }
    else
    {
        cout << "Are you sure you want to exit?" << endl;
    }
    cout << "Would you like to go back to the main menu?" << endl;
    cout << "Enter [Y] or [N]: ";
    cin >> menu;
    cout << endl;
    }while(tolower(menu) == 'y');
    
return 0;
}

MovieData* info(MovieData* movie, int SIZE){
    MovieData* temp = new MovieData[SIZE];
    for(int i = 0; i < SIZE; i++){
        cout << "Enter the movie title of movie " << (i + 1) << ": ";
        getline(cin, temp[i].title);
        cout << "Enter the director of movie " << (i + 1) << ": ";
        getline(cin, temp[i].directr);
        cout << "Enter the year movie " << (i + 1) << " was produced in: ";
        cin >> temp[i].year;
        cout << "Enter the running time (in minutes) of movie " << (i + 1) << ": ";
        cin >> temp[i].time;
        cout << "Enter the total costs of production for movie " << (i + 1)
             << ": $";   
        cin >> temp[i].cost;
        cout << "Enter the revenue of movie " << (i + 1) << "'s first year: $";
        cin >> temp[i].revenue;
        cin.ignore();
        cout << endl;
    }
    return temp;
}

void print(MovieData* movie, int SIZE){
    for(int i = 0; i < SIZE; i++){
        cout << "Movie: " << (i + 1) << endl;
        cout << "Title: " << movie[i].title << endl;
        cout << "Director: " << movie[i].directr << endl;
        cout << "Year produced: " << movie[i].year << endl;
        cout << "Total run time: " << movie[i].time << " minutes" << endl;
        cout << "Total profits: $" << movie[i].revenue - movie[i].cost << endl; 
        cout << "_______________________________" << endl;
    }
}

void ch11_1_2(){
    const int MOVIES = 2;
    MovieData* titles = new MovieData[MOVIES];
    titles = info(titles, MOVIES);
    print(titles, MOVIES);
    delete [] titles;
}

Bureau* fill(Bureau *s, int SIZE){
    //Getting speaker's data
    Bureau *ptr = new Bureau[SIZE];
    cout << "Enter the data of the " << SIZE << " speakers." << endl;
    for(int i = 0; i < SIZE; i++){
        cout << "Name of speaker " << (i + 1) << ": ";
        getline(cin, ptr[i].name);
        cout << "Telephone number of speaker " << (i + 1) << ": ";
        cin >> ptr[i].tele;
        cout << "Topic chosen by speaker " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, ptr[i].topic);
        cout << "Fee required for speaker " << (i + 1) << ": $";
        do{
        cin >> ptr[i].fee;
        if(ptr[i].fee < 0){
            cout << "Only positive values are valid, please input again: $";
        }
        }
        while(ptr[i].fee < 0);
        cin.ignore();
        cout << endl;
        }
    
    return ptr;
}
void output(Bureau *s, int SIZE){
    for(int i = 0; i < SIZE; i++){
        cout << "Speaker " << (i + 1) << ": " << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Phone Number: " << s[i].tele << endl;
        cout << "Topic: " << s[i].topic << endl;
        cout << "Fee Required: $" << s[i].fee << endl;
        cout << "_____________________________________________" << endl;
    }
}
void ch11_9(){
    const int PEOPLE = 3; //number of speakers
    Bureau *speaker = new Bureau[PEOPLE];
    int num;
    char isIt;
    int input;
    char yes;
    speaker = fill(speaker, PEOPLE);
    do{
    do{
        cout << "Enter [1] to make changes to speaker's information: " << endl;
        cout << "Enter [2] to display all of the speaker's information: " << endl;
        cout << "Enter [3] to exit the program: " << endl;
        cin >> input;
        cin.clear();
        cin.ignore();
        do{
        if(input != 1 && input != 2 && input != 3)
        {
            cout << "Invalid input, please enter again: ";
            cin >> input;
            cin.clear();
            cin.ignore();
        }
        }while(input != 1 && input != 2 && input != 3);
        cout << endl;
    }while(input != 1 && input != 2 && input != 3);
    if(input == 1){
        cout << "Enter the speaker's number that is to be corrected: ";
        do{
        cin >> num;
        if(num > PEOPLE)
        {
            cout << "Invalid speaker number, please enter again: ";
        }
        }while(num > PEOPLE);
        do{
        cout << "Name of speaker " << num << ": ";
        cin >> speaker[num - 1].name;
        cout << "Telephone number of speaker " << num << ": ";
        cin >> speaker[num - 1].tele;
        cout << "Topic chosen by speaker " << num << ": ";
        cin >> speaker[num - 1].topic;
        cout << "Fee required for speaker " << num << ": $";
        do{
        cin >> speaker[num - 1].fee;
        if(speaker[num - 1].fee < 0)
        {
            cout << "Only positive values are valid, please input again: $";
        }
        }
        while(speaker[num - 1].fee < 0);
        cout << endl;
        cout << "Is this information correct?" << endl;
        cout << "Enter [Y] or [N]: ";
        cin >> isIt;
        cout << endl;
        }while(tolower(isIt) == 'n');
    }
    else if(input == 2){
        output(speaker, PEOPLE);
    }
    else{
        cout << "Are you sure you are done?" << endl;
    }
    cout << "Would you like to go back to the menu?" << endl;
    cout << "Enter [Y] or [N]: ";
    cin >> yes;
    }while(tolower(yes) == 'y');
    
    delete [] speaker;
}

