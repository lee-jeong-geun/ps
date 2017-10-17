#include <cstdio>
#include <iostream>
using namespace std;
int N;
char arr[1005], Num[70];

int chk(int a, int count)
{
    int idx = 0;
    while(a != 0)
    {
        arr[idx] = Num[a % count];
        idx++;
        a = a / count;
    }
    for(int i = 0; i < idx / 2; i++)
    {
        if(arr[i] != arr[idx - i - 1])
        {
            return 0;
        }
    }
    return 1;
} 

int main()
{
    for(int i = 0; i < 10; i++)
    {
        Num[i] = (char)i + '0';
    }
    for(int i = 10; i < 36; i++)
    {
        Num[i] = (char)(i - 10) + 'A';
    }
    for(int i = 36; i < 62; i++)
    {
        Num[i] = (char)(i - 36) + 'a';
    }
    Num[62] = '!';
    Num[63] = '@';
    Num[64] = '#';
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        int flag = 0;
        scanf("%d", &N);
        for(int i = 2; i <= 64; i++)
        {
            if(chk(N, i) == 1)
            {
                flag = 1;
                break;
            }
        }
        printf("%d\n", flag);
    }
}