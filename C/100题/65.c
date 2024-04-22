/* 已知求成绩的平均值和均方差公式为：𝑎𝑣𝑒 =∑𝑠𝑖/n ,
𝑑𝑒𝑣 =  √(∑ (𝑠𝑖−𝑎𝑣𝑒)^2/n)，其中 n 为学生人数，si 为第 i 个学生成绩。求某班学生的平均成绩和均方差。*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    //学生个数
    int n;
    printf("请输入学生个数：");
    scanf("%d",&n);
    //动态分配数组空间，可以存储n个学生的成绩
    int *grade=(int *)malloc(n*sizeof(int));
    //学生成绩总和
    int sum=0;
    //输入学生的成绩，并计算成绩总和
    for (size_t i = 0; i < n; i++)
    {
        printf("请输入第%d个学生的成绩\n",i+1);
        scanf("%d",&grade[i]);
        sum+=grade[i];
    }
    //平均成绩
    double ave=sum/(double)n;
    //num是对(𝑠𝑖−𝑎𝑣𝑒)^2的求和，dev是均方差
    double num=0,dev;
    for (int i = 0; i < n; i++)
    {
        num+=(grade[i]-ave)*(grade[i]-ave);
    }
    dev=sqrt(num/n);
    printf("平均成绩为：%f，均方差为%f",ave,dev);
    return 0;
}