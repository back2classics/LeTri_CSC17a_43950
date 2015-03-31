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
    char name[20];
    char tele[13];
    char topic[50];
    float fee;
};

int main(int argc, char** argv) {

    const int PEOPLE = 2; //number of speakers
    Bureau speaker[PEOPLE];
    //Getting speaker's data
    cout << "Enter the data of the " << PEOPLE << " speakers." << endl;
    for(int i = 0; i < PEOPLE; i++){
        cout << "Name of speaker " << (i + 1) << ": ";
        cin.getline(speaker[i].name, 20);
        cout << "Telephone number of speaker " << (i + 1) << " (Be sure to"
                " include the '-'s in the phone number): ";
        cin.getline(speaker[i].tele, 13);
        cout << "Topic chosen by speaker " << (i + 1) << ": ";
        cin.getline(speaker[i].topic, 50);
        cout << "Fee required for speaker " << (i + 1) << ": $";
        do{
        cin >> speaker[i].fee;
        cin.ignore();
        if(speaker[i].fee < 0){
            cout << "Only positive values are valid, please input again: $";
        }
        }
        while(speaker[i].fee < 0);
        cout << endl;
    }
    cout << "Is the information you provided correct?" << endl;
    cout << "Enter [Y] or [N]: ";
    char correct;
    int num = 0; //speaker's number if incorrect information was provided
    char isIt;
    cin >> correct;
    cin.ignore();
    if(tolower(correct) == 'y'){
    //Display the speaker's data
    for(int i = 0; i < PEOPLE; i++){
        cout << "Speaker " << (i + 1) << ": " << endl;
        cout << "Name: " << speaker[i].name << endl;
        cout << "Phone Number: " << speaker[i].tele << endl;
        cout << "Topic: " << speaker[i].topic << endl;
        cout << "Fee Required: $" << speaker[i].fee << endl;
        cout << "_____________________________________________" << endl;
    }
    }
    else{
        do{
        cout << "Enter the speaker's number that is to be corrected: ";
        do{
        cin >> num;
        cin.ignore();
        if(num > PEOPLE)
        {
            cout << "Invalid speaker number, please enter again: ";
        }
        }while(num < PEOPLE);
        cout << "Name of speaker " << num << ": ";
        cin.getline(speaker[num].name, 20);
        cout << "Telephone number of speaker " << num << " (Be sure to"
                " include the '-'s in the phone number): ";
        cin.getline(speaker[num].tele, 13);
        cout << "Topic chosen by speaker " << num << ": ";
        cin.getline(speaker[num].topic, 50);
        cout << "Fee required for speaker " << num << ": $";
        do{
        cin >> speaker[num].fee;
        cin.ignore();
        if(speaker[num].fee < 0)
        {
            cout << "Only positive values are valid, please input again: $";
        }
        }
        while(speaker[num].fee < 0);
        cout << endl;
        cout << "Is this information correct?" << endl;
        cout << "Enter [Y] or [N]: ";
        cin >> isIt;
        }while(tolower(isIt) == 'n');
        }
    if(tolower(isIt) == 'y'){
        //Display the speaker's corrected data
        cout << "Speaker " << num << ": " << endl;
        cout << "Name: " << speaker[num].name << endl;
        cout << "Phone Number: " << speaker[num].tele << endl;
        cout << "Topic: " << speaker[num].topic << endl;
        cout << "Fee Required: $" << speaker[num].fee << endl;
        cout << "_____________________________________________" << endl;
    }
    
    return 0;
}

