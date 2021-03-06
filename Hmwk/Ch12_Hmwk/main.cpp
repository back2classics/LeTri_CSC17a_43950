/* 
 * File:   main.cpp
 * Author: Tri Le
 * Ch. 12 Hmwk Problems
 * Created on April 3, 2015, 1:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

struct Company{
    string name[4];
    float sales[4][4];
};

int ch12_7();
void ch12_8();
void ch12_11();
void arrayToFile(string, int *, int);
void fileToArray(string, int *, int);

int main(int argc, char** argv) {

    ch12_8();
    
    return 0;
}

void arrayToFile(string filName, int *num, int SIZE){
    fstream file;
    file.open(filName.c_str(), ios::out | ios::binary);
    //Write the contents of the array to the file
    file.write(reinterpret_cast<char *>(num), sizeof(num));
    file.close();
}

void fileToArray(string filName, int *num, int SIZE){
    fstream file;
    file.open(filName.c_str(), ios::in | ios:: binary);
    cout << "Now reading the data back into memory." << endl;
    //Read the contents of the file into the array
    file.read(reinterpret_cast<char *>(num), sizeof(num));
    cout << "Here are the contents of the array: " << endl;
    //Outputting the contents of the array
    for(int i = 0; i < SIZE; i++){
        cout << num[i] << " ";
    }
    cout << endl;
    file.close();
}

void ch12_11(){
    const int NUM = 4;
    Company divis;
    fstream entity("company.txt", ios::out | ios::binary);
    for(int i = 0; i < NUM; i++){
    cout << "Enter the division name: ";
    cin >> divis.name[i];
    for(int j = 0; j < NUM; j++){
    cout << "Enter the sales for quarter " << (j + 1) << ": $";
    do{
    cin >> divis.sales[i][j];
    if(divis.sales[i][j] < 0){
        cout << "Invalid amount. Please enter again: ";
    }
    }while(divis.sales[i][j] < 0);
    }
    cout << endl;
    }
    entity.write(reinterpret_cast<char *>(&entity), sizeof(entity));
    entity.close();
    
    entity.open("company.txt", ios::in | ios::binary);
    cout << "Here are the company divisions on the file: " << endl;
    entity.read(reinterpret_cast<char *>(&entity), sizeof(entity));
        for(int i = 0; i < NUM; i++){
        cout << "Division name: ";
        cout << divis.name[i] << endl;
        for(int j = 0; j < NUM; j++){
        cout << "Quarter " << (j + 1) << " sales: $";
        cout << divis.sales[i][j] << endl;
        }
        cout << endl;
        }
    cout << "File has been completely read." << endl;
    entity.close();
}

void ch12_8(){
    const int SIZE = 10;
    int numbers[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr;
    ptr = numbers;
    int othrNum[SIZE];
    int *othrPtr;
    othrPtr = numbers;
    string filName;
    cout << "Enter the file name: ";
    cin >> filName;
    cout << "Writing contents to the file..." << endl;
    arrayToFile(filName, ptr, SIZE);
    cout << "File has been successfully written to." << endl;
    cout << endl;
    cout << "Now reading contents from the file into the array..." << endl;
    fileToArray(filName, othrPtr, SIZE);
    cout << "File has been successfully read to." << endl;
}
int ch12_7(){
    fstream file1, file2; //files that are to be created by user
    const int SIZE = 51;
    char name1[SIZE]; //name of file 1
    char name2[SIZE]; //name of file 2
    char ch; //holding character for file input/output
    cout << "Enter the file name of the first file to be created: ";
    cin >> name1;
    cout << "Enter the file name of the second file to be created: ";
    cin >> name2;
    file1.open(name1, ios::out); //creates file 1
    if(!file1){
        cout << name1 << " could not be opened." << endl;
        return 0;
    }
    file2.open(name2, ios::out); //creates file2
    if(!file2){
        cout << name2 << " could not be opened." << endl;
        return 0;
    }
    //Tells user if files were made
    cout << "Files successfully created." << endl;
    //Gets user input
    cout << "Enter a sentence, make sure it ends with a period: ";
    cin.get(ch);
    while(ch != '.'){
        file1.put(ch);
        cin.get(ch);
    }
    file1.put(ch);
    //Close file 1 so it can be opened for input
    file1.close();
    //Opens file 1 in input mode
    file1.open(name1, ios::in);
    if(!file1){
        cout << name1 << " could not be opened." << endl;
        return 0;
    }
    //Counter for the first char in the sentence
    int count = 0;
    file1.get(ch);
    while(!file1.eof()){
        file1.get(ch);
        if(ch == toupper(ch) || ch == tolower(ch)){
            count++;
        }
        if(count == 1){
            file2.put(toupper(ch));
        }
        if(count != 1){
            if(ch == '.'){
                count = 0; //this statement prevents the program into going
                           //to the else if a period is detected. this is so
                           //the sentence will not end with two periods.
            }
            else{
            file2.put(tolower(ch));
            }
        }
    }
    cout << name1 << " contains the original input written to the file." << endl;
    cout << name2 << " contains the modified output read from the file." << endl;
    
    file1.close();
    file2.close();
}
