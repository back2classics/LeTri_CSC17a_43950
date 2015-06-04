/* 
 * File: VectorFileIO.h
 * Author: Gaddis, borrowed from Ch. 16 
 *
 * Created on June 4, 2015, 2:27 PM
 */

#ifndef VECTORFILEIO_H
#define	VECTORFILEIO_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class VectorFileIO
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   VectorFileIO()
   { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   VectorFileIO(int);
   
   // Copy constructor declaration
   VectorFileIO(const VectorFileIO &);
   
   // Destructor declaration
   ~VectorFileIO();
   
   // Accessor to return the array size
   int size() const
   { return arraySize; }
   
   // Push the new value onto the array
   void push(T);

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
};

//Constructor
template <class T>
VectorFileIO<T>::VectorFileIO(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch(bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++){
       *(aptr + count) = 0;
   }
}
//Copy constructor
template <class T>
VectorFileIO<T>::VectorFileIO(const VectorFileIO &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0){
       memError();
   }
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++){
       *(aptr + count) = *(obj.aptr + count);
   }
}
//Push for vector
template <class T>
void VectorFileIO<T>::push(T value)
{
   // New Size
   int newSize = arraySize + 1;
   
   // Allocate memory for the array.
   T* newaptr = new T [newSize];
   if (newaptr == 0){
       memError();
   }  
   // Copy the elements of the old into the new
   for(int count = 0; count < arraySize; count++){
       *(newaptr + count) = *(aptr + count);
   }
   *(newaptr + arraySize)=value;
      
   //Deallocate and Transfer variables
      delete []aptr;
      aptr=newaptr;
      arraySize=newSize;
}
//Destructor
template <class T>
VectorFileIO<T>::~VectorFileIO()
{
   if (arraySize > 0){
       delete [] aptr;
   }
}
//Detects memory error
template <class T>
void VectorFileIO<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}
//Detects subscript error
template <class T>
void VectorFileIO<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}
//Returns value at subscript in vector
template <class T>
T VectorFileIO<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize){
       subError();
   }
   return aptr[sub];
}
//Returns reference of the vector subscript
template <class T>
T &VectorFileIO<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize){
       subError();
   }
   return aptr[sub];
}

#endif	/* VECTORFILEIO_H */

