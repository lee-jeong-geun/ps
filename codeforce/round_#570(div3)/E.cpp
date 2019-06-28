#include <bits/stdc++.h>
using namespace std;
vector<string> vec;
set<string> s;
int n, k, Count, result;
string word;

/*
k가 100까지 밖에 안되고 최대한 긴 부분수열을 구해야 하므로 BFS를 이용하면 짧은 시간안에 구할 수 있다.
처음 주어진 단어부터 시작해서 문자들을 하나씩 지워가면서 k개를 구하면 된다.
*/

void func(string a)
{
    string temp;
    //a라는 단어에서 i번째 인덱스 하나씩 지움
    for(int i = 0; i < a.size(); i++)
    {
        temp.clear();
        //i를 제외하고 전부 temp에 저장
        for(int j = 0; j < a.size(); j++)
        {
            if(j == i)
                continue;
            temp += a[j];
        }
        //해당 단어가 한번도 안쓰이고 k보다 작은 경우
        if(s.find(temp) == s.end() && Count < k)
        {
            Count++;
            result += n - temp.size();
            vec.push_back(temp);
            s.insert(temp);
        }
    }
}

int main()
{
    int length;
    scanf("%d %d", &n, &k);
    cin >> word;
    int idx = 0, tsize = 1;
    vec.push_back(word);
    s.insert(word);
    Count = 1;
    //BFS 큐대신 벡터 이용
    while(1)
    {
        tsize = vec.size();
        for(int i = idx; i < vec.size(); i++)
        {
            //k개 구했으면 빠져나옴
            if(Count == k)
                break;
            func(vec[i]);
        }
        //k개를 다 구했거나 전체를 다 돌았는데 k개를 못구한 경우
        if(Count == k || tsize == vec.size())
            break;
        idx = tsize;
    }
    if(Count < k)
        result = -1;
    printf("%d", result);
}