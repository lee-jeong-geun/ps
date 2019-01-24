#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, Num[135], chk[10005], result[5];

/*
수들을 정렬 후 큰 수들부터 접근 한다.
처음에 제일 큰 수가 x값이 된다. x의 약수를 전부 제거 후 남은 수들중 가장 큰 수가 y가 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
        chk[Num[i]]++;
    }
    sort(Num, Num + n);
    result[0] = Num[n - 1];
    for(int i = n - 1; i >= 0; i--)
    {
        //x와 y의 공약수도 있으므로 공약수 존재시 하나만 제거
        if(result[0] % Num[i] == 0 && Num[i] != Num[i + 1])
        {
            chk[Num[i]]--;
        }
    }
    for(int i = n - 2; i >= 0; i--)
    {
        if(chk[Num[i]] == 1)
        {
            result[1] = Num[i];
            break;
        }
    }
    printf("%d %d", result[0], result[1]);
}