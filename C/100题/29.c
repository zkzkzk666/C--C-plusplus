/*编程序模拟剪刀，石头和布游戏。游戏规则为:剪刀剪布，石头砸剪刀，布包石头。玩
游 戏者从键盘上输入 s (表示剪刀)或 r (表示石头)或 p(表示布)，要求两个游戏
者交替输入，计算机给出输赢的信息。*/
#include<stdio.h>

int main(){
    char a1,a2;
    printf("请玩家一选择剪刀(s)石头(r)或布(p)\n");
    a1=getchar();
    fflush(stdin);//清空缓存区,避免上次getchar中的回车被读入
    printf("请玩家二选择剪刀(s)石头(r)或布(p)\n");
    a2=getchar();
    if (a1!=a2)
    {
        if (a1=='s')
        {
            if (a2=='r')
            {
                printf("玩家二获胜\n");
            }
            else{
                printf("玩家一获胜\n");
            }
        }
        if (a1=='r')
        {
            if (a2=='p')
            {
                printf("玩家二获胜\n");
            }
            else{
                printf("玩家一获胜\n");
            }
        }
        if (a1=='p')
        {
            if (a2=='s')
            {
                printf("玩家二获胜\n");
            }
            else{
                printf("玩家一获胜\n");
            }
        }
    }
    else{
        printf("平局\n");
    }
    return 0;
}