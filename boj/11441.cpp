#include <cstdio>
#include <iostream>
using namespace std;
int N, Sum[100005], M;

/*
숫자는 최대 100000개 이고 구간 쿼리는 최대 100000개이다.
구간을 일일이 구한다면 시간 복잡도는 최대 100000 * 100000이다.
누적합을 이용해서 쿼리의 시간복잡도를 O(1)로 만든다면
O(N)으로 풀수 있다.
구간 s부터 e 까지의 합은 처음부터 e까지를 더한 누적합에서 처음부터 s - 1까지 더한
누적합을 뺴면 s부터 e까지의 누적합을 구할수 있다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int num;
        scanf("%d", &num);
        //합을 계속 누적 시킴
        Sum[i] = Sum[i - 1] + num;
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", Sum[e] - Sum[s - 1]);
    }
}