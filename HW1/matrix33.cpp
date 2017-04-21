#include "matrix33.h"
#include<bits/stdc++.h>

	// v1, v2, v3 are column vectors 

	matrix33::matrix33(vector3 inv1, vector3 inv2, vector3 inv3){
		//this->set(inv1, inv2, inv3) ;
		v1 = inv1 ; v2 = inv2 ; v3 = inv3 ; 
	}

	matrix33::matrix33(const matrix33 &m){
		//this->.set(m.v1, m.v2, m.v3) ;
		v1 = m.v1 ; v2 = m.v2 ; v3 = m.v3 ;
	}

	void matrix33::set(vector3 _v1In, vector3 _v2In, vector3 _v3In){
		v1 = _v1In ;
		v2 = _v2In ;
		v3 = _v3In ;
	}	
	
	vector3& matrix33::operator  []  (unsigned int index)
	{
		if 	(index==0)
		{
			return 	v1 ;
		}
	
		else if (index==1)
		{
			return v2 ;
		}
	
		else if (index==2)
		{
			return v3 ;
		}
	}
	
 	const vector3& matrix33::operator []  (unsigned int index) const
	{
		if 	(index==0)
		{
			return v1 ;
		}
	
		else if (index==1)
		{
			return v2 ;
		}
	
		else if (index==2)
		{
			return v3 ;
		}
	}
			
	matrix33& matrix33::operator = (const matrix33 &m){
		//this->set(m.v1, m.v2, m.v3) ;
		v1 = m.v1 ; v2 = m.v2 ; v3 = m.v3 ;
		return *this ;
	}
	
	matrix33& matrix33::operator += (const matrix33 &m){
		return *this = *this + m ;
	}
	
	matrix33& matrix33::operator -= (const matrix33 &m){
		return *this = *this - m ;
	}

	matrix33& matrix33::operator *= (float f){
		return *this = *this * f ;
	}

	bool operator == (const matrix33 &a, const matrix33 &b){
		if ((a.v1 == b.v1) && (a.v2 == b.v2) && (a.v3 == b.v3))		return 1 ;
		else	return 0 ;
	}
	
	bool operator != (const matrix33 &a, const matrix33 &b){
		if ((a.v1 == b.v1) && (a.v2 == b.v2) && (a.v3 == b.v3))		return 0 ;
		else	return 1 ;
	}
	
//	matrix33 operator - (const matrix33 &a){
//		return m * (-1) ;
//	} 
	
	matrix33 operator + (const matrix33 &a, const matrix33 &b){
		//v1 = a.v1 + b.V1 ;
		//v2 = a.v2 + b.v2 ;
		//v3 = a.v3 + b.v3 ;
		//return *this ; 
		return matrix33(a.v1+b.v1 , a.v2+b.v2 , a.v3+b.v3) ;
	}
	
	matrix33 operator - (const matrix33 &a, const matrix33 &b){
		//v1 = a.v1 - b.V1 ;
		//v2 = a.v2 - b.v2 ;
		//v3 = a.v3 - b.v3 ;
		//return *this ;
		return matrix33(a.v1-b.v1 , a.v2-b.v2 , a.v3-b.v3) ;		
	}
	
	matrix33 operator * (const matrix33 &m, float f){
		return matrix33(m.v1*f, m.v2*f, m.v3*f) ;
	}
	
	matrix33 operator * (float f, const matrix33 &m){
		return matrix33(m.v1*f, m.v2*f, m.v3*f) ;
	}
	
	matrix33 operator / (const matrix33 &m, float f){
		return m * ( 1/f ) ;
	}
	
	matrix33 operator / (const matrix33 &a, const matrix33 &b){
		return a * b.invert() ;
	}
	
	matrix33 operator * (const matrix33 &_m1, const matrix33 &_m2)
	{
		return matrix33( (_m1.v1 * _m2.v1.x) + (_m1.v2 * _m2.v1.y) + (_m1.v3 * _m2.v1.z), 
						 (_m1.v1 * _m2.v2.x) + (_m1.v2 * _m2.v2.y) + (_m1.v3 * _m2.v2.z), 
						 (_m1.v1 * _m2.v3.x) + (_m1.v2 * _m2.v3.y) + (_m1.v3 * _m2.v3.z) ) ;
	}
	
	
	void matrix33::printMatrix() const{
//		for (int i=0 ; i<=2 ; i++){
//			for (int j=0 ; j<=2 ; j++){
//				std::cout << (*this)[i][j] << " " ;
//			}
//			std::cout << std::endl ;
//		}
		std::cout << v1.x << "  " << v2.x << "  " << v3.x << std::endl ;
		std::cout << v1.y << "  " << v2.y << "  " << v3.y << std::endl ;
		std::cout << v1.z << "  " << v2.z << "  " << v3.z << std::endl ;
	}
	
	void matrix33::identity(){
		v1.set(1,0,0);
		v2.set(0,1,0);
		v3.set(0,0,1);
	}
	
	float matrix33::determinant() const{
		return ( v1.x*v2.y*v3.z + v1.y*v2.z*v3.x + v1.z*v2.x*v3.y - v1.z*v2.y*v3.x - v1.y*v2.x*v3.z - v1.x*v2.z*v3.y ) ;
	}
	
	matrix33 matrix33::invert() const
	{
		if ( this->determinant() == 0.0)
		{
			std::cout << " Fail to calculate the inverse. " << std::endl ;
			return *this ;
		}
			matrix33 re ;
			re.v1.x = ( v2.y*v3.z - v2.z*v3.y ) ;
			re.v1.y = ( v1.z*v3.y - v1.y*v3.z ) ;
			re.v1.z = ( v1.y*v2.z - v1.z*v2.y ) ;
			re.v2.x = ( v2.z*v3.x - v2.x*v3.z ) ;
			re.v2.y = ( v1.x*v3.z - v1.z*v3.x ) ;
			re.v2.z = ( v1.z*v2.x - v1.x*v2.z ) ;
			re.v3.x = ( v2.x*v3.y - v2.y*v3.x ) ;
			re.v3.y = ( v1.y*v3.x - v1.x*v3.y ) ;
			re.v3.z = ( v1.x*v2.y - v1.y*v2.x ) ;	
			return re/this->determinant() ;	
		
	}
	

	
