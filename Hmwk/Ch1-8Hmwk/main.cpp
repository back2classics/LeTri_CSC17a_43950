/* 
 * File:   main.cpp
 * Author: Tri Le
 * Review Problems Ch. 1-8
 * Created on March 11, 2015, 3:17 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Function prototypes
void ch3_12();
void ch3_13();
void ch4_10();
void ch5_11();
void ch6_7();
float celsius(float); // Ch 6.7
void output(float[], float[], int); // Ch 6.7
void ch7_6(); 
int getTotal(int[], int); // Ch 7.6
float getAvg(int[], int); // Ch 7.6
void sort(int[], int); // Ch 7.6
void ch8_7();
void sortStr(string[], int); // Ch 8.7
int binary(string[], int, string); // Ch 8.7

int main(int argc, char** argv) {

    int choice;
    cout << "Enter [1] for Chapter 3.12: " << endl;
    cout << "Enter [2] for Chapter 3.13: " << endl;
    cout << "Enter [3] for Chapter 4.10: " << endl;
    cout << "Enter [4] for Chapter 5.11: " << endl;
    cout << "Enter [5] for Chapter 6.7: " << endl;
    cout << "Enter [6] for Chapter 7.6: " << endl;
    cout << "Enter [7] for Chapter 8.7: " << endl;
    do
    {
        cin >> choice;
        if(choice <= 0 || choice >= 8) // error checking for proper input
        {
            cout << "Invalid Input, enter again." << endl;
        }
    }while(choice <= 0 || choice >= 8);
    cout << endl;
    switch(choice)
    {
        case 1:
            cout << "This is from chapter 3, number 12: " << endl;
            ch3_12(); break;
        case 2:
            cout << "This is from chapter 3, number 13: " << endl;
            ch3_13(); break;
        case 3:
            cout << "This is from chapter 4, number 10: " << endl;
            ch4_10(); break;
        case 4: 
            cout << "This is from chapter 5, number 11: " << endl;
            ch5_11(); break;
        case 5:
            cout << "This is from chapter 6, number 7: " << endl;
            ch6_7(); break;
        case 6:
            cout << "This is from chapter 7, number 6: " << endl;
            ch7_6(); break;
        case 7:
            cout << "This is from chapter 8, number 7: " << endl;
            ch8_7(); break;
        default:
            cout << "Invalid input, enter again: " << endl;
    }
    return 0;
}
void ch3_12()
{
    string month;
    float total;
    cout << "What month is this tax collection for?: ";
    cin >> month;
    cout << "How much was collected during " << month << "?: ";
    cin >> total;
    float sales = total / 1.06; // sales after tax deduction
    float sp = sales + .005; // rounds to nearest half penny
    float totalTx = total - sp; // total tax of all sales(total - sales tax)
    // county tax is 1/3 of total tax, added half penny to round to nearest penny
    float county = (totalTx * 1/3) + .005;
    // state tax is 2/3 of total tax, added half penny to round to nearest penny
    float state = (totalTx * 2/3) + .005; // state tax is 2/3 of total tax
    
    cout << endl;
    cout << "Here are the results: " << endl;
    cout << "Month: " << month << endl;
    cout << "-----------------------" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Total Collected:       $ " << total << endl;
    cout << "Sales:                 $ " << sp << endl;
    cout << "County Sales Tax:      $ " << county << endl;
    cout << "State Sales Tax:       $ " << state << endl;
    cout << "Total Sales Tax:       $ " << totalTx << endl;
}
void ch3_13()
{
    // Chapter 3 - #13
    float value; // actual value of piece of land
    cout << "Enter the value of the piece of land: $ ";
    cin >> value;
    cout << endl;
    cout << "Here is the assessment of the land: " << endl;
    float assess = value * .6; // assessment value of the land
    cout << "The assessment value of the land is: $ " << assess << endl; 
    float counter = assess/100.0; // used to determine how
    // many 100's there are in assess so property tax can be calculated
    float tax = counter * .64; // property tax of the land
    cout << "The property tax of this piece of land is $ " << tax << endl;
}
void ch4_10()
{
    // Chapter 4 - #10
    int units; // number of units sold
    float discount = 0; // discount applied to profits
    float final = 0; // final amount of profits gained after discount
    do
    {
        cout << "How many units were purchased?: ";
        cin >> units;
        if(units <= 0) // error checking 
        {
            cout << "Invalid input. Enter a number greater than zero." << endl;
        }
        cout << endl;
    }
    while(units <= 0);
    
    int costs = units * 99; // profits of the units sold
    if(units >= 10 && units <= 19) // 10-19 units
    {
        discount = static_cast<float>(costs) * .2; // 20%
        final = static_cast<float>(costs) - discount;
    }
    else if(units >= 20 && units <= 49) // 20-49 units
    {
        discount = static_cast<float>(costs) * .3; // 30%
        final = costs - discount;
    } 
    else if(units >= 50 && units <= 99) // 50-99 units
    {
        discount = static_cast<float>(costs) * .4; // 40%
        final = costs - discount;
    }
    else // 100+ units
    {
        discount = static_cast<float>(costs) * .5; // 50%
        final = costs - discount;
    }
    cout << "The number of units sold was: " << units << endl;
    cout << "The cost was: $ " << costs << endl;
    cout << "The discount of the sales was: $ " << costs - final << endl;
    cout << "The total amount after the discount is: $ " << final << endl;
}
void ch5_11()
{
    int start = 0; // starting number of organisms
    float mating = 0; // average of daily population increase (as a percentage)
    int days = 0; // number of days organisms will multiply
    float newPop = 0; // current size of the population after X amount of days
    float total = 0; // final size of the population after multiplying
    
    do
    {
        cout << "Enter the starting number of organisms: ";
        cin >> start;
        if(start < 2) // error checking 
        {
            cout << "Invalid number of starting organisms. Enter a number greater"
                    " than 2." << endl;
        }
        cout << endl;
    }while(start < 2);
    
    do
    {
        cout << "Enter their average of daily population increase "
                "(as a percentage): ";
        cin >> mating;
        if(mating <= 0) // error checking
        {
            cout << "Invalid input. Cannot accept zero or negative"
                    " percentages." << endl;
        }
        cout << endl;
    }while(mating <= 0);
    
    do
    {
        cout << "Enter the numbers of days the organisms will multiply: ";
        cin >> days;
        if(days < 1) // error checking
        {
            cout << "Invalid input. The number of days has to be larger than"
                    " 1." << endl;
        }
        cout << endl;
    }while(days < 1);
    // newPop = the first day of multiplying - mating/100 represents the percentage
    // the user inputted converted to a real percentage. i.e if the user inputted
    // 10 as 'mating' the percentage would be .1 which = 10%
    newPop = start + (static_cast<float>(start) * (mating/100));
    cout << "Day 1: " << newPop << endl;
    for(int i = 2; i <= days; i++) // for Day 2 and onward
    {
        // total is all of newPop after each day
        total = newPop + (static_cast<float>(newPop) * (mating/100)); 
        cout << "Day " << i << ": ";
        cout << total << endl;
        newPop = total; // saves current population so it is not reset when the
                        // for loop iterates
    }
}
void ch6_7()
{
    // forumla for celsius = 5/9(F-32)
    float fahren;
    const int SIZE = 20;
    cout << "Enter a temperate in degrees Fahrenheit: ";
    cin >> fahren;
    cout << "This is the temperature converted to Celsius: " <<  celsius(fahren)
         << endl;
    float degreeF[SIZE]; 
    float degreeC[SIZE];
    cout << "Fahrenheit   to   Celsius: " << endl;
    output(degreeF, degreeC, SIZE); // chart of F to C degrees from 0 to 20
}
float celsius(float fahren) // Ch 6.7
{
    float celsius = (5.0/9) * static_cast<float>((fahren - 32));
    return celsius;
}
void output(float array[], float array2[], int SIZE) // Ch 6.7
{
    for(int i = 0; i <= SIZE; i++)
    {
        array[i] = i;
        array2[i] = celsius(i);
        cout << array[i] << "                 " << array2[i] << endl;
    }
}
void ch7_6()
{
    // Ch 7.6
    const int SIZE = 10;
    int numbers[SIZE];
    int total = 0, average = 0;
    ifstream infile;
    infile.open("data.dat.txt"); // OPEN
    int num;
    for(int i = 0; i < SIZE; i++)
    {
        infile >> num; // infiling to num
        numbers[i] = num; 
    }
    infile.close(); // CLOSE
    sort(numbers, SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    cout << "The highest number is: " << numbers[9] << endl;
    cout << "The lowest number is: " << numbers[0] << endl;
    cout << "The total of all numbers is: " << getTotal(numbers, SIZE) << endl;
    cout << "The average of all the numbers is: " << getAvg(numbers, SIZE) << endl;
}
void sort(int array[], int SIZE) // Ch 7.6
{
    // selection sort
    for(int i = 0; i < SIZE; i++) // passes array
    {
        int currMin = 999999999; int loc = -1;
        for(int j = i; j < SIZE; j++) // finding min value
        {
            if(array[j] < currMin) // ascending order
            {
                loc = j;
                currMin = array[j];
            }
        }
        swap(array[i], array[loc]);
    }
}
int getTotal(int array[], int SIZE) // Ch 7.6
{
    // total of the contents in the array
    int sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sum += array[i];
    }
    return sum;
}
float getAvg(int array[], int SIZE) // Ch 7.6
{
    // average value of the contents in the array
    float avg = 0;
    int sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sum += array[i];
    }
    avg = static_cast<float>(sum) / SIZE;
    return avg;
}
void ch8_7()
{
    cout << endl;
    const int SIZE = 20;
    // set of names from the book to be used for this problem
    string names[SIZE] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                          "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                          "Taylor, Terri", "Johnson, Jill",
                          "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                          "James, Jean", "Weaver, Jim", "Pore, Bob",
                          "Rutherford, Greg", "Javens, Renee",
                          "Harrison, Rose", "Setzer, Cathy",
                          "Pike, Gordon", "Holland, Beth" };
    cout << "Here are the names you can choose to search for: " << endl;
    for(int i = 0; i < SIZE; i++) // shows names so user can select which to find
    {
        cout << names[i] << " | ";
    }
    cout << endl;
    cout << endl;
    sortStr(names, SIZE); // sorts alphabetically by last name
    cout << "Enter the name you are trying to find: ";
    string find;
    cin.ignore();
    getline(cin, find);
    cout << endl;
    cout << "The location of the name is: " << binary(names, SIZE, find) << endl;
    cout << endl;
    cout << "Here are all of the names, sorted alphabetically, by last names: "
         << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << names[i] << " | ";
    }
    cout << endl;
}
void sortStr(string array[], int SIZE) // Ch 8.7
{
    for(int i = 0; i < SIZE - 1; i++)
    {
        for(int j = i + 1; j < SIZE; j++)
        {
            if(array[i] > array[j])
            {
                swap(array[i], array[j]);
            }
        }
    }
}
int binary(string array[], int SIZE, string find) // Ch 8.7
{
    // binary search algorithm stated in the book to be used for this problem
    int first = 0, 
        last = SIZE - 1, 
        middle, 
        position = -1; 
    bool found = false; 
 
    while (!found && first <= last)
    {
       middle = (first + last) / 2; 
       if (array[middle] == find) 
       {
           found = true;
           position = middle;
       }
       else if (array[middle] > find) 
           last = middle - 1;
       else
           first = middle + 1; 
    }
 return position;
}





