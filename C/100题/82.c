/*利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间
的用B表示，60分以下的用C表示*/
#include<stdio.h>

int main(){
    int score;
    char grade;
    printf("请输入你的成绩：");
    scanf("%d",&score);
    grade=score>=90?'A':((score<=89&&score>=60)?'B':'C');
    printf("%c",grade);
    return 0;
}