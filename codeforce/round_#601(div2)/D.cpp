#include <bits/stdc++.h>
using namespace std;
vector<int> vec, vec2;
int r, c, k, Count;
char zone[105][105], result[105][105];

/*
우선 모든 닭들에게 최대한 공평하게 쌀을 나눠주기 위해서는 전체 쌀의 개수를 구하고
그것을 닭의 수로 나눈 만큼 닭들에게 배분하면 된다. 물론 나머지가 존재하면 나머지를 닭들에게 배분하면
된다. 이제 받은 쌀들을 연속된 구간으로 할당 해야 하는데 다른 구간들에 침범을 하지 않고 구간을
나누는 방법은 한붓 그리기로 할당 하면 된다. 처음에 1번 닭에게 한붓 그리면서 영역을 그리다가 쌀을 다
만족 시켰으면 2번 닭으로 바꾸고 .... 이런식으로 하면 영역 전체를 닭들에게 줄 수 있고 쌀도 공평하게
배분할 수 있다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < 10; i++)
    {
        vec.push_back('0' + i);
    }
    for(int i = 0; i < 26; i++)
    {
        vec.push_back('A' + i);
        vec.push_back('a' + i);
    }
    for(int tc = 0; tc < T; tc++)
    {
        scanf("%d %d %d", &r, &c, &k);
        Count = 0;
        vec2.clear();
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                scanf(" %c", &zone[i][j]);
                //쌀의 개수 구함
                if(zone[i][j] == 'R')
                    Count++;
            }
        }
        //쌀 전체를 공평하게 배분
        for(int i = 0; i < k; i++)
        {
            vec2.push_back(Count / k);
        }
        //나머지 존재시 존재하는 만큼 배분
        for(int i = 0; i < Count % k; i++)
        {
            vec2[i]++;
        }
        int riceCount = 0, idx = 0;
        for(int i = 0; i < r; i++)
        {
            //짝수번째 행은 왼쪽에서 오른쪽으로 이동
            if(i % 2 == 0)
            {
                for(int j = 0; j < c; j++)
                {
                    //해당 칸을 닭에게 할당
                    result[i][j] = vec[idx];
                    if(zone[i][j] == 'R')
                        riceCount++;
                    //idx번 닭이 쌀을 다 받았으면 다음 닭으로 넘어감
                    if(riceCount == vec2[idx])
                    {
                        //idx는 k를 넘지 못함
                        if(idx + 1 < k)
                            idx++;
                        riceCount = 0;
                    }
                }
            }
            //홀수번째 행은 오른쪽에서 왼쪽으로 이동
            else
            {
                for(int j = c - 1; j >= 0; j--)
                {
                    result[i][j] = vec[idx];
                    if(zone[i][j] == 'R')
                        riceCount++;
                    if(riceCount == vec2[idx])
                    {
                        if(idx + 1 < k)
                            idx++;
                        riceCount = 0;
                    }
                }
            }
        }
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                printf("%c", result[i][j]);
            }
            printf("\n");
        }
    }
}