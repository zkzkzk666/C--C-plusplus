#include<iostream>
using namespace std;
#include<string>


template<class NameType,class AgeType>

class Person{
public:
    Person(NameType name,AgeType age){
        this->m_age=age;
        this->m_name=name;
    }
    void showPerson(){
        cout<<"age:"<<this->m_age<<" name:"<<this->m_name<<endl;
}
    NameType m_name;
    AgeType m_age;
};

//整个类模板化
template<class T>
void PrintPerson(T &p){
    p.showPerson();
}



int main(){
    Person<string,int> p={"aaa",666};
    PrintPerson(p);
    return 0;
}