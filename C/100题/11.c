/*求 Sn = a + aa + aaa + … + a…a 的值，其中 a 是一个数字。例如：
2+22+222+2222+22222(n = 5)，n 由键盘输入。*/
#include<stdio.h>

int func(int n){
    int a=2;
    int result=0;//结果
    int i=0;
    //每次累加的结果为上一次的加数*10再加a
    int add=a;
    while (i<n)//循环n次，也就是n项和
    {
        result+=add;
        add=add*10+a;
        i++;
    }
    return result;
}


int main(){
    int n;
    printf("请输入n\n");
    scanf("%d",&n);
    printf("结果为：%d\n",func(n));
    return 0;
}