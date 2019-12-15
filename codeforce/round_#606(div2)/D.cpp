#include <bits/stdc++.h>
using namespace std;
set<string> s[5];
vector<pair<string, int>> vec[5];
vector<int> result;
int t, n, flag[5];

/*
01110, 01111, 1110, 0110 처럼 끝나는 지점이 같은 문자인 문자열들을 전부 이어야 한다.
따라서 맨앞, 맨뒤를 제외한 안쪽 문자들은 크게 볼 필요가 없다는 뜻이다.
문자열을 뒤집어서 매칭 시킬수도 있다. 문자열을 전부 매칭시키기 위해서는 맨앞 맨뒤가 01, 10인 문자열의
개수가 중요하다. 그 이유는 맨앞 맨뒤가 00, 11은 뒤집어도 똑같은 문자열이므로 필요가 없고
01, 10은 뒤집어서 매칭 시킬수 있기 때문이다. 따라서 01, 10의 개수를 구하고 01, 10의 개수 차이가
1 이하가 되도록 개수가 많은것을 뒤집으면 된다. 단 조건중에 문자열은 항상 고유해야 하므로 뒤집은 문자열이
이미 존재하는 문자열이면 다른 문자열을 뒤집도록 한다.
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int tc = 0; tc < t; tc++)
    {
        for(int i = 0; i < 5; i++)
        {
            s[i].clear();
            vec[i].clear();
            flag[i] = 0;
        }
        result.clear();
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            string word;
            cin >> word;
            if(word[0] == '0' && *word.rbegin() == '1')
            {
                vec[0].push_back({word, i + 1});
                s[0].insert(word);
            }
            else if(word[0] == '1' && *word.rbegin() == '0')
            {
                vec[1].push_back({word, i + 1});
                s[1].insert(word);
            }
            else if(word[0] == '0' && *word.rbegin() == '0')
                flag[0] = 1;
            else
                flag[1] = 1;
        }
        //00, 11이 존재 하는데 01, 10이 없으면 00, 11만으로는 매칭 불가
        if(flag[0] == 1 && flag[1] == 1 && vec[0].size() == 0 && vec[1].size() == 0)
            flag[2] = 1;
        int Cur = 0, size[5] = {0};
        if(vec[0].size() < vec[1].size())
            Cur = 1;
        size[0] = vec[0].size();
        size[1] = vec[1].size();
        for(int i = 0; i < vec[Cur].size(); i++)
        {
            if(abs(size[0] - size[1]) <= 1)
                break;
            string temp;
            temp = vec[Cur][i].first;
            reverse(temp.begin(), temp.end());
            //뒤집은 문자열이 고유한 경우
            if(s[Cur ^ 1].find(temp) == s[Cur ^ 1].end())
            {
                result.push_back(vec[Cur][i].second);
                size[Cur]--;
                size[Cur ^ 1]++;
            }
        }
        if(flag[2] == 1)
        {
            cout << -1 << "\n";
            continue;
        }
        cout << result.size() << "\n";
        for(int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
}