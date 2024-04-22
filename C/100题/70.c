/*编写以下函数
1．在一个二维数组中形成如以下形式的 n 阶矩阵：
1 1 1 1 1 
2 1 1 1 1 
3 2 1 1 1 
4 3 2 1 1 
5 4 3 2 1
2．去掉靠边元素，生成新的 n-2 阶矩阵；
3．求矩阵主对角线下元素之和：
4．以方阵形式输出数组
*/

#include<stdio.h>
#include<stdlib.h>


//全局变量，所有函数都可以访问到
int **arr;

//创建n阶矩阵
void func1(int n){
    // 要使用malloc函数动态分配内存
    arr = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    // 创建数组
    for (int i = 0; i < n; i++){
        //先把所有的元素都赋值为1
        for (int k = 0; k < n; k++)
        {
            arr[i][k]=1;
        }
        //让后按照三角形的规律赋值
        for (int j = 0; j < i; j++){
            arr[i][j]=i+1-j;
        }
    }
}

//创建n-2阶矩阵
void func2(int n){
    //只需要调用n-2时的func1就可以
    func1(n-2);
}

//求矩阵主对角线下元素之和
int func3(int n){
    int sum=0;
    //循环累加对角线下的所有元素，只需要j<i就可以
    for (int i = 0; i < n; i++)
    { 
        for (int j = 0; j < i; j++)
        {
            sum+=arr[i][j];
        }
    }
    return sum;
}

//以方阵形式输出数组
void func4(int n){
    // 打印矩阵
    printf("该矩阵为:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
     int n=0;
    printf("请输入矩阵的行数:");
    scanf("%d",&n);
    //创建n阶矩阵
    func1(n);
    // 打印矩阵
    func4(n);
    printf("该矩阵主对角线下元素之和为：%d\n",func3(n));
    //生成新的矩阵
    func2(n);
    //打印新的矩阵
    func4(n-2);
    printf("该矩阵主对角线下元素之和为：%d\n",func3(n-2));
    return 0;
}