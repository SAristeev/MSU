#include"class.h"

void TestInheritance(){
	vector<CFabricVector*> fabric;
	vector<CComplexVector*> w;
	fabric.push_back(new CFabricVector1);
	fabric.push_back(new CFabricVector2);
	ifstream in("in.txt"); string str;
	while(getline(in,str)){
		int Type; string outfile; vector<ComplexNumber> vec;
		stringstream ss(str);
		ss >> Type >> outfile;
		for(ComplexNumber tmp;ss >> tmp;){
			vec.push_back(tmp);
		}
		CComplexVector *t=fabric[Type-1]->Create();
		*t=vec;
		t->show(outfile);
		w.push_back(t);
	}
	for(size_t i=0;i<w.size();i++){
		delete w[i];
	}
}


int main() {
	try{
		//TestComplexNumber();
		//TestComplexVector();
		TestInheritance();
	}catch(exception &err){
		cout << err.what() << endl;
	}
	return 0;
}

/*
void TestComplexNumber(){
	srand(time(NULL));
	ComplexNumber a(rand()%(8),rand()%(8)),b(rand()%(8),rand()%(8)), c(rand()%(8),rand()%(8));
	cout<<a<<" "<<b<<" "<<endl;
	cout << c << endl;
	c.Conjugation();
	cout << c << endl;
	ComplexNumber d=a-b;
	ComplexNumber e=a+b;
	ComplexNumber f=a*b;
	cout<<d<<" "<<a-b<<" "<<e<<" "<<a+b<<" "<<f<<" "<<a*b<<" "<<endl;
	ComplexNumber x;
	cin >> x;
	cout<<x<< endl;
}
void TestComplexVector(){
	ComplexNumber a(1,1),b(2,3),c(5,2),d(2,7),f, g;
	vector<ComplexNumber> a1,a2;
	a1.push_back(a);
	a1.push_back(b);
	a1.push_back(c);
	a1.push_back(d);
	a1.push_back(f);
	
	a2.push_back(2*d);
	a2.push_back(f);
	a2.push_back(3*c);
	CComplexVector1 v1(a1,5);
	CComplexVector1 v2(a2,3);
	CComplexVector1 v3(8),v4;
	v1.show("out1");
	v2.show("out2");
	cout << endl;
	v3=v2+v1;
	v4=v1-v2;
	//v3=v2;
	v3.show("out3");
	v4.show("out4");
	cout << endl;
	
	ComplexNumber b1, b2;
	b2=v1*v1;
	cout << b2 << endl;
	b1=v2*v1;
	cout << b1 << endl;
}
*/