#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, string>> vec[1000005], same, notsame;
vector<int> sortNum;
vector<pair<pair<string, string>, pair<string, string>>> result;
int n, chk[30], visit[1000005];
string word;

/*
우선 각각의 단어들을 {모음의 개수, 마지막 모음, 단어}의 형식으로 처리를 한 후 
벡터[모음의 개수]에 넣어준다. 이제 마지막 모음이 같은 단어들을 처리 해야한다.
그것은 벡터의 각 인덱스 안에 있는 원소들을 탐색하면서 vec[i][j] == vec[i][j + 1]이 같다면
같은 쌍들을 관리하는 벡터에 넣어준다. 그게 아니라면 다른 쌍들을 관리하는 벡터에 넣어준다.
이렇게 하고 같은 쌍 벡터, 다른 쌍 벡터를 돌면서 서로 연결 시켜주면 된다.
*/

int main()
{
    //모음 쉽게 확인 하기 위한 배열
    chk['a' - 'a'] = 1;
    chk['e' - 'a'] = 1;
    chk['i' - 'a'] = 1;
    chk['o' - 'a'] = 1;
    chk['u' - 'a'] = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int count = 0, last;
        cin >> word;
        for(int j = 0; word[j] != 0; j++)
        {
            //모음인 경우
            if(chk[word[j] - 'a'] == 1)
            {
                count++;
                //마지막 모음 저장
                last = word[j] - 'a';
            }
        }
        //해당 모음 개수가 처음으로 나온 경우
        if(visit[count] == 0)
        {
            visit[count] = 1;
            sortNum.push_back(count);
        }
        vec[count].push_back({{count, last}, word});
    }
    //마지막 모음을 기준으로 정렬
    for(int i = 0; i < sortNum.size(); i++)
    {
        sort(vec[sortNum[i]].begin(), vec[sortNum[i]].end());
    }
    for(int i = 0; i < sortNum.size(); i++)
    {
        //예외처리 하기 위해 임의의 값 삽입
        vec[sortNum[i]].push_back({{-1, -1}, "x"});
        for(int j = 0; j < vec[sortNum[i]].size() - 1; j++)
        {
            //j와 j + 1이 같다면 같은 쌍 관리하는 벡터에 삽입
            if(vec[sortNum[i]][j].first.second == vec[sortNum[i]][j + 1].first.second)
            {
                same.push_back(vec[sortNum[i]][j]);
                same.push_back(vec[sortNum[i]][j + 1]);
                j++;
            }
            //아니라면 다른 쌍 벡터에 삽입
            else
            {
                notsame.push_back(vec[sortNum[i]][j]);
            }
        }
    }
    int sameIdx = 0;
    //예외처리 위한 임의의 값 삽입
    notsame.push_back({{10000005, 10}, "x"});
    for(int i = 0; i < notsame.size() - 1; i++)
    {
        //애초에 모음의 개수가 다르면 볼 필요 없음
        if(notsame[i].first.first != notsame[i + 1].first.first)
        {
            continue;
        }
        if(sameIdx < same.size())
        {
            result.push_back({{notsame[i].second, same[sameIdx].second}, {notsame[i + 1].second, same[sameIdx + 1].second}});
            sameIdx += 2;
            i++;
        }
    }
    while(sameIdx + 4 <= same.size())
    {
        result.push_back({{same[sameIdx].second, same[sameIdx + 2].second}, {same[sameIdx + 1].second, same[sameIdx + 3].second}});
        sameIdx += 4;
    }
    printf("%d\n", result.size());
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i].first.first << " " << result[i].first.second << "\n";
        cout << result[i].second.first << " " << result[i].second.second << "\n";
    }
}