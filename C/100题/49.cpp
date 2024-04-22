/*一个班有 n 个学生，需要把每个学生的简单材料（姓名和学号）输入计算机保存。然
后可以通过输入某一学生的姓名查找其有关资料，当输入一个姓名后，程序就查找该班
中有无此学生，如果有，则输出他的姓名和学号，如果查不到，则输出“本班无此人”。*/
#include<iostream>
#include<string>
using namespace std;
//定义数组的大小为10
#define N 10
//学生类
class Student{
    //类中的属性默认私有
    //学生姓名
    string m_name;
    //学生学号
    int m_id;
    public:
    //无参构造函数
    Student(){}
    //有参构造函数
    Student(string name,int id){
        this->m_id=id;
        this->m_name=name;
    }
    //打印出当前对象的信息（学号，姓名）
    void getMessage(){
        cout<<"学号："<<this->m_id<<endl;
        cout<<"姓名："<<this->m_name<<endl;
    }
    //获取当前对象的姓名
    string getName(){
        return this->m_name;
    }
};
//学生信息录入
void message(int n,Student *stu){
    //循环录入n个学生的信息
    for (int i = 0; i <n; i++)
    {
        int id;
        string name;
        cout<<"请输入第"<<i+1<<"个学生的姓名"<<endl;
        cin>>name;
        cout<<"请输入第"<<i+1<<"个学生的学号"<<endl;
        cin>>id;
        //录入后，进行有参构造对象并存放在stu数组中
        stu[i]=Student(name,id);
    }
    cout<<"录入完成"<<endl;
}
//查询学生
void search(int n,string name,Student *stu){
    //判断是否查询到学生
    int flag=0;
    for (int i = 0; i <n; i++)
    {
        if (stu[i].getName()==name)
        {
            stu[i].getMessage();
            flag=1;
            //查询成功后，直接跳出循环
            break;
        }
    }
    if (flag==0)
    {
        cout<<"本班无此人"<<endl;
    }
}


int main(){
    int n;
    cout<<"输入学生个数n"<<endl;
    cin>>n;
    Student stu[N];
    message(n,stu);
    string name;
    cout<<"输入某一学生的姓名查找其有关资料"<<endl;
    cin>>name;
    search(n,name,stu);
}