#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, s1, s2;
char channel[15];

/*
단순하게 현재 커서에서 KBS1으로 커서를 옮기고 KBS1을 처음 위치로 옮기고 다시
커서를 KBS2로 옮기고 KBS2를 두번째 위치로 옮기면 된다.
단 KBS2가 KBS1보다 앞에 있는 경우에는 KBS1을 옮기는 과정에서 KBS2가 뒤로 한칸 옮겨지기 때문에
KBS2의 위치를 1증가 시키면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s", channel);
        if(strcmp(channel, "KBS1") == 0)
        {
            s1 = i;
        }
        if(strcmp(channel, "KBS2") == 0)
        {
            s2 = i;
        }
    }
    if(s2 < s1)
    {
        s2++;
    }
    //커서를 KBS1로 옮김
    for(int i = 0; i < s1; i++)
    {
        printf("1");
    }
    //KBS1을 첫번째로 옮김
    for(int i = s1; i > 0; i--)
    {
        printf("4");
    }
    //커서를 KBS2로 옮김
    for(int i = 0; i < s2; i++)
    {
        printf("1");
    }
    //KBS2를 두번째로 옮김
    for(int i = s2; i > 1; i--)
    {
        printf("4");
    }
}