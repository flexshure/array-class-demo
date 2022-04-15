#include <iostream>
#include <iomanip>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

//template <typename T>
class Array
{
	friend std::ostream &operator<<( std::ostream &output, const Array &a )
	{
		// output private ptr-based array 
		for ( size_t i = 0; i < a.size; ++i )
		{
			output << setw( 12 ) << a.ptr[ i ];

			if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
				output << endl;
		} // end for

		if ( a.size % 4 != 0 ) // end last line of output
			output << endl;

		return output; // enables cout << x << y;
	}

	friend std::istream &operator>>( std::istream &input, Array &a )
	{
		for ( size_t i = 0; i < a.size; ++i )
			input >> a.ptr[ i ];

		return input; // enables cin >> x >> y;
	}

public:
	explicit Array( int arraySize = 10 )
		: size( arraySize > 0 ? arraySize : 
			throw invalid_argument( "Array size must be greater than 0" ) ),
		  ptr( new int[ size ] )
	{

		//cout << "INSIDE (int) CONSTRUCTOR...\n\n";

		for ( size_t i = 0; i < size; ++i )
			ptr[ i ] = 0; // set pointer-based array element
	}

	Array( const Array &arrayToCopy ) // copy constructor
		: size( arrayToCopy.size ),
		  ptr( new int[ size ] )
	{
		//cout << "INSIDE COPY CONSTRUCTOR...\n\n";

		for ( size_t i = 0; i < size; ++i )
			ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
	}

	~Array() // destructor
	{
		//cout << "INSIDE DESTRUCTOR...\n\n";
		delete [] ptr; // release pointer-based array space
	}

	size_t getSize() const { return size; } // return size

	const Array &operator=( const Array &right ) // assignment operator
	{
		//cout << "INSIDE ASSIGNMENT OPERATOR...\n\n";

		if (&right != this) // avoid self-assignment
		{
			cout << "NO SELF ASSIGNMENT\n\n";

			// for Arrays of different sizes, deallocate original
			// left-side Array, then allocate new left-side Array
			if (size != right.size)
			{
				delete[] ptr; // release space
				size = right.size; // resize this object
				ptr = new int[size]; // create space for Array copy
			} // end inner if

			for (size_t i = 0; i < size; ++i)
				ptr[i] = right.ptr[i]; // copy array into object
		} // end outer if

		else
			cout << "SELF ASSIGNMENT WAS ATTEMPTED!\n\n";

		return *this; // enables x = y = z, for example	
	}

	bool operator==( const Array &right) const // equality operator
	{
		if ( size != right.size )
			return false; // arrays of different number of elements

		for ( size_t i = 0; i < size; ++i )
			if ( ptr[ i ] != right.ptr[ i ] )
				return false; // Array contents are not equal

		return true; // Arrays are equal
	}

	// inequality operator; returns opposite of == operator
	bool operator!=( const Array &right ) const  
	{ 
		return ! ( *this == right ); // invokes Array::operator==
	} // end function operator!=
	

	// subscript operator for non-const objects returns modifiable lvalue
	int &operator[]( int subscript )
	{

		//cout << "INSIDE OF NON-CONST OPERATOR[]\n\n";

		// check for subscript out-of-range error
		if ( subscript < 0 || subscript >= size )
			throw out_of_range( "Subscript out of range" );

		return ptr[ subscript ]; // reference return
	}             

	// subscript operator for const objects returns rvalue
	int operator[]( int subscript ) const
	{

		//cout << "INSIDE OF CONST OPERATOR[]\n\n";

		// check for subscript out-of-range error
		if ( subscript < 0 || subscript >= size )
			throw out_of_range( "Subscript out of range" );

		return ptr[ subscript ]; // returns copy of this element
	}

private:
	size_t size; // pointer-based array size
	int *ptr; // pointer to first element of pointer-based array
}; // end class Array

#endif