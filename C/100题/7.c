// 将两个十进制正整数的和输出为任意的 m 进制，m 为用户输入。
#include<stdio.h>
#define MaxSize 10
int func(int m,int a,int b){
    int num=a+b;
    //判断进制数师范合法
    if (m<=1)
    {
        printf("错误进制\n");
        return 0;
    }
    //创建数组存储先得到的低位数
    int arr[MaxSize];
    int length=0;//存储该m进制数的位数
    for (int i =MaxSize-1; i >=0; i--)
    {
        //辗转相除获取m进制后的数
        arr[i]=num%m;
        num=num/m;
        if (num<m)
        {
            arr[i-1]=num;
            length++;
            break;
        }
        length++;
    }
    printf("两个十进制正整数%d，%d的和为 %d 进制的：\n",a,b,m);
    for (int i = MaxSize-length-1; i < MaxSize; i++)
    {
        printf("%d",arr[i]);
    }
}


int main(){
    //a,b的值可任意修改
    int a=8,b=9;
    int m;
    printf("输入进制数m：");
    scanf("%d",&m);
    func(m,a,b);
}
