#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Count[2][100005], Max[2][5], result;

/*
홀수, 짝수 인덱스 나누어서 나오는 수들을 카운트 한다음
최대 등장 수와 그다음 등장 수를 저장후 홀수 짝수 최대 등장 수가 다를 경우와 같은 경우로 나누어서
해결 하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        Count[i % 2][num]++;
    }
    for(int i = 1; i <= 100000; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            //최대 등장 수보다 더 많이 등장한 경우
            if(Count[j][Max[j][0]] < Count[j][i])
            {
                //최대 등장 수를 2번째로 내림
                Max[j][1] = Max[j][0];
                Max[j][0] = i;
            }
            //2번째로 많이 나온 등장 수와 비교
            else if(Count[j][Max[j][1]] < Count[j][i])
            {
                Max[j][1] = i;
            }
        }
    }
    //홀수 짝수 다른 경우
    if(Max[0][0] != Max[1][0])
    {
        result = Count[0][Max[0][0]] + Count[1][Max[1][0]];
    }
    else
    {
        //홀수 1 짝수 2, 홀수 2 짝수 1의 쌍으로 비교
        result = max(Count[0][Max[0][0]] + Count[1][Max[1][1]], Count[0][Max[0][1]] + Count[1][Max[1][0]]);
    }
    printf("%d", N - result);
}