#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, inputcam[10005], cam[10005], cidx, result, between[10005], bidx;

/*
일단 중복 제거를 한 후 각각의 카메라의 양 옆의 거리를 계산 후 배열에 저장 한다.
그리고 그 배열을 하나의 사슬이라 생각하고 K등분을 한다고 생각하면 된다.
예제를 보면 카메라의 위치는 1, 3, 6, 7, 9이고 양옆의 거리를 계산 하면
2, 3, 1, 2라는 배열이 나오게 된다. 이 배열은 카메라들을 하나의 사슬로 만들었을때 
각각의 구간들을 나타낸다. [2][3][1][2] 이렇게 구성된 사슬을 K등분을 할 때 구간들을 최소화 해야한다.
[2][3][1][2]에서 [3]을 제거하면 [2], [1][2] <== 이렇게 2등분이 되는데 그때가 최소이다.
즉 하나의 사슬로 만들고 큰 구간 부터 K-1개를 지워주면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        cidx = 0;
        bidx = 0;
        scanf("%d %d", &N, &K);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &inputcam[i]);
        }
        //중복 제거를 위한 정렬
        sort(inputcam, inputcam + N);
        inputcam[N] = 987654321;
        //중복 제거
        for(int i = 0; i < N; i++)
        {
            if(inputcam[i] != inputcam[i + 1])
            {
                cam[cidx++] = inputcam[i];
            }
        }
        //양 옆 카메라 거리 저장
        for(int i = 0; i < cidx - 1; i++)
        {
            between[bidx++] = cam[i + 1] - cam[i];
        }
        //거리들 내림차순으로 정렬
        sort(between, between + bidx, greater<int>());
        //K-1개 부터 값을 더함(k-1개를 무시함)
        for(int i = K - 1; i < bidx; i++)
        {
            result += between[i];
        }
        printf("#%d %d\n", testcase, result);
    }
}