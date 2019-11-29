#include <bits/stdc++.h>
using namespace std;
set<string> s;
set<int> s2;
vector<string> vec;
int n, result;
string word[15];

/*
나오는 개수는 최대 10개이고 각각의 자리에 나올수 있는 번호는 0 ~ 9까지 총 10개 이므로
맨앞자리로 10개의 수를 모두 구분 가능하다. 따라서 중복된 번호가 존재시 0 ~ 9 사이로 바꿔주면 된다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        result = 0;
        vec.clear();
        s.clear();
        s2.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            cin >> word[i];
            //맨앞자리 사용 여부 확인
            s2.insert(word[i][0] - '0');
        }
        for(int i = 0; i < n; i++)
        {
            //중복된 번호인 경우
            if(s.find(word[i]) != s.end())
            {
                result++;
                for(int j = 0; j < 10; j++)
                {
                    string temp;
                    temp = word[i];
                    temp[0] = j + '0';
                    //j번호가 안쓰였고 j번호를 맨앞자리로 사용했을때 중복이 아닌 경우
                    if(s2.find(j) == s2.end() && s.find(temp) == s.end())
                    {
                        s2.insert(j);
                        word[i] = temp;
                        break;
                    }
                }
            }
            s.insert(word[i]);
            vec.push_back(word[i]);
        }
        cout << result << endl;
        for(int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << endl;
        }
    }
}