/* 
 * File:   main.cpp
 * Author: Tri Le
 * CSC17a Spring 2015 Midterm
 * Created on April 10, 2015, 5:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries
#include "balance.h"
#include "payroll.h"
#include "stats.h"

//Function Prototypes
void Menu();
int getN();
void def(int);
float mean(int[], int); //Problem 3
float median(int *, int); //Problem 3
int numMode(int [], int); //Problem 3
int freq(int [], int); //Problem 3
int *mode(int [], int *, int); //Problem 3
statsResult *avgMedMode(int *,int); //Problem 3
void printStat(statsResult *); //Problem 3
void bubble(int *, int); //Problem 3
void solution(); //Problem 6
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Begin Execution Here
int main(int argc, char** argv) {

    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    
    return 1;
}
void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
    Balance person;
    int newBal = 0; //New balance after any deductions or additions to balance
    int write = 0; //Total amount of written checks
    int credit = 0; //Total amount of deposited checks
    char cont; //User input to determine if user wants to write/deposit more checks
    char numId[5];
    cout << "Enter your 5-digit account number: ";
    cin >> numId;
    while(strlen(numId) != 5){
        cout << "Invalid account number. Must be 5 digits long." << endl;
        cout << "Account number: ";
        cin >> numId;
    }
    person.accNum = atoi(numId); //changes char numId[5] to int value
    cout << "ID: " << person.accNum << endl;
    cout << "Enter your account balance at the start of this month: $";
    cin >> person.start;
    do{
    cout << "Enter the amount of a check you have written this month: $";
    cin >> person.written;
    write += person.written;
    cout << "Continue? [Y] or [N]: ";
    cin >> cont;
    }while(tolower(cont) == 'y');
    do{
    cout << "Enter the amount of a deposit you made this month: $";
    cin >> person.deposit;
    credit += person.deposit;
    cout << "Continue? [Y] or [N]: ";
    cin >> cont;
    }while(tolower(cont) == 'y');
    cout << endl;
    newBal = (person.start + person.deposit) - write;
    if(newBal < 0){
        newBal -= 12;
        cout << "Account has been overdrawn. A $12 fee has been charged to your"
                " account." << endl;
    }
    cout << "Here is your new balance with any extra fees if applicable: $"
         << newBal << endl;
    cout << endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    int size;
    do{
    cout << "Enter the number of employees you would like to calculate"
            " their gross pay for: ";
    cin >> size;
    if(size < 0){
        cout << "Invalid input. Please enter again." << endl;
    }
    }while(size < 0);
    PayRoll workers[size];
    for(int i = 0; i < size; i++){
        cout << "Enter the name of employee " << (i + 1) << ": ";
        cin >> workers[i].name;
        //getline and cin.ignore would not work properly when the menu was
        //implemented so cin was used because I could not debug the problem
        cout << "Enter the hours worked of employee " << (i + 1) << ": ";
        cin >> workers[i].hours;
        cout << "Enter the rate of pay of employee " << (i + 1) << ": $";
        cin >> workers[i].payRate;
        
        if(workers[i].hours <= 20){
            workers[i].gross = workers[i].hours * workers[i].payRate;
        }
        else if(workers[i].hours >= 20 && workers[i].hours <= 40){
            workers[i].gross = 20 * workers[i].payRate;
            workers[i].gross += (workers[i].hours - 20) * (workers[i].payRate * 2);
        }
        else{
            workers[i].gross = 20 * workers[i].payRate;
            workers[i].gross += 20 * (workers[i].payRate * 2);
            workers[i].gross += (workers[i].hours - 40) * (workers[i].payRate * 3);
        }
        cout << endl;
        
    }
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << endl;
        cout << "Name of employee " << (i + 1) << ": " << workers[i].name << endl;
        cout << "Hours of employee " << (i + 1) << ": "
             << workers[i].hours << " hours" << endl;
        cout << "Rate of pay of employee " << (i + 1) << ": $"
             << workers[i].payRate << " per hour" << endl;
        cout << "Gross pay of employee this month " << (i + 1) << ": $"
             << workers[i].gross << endl;
    }
    cout << endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    statsResult *numbers;
    int size = 0;
    cout << "Enter the array size: ";
    cin >> size;
    int array[size];
    for(int i = 0; i < size; i++){
        cout << "Enter the element: ";
        cin >> array[i];
    }
    bubble(array, size); // sorts the array
    numbers = avgMedMode(array, size);
    printStat(numbers);
    cout << endl;
    delete numbers;
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    char code[4]; //used to store the code as chars
    int data[4]; //used to store char code when converted to int values
    bool count = false;
    cout << "Enter the 4-digit code to be encrypted (from 0-7): ";
    cin >> code;
    data[0] = code[0] - '0';
    data[1] = code[1] - '0';
    data[2] = code[2] - '0';
    data[3] = code[3] - '0';
    for(int i = 0; i < 4; i++){
        if(data[i] == 5){
            data[i] = 1;
        }
        else if(data[i] == 6){
            data[i] = 2;
        }
        else if(data[i] == 7){
            data[i] = 3;
        }
        else{
            data[i] += 3; //adds 3 to each element
        }
        data[i] %= 8; //mods every element by 8
    }
    swap(data[0], data[1]); //swaps first and second values
    swap(data[2], data[3]); //swaps third and fourth values
    cout << "Here is the encrypted code: ";
    for(int i = 0; i < 4; i++){
        cout << data[i];
    }
    cout << endl;
    cout << endl;
    cout << "Enter the same 4-digit code to be decrypted: ";
    cin >> code;
    data[0] = code[0] - '0';
    data[1] = code[1] - '0';
    data[2] = code[2] - '0';
    data[3] = code[3] - '0';
    swap(data[1], data[0]); //swap back first and second values
    swap(data[3], data[2]); //swap back third and fourth values
    for(int i = 0; i < 4; i++){
    if(data[i] == 0){
        data[i] = 5; //otherwise 0 = +3 %8
    }
    else if(data[i] == 1){
        data[i] = 5; //1 = +3 %8
    }
    else if(data[i] == 2){
        data[i] = 6; //2 = +3 %8
            
    }
    else if(data[i] == 3){
        data[i] = 7;
    }
    else{
        data[i] -= 3; //if value is from 3-7 only 3 is needed to be subtracted
    }
    }
    cout << "Here is the decrypted code: ";
    for(int i = 0; i < 4; i++){
        cout << data[i];
    }
    cout << endl << endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    cout << "short: 7 is the highest factorial" << endl;
    cout << "unsigned short: 8 is the highest factorial" << endl;
    cout << "int: 16 is the highest factorial" << endl;
    cout << "unsigned int: 33 is the highest factorial" << endl;
    cout << "long: 16 is the highest factorial" << endl;
    cout << "unsigned long: 33 is the highest factorial" << endl;
    cout << "float: 34.03 is the highest factorial" << endl;
    cout << "double: 170.6 is the highest factorial" << endl;
    cout << endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    solution();
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void solution(){
    cout << "2.125 base 10 = 10.001 base 2 = 2.2 base 16 = 2.1 base 8" << endl
         << endl;
    cout << "0.06640625 base 10 = .00010001 base 2 = .11 base 16 = .042 base 8"
         << endl << endl;
    cout << "-2.125 when converted to hex from float conversion is: BC0000FE"
         << endl << endl;
    cout << "0.06640625 when converted to hex from float conversion is: 44000003"
         << endl << endl;
    cout << "46666601 = 1.09 base 10 (where 9 repeats forever)" << endl;
    cout << " = 1.000110 base 2 (where the last 4 digits repeat forever)" << endl;
    cout << " = 1.19 base 16 (where 9 repeats forever)" << endl;
    cout << " = 1.06314 base 8 (where the last 4 digits repeat forever)" << endl;
    cout << "46666602 = 1.09 base 10 (where 9 repeats forever)" << endl;
    cout << " = 1.000110 base 2 (where the last 4 digits repeat forever)" << endl;
    cout << " = 1.19 base 16 (where 9 repeats forever)" << endl;
    cout << " = 1.06314 base 8 (where the last 4 digits repeat forever)" << endl;
    cout << "B9999AFE = -2.19 base 10 (where 9 repeats forever)" << endl;
    cout << " = -10.00110 base 2 (where the last 4 digits repeat forever)" << endl;
    cout << " = -2.3 base 16 (where the 3 repeats forever)" << endl;
    cout << " = -2.1463 base 8 (where the last 4 digits repeat forever)" << endl;
    cout << endl;
}

statsResult *avgMedMode(int *p, int size){
    statsResult *num = new statsResult;
    num->avg = mean(p, size);
    num->median = median(p, size);
    int val;
    val = numMode(p, size);
    num->nModes = val;
    num->maxFreq = freq(p, size);
    int *modes = new int[val + 2];
    num->mode = mode(p, modes, size);
    return num;
}

void printStat(statsResult *numbers){
    cout << "Mean: " << numbers->avg << endl;
    cout << "Median: " << numbers->median << endl;
    cout << "Modes: ";
    for(int i = 2; i < numbers->nModes+2; i++){
        cout << numbers->mode[i] << " ";
    }
    cout << endl;
    cout << "Number of modes: " << numbers->nModes << endl;
    cout << "Frequency: " << numbers->maxFreq << endl;
}

float mean(int array[], int size)
{
    // average value of the contents in the array
    float mean = 0;
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    mean = static_cast<float>(sum) / size;
    return mean;
}

float median(int *p, int size) 
{
    float median;
    if(size % 2 == 0)
    {
        median = (p[size/2] + p[(size/2) - 1]) / static_cast<float>(2); 
    }
    else
    {
        median = *(p + (size/2));
    }
    return median;
}

int numMode(int p[], int size) 
{
    int mode, counter = 0, curFreq = 0, freq = 0, numMode = 0;
    
    mode = p[0];
    for(int i = 0; i < size; i++)
    {
        if(p[i] == p[i+1]) // checks if one element is equal to another
        {
            counter++; // counter is the frequency of that number appearing
            if(curFreq < counter) 
            // if curFreq is less than counter then curFreq is changed to the new freq
            { 
                curFreq = counter;
                // mode is assigned to the number in the element p[i]
                mode = p[i]; 
            }
            if(counter == 1) 
            {  
                // if counter is ever 1 that means there is at least one new mode
                // because it only resets back to 1 when a new mode is detected 
                numMode++;
            }
        }
        else
        {
            if(counter >= freq)
            // the first run of the program will always assign freq to a number
            // if there is a higher frequency then it will change after 'X' runs
            {
                freq = counter + 1;
            }
            
            counter = 0;
            if(curFreq == 0)
            // if curFreq is never changed that means there is no mode    
            {
                mode = -1;
            }
        }
    }
    return numMode;
}

int freq(int p[], int size) 
{
    int mode, counter = 0, curFreq = 0, freq = 0, numMode = 0;
    
    mode = p[0];
    for(int i = 0; i < size; i++)
    {
        if(p[i] == p[i+1]) // checks if one element is equal to another
        {
            counter++; // counter is the frequency of that number appearing
            if(curFreq < counter) 
            // if curFreq is less than counter then curFreq is changed to the new freq
            { 
                curFreq = counter;
                // mode is assigned to the number in the element p[i]
                mode = p[i]; 
            }
            if(counter == 1) 
            {  
                // if counter is ever 1 that means there is at least one new mode
                // because it only resets back to 1 when a new mode is detected 
                numMode++;
            }
        }
        else
        {
            if(counter >= freq)
            // the first run of the program will always assign freq to a number
            // if there is a higher frequency then it will change after 'X' runs
            {
                freq = counter + 1;
            }
            
            counter = 0;
            if(curFreq == 0)
            // if curFreq is never changed that means there is no mode    
            {
                mode = -1;
            }
        }
    }
    return freq;
}

int *mode(int p[], int *modes, int size)
{
    int mode, counter = 0, curFreq = 0, freq = 0, numMode = 0;
    int j = 0;
    mode = p[0];
    for(int i = 0; i < size; i++)
    {
        if(p[i] == p[i+1]) // checks if one element is equal to another
        {
            counter++; // counter is the frequency of that number appearing
            if(curFreq < counter) 
            // if curFreq is less than counter then curFreq is changed to the new freq
            { 
                curFreq = counter;
                // mode is assigned to the number in the element p[i]
                mode = p[i]; 
            }
            if(counter == 1) 
            {  
                // if counter is ever 1 that means there is at least one new mode
                // because it only resets back to 1 when a new mode is detected 
                numMode++;
                modes[2 + j] = p[i];
                j++;
            }
        }
        else
        {
            if(counter >= freq)
            // the first run of the program will always assign freq to a number
            // if there is a higher frequency then it will change after 'X' runs
            {
                freq = counter + 1;
            }
            
            counter = 0;
            if(curFreq == 0)
            // if curFreq is never changed that means there is no mode    
            {
                mode = -1;
            }
        }
    }
    modes[0] = numMode;
    modes[1] = freq;
    
    return modes;
}

void bubble(int *p, int size) // mean, median, mode problem
{
    for(int i = 0; i < size; i++) // passes array
    {
        int currMin = 999999999; int loc = -1;
        for(int j = i; j < size; j++) // finding min value
        {
            if(p[j] < currMin) // ascending order
            {
                loc = j;
                currMin = p[j];
            }
        }
        swap(p[i], p[loc]);
    }
}