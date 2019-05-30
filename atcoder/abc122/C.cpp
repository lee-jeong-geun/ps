#include <cstdio>
#include <iostream>
using namespace std;
int N, Q, Sum[100005];
char S[100005];

/*
누적합 배열에 AC의 시작 위치 인덱스에 1을 저장 후 
배열 전체를 돌면서 합들을 누적 시킨다.
쿼리는 Sum[r] - Sum[l - 1] 이지만 이때 AC의 A부분이 쿼리의 끝일수 있으므로
Sum[r - 1] - Sum[l - 1]로 예외 처리를 해주면 된다.
*/

int main()
{
    scanf("%d %d %s", &N, &Q, S);
    for(int i = 0; i < N; i++)
    {
        //AC위치에 1저장
        if(S[i] == 'A' && S[i + 1] == 'C')
        {
            Sum[i + 1] = 1;
            i++;
        }
    }
    //모든 1을 누적
    for(int i = 1; i <= N; i++)
    {
        Sum[i] += Sum[i - 1];
    }
    for(int i = 0; i < Q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", Sum[r - 1] - Sum[l - 1]);
    }
}