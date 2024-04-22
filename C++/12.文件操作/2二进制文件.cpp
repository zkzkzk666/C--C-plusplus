#include<iostream>
#include<fstream>
using namespace std;

class Person{
public:
    char name[64];
    int age;

};

//二进制文件，写文件
void test1(){
    ofstream ofs;
    ofs.open("person.txt",ios::binary|ios::out);
    Person p={"666六",18};
    ofs.write((const char *)&p,sizeof(p));
    ofs.close();
}

//二进制文件，读文件
void test2(){
    ifstream ifs;
    ifs.open("person.txt",ios::binary|ios::in);
    if (!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    Person p;
    ifs.read((char *)&p,sizeof(Person));
    cout<<"姓名："<<p.name<<"年龄："<<p.age<<endl;
    ifs.close();
}
int main(){
    // test1();
    test2();
    return 0;
}