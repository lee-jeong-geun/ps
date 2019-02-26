#include <cstdio>
#include <iostream>
using namespace std;
int N, result;
char word[55];

/*
커플석이 2개 있으면 1명은 앉지 못하고 3개 있으면 2명은 앉지 못한다.
따라서 커플석의 개수를 파악후 N - 커플석 + 1을 하면 되는데 커플석이 하나도 없는 경우는
N명 다 앉을 수 있다.
*/

int main()
{
    scanf("%d %s", &N, word);
    for(int i = 0; i < N; i++)
    {
        if(word[i] == 'L')
        {
            result++;
            i++;
        }
    }
    printf("%d", min(N, N - result + 1));
}