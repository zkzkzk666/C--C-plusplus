/*定义一个 Book(图书)类，在该类定义中包括数据成员和成员函数 数据成员：book_name
（书名）、price(价格)和 number(存书数量)； 成员函数：display()显示图书的
情况；borrow() 将存书数量减 1，并显示当前存书数量； restore() 将存书数量加
1，并显示当前存书数量。 在 main 函数中，要求创建某一种图书对象，并对该图书
进行简单的显示、借阅和归还管理。
*/
#include<iostream>
#include<string>
using namespace std;

class Book
{
private:
    string book_name;//书名
    int price;//价格
    int number;//存书数量
public:
    void display(){
        cout<<"书名："<<this->book_name<<endl;
        cout<<"价格："<<this->price<<endl;
        cout<<"当前数量："<<this->number<<endl;
    }
    //借书
    void borrow(){
        this->number-=1;
    }
    //还书
    void restore(){
        this->number+=1;
    }
    //有参构造
    Book(string name,int price,int number){
        this->book_name=name;
        this->price=price;
        this->number=number;
    }
};


int main(){
    //构造对象b1
    Book b1("全职法师",100,60);
    b1.display();
    b1.borrow();
    b1.display();
    b1.restore();
    b1.display();
    return 0;
}