#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"

class matrix33 
{  
public:
	/* data members */
	// v1, v2, v3 are column vectors 
	vector3 v1, v2, v3 ;

	//****************************************************//
	//  You need to implement the following functions !!  //
	//****************************************************//

public:
	/* constructors */
	// default constructor -- don't do anything with it
	matrix33() {};
	
	// constructor with initializing float values
	matrix33(vector3 inv1, vector3 inv2, vector3 inv3);
	
	// constructor with initializing matrix33
	matrix33(const matrix33 &m);

public:
	/* Operators */
	
	// access element
	vector3                  &operator  []  (unsigned int index);
	const vector3            &operator  []  (unsigned int index) const;
	
	matrix33               &operator  =   (const matrix33 &m);
	matrix33               &operator  +=  (const matrix33 &m);
	matrix33               &operator  -=  (const matrix33 &m);
	matrix33               &operator  *=  (float f);
	matrix33               &operator  /=  (float f);
	friend bool            operator   ==  (const matrix33 &a, const matrix33 &b);
	friend bool            operator   !=  (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator   -   (const matrix33 &a);
	friend matrix33        operator   +   (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator   -   (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator   *   (const matrix33 &m, float f);
	friend matrix33        operator   *   (float f, const matrix33 &m);
	friend matrix33        operator   /   (const matrix33 &m, float f);

	friend matrix33        operator   *   (const matrix33 &_m1, const matrix33 &_m2);
	
 public:
	 /* Methods */

	 // set values (e.g. x = xIn, ...)
	 void set(vector3 _v1In, vector3 _v2In, vector3 _v3In);

	  // print matrix using std::cout
	 void printMatrix() const ;
	 
	 void identity() ;
	 
	 matrix33 invert() const ;

	 float determinant() const;


};

#endif
