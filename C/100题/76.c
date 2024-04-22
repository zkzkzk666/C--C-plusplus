//选择排序
// 选择排序是一种简单直观的排序算法。它的工作原理如下:首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕
#include<stdio.h>

//交换两个数
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//选择排序
//传入数组和数组长度
void select_sort(int arr[],int len){
    //双重循环
    //外层循环是给每个arr[i]都交换每次内层循环中最小的那个数
    for (int i = 0; i < len-1; i++)
    {
        //开始时默认最小数为arr[i]
        int min=i;
        //内层循环找到本次循环中最小的那个数
        for (int j =len-1; j >i ; j--)
        {
            if (arr[j]<arr[min])
            {
                //记录最小值的下标
                min=j;
            }
        }
        //交换arr[i]与arr[min]的位置，使arr[i]成为本次循环中的最小值
        swap(&arr[i],&arr[min]);
    }
    
}

int main(){
    int arr[6]={2,6,3,5,9,1};
    printf("排序前数组：\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",arr[i]);
    }
    select_sort(arr,6);
    printf("\n排序后数组：\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}