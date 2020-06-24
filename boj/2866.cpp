#include <bits/stdc++.h>
using namespace std;
vector<string> vec;
int R, C, result;
char word[1005][1005];

/*
주어진 문자열을 정렬하고 인접한 2개의 문자가 뒤에서부터 몇 개와 같은지 개수를 센다.
뒤에서부터 접근하는 이유는 앞에서부터 접근하면 문자가 달라도 뒤의 문자가 같을 수 있으므로 계속
탐색해야 한다. 하지만 뒤에서부터 하면 문자가 다르면 아예 다른 문자열이기 때문에 더는 탐색을 안 해도
되므로 시간이 많이 줄어들게 된다.
*/

int main()
{
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            scanf(" %c", &word[i][j]);
        }
    }
    for(int i = 0; i < C; i++)
    {
        string temp;
        for(int j = R - 1; j >= 0; j--)
        {
            temp += word[j][i];
        }
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i + 1 < vec.size(); i++)
    {
        int count = 0;
        for(int j = 0; j < R; j++)
        {
            if(vec[i][j] != vec[i + 1][j])
                break;
            count++;
        }
        result = max(result, count);
    }
    printf("%d", R - result - 1);
}