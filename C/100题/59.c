// 有一行电文，已按下面规律译成密码：
// A→Z a→z 
// B→Y b→y 
// C→X c→x
/*即第 1 个字母变成第 26 个字母，第 i 个字母变成第（26-i+1）个字母，非字母字
符不变。要求编程序将密码译回原文，并输出密码和原文。*/
#include<stdio.h>

int main(){
    char str[]="Svool Dliow!";
    printf("密码：");
    puts(str);
    int i=0;
    while (str[i]!='\0')
    {
        if (str[i]>='A'&&str[i]<='Z')
        {
            str[i]='Z'-str[i]+'A';
        }
        else if (str[i]>='a'&&str[i]<='z')
        {
            str[i]='z'-str[i]+'a';
        }
        i++;
    }
    printf("原文：");
    puts(str);
    return 0;
}