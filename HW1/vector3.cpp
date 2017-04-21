#include "vector3.h"
#include<bits/stdc++.h>
using namespace std ;
vector3::vector3(float inX, float inY, float inZ){
	this->set(inX, inY, inZ) ;
	/*
	x = inX ;
	y = inY ;
	z = inZ ;
	*/
}

vector3::vector3(const vector3 &v){
	this->set(v.x, v.y, v.z) ;
	/*
	x = v.x ;
	y = v.y ;
	z = v.z ;
	*/
}

void vector3::set(float xIn, float yIn, float zIn){
	x = xIn ; y = yIn ; z = zIn ;
}

float vector3::length() const{
	sqrt( pow(x, 2) + pow(y, 2) + pow(z, 2) ) ;
}

void vector3::printVector3() const{
	cout << "(" << x << ", " << y << ", " << z << ")" << endl ;
}

float& vector3::operator [] (unsigned int index){
	if 		(index == 0) return x ;
	else if (index == 1) return y ;
	else if (index == 2) return z ;
}

const float& vector3::operator [] (unsigned int index) const{
	if 		(index == 0) return x ;
	else if (index == 1) return y ;
	else if (index == 2) return z ;
}
	
vector3& vector3::operator = (const vector3 &v){
	/*	
		x = v.x ; 
		y = v.y ; 
		z = v.z ;
	*/
	this->set(v.x, v.y, v.z) ;
	return *this ;
}

// 		¡õ	since "+"  "-"  "*"  "/"  "="   had been defined,    
 
vector3& vector3::operator += (const vector3 &v){
	return *this = *this + v ;
	/*
	x = x + v.x ;
	y = y + v.y ;
 	z = z + v.z ;
	*/
}

vector3& vector3::operator -= (const vector3 &v){
	return *this = *this - v ;
}

vector3& vector3::operator *= (float f){
	return *this = *this * f ;
}

vector3& vector3::operator /= (float f){
	return *this = *this * ( 1/f ) ;
}

bool operator == (const vector3 &a, const vector3 &b){
	if ( (a.x == b.x) && (a.y == b.y) && (a.z == b.z) )	return 1 ;
	else	return 0;
}

bool operator != (const vector3 &a, const vector3 &b){
	if ( (a.x == b.x) && (a.y == b.y) && (a.z == b.z) )	return 0 ;
	else	return 1;	
}

vector3 operator - (const vector3 &a){
	 vector3 vec_2;
	 vec_2 = a * (-1) ;
	 return vec_2 ; 
}

vector3 operator + (const vector3 &a, const vector3 &b){
	vector3 vec_2;
	vec_2.x = a.x + b.x ; 
	vec_2.y = a.y + b.y ;
	vec_2.z = a.z + b.z ;
	return vec_2 ;
	
}

vector3 operator - (const vector3 &a, const vector3 &b){
	vector3 vec_2;
	vec_2.x = a.x - b.x ; 
	vec_2.y = a.y - b.y ;
	vec_2.z = a.z - b.z ;
	return vec_2 ;	
}

vector3 operator * (const vector3 &v, float f){
	vector3 vec_2;
	vec_2.x = v.x * f ; 
	vec_2.y = v.y * f ;
	vec_2.z = v.z * f ;
	return vec_2 ;	
}

vector3 operator * (float f, const vector3 &v){
	vector3 vec_2;
	vec_2.x = v.x * f ; 
	vec_2.y = v.y * f ;
	vec_2.z = v.z * f ;
	return vec_2 ;	
}

vector3 operator / (const vector3 &v, float f){
	return v * ( 1/f ) ;
}
