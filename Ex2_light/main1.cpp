#include"class.h"

int main() {
	try{
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
			t->input(outfile);
			w.push_back(t);
		}
		for(size_t i=0;i<w.size();i++){
			delete w[i];
		}
	}catch(exception &err){
		cout << err.what() << endl;
	}
	return 0;
}
