#include<iostream>
#include<string>
using namespace std;

//定义学生结构体
struct student
{
    string name;
    int age;
    int score;
};

int main(){
    //1
    student s1;
    s1.age=16;
    s1.name="张三";
    s1.score=80;
    cout<<s1.name<<s1.age<<s1.score<<endl;

    //2
    student s2={"111",10,80};
    cout<<s2.name<<s2.age<<s2.score<<endl;

    //结构体数组
    student arr[3]={
        {"111",14,80},
        {"222",15,90},
        {"333",16,98}
    };
    for (int i = 0; i < 3; i++)
    {
        cout<<arr[i].age<<" "<<arr[i].name<<" "<<arr[i].score<<endl;
    }
    
    //结构体指针
    student *p=&arr[1];
    cout<<p->age;
    return 0;
}