// ��һ���ַ����嵽��һ���ַ����е�ָ��λ��
#include<stdio.h>
#include<stdlib.h>
//�ַ�������󳤶�Ϊ10
#define N 10

int main(){
    //��str2���뵽str1��
    char *str1=(char *)malloc(N*sizeof(char));
    char *str2=(char *)malloc(N*sizeof(char));
    printf("�����ַ���str1\n");
    gets(str1);
    printf("�����ַ���str2\n");
    gets(str2);
    //ָ��λ�ã�ҪС�ڵ���str1�ĳ���
    int n;
    printf("���������str2���뵽str1�е�λ��n��");
    scanf("%d",&n);
    //str2�ĳ���
    int length=0;
    while (str2[length]!='\0')
    {
        length++;
    }
    //������γɵ��ַ���str3
    char *str3=(char *)malloc((N+length+1)*sizeof(char));
    
    //ѭ����str3��ֵ
    for (int i = 0; i < N+length; i++)
    {
        //û�е�����λ��֮ǰ����str1�Ĳ���
        if (i<n)
        {
            str3[i]=str1[i];
        }
        //���˲���λ��ʱ����Ӧ�ò���str2
        else if (i<n+length)
        {
            str3[i]=str2[i-n];
        }
        //���str1��ʣ�ಿ�֣��͸�����ȥ
        else{
            str3[i]=str1[i-length];
        } 
    }
    str3[N + length] = '\0'; 
    printf("%s\n",str3);
    free(str1);
    free(str2);
    free(str3);
    return 0;
}
