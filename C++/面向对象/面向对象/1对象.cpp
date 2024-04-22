#include <iostream>
using namespace std;
class person {
public:
    int age;
    int score;
    void eat() {
        cout << "吃饭" << endl;
    }
    int getAge() {
        return this->age;
    }
    //无参构造函数
    person() {

    }
    //有参构造函数
    person(int m_age) {
        age = m_age;
    }
    person(int a,int s):age(a),score(s){}
    //析构函数
    ~person()
    {
        cout << "析构函数" << endl;
    }
};

class son :public person {

};


//int main()
//{
//    //栈上开辟内存
//    person p=person();
//    //堆上开辟内存（new）
//    person *p1 = new person();
//    p.age = 18;
//    p.eat();
//    cout << p.getAge()<< endl;
//    person p2(20, 99);
//    cout << p2.age << endl;
//    
//
//    son s = son();
//    s.eat();
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
