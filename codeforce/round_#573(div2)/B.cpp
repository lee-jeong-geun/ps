#include <bits/stdc++.h>
using namespace std;
vector<int> vec[5];
int op[30], result;

/*
같은 알파벳에 대해서 벡터에 숫자만 집어 넣고 숫자 3개가 같은지 or 숫자 3개가 1씩 오름차순인지 확인한다.
이게 아니라면 같은 숫자가 몇개가 있는지 or 1씩 오름차순이 몇개가 있는지 확인하면 된다.
*/

int main()
{
    op['p' - 'a'] = 1;
    op['s' - 'a'] = 2;
    for(int i = 0; i < 3; i++)
    {
        string str;
        cin >> str;
        vec[op[str[1] - 'a']].push_back(str[0] - '0');
    }
    for(int i = 0; i < 3; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    result = 2;
    for(int i = 0; i < 3; i++)
    {
        int count[5] = {0};
        for(int j = 0; j < (int)vec[i].size() - 1; j++)
        {
            //1씩 차이나는 오름 차순인 경우
            if(vec[i][j] == vec[i][j + 1] - 1)
                count[0]++;
            //수가 같은 경우
            if(vec[i][j] == vec[i][j + 1])
                count[1]++;
            //1, 3, 5 처럼 2씩 차이 나는 경우
            if(vec[i][j] == vec[i][j + 1] - 2)
                count[2]++;
        }
        if(count[2] >= 1)
            result = min(result, 1);
        result = min(result, 2 - count[0]);
        result = min(result, 2 - count[1]);
    }
    printf("%d", result);
}