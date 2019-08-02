#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
char str[1000005];
int length;
long long result, Sum[1000005];

/*
연속된 v와 o를 카운트 하는데 v는 2개이상이 연속된 경우에만 해준다.
o에 대해서 왼쪽 v의 개수와 오른쪽 v의 개수를 곱해서 결과값에 더해주면 된다.
*/

int main()
{
    scanf("%s", str);
    length = strlen(str);
    int count = 0;
    vec.push_back({0, 0});
    for(int i = 0; i < length; i++)
    {
        count = 0;
        //연속된 문자 카운트
        for(int j = i; j < length; j++)
        {
            //다르면 종료
            if(str[i] != str[j])
                break;
            count++;
            i = j;
        }
        if(str[i] == 'v')
            vec.push_back({1, count});
        else
            vec.push_back({0, count});
    }
    //v에 대해서 누적합
    for(int i = 1; i < vec.size(); i++)
    {
        Sum[i] = Sum[i - 1];
        //2개이상 연속인 v에 대해서만 합 구함
        if(vec[i].first == 1 && vec[i].second > 1)
            Sum[i] += (vec[i].second - 1);
    }
    for(int i = 1; i < vec.size(); i++)
    {
        if(vec[i].first == 0)
            result += Sum[i] * vec[i].second * (Sum[vec.size() - 1] - Sum[i]);
    }
    printf("%lld", result);
}