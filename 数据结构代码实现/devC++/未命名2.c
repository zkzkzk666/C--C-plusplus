/*дһ��������֤��°ͺղ��룺һ����С�� 6 ��ż�����Ա�ʾΪ��������֮�ͣ���
6=3+3��8=3+5��10=3+7����������������һ����С�� 6 ��ż�� n��Ȼ����ú��� gotbaha��
�� gotbaha �������ٵ��� prime ������prime �������������б�һ�����Ƿ�Ϊ��
������ godbaha ���������������ʽ�Ľ����34=3+31��*/
#include<stdio.h>
int gotbaha(int n){
    //˫��ѭ���ҵ���������
    for (int num1 = 0; num1 <n; num1++)
    {
        for (int num2 = 0; num2 < n; num2++)
        {
            //��num1��num2��Ϊ������������֮�͵���nʱ�������
            if (prime(num1)&&prime(num2)&&num1+num2==n)
            {
                printf("%d=%d+%d",n,num1,num2);
                //��returnֱ������ѭ��
                return 1;
            }
        }
    }
}
//�ж�һ�����Ƿ�Ϊ����
int prime(int num){
    //1��������
    if (num==1)
    {
        return 0;
    }
    for (int i = 2; i <=(num/2); i++)
    {
        //����n�ܱ�����ʱ����������
        if ((num%i)==0)
        {
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    printf("������һ����С�� 6 ��ż��");
    scanf("%d",&n);
    gotbaha(n);
    return 0;
}
