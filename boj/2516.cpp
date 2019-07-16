#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> vec[100005];
int N, color[100005], colorCount[5];

/*
처음에 모든 원숭이들을 첫번째 우리에 다 집어 넣는다.
그리고 각각의 원숭이들에 대해서 반대편 우리에 앙숙관계가 적다면 반대편으로 이동 시키고 큐에 집어 넣는다.
다시 큐에서 하나씩 빼면서 작업을 반복한다. 그게 아니라면 다른 원숭이들을 선택한다. 
모든 원숭이들에 대해 이러한 작업을 하면 된다. 증명은 설명하기 어려우므로 솔루션을 보길 추천한다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int M, num;
        scanf("%d", &M);
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &num);
            vec[i].push_back(num);
        }
    }
    queue<int> q;
    //처음에 0번 우리에 다 집어 넣음
    colorCount[0] = N;
    for(int i = 1; i <= N; i++)
    {
        q.push(i);
        while(!q.empty())
        {
            int temp, count = 0;
            temp = q.front();
            q.pop();
            for(int i = 0; i < vec[temp].size(); i++)
            {
                //같은 우리에 앙숙관계가 있는 경우
                if(color[temp] == color[vec[temp][i]])
                    count++;
                //반대편 우리
                else
                    count--;
            }
            //반대편 우리의 앙숙관계가 더 많은 경우
            if(count <= 0)
                continue;
            //원숭이를 반대편으로 옮김
            colorCount[color[temp]]--;
            colorCount[!color[temp]]++;
            color[temp] ^= 1;
            for(int i = 0; i < vec[temp].size(); i++)
            {
                q.push(vec[temp][i]);
            }
        }
    }
    for(int i = 0; i < 2; i++)
    {
        printf("%d ", colorCount[i]);
        for(int j = 1; j <= N; j++)
        {
            if(color[j] == i)
                printf("%d ", j);
        }
        printf("\n");
    }
}