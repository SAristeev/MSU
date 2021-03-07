#pragma once 
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
class CFabricVector;


// ==== Class ComplexNumber ========


class ComplexNumber{
	double Re, Im;
public:
	ComplexNumber(){Re=0; Im=0;}
	ComplexNumber(double x){Re=x; Im=0;}
	ComplexNumber(double Re, double Im){this->Re=Re; this->Im=Im;}
	double GetRe() const {return Re;}
	double GetIm() const {return Im;}
	void SetRe(double Re) {this->Re=Re;}
	void SetIm(double Im) {this->Im=Im;}
	ComplexNumber operator+(const ComplexNumber &x) {ComplexNumber result; result.Re=Re+x.Re; result.Im=Im+x.Im; return result;}
	ComplexNumber operator+(const double &x) {ComplexNumber result; result.Re=Re+x; result.Im=Im; return result;}
	ComplexNumber operator+(const int &x) {ComplexNumber result; result.Re=Re+x; result.Im=Im; return result;}
	ComplexNumber operator-(const ComplexNumber &x) {ComplexNumber result; result.Re=Re-x.Re; result.Im=Im-x.Im; return result;}
	ComplexNumber operator-(const double &x) {ComplexNumber result; result.Re=Re-x; result.Im=Im; return result;}
	ComplexNumber operator-(const int &x) {ComplexNumber result; result.Re=Re-x; result.Im=Im; return result;}
	ComplexNumber operator*(const ComplexNumber &x) {ComplexNumber result; result.Re=Re*x.Re-Im*x.Im; result.Im=Im*x.Re+Re*x.Im; return result;}
	ComplexNumber operator*(const double &x) {ComplexNumber result; result.Re=Re*x; result.Im=Im*x; return result;}
	ComplexNumber operator*(const int &x) {ComplexNumber result; result.Re=Re*x; result.Im=Im*x; return result;}
	void Conjugation(){Im=-Im;}
	friend ostream &operator<<(ostream &stream, const ComplexNumber &number);
	friend istream &operator>>(istream &stream, ComplexNumber &number);
};

ComplexNumber operator+(const int &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const int &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const int &lhs, const ComplexNumber &rhs);

ComplexNumber operator+(const double &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const double &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const double &lhs, const ComplexNumber &rhs);


// ==== Base Class CComplexVector ========


class CComplexVector{
protected:
	vector<ComplexNumber> v;
public:
	
	CComplexVector(){}
	CComplexVector(const int &n){v.resize(n);}
	CComplexVector(const vector<ComplexNumber> rhs, const int &n){CopyOnly(rhs,n);}
	CComplexVector(const vector<ComplexNumber> rhs){CopyOnly(rhs);}
	CComplexVector(const CComplexVector &rhs){CopyOnly(rhs);}
	CComplexVector(CComplexVector &&rhs){v=rhs.v;rhs.Clean();}

	size_t Size(){return v.size();}
	//static CComplexVector *create(int Type, const ComplexNumber *b, const int &nn);
	virtual ~CComplexVector(){Clean();}
	virtual void show(const string sf)=0;

	CComplexVector &operator=(const CComplexVector &rhs){if(this!=&rhs){Clean();CopyOnly(rhs);} return *this;}
	CComplexVector &operator=(const vector<ComplexNumber> rhs){CopyOnly(rhs); return *this;}
	CComplexVector &operator=(CComplexVector &&rhs){if(this!=&rhs){v.clear();v=rhs.v;rhs.Clean();} return *this;}

	ComplexNumber &operator[](size_t i){return v[i];}

	void Conjugation(){for(size_t i=0;i<v.size();i++)v[i].Conjugation();}
	void Set(ComplexNumber rhs, int i){v[i]=rhs;}

	void Clean(){v.clear();}
	void CopyOnly(const CComplexVector &rhs){if(this!=&rhs){v.insert(v.begin(),rhs.v.begin(),rhs.v.end());}}
	void CopyOnly(const vector<ComplexNumber> rhs, const int &n){v.insert(v.begin(),rhs.begin(),rhs.begin()+n);}
	void CopyOnly(const vector<ComplexNumber> rhs){v.insert(v.begin(),rhs.begin(),rhs.end());}
};


// ==== First Child Class CComplexVector1 ========


class CComplexVector1 : public CComplexVector{
public:
	CComplexVector1(): CComplexVector(){};
	CComplexVector1(const int &n): CComplexVector(n){};
	CComplexVector1(const vector<ComplexNumber> rhs, const int &n){CopyOnly(rhs,n);}
	CComplexVector1(const CComplexVector1 &rhs): CComplexVector(rhs){}

	CComplexVector &operator=(const CComplexVector &rhs){if(this!=&rhs){Clean();CopyOnly(rhs);} return *this;}
	CComplexVector &operator=(const vector<ComplexNumber> rhs){CopyOnly(rhs); return *this;}

	virtual void show(const string sf);
};


// ==== Second Child Class CComplexVector2 ========


class CComplexVector2 : public CComplexVector{
public:
	CComplexVector2(): CComplexVector(){};
	CComplexVector2(const int &n): CComplexVector(n){};
	CComplexVector2(const vector<ComplexNumber> rhs, const int &n){CopyOnly(rhs,n);}
	CComplexVector2(const CComplexVector2 &rhs): CComplexVector(rhs){}

	CComplexVector &operator=(const CComplexVector &rhs){if(this!=&rhs){Clean();CopyOnly(rhs);} return *this;}
	CComplexVector &operator=(const vector<ComplexNumber> rhs){CopyOnly(rhs); return *this;}

	virtual void show(const string sf);
};



CComplexVector2 operator+(const CComplexVector &lhs, const CComplexVector &rhs);
CComplexVector2 operator-(const CComplexVector &lhs, const CComplexVector &rhs);
ComplexNumber operator*(const CComplexVector &lhs, const CComplexVector &rhs); 


class CFabricVector{
public:
	virtual CComplexVector *Create() = 0;
};

class CFabricVector1: public CFabricVector{
	virtual CComplexVector *Create() {return new CComplexVector1;}
};
class CFabricVector2: public CFabricVector{
	virtual CComplexVector *Create() {return new CComplexVector2;}
};
