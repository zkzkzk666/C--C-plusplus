#include<iostream>
using namespace std;

//ʵ���������
//int add(int a, int b) {
//	return a + b;
//}
//double add(double a, double b) {
//	return a + b;
//}

//����ģ��ʵ��
template<typename T,typename M>

void add(T t, M m){
	cout << t + m << endl;
}

//��ģ��
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