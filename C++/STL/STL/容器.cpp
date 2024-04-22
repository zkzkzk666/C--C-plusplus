#include<iostream>
using namespace std;
#include<deque>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>

void printMap(map<string,int>& m) {
	for (pair<string,int> p:m) {
		cout << p.first << "," << p.second << endl;
	}
}
void printSet(set<int>& s) {
	for (int ele : s) {
		cout << ele << " ";
	}
	cout << endl;
}

void printDeque(deque<int>& d) {
	for (int& ele:d)
	{
		cout << ele << " ";
	}
	cout << endl;
}
void printList(list<int>& l) {
	for (int& ele : l)
	{
		cout << ele << " ";
	}
	cout << endl;
}
void deque1() {
	int array[5] = { 1,2,3,4,5 };
	deque<int> d(array, array + 5);
	printDeque(d);
}

void stack1() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.empty()<< endl;
	cout << s.size()<< endl;

}
void queue1() {
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout << q.front() << endl;
	cout << q.back() << endl;

}
void list1() {
	int array[5] = { 1,2,3,4,5 };
	list<int> l(array, array + 5);
	printList(l);
}

void set1() {
	set<int> s;
	multiset<int> ms;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(3);
	printSet(s);
	s.erase(2);
	printSet(s);
}

void pair1() {
	pair<string, int> p("abc", 666);
	pair<string, int> p2 = make_pair("aaa", 1);
	cout << p.first << endl;
	cout << p.second << endl;
}

void map1() {
	map<string, int> m;
	m.insert(pair<string, int>("aaa", 666));
	m.insert(make_pair("abc", 1));
	m["zk"] = 100;
	printMap(m);
}

//int main() {
//	//stack1();
//	//queue1();
//	//list1();
//	//set1();
//	//pair1();
//	//map1();
//	return 0;
//}