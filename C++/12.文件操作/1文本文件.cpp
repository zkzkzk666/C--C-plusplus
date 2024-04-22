#include<iostream>
#include<fstream>
using namespace std;

//文本文件，写文件
void test1(){
    ofstream ifs;
    ifs.open("test.txt",ios::out);
    ifs<<"666"<<endl;
    ifs<<"aaa"<<endl;
    ifs<<"bbb"<<endl;
    ifs.close();

}
//文本文件，读文件
void test2(){
    ifstream ifs;
    ifs.open("test.txt",ios::in);
    //判断文件是否打开
    if (!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    //读数据
    //1
    // char buf[1024]={0};
    // while (ifs>>buf)
    // {
    //     cout<<buf<<endl;
    // }
    //2
    // char buf[1024]={0};
    // while (ifs.getline(buf,sizeof(buf)))
    // {
    //     cout<<buf<<endl;
    // }
    //3
    // string buf;
    // while (getline(ifs,buf))
    // {
    //     cout<<buf<<endl;
    // }
    //4
    char c;
    while ((c=ifs.get())!=EOF)
    {
        cout<<c;
    }
    
    
    
    
    
    
    
    ifs.close();

}
int main(){
    // test1();
    test2();
    return 0;
}