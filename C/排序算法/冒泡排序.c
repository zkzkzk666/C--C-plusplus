#include<stdio.h>

//交换两个数
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//冒泡排序，每一趟排序把最大的数移动到最右端
//参数：arr[]表示待排序数组，len表示该数组长度
void bubble_sort(int arr[],int len){
    //外层循环控制此次排序一共有多少趟
    for (int i = 0; i < len; i++)
    {
        //内层排序控制一趟排序有多少次比较
        //因为每一趟排序会确定一个最大的数，所以下一次排序就可以直接比较最大数之前的那些数就可以了
        for (int j = 0; j <len-i-1; j++)
        {
            //如果前一个数比后一个数大，那么就交换它们，从而实现大的数在后面小的数在前面
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[10]={3,2,1,7,5,9,8,4,10,6};
    bubble_sort(arr,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}