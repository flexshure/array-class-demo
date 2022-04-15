// Array class test program.
#include <iostream>
#include <stdexcept>
#include "fletcher_dube_Array.h"
using namespace std;

int main()
{
	
	// This block of code is safe because with a deep copy
	// we make a true copy of the data -- i.e., we dynamically 
	// allocate an array that's the same size as the other object's array
	// and copy the elements over. So unlike the shallow copy version, there are never multiple
	// pointers to the same dynamically allocated array.
	
	{
		Array int1(5);
		Array int2(6);
		int1 = int2; 
	    Array int3(int1);
	}

	cout << "\n-----------\n";


	{
		Array *ptr = new Array[2]{ Array(2), Array(2) };
	
		
		
		
		//	Array **ptr2 = new Array*[2];


		ptr[0][0] = 15;
		ptr[1][0] = 20;

		cout << "BEFORE DELETE[] PTR\n\n";

		
		delete[] ptr;
		cout << "AFTER DELETE[] PTR\n\n";
	}

	const Array numbers(7);


	cout << numbers[0];

	Array newarr[5];

	newarr[0].operator[](0) = 5;

	cout << newarr[0][0];

	//delete[] newarr;



	/*
	{
		Array *ptr = new Array[5];
		Array nums(5);

		delete[] ptr;
	} */



   Array integers1( 7 ); // seven-element Array
   Array integers2; // 10-element Array by default

   integers1.operator[](0) = 15;

   cout << integers1[0] << endl;

   // print integers1 size and contents
   cout << "Size of Array integers1 is " 
      << integers1.getSize()
      << "\nArray after initialization:\n" << integers1;

   // print integers2 size and contents
   cout << "\nSize of Array integers2 is " 
      << integers2.getSize()
      << "\nArray after initialization:\n" << integers2;

   // input and print integers1 and integers2
   cout << "\nEnter 17 integers:" << endl;
   cin >> integers1 >> integers2;

   cout << "\nAfter input, the Arrays contain:\n"
      << "integers1:\n" << integers1
      << "integers2:\n" << integers2;

   // use overloaded inequality (!=) operator
   cout << "\nEvaluating: integers1 != integers2" << endl;

   if ( integers1 != integers2 )
      cout << "integers1 and integers2 are not equal" << endl;

   // create Array integers3 using integers1 as an
   // initializer; print size and contents
   Array integers3( integers1 ); // invokes copy constructor

   cout << "\nSize of Array integers3 is "
      << integers3.getSize()
      << "\nArray after initialization:\n" << integers3;

   // use overloaded assignment (=) operator
   cout << "\nAssigning integers2 to integers1:" << endl;
   integers1 = integers2; // note target Array is smaller

   cout << "integers1:\n" << integers1
      << "integers2:\n" << integers2;

   // use overloaded equality (==) operator
   cout << "\nEvaluating: integers1 == integers2" << endl;

   if ( integers1 == integers2 )
      cout << "integers1 and integers2 are equal" << endl;

   // use overloaded subscript operator to create rvalue
   cout << "\nintegers1[5] is " << integers1[ 5 ];

   // use overloaded subscript operator to create lvalue
   cout << "\n\nAssigning 1000 to integers1[5]" << endl;
   integers1[ 5 ] = 1000;
   cout << "integers1:\n" << integers1[5];
   cout << "integers2:\n" << integers2[5];

   // attempt to use out-of-range subscript
   try                                                               
   {                                                                 
      cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
      integers1[ 15 ] = 1000; // ERROR: subscript out of range
   } // end try                                                      
   catch ( out_of_range &ex )                                        
   {                                                                 
      cout << "An exception occurred: " << ex.what() << endl;        
   } // end catch

   system("PAUSE");
   return 0;
} // end main
