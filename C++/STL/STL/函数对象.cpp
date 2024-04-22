#include<iostream>
using namespace std;
class myPrint {
public:
	int num;
	myPrint() {
		num = 0;
	}
	void operator()(int n){
		cout << n << endl;
		num++;
	}
};
//int main() {
//	myPrint my;
//	//º¯Êý¶ÔÏó
//	my(6);
//	my(7);
//	my(8);
//	cout << my.num << endl;
//	return 0;
//}