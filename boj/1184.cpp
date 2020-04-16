#include <bits/stdc++.h>
using namespace std;
int N, Sum[55][55], result, Count[5200005], chk[2505], chkIdx;

/*
두 사람 땅의 수익의 합이 같은지 확인하기 위해서는 각 사람의 땅을 하나씩 확인하면서 수익을 구할 수 있다.
하지만 경우의 수가 많기 때문에 하나씩 확인하면서 구하기에는 시간이 오래 걸린다.
모든 땅은 직사각형의 모양으로 되어있기 때문에 부분합을 이용하여 각 경우의 수마다 수익을 O(1)로 확인 할 수 있다.
이제 경우의 수가 몇 개인지 확인해야 하는데 각각의 경우의 수마다 수익을 비교하는 것은 너무 오래 걸리므로
두 사람 중 한 사람의 수익들의 개수를 저장하고 나머지 한 사람은 각 경우의 수를 만들면서 해당 수익이
반대쪽에 존재하는지 확인을 하는 방식으로 하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int num;
            scanf("%d", &num);
            Sum[i][j] = Sum[i - 1][j] + Sum[i][j - 1] + num - Sum[i - 1][j - 1];
        }
    }
    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            // '\'모양의 아래쪽 수익 개수 저장
            chkIdx = 0;
            for(int k = i + 1; k <= N; k++)
            {
                for(int l = j + 1; l <= N; l++)
                {
                    Count[Sum[k][l] - Sum[i][l] - Sum[k][j] + Sum[i][j] + 2500000]++;
                    chk[chkIdx++] = Sum[k][l] - Sum[i][l] - Sum[k][j] + Sum[i][j] + 2500000;
                }
            }
            // '\'모양의 위쪽 경우의 수 만들면서 아래쪽 수익 존재 확인
            for(int k = i; k >= 1; k--)
            {
                for(int l = j; l >= 1; l--)
                {
                    result += Count[Sum[i][j] - Sum[i][l - 1] - Sum[k - 1][j] + Sum[k - 1][l - 1] + 2500000];
                }
            }
            //초기화
            for(int k = 0; k < chkIdx; k++)
            {
                Count[chk[k]] = 0;
            }
            chkIdx = 0;
            for(int k = i + 1; k <= N; k++)
            {
                for(int l = j - 1; l >= 1; l--)
                {
                    Count[Sum[k][j - 1] - Sum[k][l - 1] - Sum[i][j - 1] + Sum[i][l - 1] + 2500000]++;
                    chk[chkIdx++] = Sum[k][j - 1] - Sum[k][l - 1] - Sum[i][j - 1] + Sum[i][l - 1] + 2500000;
                }
            }            
            for(int k = i; k >= 1; k--)
            {
                for(int l = j; l <= N; l++)
                {
                    result += Count[Sum[i][l] - Sum[i][j - 1] - Sum[k - 1][l] + Sum[k - 1][j - 1] + 2500000];
                }
            }
            for(int k = 0; k < chkIdx; k++)
            {
                Count[chk[k]] = 0;
            }
        }
    }
    printf("%d", result);
}