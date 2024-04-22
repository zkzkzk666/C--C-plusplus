#include<iostream>
//算法包
#include<algorithm>
#include<vector>
using namespace std;


//创建一个有数据的容器
vector<int> getVector() {
	vector<int> v;
	for (int i = 0; i <10; i++)
	{
		v.push_back(i);
	}
	return v;
}

class myPrint {
public:
	void operator()(int i){
		cout << i << " ";
	}
	

};
class NumberOperate {
public:
	int operator()(int i) {
		return i + 100;
	}
};
class SumOperate {
public:
	int operator()(int n1,int n2) {
		return n1+n2;
	}
};

void test1() {
	vector<int> v=getVector();
	for_each(v.begin(), v.end(),myPrint());

}

void test2() {
	vector<int> v1 = getVector();
	for_each(v1.begin(), v1.end(), myPrint());
	vector<int> v2 ;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), NumberOperate());
	for_each(v2.begin(), v2.end(), myPrint());
	vector<int> v3;
	v3.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(),v3.begin(), SumOperate());
	for_each(v3.begin(), v3.end(), myPrint());
}

class Person {
public:
	string name;
	int age;
	Person() = default;
	Person(string n,int a):name(n),age(a){}
};
class PersonCompare {
public:
	bool operator()(Person& p1, Person& p2) {
		return p1.age < p2.age;
	}
};
void test3() {
	vector<Person> v;
	v.push_back(Person("aaa", 18));
	v.push_back(Person("a", 19));
	v.push_back(Person("aa", 15));
	v.push_back(Person("abc", 30));
	v.push_back(Person("acccc", 40));
	v.push_back(Person("acdcd", 60));
	v.push_back(Person("adqdqwa", 40));
	sort(v.begin(), v.end(), PersonCompare());
	for (Person p : v) {
		cout << p.name << " " << p.age << endl;
	}
}

int main() {
	//test1();
	//test2();
	test3();
	return 0;
}
