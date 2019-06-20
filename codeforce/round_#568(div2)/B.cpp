#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec[5];
int n;
char word[5][1000005];

/*
첫번째와 두번째 모두 연속된 글자를 하나로 압축 시키고 몇개가 연속이였는지
{알파벳, 연속된 개수}형식으로 저장을 한다.
이제 두 단어를 비교하면서 같은 위치에 알파벳이 다른 경우거나 두번째 단어의 연속된 개수가
첫번째보다 미만인 경우 틀린 답이 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int tc = 0; tc < n; tc++)
    {
        int flag = 0;
        //{알파벳, 연속된 개수}의 형식을 저장하는 벡터
        vec[0].clear();
        vec[1].clear();
        scanf("%s %s", word[0], word[1]);
        int length1, length2;
        length1 = strlen(word[0]);
        length2 = strlen(word[1]);
        int count = 1;
        //연속된 글자들 카운트
        for(int i = 0; i < length1; i++)
        {
            //다른 글자라면 카운트를 0을 바꿈
            if(word[0][i] != word[0][i + 1])
            {
                vec[0].push_back({word[0][i] - 'a', count});
                count = 0;
            }
            count++;
        }
        count = 1;
        for(int i = 0; i < length2; i++)
        {
            if(word[1][i] != word[1][i + 1])
            {
                vec[1].push_back({word[1][i] - 'a', count});
                count = 0;
            }
            count++;
        }
        for(int i = 0; i < vec[0].size(); i++)
        {
            //틀린 답이 되는 경우
            if(vec[0][i].first != vec[1][i].first || vec[0][i].second > vec[1][i].second)
            {
                flag = 1;
                break;
            }
        }
        //압축 시킨 형식의 크기가 다르면 틀린 답
        if(vec[0].size() != vec[1].size())
            flag = 1;
        if(flag == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}