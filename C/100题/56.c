/* 有 15 个数按由大到小顺序存放在一个数组中，输入一个数，要求用折半查找法找出
该数是数组中第几个元素的值。如果该数不在数组中，则输出“无此数”。*/
#include<stdio.h>

//折半查找法，n是查找的那个数，arr是数组，len是数组长度
int binarySearch(int n,int *arr,int len){
    //定义三个指针分别指向数组前中后
    int low=0;
    int high=len-1;
    int mid=(low+high)/2;
    //如果这个数比数组中最大数还要大，比最小数还要小时，在数组中肯定找不到该数，返回-1
    if (n<arr[high]||n>arr[low])
    {
        return -1;
    }
    //当数组的头指针比尾指针小时，说明查询未结束，继续进行折半查找
    while (low<=high)
    {
        //相等时说明已经找到，返回此时mid值，也就是数组中该数的下标
        if (n==arr[mid])
        {
            return mid;
        }
        //要找的数比数组中间的数大时，说明该数可能在数组的左边
        //此时应该改变high的值，使之指向mid之前的那个数
        else if (n>arr[mid])
        {
            high=mid-1;
        }
        //要找的数比数组中间的数小时，说明该数可能在数组的右边
        //此时应该改变low的值，使之指向mid之后的那个数
        else if (n<arr[mid])
        {
            low=mid+1;
        }
        //改变mid的指向，使之指向当前数组的中间
        mid=(low+high)/2;
    }
    //若循环结束之后，还是没有找到，说明数组中无此数
    return -1;
}


int main(){
    //创建数组
    int arr[15]={100,87,84,80,64,59,56,55,50,49,38,33,30,28,17};
    int len=sizeof(arr)/sizeof(arr[0]);
    int n;
    printf("请输入你想查找的数\n");
    scanf("%d",&n);
    //返回值为-1时就是数组中无此数
    if (binarySearch(n,arr,len)!=-1)
    {
        printf("该数是数组中第%d个元素的值\n",binarySearch(n,arr,len)+1);
    }
    else{
        printf("无此数");
    }
    return 0;
}