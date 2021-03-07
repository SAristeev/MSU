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
	const CComplexVector& ltmp=lhs;
	const CComplexVector& rtmp=rhs;
	CComplexVector& lv=const_cast<CComplexVector&>(ltmp);
	CComplexVector& rv=const_cast<CComplexVector&>(rtmp);

	size_t l=lv.Size();
	size_t r=rv.Size();
	if(l>r){
		CComplexVector2 result(l);
		for(size_t i=0; i<r; i++){
			ComplexNumber tmp=lv[i]+rv[i];
			result.Set(tmp,i);	
		}
		for(size_t i=r; i<l; i++)
			result.Set(lv[i],i);
		return result;
	}
	else{
		CComplexVector2 result(r);
		for(size_t i=0; i<l; i++){
			ComplexNumber tmp=lv[i]+rv[i];
			result.Set(tmp,i);	
		}
		for(size_t i=l; i<r; i++)
			result.Set(rv[i],i);
		return result;
	}
}
CComplexVector2 operator-(const CComplexVector &lhs, const CComplexVector &rhs){
	const CComplexVector& ltmp=lhs;
	const CComplexVector& rtmp=rhs;
	CComplexVector& lv=const_cast<CComplexVector&>(ltmp);
	CComplexVector& rv=const_cast<CComplexVector&>(rtmp);
	size_t l=lv.Size();
	size_t r=rv.Size();
	if(l>r){
		CComplexVector2 result(l);
		for(size_t i=0; i<r; i++){
			ComplexNumber tmp=lv[i]-rv[i];
			result.Set(tmp,i);	
		}
		for(size_t i=r; i<l; i++)
			result.Set(lv[i],i);
		return result;
	}
	else{
		CComplexVector2 result(r);
		for(size_t i=0; i<l; i++){
			ComplexNumber tmp=lv[i]-rv[i];
			result.Set(tmp,i);
		}
		for(size_t i=l; i<r; i++){
			ComplexNumber tmp=(-1)*rv[i];
			result.Set(tmp,i);
		}
		return result;
	}
}

ComplexNumber operator*(const CComplexVector &lhs, const CComplexVector &rhs){
	const CComplexVector& ltmp=lhs;
	const CComplexVector& rtmp=rhs;
	CComplexVector& lv=const_cast<CComplexVector&>(ltmp);
	CComplexVector& rv=const_cast<CComplexVector&>(rtmp);
	ComplexNumber result;
	rv.Conjugation();
	size_t l=lv.Size();
	size_t r=rv.Size();
	if(l>r){
		for(size_t i=0; i<r; i++)
			result=result+lv[i]*rv[i];
	}
	else{
		for(size_t i=0; i<l; i++)
			result=result+lv[i]*rv[i];
	}
	return result;
}


// ==== Show Functions ========


void CComplexVector1::show(const string sf){
	ofstream out;
	out.open(sf);
	out << "Type-1{";
	for(size_t i=0; i<v.size();i++){
		out << v[i] << " ";
	}
	out << "}" << endl;
	out.close();
}

void CComplexVector2::show(const string sf){
	ofstream out;
	out.open(sf);
	out << "Type-2{";
	for(size_t i=0; i<v.size();i++){
		out << v[i] << endl;
	}
	out << "}" << endl;
	out.close();
}
