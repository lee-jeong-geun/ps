#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, zone[20][20], chk[20], result;

/*
각각의 조합들을 탐색하면 된다.
식재료들을 2개의 팀으로 나눈 후 각각의 팀을 2개씩 조합하여 시너지들을 더한다.
2개의 팀의 시너지 차이의 최소를 구하면 된다.
*/

//시너지 구하는 함수
int func2(int depth, int flag)
{
    int hap = 0;
    for(int i = 0; i < N; i++)
    {
        if(chk[i] == flag)
        {
            for(int j = 0; j < N; j++)
            {
                if(chk[j] == flag)
                {
                    hap += zone[i][j];
                }
            }
        }
    }
    return hap;
}

//팀을 나누는 함수
void func1(int depth, int idx)
{
    //기저 사례
    if(depth == N / 2)
    {
        int t1, t2;
        //0팀
        t1 = func2(0, 0);
        //1팀
        t2 = func2(0, 1);
        result = min(result, abs(t1 - t2));
        return;
    }
    for(int i = idx + 1; i < N; i++)
    {
        chk[i] = 1;
        func1(depth + 1, i);
        chk[i] = 0;
    }
}

int main()
{
    result = 987654321;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    func1(0, -1);
    printf("%d", result);
}