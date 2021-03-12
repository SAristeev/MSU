#include"class.h"


// ==== ComplexVector2's Functions ========


CVector operator+(const CVector &lhs, const CVector &rhs){
	if(lhs.Size()!=rhs.Size()){
		throw -1;
	}
	else{
		vector<double> result;
		for(size_t i=0; i<lhs.Size(); i++){
			result.push_back(lhs[i]+rhs[i]);	
		}
		CVector tmp(result);
		return tmp;
	}
}


// ==== Show Functions ========


void CVector::show(){
	cout << "{";
	for(size_t i=0; i<v.size();i++){
		cout << v[i] << " ";
	}
	cout << "}" << endl;
}