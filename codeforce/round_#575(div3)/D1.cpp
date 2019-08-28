#include <bits/stdc++.h>
using namespace std;
int N, K, chk[30], result;
char word[2005];

/*
각각의 구간에 대해서 시작하는 방법은 RGB, GBR, BRG 3가지에 대해서만 시작하므로
모든 구간에 대해서 3가지의 경우를 파악해서 가장 작게 바꾸는 경우를 찾으면 된다.
*/

int main()
{
    int q;
    scanf("%d", &q);
    //R은 0, G는 1, B는 2
    chk['G' - 'A'] = 1;
    chk['B' - 'A'] = 2;
    for(int tc = 0; tc < q; tc++)
    {
        result = 987654321;
        scanf("%d %d %s", &N, &K, word);
        for(int i = 0; i < N - K + 1; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int count = 0, flag = j;
                for(int k = i; k < i + K; k++)
                {
                    if(chk[word[k] - 'A'] != flag)
                        count++;
                    flag = (flag + 1) % 3;
                }
                result = min(result, count);
            }
        }
        printf("%d\n", result);
    }
}