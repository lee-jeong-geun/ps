#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
int R, S, result;
char zone[55][55];
int arrR[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int arrC[8] = {1, 1, 0, -1, -1, -1, 0, 1};

/*
조건에 맞게 구현하면 된다.
*/

int main()
{
    scanf("%d %d", &R, &S);
    for(int i = 0; i <= R + 1; i++)
    {
        for(int j = 0; j <= S + 1; j++)
        {
            zone[i][j] = '.';
        }
    }
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= S; j++)
        {
            scanf(" %c", &zone[i][j]);
            if(zone[i][j] == '.')
                vec.push_back({i, j});
        }
    }
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= S; j++)
        {
            if(zone[i][j] == '.')
                continue;
            for(int k = 0; k < 4; k++)
            {
                if(zone[i + arrR[k]][j + arrC[k]] == 'o')
                    result++;
            }
        }
    }
    int tempResult = result;
    for(int i = 0; i < vec.size(); i++)
    {
        int count = tempResult;
        for(int j = 0; j < 8; j++)
        {
            if(zone[vec[i].first + arrR[j]][vec[i].second + arrC[j]] == 'o')
                count++;
        }
        result = max(result, count);
    }
    printf("%d", result);
}