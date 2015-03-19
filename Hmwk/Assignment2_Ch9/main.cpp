/* 
 * File:   main.cpp
 * Author: Tri Le
 * Assignment 2 - Chapter 9
 * Created on March 14, 2015, 8:23 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

// Function Prototypes
int *create(int); // 1.
int *create2(int); // 2.
int *calcTest(int *, int, int); // 2. 
void output2(int *, int); // 2.
void sort2(int *, int); // 2. && 3.
int doSomething(int*, int*); // 5.
int *create6(int); // 6.
void sort7(int *, int); // 7.
void output7(int *, int); // 7.
int mode8(int *, int); // 8.
float median(int *, int); // mean, median, mode problem
void number1();
void number2(); // 2/3
void number5();
void number6(); // 6/7/8/9
int numMode(int[], int);
int *mode(int[], int*, int);
float mean(int[], int); // mean, median, mode problem
void bubble(int *, int); // mean, median, mode problem
void number10(); // mean, median, mode problem

int main(int argc, char** argv) {

    int choice;
    cout << "Enter [1] for Problem 1: " << endl;
    cout << "Enter [2] for Problem 2/3: " << endl;
    cout << "Enter [3] for Problem 5: " << endl;
    cout << "Enter [4] for Problem 6/7/8/9: " << endl;
    cout << "Enter [5] for the Mean/Median/Mode Problem: " << endl;
    do
    {
        cin >> choice;
        if(choice <= 0 || choice >= 6) // error checking for proper input
        {
            cout << "Invalid Input, enter again." << endl;
        }
    }while(choice <= 0 || choice >= 6);
    cout << endl;
    switch(choice)
    {
        case 1:
            cout << "This is problem number 1: " << endl;
            number1(); break;
        case 2:
            cout << "This is problem numbers 2 and 3: " << endl;
            number2(); break;
        case 3:
            cout << "This is problem number 5: " << endl;
            number5(); break;
        case 4: 
            cout << "This is problem numbers 6,7,8, and 9: " << endl;
            number6(); break;
        case 5:
            cout << "This is the mean, median, and mode problem: " << endl;
            number10(); break;
        default:
            cout << "Invalid input, enter again: " << endl;
    }
    
    return 0;
}
int *create(int num) // 1.
{
    int *ptr;
    ptr = new int[num];
    return ptr;
}
int *create2(int num) // 2.
{
    int *test;
    test = new int[num];
    cout << "Enter the test scores: " << endl;
    for(int i = 0; i < num; i++)
    {
        cout << "Test " << (i + 1) << ": ";
        cin >> *(test + i);
        if(*(test + i) < 0)
        {
            cout << "Invalid. Negative numbers cannot be inputted." << endl;
            i--;
        }
    }
    return test;
}
int *calcTest(int *p, int scores, int total) // 2.
{
    float avg;
    for(int i = 0; i < scores; i++)
    {
        total += *(p + i);
    }
    avg = static_cast<float>(total) / (scores - 1); // -1 = dropped test score
    cout << "The average of the scores is: " << avg << endl;
    return p;
}
void output2(int *p, int size) // 2.
{
    cout << "Here are the test scores in ascending order, where 0"
            " represents the dropped test score(lowest): " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << *(p + i) << endl;
    }
    cout << endl;
}
void sort2(int *p, int size) // 2. && 3.
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
    p[0] = 0; // drops lowest test score
}
int doSomething(int *x, int *y) // 5.
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}
int *create6(int num) // 6.
{
    int *donate;
    donate = new int[num];
    cout << "Enter the amount to be donated: " << endl;
    for(int i = 0; i < num; i++)
    {
        cin >> *(donate + i);
    }
    return donate;
}
void sort7(int *p, int size) // 7.
{
    for(int i = 0; i < size; i++) // passes array
    {
        int currMin = 0; int loc = -1;
        for(int j = i; j < size; j++) // finding min value
        {
            if(p[j] > currMin) // descending order
            {
                loc = j;
                currMin = p[j];
            }
        }
        swap(p[i], p[loc]);
    }
}
void output7(int *p, int size) // 7.
{
    cout << "Here are the donations in descending order: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << *(p + i) << endl;
    }
    cout << endl;
}
int mode8(int *p, int size) // 8.
{
    int mode, counter = 0, currMode = 0;
    mode = *(p + 0);
    for(int i = 0; i < size; i++)
    {
        if(*(p + i) == *(p + i + 1))
        {
            counter++;
            if(currMode < counter)
            {
                currMode = counter;
                mode = *(p + i);
            }
        }
        else
        {
            counter = 0;
            if(currMode == 0)
            {
                mode = -1;
            }
        }
    }
    return mode;
}
float median(int *p, int size) // 9.
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
void number1()
{
    // Number 1
    int size1;
    cout << "Enter the size of the array to be created: ";
    cin >> size1;
    int *pArray = create(size1);
    delete [] pArray;
    pArray = 0;
}
void number2() 
{
    // Number 2
    int *pTest, size2, // pTest = dynamic array of test scores
    total = 0; // total is placeholder value 
    cout << "Enter the number of test scores: ";
    cin >> size2;
    pTest = create2(size2); // pointer assigned to function that creates test array
    // Number 3(Part of Number 2)
    sort2(pTest, size2); // sorts the array in ascending order and drops lowest score
    calcTest(pTest, size2, total);
    output2(pTest, size2); // outputs # of test and scores
    delete [] pTest; // frees memory space of pTest
    pTest = 0;
}
void number5()
{
    // Number 5
    int num1, num2;
    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;
    int *x = &num1, *y = &num2;
    cout << "The numbers you have entered have both been"
            " multiplied by 10 and added together." << endl;
    cout << "Here are the results: " << doSomething(x,y) << endl;
}
void number6()
{
    // Number 6
    int *pDonate, size6; // pDonate = dynamic array of donations
    cout << "How many donations do you want to make? : ";
    cin >> size6;
    pDonate = create6(size6); // creates donations array
    
    // Number 7
    sort7(pDonate, size6); // sorts the donations from descending order
    output7(pDonate, size6); // outputs donations
    
    // Number 8 - finds the mode of the donations
    cout << "The mode of the donations is: " << mode8(pDonate, size6) << endl;
    
    // Number 9 - finds the median of the donations
    cout << "The median of the donations is: " << median(pDonate, size6) << endl;
    delete [] pDonate;
    pDonate = 0;
}
int numMode(int p[], int SIZE) 
{
    int mode, counter = 0, curFreq = 0, freq = 0, numMode = 0;
    
    mode = p[0];
    for(int i = 0; i < SIZE; i++)
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
int *mode(int p[], int *modes, int SIZE)
{
    int mode, counter = 0, curFreq = 0, freq = 0, numMode = 0;
    int j = 0;
    mode = p[0];
    for(int i = 0; i < SIZE; i++)
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
float mean(int array[], int SIZE) // Ch 7.6
{
    // average value of the contents in the array
    float mean = 0;
    int sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sum += array[i];
    }
    mean = static_cast<float>(sum) / SIZE;
    return mean;
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
void number10() // median, mean, mode problem
{
    const int SIZE = 15;
    // unsorted array w/ repeating elements
    int array[SIZE] = {3,2,4,1,3,6,4,2,6,4,6,3,6,6,4}; 
    bubble(array, SIZE); // sorts the array
    cout << "Here is the array: " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "The mean of the array is: " << mean(array, SIZE) << endl;
    cout << "The median of the array is: " << median(array, SIZE) << endl;
    // val represents the number of modes for the dynamically allocated array
    int val; 
    val = numMode(array, SIZE);
    int *modes = new int[val + 2]; // num modes + 2
    mode(array, modes, SIZE);
    cout << "Here is the array with the number of modes, max frequency, and X"
            " amount of modes. The array is read from left to right." << endl;
    for(int i = 0; i < val + 2; i++)
    {
        cout << modes[i] << " ";
    }
    cout << endl;
    // deallocates the array
    delete [] modes;
}


