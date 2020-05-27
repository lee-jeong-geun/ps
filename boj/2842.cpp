#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int N, R, C, homeCount, chk[55][55], height[55][55], result = 987654321, Count;
char zone[55][55];
int arrR[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int arrC[8] = {0, 1, 1, 1, 0, -1, -1, -1};

/*
높이를 저장한 배열을 정렬하고 하한값, 상한값 두 개를 고른 다음 그 값 사이들만 방문하도록 BFS를 돌리면 된다.
하한, 상한값을 고르는 방법은 N^2로 고르는 방법이 있지만, 시간이 너무 오래 걸리므로 하한값을 고른 후
상한값은 이분 탐색으로 찾는 방법이 있다. 하지만 이 방법도 오래 걸리므로 투 포인터를 이용하여
집 전체를 갈 수 있다면 left를 증가, 못 간다면 right를 증가시키는 방법으로 최소 피로도를 구할 수 있다.
*/

void DFS(int r, int c, int left, int right)
{
    if(height[r][c] < left || height[r][c] > right)
        return;
    if(zone[r][c] == 'K')
        Count++;
    for(int i = 0; i < 8; i++)
    {
        int nextR, nextC;
        nextR = r + arrR[i];
        nextC = c + arrC[i];
        if(nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || chk[nextR][nextC] == 1)
            continue;
        chk[nextR][nextC] = 1;
        DFS(nextR, nextC, left, right);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf(" %c", &zone[i][j]);
            if(zone[i][j] == 'P')
            {
                R = i;
                C = j;
            }
            else if(zone[i][j] == 'K')
                homeCount++;
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &height[i][j]);
            vec.push_back(height[i][j]);
        }
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int l, r;
    l = 0;
    r = 0;
    while(l <= r && r < vec.size())
    {
        memset(chk, 0, sizeof chk);
        Count = 0;
        chk[R][C] = 1;
        DFS(R, C, vec[l], vec[r]);
        if(Count == homeCount)
        {
            result = min(result, vec[r] - vec[l]);
            l++;
        }
        else
            r++;
    }
    printf("%d", result);
}