#include<iostream>
using namespace std;

//实现数字相加
//int add(int a, int b) {
//	return a + b;
//}
//double add(double a, double b) {
//	return a + b;
//}

//函数模板实现
template<typename T,typename M>

void add(T t, M m){
	cout << t + m << endl;
}

//类模板
template<typename T>
class person {
public:
	T age;
	person();
	person(T t);
};

template<typename T>
person<T>::person(T t) {
	this->age = t;
}

//int main() {
//	add(10, 20);
//	return 0;
//}