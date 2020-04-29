#include <bits/stdc++.h>
using namespace std;
int N, M, Start[2][1000005], Count[2][1000005];

/*
페스트리가 2등분 되는 조건은 수직으로 자를 때 3개의 점 중에서 가장 작은 x 점과 가장 큰 x 점
사이에 있어야 한다. 이러한 조건을 이용해서 해결한다.
우선 매 쿼리마다 페스트리 전체를 보면서 처리하기에는 시간 복잡도가 O(N * M)이 되므로 
시간이 오래 걸린다. 좌표의 범위가 0~1000000이므로 백만짜리 배열을 생성 후 부분합으로 
빠르게 구해주면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int minX = 987654321, minY = 987654321, maxX = -1, maxY = -1;
        for(int j = 0; j < 3; j++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }
        Start[0][minX + 1]++;
        Start[0][maxX]--;
        Start[1][minY + 1]++;
        Start[1][maxY]--;
    }
    for(int i = 1; i <= 1000000; i++)
    {
        Count[0][i] = Start[0][i] + Count[0][i - 1];
        Count[1][i] = Start[1][i] + Count[1][i - 1];
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        char op;
        int num, temp = 0;
        scanf(" %c = %d", &op, &num);
        if(op == 'y')
            temp = 1;
        printf("%d\n", Count[temp][num]);
    }
}