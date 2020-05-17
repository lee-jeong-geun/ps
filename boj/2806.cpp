#include <bits/stdc++.h>
using namespace std;
int N, A[5], B[5];
char word[1000005];

/*
첫 번째부터 i 번째까지 한 번에 뒤집는 연산을 이용한다.
i 번째까지 전부 A로 만드는 최소 연산은 i - 1까지 전부 A로 만든 다음 i를 A로 만들거나
i - 1까지 전부 B로 만든 다음 i까지 A로 바꾼 것 중 최소 연산이다.
이러한 방식으로 한 글자씩 붙이면서 N개를 완성 시킬 때 최소 연산을 구하면 된다.
*/

int main()
{
    scanf("%d %s", &N, word);
    for(int i = 0; i < N; i++)
    {
        if(word[i] == 'A')
        {
            A[1] = min(A[0], B[0] + 1);
            B[1] = min(A[0] + 1, B[0] + 1);
        }
        else
        {
            A[1] = min(A[0] + 1, B[1] + 1);
            B[1] = min(A[0] + 1, B[1]);
        }
        A[0] = A[1];
        B[0] = B[1];
    }
    printf("%d", min(A[1], B[1] + 1));
}