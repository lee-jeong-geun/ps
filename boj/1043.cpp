#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[105];
int N, M, T, Truth[105], chk[105], result;

//연결된 모든 노드들 탐색 하는 재귀함수
void func(int num)
{
    for(int i = 0; i < vec[num].size(); i++)
    {
        Truth[vec[num][i]] = 1;
        if(chk[vec[num][i]] == 0)
        {
            chk[vec[num][i]] = 1;
            func(vec[num][i]);
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &T);
    for(int i = 0; i < T; i++)
    {
        int num;
        scanf("%d", &num);
        Truth[num] = 1;
    }
    for(int i = 0; i < M; i++)
    {
        int num;
        scanf("%d", &num);
        for(int j = 0; j < num; j++)
        {
            int people;
            scanf("%d", &people);
            //해당 파티와 파티에 속해있는 사람을 서로 연결 해줌
            vec[i + N + 1].push_back(people);
            vec[people].push_back(i + N + 1);
        }
    }
    //진실을 말해야되는 사람일 경우 재귀함수를 탄다
    for(int i = 1; i <= N; i++)
    {
        if(Truth[i] == 1)
        {
            chk[i] = 1;
            func(i);
        }
    }
    //거짓을 말해도 되는 파티찾음
    for(int i = N + 1; i <= N + M; i++)
    {
        if(Truth[i] == 0)
        {
            result++;
        }
    }
    printf("%d", result);
}