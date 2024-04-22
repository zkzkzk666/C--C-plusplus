// 输入 n 个字符串，将它们按字母由小到大的顺序排列并输出
#include<stdio.h>
#include<stdlib.h>
//字符串的最大长度
#define N 20

//交换两个字符串在数组中的位置
void swap(char **str1,char **str2){
    char *temp=*str1;
    *str1=*str2;
    *str2=temp;
}

//比较字符串大小
int my_strcmp(char *str1, char *str2) {
    //当字符相差为0时且两个字符不同时为'\0'(字符串结尾)，此时两个字符相等，移动到下一个字符继续比较
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

//冒泡排序
void sort(char **str,int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            //较大的字符串往数组上面移动
            if (my_strcmp(str[j],str[j+1])>0)
            {
                swap(&str[j],&str[j+1]);
            }
        }
    }
}

int main(){
    int n;
    printf("请输入字符串个数n:");
    scanf("%d",&n);
    //读取缓冲区的回车字符
    getchar();
    //动态分配空间存储字符串数组，就是分配有n个字符串的数组
    char **str=(char**)malloc(n*sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        //分配数组中每个字符串的空间，就是字符串中能有多少个字符
        str[i]=(char *) malloc(N * sizeof(char));
        printf("请输入第%d个字符串\n",i+1);
        gets(str[i]);
    }
    printf("排序前字符串为：\n");
    for (int j = 0; j < n; j++)
    {
        printf("%s\n",str[j]);
    }
    sort(str,n);
    printf("排序后字符串为：\n");
    for (int j = 0; j < n; j++)
    {
        printf("%s\n",str[j]);
    }
    for (int j = 0; j < n; j++)
    {
        //先释放字符串所占的空间
        free(str[j]);
    }
    //最后释放字符串数组占用的空间
    free(str);
    return 0;
}