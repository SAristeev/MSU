#include"class.h"


// ==== ComplexNumber's Functions ========


ostream &operator<<(ostream &stream, const ComplexNumber &number){
	double Im=number.GetIm(), Re=number.GetRe();
	if(Re>0 || Re<0){
	if(Im>0)
		stream << Re << "+" << Im << "i";
	else if(Im<0)
		stream << Re << Im << "i";
	else
		stream << Re;}
	else{ 
		if(Im>0 || Im<0)
			stream << Im << "i";
		else
			stream << 0;}
	return stream;
}

istream &operator>>(istream &stream, ComplexNumber &number){
	string digit;
	stream >> digit;
	istringstream ss(digit);
	if(digit[0]=='i'){
		number.SetRe(0);
		number.SetIm(1);
	}
	else if(digit[0]=='-' && digit[1]=='i'){
		number.SetRe(0);
		number.SetIm(-1);
	}
	else{
		double n1;
		ss >> n1;
		string digit1;
		ss >> digit1;
		if(digit1[0]=='+' && digit1[1]=='i'){
			number.SetRe(n1);
			number.SetIm(1);
		}
		else if(digit1[0]=='-' && digit1[1]=='i'){
			number.SetRe(n1);
			number.SetIm(-1);
		}
		else if(digit1[0]=='i'){
			number.SetRe(0);
			number.SetIm(n1);
		}
		else{
			istringstream sss(digit1);
			double n2;
			number.SetRe(n1);
			if(sss >> n2)
				number.SetIm(n2);
		}
	}
	return stream;
}
ComplexNumber operator+(const int &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs+rhs.GetRe(),rhs.GetIm());
	return result;
}
ComplexNumber operator-(const int &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs-rhs.GetRe(),rhs.GetIm());
	return result;
}
ComplexNumber operator*(const int &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs*rhs.GetRe(),lhs*rhs.GetIm());
	return result;
}
ComplexNumber operator+(const double &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs+rhs.GetRe(),rhs.GetIm());
	return result;
}
ComplexNumber operator-(const double &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs-rhs.GetRe(),rhs.GetIm());
	return result;
}
ComplexNumber operator*(const double &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs*rhs.GetRe(),lhs*rhs.GetIm());
	return result;
}


// ==== ComplexVector2's Functions ========


CComplexVector2 operator+(const CComplexVector &lhs, const CComplexVector &rhs){
	if(lhs.Size()!=rhs.Size()){
		throw -1;
	}
	else{
		vector<ComplexNumber> result;
		for(size_t i=0; i<lhs.Size(); i++){
			result.push_back(lhs[i]+rhs[i]);	
		}
		CComplexVector2 tmp(result);
		return tmp;
	}
}
CComplexVector2 operator-(const CComplexVector &lhs, const CComplexVector &rhs){
	if(lhs.Size()!=rhs.Size()){
		throw -1;
	}
	else{
		vector<ComplexNumber> result;
		for(size_t i=0; i<lhs.Size(); i++){
			result.push_back(lhs[i]-rhs[i]);	
		}
		CComplexVector2 tmp(result);
		return tmp;
	}
}

ComplexNumber operator*(const CComplexVector &lhs, const CComplexVector &rhs){
	if(lhs.Size()!=rhs.Size()){
		throw -1;
	}
	else{
		ComplexNumber result;
		for(size_t i=0; i<lhs.Size(); i++){
			ComplexNumber tmp=rhs[i];
			tmp.Conjugation();
			result=result+lhs[i]*tmp;
		}
		return result;
	}
}

// ==== Show Functions ========


void CComplexVector1::input(const string sf){
	ofstream out;
	out.open(sf);
	out << "Type-1(";
	for(size_t i=0; i<w.size();i++){
		out << w[i] << " ";
	}
	out << ")" << endl;
	out.close();
}

void CComplexVector2::input(const string sf){
	ofstream out;
	out.open(sf);
	out << "Type-2(";
	for(size_t i=0; i<w.size();i++){
		out << w[i] << endl;
	}
	out << ")" << endl;
	out.close();
}
