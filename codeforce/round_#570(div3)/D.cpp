#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
set<int> s;
multiset<int> ms;
int n, result;

/*
주어진 배열에서 같은 값을 가진 원소들을 하나로 합쳐 개수만 남긴다.
개수가 작은것 부터 접근해서 중복된 개수가 아니라면 결과값에 더하고 중복된 개수라면
그 값을 하나씩 빼서 0보다크면서 중복이 없을때까지 확인한다.
*/

int main()
{
    int q;
    scanf("%d", &q);
    for(int tc = 0; tc < q; tc++)
    {
        result = 0;
        m.clear();
        s.clear();
        ms.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            //해당 원소 개수 카운트
            m[num]++;
        }
        for(auto i = m.begin(); i != m.end(); i++)
        {
            //멀티셋에 개수를 원소로 저장
            ms.insert(i->second);
        }
        for(auto i = ms.begin(); i != ms.end(); i++)
        {
            //한번도 안나온 값인 경우
            if(s.find(*i) == s.end())
            {
                result += *i;
                s.insert(*i);
            }
            else
            {
                int temp;
                temp = *i - 1;
                while(temp > 0)
                {
                    //한번도 안나온 경우
                    if(s.find(temp) == s.end())
                    {
                        s.insert(temp);
                        result += temp;
                        break;
                    }
                    temp--;
                }
            }
        }
        printf("%d\n", result);
    }
}