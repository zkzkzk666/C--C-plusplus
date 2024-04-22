#include<iostream>
#include<string>
using namespace std;

//创建学生
struct student
{
    string name;
    int age;
    int score;
};

//创建老师
struct teacher
{
    int id;
    string name;
    int age;
    student stu;
};


int main(){
    teacher t1;
    t1.age=50;
    t1.id=1;
    t1.name="111";
    t1.stu.age=15;
    t1.stu.name="222";
    t1.stu.score=66;
    cout<<t1.age<<" "<<t1.id<<" "<<t1.name<<" "<<t1.stu.age<<" "<<t1.stu.name<<" "<<t1.stu.score<<endl;
    system("pause");
    return 0;
}