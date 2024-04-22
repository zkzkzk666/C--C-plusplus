//  判断一个素数能被几个9整除
//就是99...99%n==0,n为那个素数
#include<stdio.h>

int func(int n){
    //num是被除数就是99..9,i记录num有多少个9
    int num=0,i=0;
    //死循环
    while (1)
    {
        i++;
        num=num*10+9;
        //直到整除才跳出循环
        if (num%n==0)
        {
            //返回值为9的个数
            return i;
        }  
    }
}

int main(){
    int n;
    printf("请输入一个素数：");
    scanf("%d",&n);
    printf("%d能被%d个9整除",n,func(n));
    return 0;
}