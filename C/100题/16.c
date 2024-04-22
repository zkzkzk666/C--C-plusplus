// 输入三个数，输出其中绝对值最大的数字

#include<stdio.h>
//使用abs()求绝对值函数
#include<math.h>

//求三个数字中绝对值最大的数字
int max(int a,int b,int c){
    //三元运算符
    return abs(a)>=abs(b)?(abs(a)>=abs(c)?a:c):(abs(b)>=abs(c)?b:c);
}
int main(){
    int a,b,c;
    printf("输入第一个数\n");
    scanf("%d",&a);
    printf("输入第二个数\n");
    scanf("%d",&b);
    printf("输入第三个数\n");
    scanf("%d",&c);
    printf("三个数其中绝对值最大的数字为%d",max(a,b,c));
    return 0;
}