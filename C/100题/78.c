/*输入 10 个学生 5 门课的成绩，分别用函数实现下列功能： ①计算每个学生的平均
分； ②计算每门课的平均分； ③找出所有 50 个分数中最高的分数所对应的学生和课
程； ④计算平均分方差,平均分为每个学生的平均分*/
#include<stdio.h>
//学生个数
#define N 10
//课程数量
#define n 5

//计算每个学生的平均分
void student_avg(int stu[N][n]){
    for (int i = 0; i < N; i++)
    {
        //sum为一个学生所有课程分数总和
        double sum=0;
        for (int j = 0; j < n; j++)
        {
            sum+=stu[i][j];
        }
        //分数总和除以课程数就得学生的平均分
        printf("第%d个学生的平均成绩为：%lf\n",i+1,sum/n);
    }
}

// 计算每门课的平均分
void class_avg(int stu[N][n]){
    for (int i = 0; i < n; i++)
    {
        //sum为所有学生这一门课的成绩总和
        double sum=0;
        for (int j = 0; j < N; j++)
        {
            sum+=stu[j][i];
        }
        //总和除以学生人数就得这门课学生的平均成绩
        printf("第%d门课的平均成绩为：%lf\n",i+1,sum/N);
    }  
}
//找出所有 50 个分数中最高的分数所对应的学生和课程
void getMax(int stu[N][n]){
    //最高分数
    int max=0;
    //对应的学生
    int student;
    //对应的课程
    int grade;
    //遍历所有数据
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (stu[i][j]>max)
            {
                max=stu[i][j];
                //加一是因为数组下标从零开始的
                student=i+1;
                grade=j+1;
            }
        }
    }  
    printf("最高分数是第%d名学生的第%d门成绩，分数为：%d\n",student,grade,max);
}

//计算平均分方差
double getVariance(int stu[N][n]){
    //辅助变量
    double temp;
    //所有学生的平均分
    double avg;
    //所有学生所有课程分数总和
    double sum=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum+=stu[i][j];
        }
    }
    //总和除以人数除以课程就得平均分
    avg=sum/(N*n);
    for (int i = 0; i < N; i++)
    {
        //每个学生五门课程的平均分
        double stdAvg=0;
        for (int j = 0; j < n; j++)
        {
            stdAvg+=stu[i][j];
        }
        //方差就为每个学生的平均分减去所有学生的平均分的平方之和
        temp+=((stdAvg/n)-avg)*((stdAvg/n)-avg);
    }
    return temp/N;
}

int main(){
    int stu[N][n];
    int grade=0;
    //输入数据
    for (int i = 0; i <N ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("请输入第%d个学生，第%d门的成绩：",i+1,j+1);
            scanf("%d",&grade);
            stu[i][j]=grade;
        }
    }
    printf("---------------\n");
    //打印数组
    for (int i = 0; i <N ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ",stu[i][j]);
        }
        printf("\n");
    }
    student_avg(stu);
    printf("---------------\n");
    class_avg(stu);
    printf("---------------\n");
    getMax(stu);
    printf("---------------\n");
    printf("方差为%lf",getVariance(stu));
    return 0;
}