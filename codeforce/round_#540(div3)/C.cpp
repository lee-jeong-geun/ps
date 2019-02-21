#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> vec;
int n, Count[1005], result[25][25], vIdx;

/*
모든 수들의 개수를 저장 후 4방향에 숫자를 두면 팰린드롬이 된다.
n이 짝수, 홀수 두 경우를 생각해야 하는데 그 이유는 짝수 일때는 단순하게 4방향에 수를 두는것으로
끝낼수 있는데 홀수 일때는 배열의 정중앙을 통과하는 행,열이 있기 때문이다.
우선 팰린드롬이 되는 경우는 짝수일때 홀수 개수가 없어야 하고 홀수 일때 홀수 개수가 하나 있어야 한다.
그 다음은 개수를 내림차순으로 정렬 후 각 수들을 4방향에 넣으면 된다.
홀수 일때는 정중앙 행, 열에 넣어야 하는데 이때 홀수가 되는 수를 먼저 맨 가운데에 넣고 4의 배수들을
4방향에 넣고 남은 수들을 정중앙 행,열에 2개씩 넣으면 된다.
*/

bool comp(pii &t, pii &u)
{
    return t.second > u.second;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n * n; i++)
    {
        int num;
        scanf("%d", &num);
        Count[num]++;
    }
    int flag = 0, count = 0;
    for(int i = 1; i <= 1000; i++)
    {
        //홀수 개수 확인
        if(Count[i] % 2 == 1)
        {
            result[n / 2][n / 2] = i;
            Count[i]--;
            count++;
        }
        //개수가 0이 아니라면 벡터에 푸쉬
        if(Count[i] != 0)
        {
            vec.push_back({i, Count[i]});
        }
    }
    //내림차순으로 정렬
    sort(vec.begin(), vec.end(), comp);
    //팰린드롬이 안되는 경우
    if(n % 2 == 0 && count > 0 || n % 2 == 1 && count > 1)
    {
        flag = 1;
    }
    int tn = n;
    //홀수라면 짝수를 먼저 처리
    if(tn % 2 == 1)
    {
        tn--;
    }
    for(int i = 0; i < tn / 2; i++)
    {
        for(int j = 0; j < tn / 2; j++)
        {
            //4보다 작으면 4방향 못채움
            if(vec[vIdx].second < 4)
            {
                flag = 1;
            }
            result[i][j] = vec[vIdx].first;
            result[i][n - 1 - j] = vec[vIdx].first;
            result[n - 1 - i][j] = vec[vIdx].first;
            result[n - 1 - i][n - 1 - j] = vec[vIdx].first;
            vec[vIdx].second -= 4;
            if(vec[vIdx].second == 0 || vec[vIdx].second == 2 && n % 2 == 1)
            {
                vIdx++;
            }
        }
    }
    if(n % 2 == 1)
    {
        vIdx = 0;
        for(int i = 0; i < tn / 2; i++)
        {
            if(vec[vIdx].second == 0)
            {
                vIdx++;
                i--;
                continue;
            }
            result[i][n / 2] = vec[vIdx].first;
            result[n - 1 - i][n / 2] = vec[vIdx].first;
            vec[vIdx].second -= 2;
        }
        for(int i = 0; i < tn / 2; i++)
        {
            if(vec[vIdx].second == 0)
            {
                vIdx++;
                i--;
                continue;
            }
            result[n / 2][i] = vec[vIdx].first;
            result[n / 2][n - 1 - i] = vec[vIdx].first;
            vec[vIdx].second -= 2;
        }
    }
    if(flag == 1)
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}