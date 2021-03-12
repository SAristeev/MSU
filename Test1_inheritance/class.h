#pragma once 
#include<iostream>
#include<exception>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;


// ==== Class ComplexNumber ========


class CVector{
protected:
	vector<double> v;
public:
	CVector(){}
	CVector(const int &n){v.resize(n);}
	CVector(const vector<double> rhs, const int &n){CopyOnly(rhs,n);}
	CVector(const vector<double> rhs){CopyOnly(rhs);}
	CVector(const CVector &rhs){CopyOnly(rhs);}
	CVector(CVector &&rhs){v=rhs.v;rhs.Clean();}

	size_t Size()const{return v.size();}
	virtual ~CVector(){Clean();}

	virtual bool low(double rhs){if(abs(rhs)<1e-9) return true; else return false;}
	void Low(){for(size_t i=0; i<v.size(); i++){if(low(v[i])) v[i]=0;}}

	void show();

	CVector &operator=(const CVector &rhs){if(this!=&rhs){Clean();CopyOnly(rhs);} return *this;}
	CVector &operator=(const vector<double> rhs){CopyOnly(rhs); return *this;}
	CVector &operator=(CVector &&rhs){if(this!=&rhs){v.clear();v=rhs.v;rhs.Clean();} return *this;}

	double &operator[](size_t i)const{return const_cast<double&>(v[i]);}

	void Set(double rhs, size_t i){v[i]=rhs;}

	void Clean(){v.clear();}
	void CopyOnly(const CVector &rhs){if(this!=&rhs){v.insert(v.begin(),rhs.v.begin(),rhs.v.end());}}
	void CopyOnly(const vector<double> rhs, const int &n){v.insert(v.begin(),rhs.begin(),rhs.begin()+n);}
	void CopyOnly(const vector<double> rhs){v.insert(v.begin(),rhs.begin(),rhs.end());}
};


// ==== First Child Class CComplexVector2 ========


class CVector1 : public CVector{
public:
	CVector1(): CVector(){};
	CVector1(const int &n): CVector(n){};
	CVector1(const vector<double> rhs, const int &n){CopyOnly(rhs,n);}
	CVector1(const vector<double> rhs){CopyOnly(rhs);}
	CVector1(const CVector1 &rhs): CVector(rhs){}

	virtual bool low(double rhs){if(abs(rhs)<1e-6) return true; else return false;}
	CVector &operator=(const CVector &rhs){if(this!=&rhs){Clean();CopyOnly(rhs);} return *this;}
	CVector &operator=(const vector<double> rhs){Clean();CopyOnly(rhs); return *this;}
};

CVector operator+(const CVector &lhs, const CVector &rhs);


