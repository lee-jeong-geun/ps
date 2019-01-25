#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, Num[200005], Nidx, result, Mod = 998244353;
char Str[200005];

/*
주어진 문자열에서 연속적인 문자열을 제거 했을때 남은 문자들이 한종류가 되는 그러한 하위 문자열들이
몇개가 되는지 찾으면 된다.
우선 왼쪽에서부터 연속되는 문자의 개수와 오른쪽에서부터 연속되는 문자의 개수를 찾는다.
그리고 두가지의 경우를 보면 되는데 첫번째는 왼쪽 문자와 오른쪽 문자가 다를 때이다.
그때는 왼쪽문자의 개수와 오른쪽 문자의 개수 + 전체 문자를 지울때 개수(1) 만큼이 있다.
두번째는 왼쪽 오른쪽 문자가 같을 경우이다.
그때는 (왼쪽 + 1) * (오른쪽 + 1) 만큼 있다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &Str[i]);
    }
    int count = 1;
    for(int i = 0; i < n; i++)
    {
        count = 1;
        for(int j = i; j < n; j++)
        {
            if(Str[j] != Str[j + 1])
            {
                Num[Nidx++] = count;
                i = j;
                break;
            }
            count++;
        }
    }
    if(Str[0] != Str[n - 1])
    {
        result = Num[0] + Num[Nidx - 1] + 1;
    }
    else
    {
        result = (long long)(Num[0] + 1) * (Num[Nidx - 1] + 1) % Mod;
    }
    printf("%d", result);
}