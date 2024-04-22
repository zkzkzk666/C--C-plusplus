/*声明一个Student类，在该类中包括一个数据成员score（分数）、两个静态数据成员total_score（总分）和count（学生人数）；还包括一个成员函数account（）用于设置分数、累计学生的成绩之和、累计学生人数，一个静态成员函数sum（）用于返回学生的成绩之和，另一个静态成员函数average（）用于求全部成绩的平均值。在main函数中，输入某班同学的成绩，并调用上述函数求出全班同学的成绩之和和平均分。*/
#include<iostream>
using namespace std;


//定义学生类
class Student
{
private:
    int score;//分数
    static double total_score;//总分数
    static int count;//总人数
public:
    //声明成员函数
    void account();
    //声明静态成员函数
    static double sum();
    static double average();
};

//每次创建对象都要调用这个相当于初始化的函数
void Student::account(){
    cout<<"请输入一位学生的成绩"<<endl;
    cin>>score;
    //这个学生的成绩要加到总分当中
    total_score+=score;
    //总人数也加一
    count++;
}
//返回总分数
double Student::sum(){
    return total_score;
}
//返回学生平均值
double Student::average(){
    return total_score/count;
}

//初始化静态变量
double Student::total_score=0;//总分数
int Student::count=0;//总人数


int main(){
    Student s1,s2,s3;
    s1.account();
    s2.account();
    s3.account();
    cout<<"学生总成绩为："<<s1.sum()<<endl;
    cout<<"学生平均成绩为："<<s1.average()<<endl;
    return 0;
}
