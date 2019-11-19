#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
int arrA[100005], arrB[100005], n, result;

/*
더해야 하는 구간이 연속되어있고 값은 양수여야 하고 같은 값을 더해야 하는지 확인하면 된다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        result = 0;
        vec.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arrA[i]);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arrB[i]);
        }
        for(int i = 0; i < n; i++)
        {
            //값이 다른것을 찾음
            if(arrA[i] != arrB[i])
                vec.push_back({i, arrB[i] - arrA[i]});
        }
        int temp = 0;
        if(vec.size() > 0)
            temp = vec[0].second;
        if(temp < 0)
            result = 1;
        for(int i = 0; i < vec.size(); i++)
        {
            //모든 더해야 하는 값이 동일해야함
            if(temp != vec[i].second)
                result = 1;
        }
        for(int i = 1; i < vec.size(); i++)
        {
            //더해야 하는 구간은 연속되어야 함
            if(vec[i].first != vec[i - 1].first + 1)
                result = 1;
        }
        if(result == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}