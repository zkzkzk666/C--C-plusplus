#include<stdio.h>

//交换函数，交换两个数
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//选择排序，从小到大
//参数：arr[]表示待排序数组，len表示该数组长度
void select_sort(int arr[],int len){
    //外层循环遍历数组中所有的数，最后一个数可以不用遍历，因为最后一个数肯定就是最大的数
    for (int i = 0; i < len-1; i++)
    {
        //记录最小数的位置，初始时为i
        int min=i;
        //内层循环遍历arr[i]之后的所有数，找出其中最小的那个数
        for (int j = i+1; j < len; j++)
        {
            //如果这个数比最小数还要小，那么它就变成最小的数
            if (arr[j]<arr[min])
            {
                min=j;
            }
        }
        //如果最小数就是i本身，就不用交换了，不是的话就交换两个数
        if (i!=min)
        {
            swap(arr+i,arr+min);
        }
    }
}
int main(){
    int arr[10]={3,2,1,7,5,9,8,4,10,6};
    select_sort(arr,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}