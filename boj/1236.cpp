#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, chkx[55], chky[55], rex, rey;

/*
X를 입력 받으면 해당 행과 열을 체크한다.
체크 안된 개수를 세서 행과 열중 큰것을 출력하면 된다.
*/

int main()
{
    scanf("%d %d", &N, &M);
    rex = M;
    rey = N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            char a;
            scanf(" %c", &a);
            if(a == 'X')
            {
                if(chkx[j] == 0)
                {
                    rex--;
                    chkx[j] = 1;
                }
                if(chky[i] == 0)
                {
                    rey--;
                    chky[i] = 1;
                }
            }
        }
    }
    printf("%d", max(rex, rey));
}