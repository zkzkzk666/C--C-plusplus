//把以下程序的 print( )函数改写为等价的递归函数。
#include<iostream>
using namespace std;
void print(int w) {
    for(int i=1;i<w;i++) {
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
    }
}
void myPrint(int w) {
    // 当 w 为 1 时，递归结束
    if (w > 1) {
        // 递归调用 myPrint 函数，传入 w - 1 作为参数
        myPrint(w - 1);
        // 使用循环打印 w - 1 的值，循环次数为 w - 1 次
        for(int j = 1; j < w; j++) {
            cout << w - 1 << " ";
        }
    }
}


int main(){
    print(5);
    cout<<endl;
    myPrint(5);
    return 0;
}