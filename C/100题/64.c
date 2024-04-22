// 输入 10 个学生的姓名、学号和成绩，将其中不及格者的姓名、学号和成绩输出
#include<stdio.h>
//学生的个数
#define N 10
struct Student
{
    char name[20];
    int id;
    int grade;
};

int main(){
    //定义学生结构体数组
    struct Student stu[N];
    for (int i = 0; i <N; i++)
    {
        printf("请输入第%d位学生姓名\n",i+1);
        scanf("%s",&stu[i].name);
        printf("请输入第%d位学生学号\n",i+1);
        scanf("%d",&stu[i].id);
        printf("请输入第%d位学生成绩\n",i+1);
        scanf("%d",&stu[i].grade);
    }
    for (int i = 0; i <N; i++)
    {
        if (stu[i].grade<60)
        {
            printf("----------------\n");
            printf("姓名：%s\n",stu[i].name);
            printf("学号：%d\n",stu[i].id);
            printf("成绩：%d\n",stu[i].grade);
        }
    }
    return 0;
}