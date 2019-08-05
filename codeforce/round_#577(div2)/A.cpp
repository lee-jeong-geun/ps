#include <bits/stdc++.h>
using namespace std;
int n, m, chk[1005][30], result, arr[1005];

/*
각 질문에 제일 많이 나오는 알파벳을 찾은 다음 각 질문에 대한 값을 곱해주면 된다.
*/

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char word;
            scanf(" %c", &word);
            chk[j][word - 'A']++;
        }
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < m; i++)
    {
        int Max = 0;
        //제일 많이 나오는 알파벳 카운트
        for(int j = 0; j < 30; j++)
        {
            Max = max(Max, chk[i][j]);
        }
        result += Max * arr[i];
    }
    printf("%d", result);
}