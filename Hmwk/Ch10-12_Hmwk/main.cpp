/* 
 * File:   main.cpp
 * Author: Tri Le
 * Ch.10-12 10 Hmwk Problems
 * Created on March 29, 2015, 2:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

//Function Prototypes
int wCountr(char *); //counts words in a string
float avgLett(char *); //gets average number of letters in a string
int vCountr(char *); //counts vowels in a string
int cCountr(char *); //counts consonants in a string

int main(int argc, char** argv) {

    const int SIZE = 100;
    char sent[SIZE];
    
    cout << "Enter a sentence: ";
    cin.getline(sent, SIZE);
    
    cout << "There are " << wCountr(sent) << " word(s) in this sentence." << endl;
    cout << "The average number of letters in each word is: " << avgLett(sent)
         << endl;
    cout << "There are " << vCountr(sent) << " vowels in this sentence." << endl;
    cout << "There are " << cCountr(sent) << " consonants in this sentence."
         << endl;   
    cout << "There are " << vCountr(sent) + cCountr(sent) << " letter in this"
            " sentence." << endl;
    return 0;
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
int vCountr(char *strPtr)
{
    int vowels = 0;
    while(*strPtr != '\0')
    {
        if(*strPtr == 'a' || *strPtr == 'e' || *strPtr == 'i' || 
           *strPtr == 'o' || *strPtr == 'u'){
            vowels++;
        }
        strPtr++;
    }
    return vowels;
}
int cCountr(char *strPtr)
{
    int consnts = 0;
    int space = 0;
    while(*strPtr != '\0')
    {
        if(*strPtr != 'a' || *strPtr != 'e' || *strPtr != 'i' || 
           *strPtr != 'o' || *strPtr != 'u'){
            consnts++;
        }
        if(*strPtr == ' ')
        {
            space++;
        }
        strPtr++;
    }
    return consnts - space;
}