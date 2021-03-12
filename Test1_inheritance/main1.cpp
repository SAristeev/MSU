#include"class.h"


void TestCVector1(){
	vector<double> a1,a2;
	a1.push_back(-1e-5);
	a1.push_back(-1e-7);
	a1.push_back(-1e-10);
	a1.push_back(-1e-8);
	a1.push_back(-1e-10);
	
	a2.push_back(3e-5);
	a2.push_back(3e-7);
	a2.push_back(3e-10);
	CVector v01(a1), v02(a2);
	CVector1 v11(a1), v12(a2), c(a2);
	CVector b(a1,3);
	v01.show();v02.show();v11.show();v12.show();
	cout << endl;

	v01=v01+v01;
	v01.show();
	v12=v12+v12;
	v12.show();
	cout << endl;

	v01.Low();
	v01.show();
	v12.Low();
	v12.show();
	cout << endl;

	b=c+v12;
	b.show();
	cout << endl;

	b.Low();
	b.show();
	cout << endl;
}


int main() {
	try{
		TestCVector1();
	}catch(exception &err){
		cout << err.what() << endl;
	}
	return 0;
}