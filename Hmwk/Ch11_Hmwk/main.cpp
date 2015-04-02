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

Bureau* fill(Bureau*, int);
void output(Bureau*, int);
void ch11_9();

int main(int argc, char** argv) {

    ch11_9();
    
return 0;
}

Bureau* fill(Bureau *s, int SIZE){
    //Getting speaker's data
    Bureau *ptr = new Bureau[SIZE];
    cout << "Enter the data of the " << SIZE << " speakers." << endl;
    for(int i = 0; i < SIZE; i++){
        cout << "Name of speaker " << (i + 1) << ": ";
        cin >> ptr[i].name;
        cout << "Telephone number of speaker " << (i + 1) << ": ";
        cin >> ptr[i].tele;
        cout << "Topic chosen by speaker " << (i + 1) << ": ";
        cin >> ptr[i].topic;
        cout << "Fee required for speaker " << (i + 1) << ": $";
        do{
        cin >> ptr[i].fee;
        if(ptr[i].fee < 0){
            cout << "Only positive values are valid, please input again: $";
        }
        }
        while(ptr[i].fee < 0);
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
    cout << "Would you like to go back to the main menu?" << endl;
    cout << "Enter [Y] or [N]: ";
    cin >> yes;
    }while(tolower(yes) == 'y');
    
    delete [] speaker;
}

