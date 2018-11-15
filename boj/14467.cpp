#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, chk[15], result;

/*
단순하게 해당 배열의 값이 몇번 바뀌었는지 확인하면 된다.
*/

int main()
{
    scanf("%d", &N);
    memset(chk, -1, sizeof chk);
    for(int i = 0; i < N; i++)
    {
        int num, pos;
        scanf("%d %d", &num, &pos);
        //맨 처음 상태가 아닌경우
        if(chk[num] != -1)
        {
            result += chk[num] ^ pos;
        }
        chk[num] = pos;
    }
    printf("%d", result);
}