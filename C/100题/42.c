/*用递归法将一个整数 n 转换成字符串。例如，输入 483，应输出字符串"483"。n 的
位数不确定，可以是任意位数的整数。*/
#include<stdio.h>
//long long int让n的取值范围更广
void func(long long int n){
    if (n<10)
    {
        //数字0的ascii码48，再加上n即可转换成数字
        char c=48+n;
        printf("%c",c); 
    }
    else{
        // n/10得到n的高位
        //此函数放在上面使得先输出的是数字的高位
        func(n/10);
        // n%10得到此时n的个位数
        func(n%10);
    }
    
}

int main(){
    int n;
    printf("请输入一个整数");
    scanf("%d",&n);
    func(n);
    return 0;
}