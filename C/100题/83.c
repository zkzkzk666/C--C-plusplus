/*  一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问
该数是多少？*/
#include<stdio.h>

int main(){
    //num为最终所求那个数
    int num;
    //i*i为第一个完全平方数
    for (int i = 10; i < 100; i++)
    {
        //j*j为第二个完全平方数
        for (int j = i; j < 100; j++)
        {
            //两个平方数相减为168
            if (j*j-i*i==168)
            {
                num=i*i-100;
                printf("这个数为：%d",num);
                return 0;
            }
        }
    }
}