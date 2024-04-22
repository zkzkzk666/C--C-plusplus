#include <stdio.h>
void swap(int *a,int *b){
    int temp;//临时变量，来保存数据
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a=3;
    int b=4;
    swap(&a,&b);
    printf("a:%d,b:%d",a,b);
}