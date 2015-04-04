/* 
 * File:   main.cpp
 * Author: Tri Le
 * Ch.10-12 10 Hmwk Problems
 * Created on March 29, 2015, 2:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>

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
struct Company{
    string name[4];
    float sales[4][4];
};

//Function Prototypes
int wCountr(char *); //counts words in a string
float avgLett(char *); //gets average number of letters in a string
int vCountr(char *); //counts vowels in a string
int cCountr(char *); //counts consonants in a string
MovieData* info(MovieData*, int);
void print(MovieData*, int);
Bureau* fill(Bureau*, int);
void output(Bureau*, int);
void arrayToFile(string, int *, int);
void fileToArray(string, int *, int);
void show(fstream &, int);
void ch10_3();
void ch10_4();
void ch10_6();
void ch11_1_2();
void ch11_9();
void ch12_1();
int ch12_7();
void ch12_8();
void ch12_11();

int main(int argc, char** argv) {

    char menu;
    int choice;
    do{
    do{
        cout << "Enter [1] to display Chapter 10 Problems 3: " << endl;
        cout << "Enter [2] to display Chapter 10 Problem 4: " << endl;
        cout << "Enter [3] to display Chapter 10 Problem 6: " << endl;
        cout << "Enter [4] to display Chapter 11 Problem 1 and 2: " << endl;
        cout << "Enter [5] to display Chapter 11 Problem 9: " << endl;
        cout << "Enter [6] to display Chapter 12 Problem 1: " << endl;
        cout << "Enter [7] to display Chapter 12 Problem 7: " << endl;
        cout << "Enter [8] to display Chapter 12 Problem 8: " << endl;
        cout << "Enter [9] to display Chapter 12 Problem 11: " << endl;
        cout << "Enter [0] to exit the program: " << endl;
        cin >> choice;
        cin.clear();
        cin.ignore();
        do{
        if(choice != 1 && choice != 2 && choice != 3 && 
           choice != 4 && choice != 5 && choice != 6 &&
           choice != 7 && choice != 8 && choice != 9 &&
           choice != 0)
        {
            cout << "Invalid input, please enter again: ";
            cin >> choice;
            cin.clear();
            cin.ignore();
        }
        }while(choice != 1 && choice != 2 && choice != 3 &&
               choice != 4 && choice != 5 && choice != 6 &&
               choice != 7 && choice != 8 && choice != 9 &&
               choice != 0);
        cout << endl;
    }while(choice != 1 && choice != 2 && choice != 3 &&
           choice != 4 && choice != 5 && choice != 6 &&
           choice != 7 && choice != 8 && choice != 9 &&
           choice != 0);
    if(choice == 1){
        cout << "This is problem 1: " << endl;
        ch10_3();
    }
    else if(choice == 2){
        cout << "This is problem 2: " << endl;
        ch10_4();
    }
    else if(choice == 3){
        cout << "This is problem 3: " << endl;
        ch10_6();
    }
    else if(choice == 4){
        cout << "This is problem 4 and 5: " << endl;
        ch11_1_2();
    }
    else if(choice == 5){
        cout << "This is problem 6: " << endl;
        ch11_9();
    }
    else if(choice == 6){
        cout << "This is problem 7: " << endl;
        ch12_1();
    }
    else if(choice == 7){
        cout << "This is problem 8: " << endl;
        ch12_7();
    }
    else if(choice == 8){
        cout << "This is problem 9: " << endl;
        ch12_8();
    }
    else if(choice == 9){
        cout << "This is problem 10: " << endl;
        ch12_11();
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

void ch10_3(){
    const int SIZE = 100;
    char sent[SIZE];
    cout << "Enter a sentence: ";
    cin.getline(sent, SIZE);
    cout << "There are " << wCountr(sent) << " word(s) in this sentence." << endl;
}

void ch10_4(){
    const int SIZE = 100;
    char sent[SIZE];
    cout << "Enter the same sentence: ";
    cin.getline(sent, SIZE);
    cout << "The average number of letters in each word is: " << avgLett(sent)
         << endl;
}

void ch10_6(){
    
    char menu;
    int choice;
    const int SIZE = 100;
    char sent[SIZE];
    
    cout << "Enter a sentence: ";
    cin.getline(sent, SIZE);
    
    do{
    do{
        cout << "Enter [1] to count the number of vowels in the string: " << endl;
        cout << "Enter [2] to count the number of consonants in the string: " 
             << endl;
        cout << "Enter [3] to count both the vowels and the consonants"
                " in the string: " << endl;
        cout << "Enter [4] to enter another string: " << endl;
        cout << "Enter [5] to exit the program: " << endl;
        cin >> choice;
        cin.clear();
        cin.ignore();
        do{
        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
        {
            cout << "Invalid input, please enter again: ";
            cin >> choice;
            cin.clear();
            cin.ignore();
        }
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4
               && choice != 5);
        cout << endl;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
    if(choice == 1){
        cout << "There are " << vCountr(sent) << " vowels in this sentence."
             << endl;
    }
    else if(choice == 2){
        cout << "There are " << cCountr(sent) << " consonants in this sentence."
             << endl;   
    }
    else if(choice == 3){
        cout << "There are " << vCountr(sent) + cCountr(sent) << " letters in this"
                " sentence." << endl;
    }
    else if(choice == 4){
        cout << "Enter a sentence: ";
        cin.getline(sent, SIZE);
    }
    else{
        cout << "Are you sure you want to exit?" << endl;
    }
    cout << "Would you like to go back to the menu?" << endl;
    cout << "Enter [Y] or [N]: ";
    cin >> menu;
    cout << endl;
    }while(tolower(menu) == 'y');
}

int wCountr(char *strPtr)
{
    int count = 0; //number of words in the string
    while(*strPtr != '\0')
    {
        if(*strPtr == ' ') //' ' = new words has been detected
        {
            count++;
        }
        strPtr++;
    }
    return count + 1; //word count + 1 because no space can be detected before 
                      //null terminator
}

float avgLett(char *strPtr)
{
    int lettrs = 0; //number of letters in the string
    int space = 0; // number of words in the sentence
    while(*strPtr != '\0')
    {
        if(*strPtr != ' ') //' ' != means the element in the array is a letter
        {
            lettrs++;
        }
        if(*strPtr == ' ') //' ' = new words has been detected
        {
            space++;
        }
        strPtr++;
    }
    space += 1;
    float avg = static_cast<float>(lettrs)/space;
    return avg;
}

int vCountr(char *word)
{
    int vowels = 0;
    for(int i = 0; i < strlen(word); i++){
        if(tolower(word[i]) == 'a' || tolower(word[i]) == 'e' || 
           tolower(word[i]) == 'i' || tolower(word[i]) == 'o' ||
           tolower(word[i]) == 'u'){
            vowels++;
        }
    }
    return vowels;
}

int cCountr(char *word)
{
    int consnts = 0;
    for(int i = 0; i < strlen(word); i++){
        if(!(tolower(word[i]) == 'a' || tolower(word[i]) == 'e' || 
             tolower(word[i]) == 'i' || tolower(word[i]) == 'o' ||
             tolower(word[i]) == 'u' || word[i] == ' ')){
            consnts++;
        }
    }
    return consnts;
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

void ch12_1(){
    const int MAXLINE = 10; //Maximum amount of lines the file will display
    fstream file;
    cout << "Opening the file..." << endl;
    file.open("num1.txt", ios::in);
    cout << "Displaying the " << MAXLINE << " contents of the file: " << endl;
    show(file, MAXLINE);
    file.close();
    cout << "Output complete." << endl;
}

void show(fstream &file, int MAXLINE){
    char max[100];
    for(int i = 0; i < MAXLINE; i++){
        file >> max;
        cout << max << endl;
    }
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