#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100005], One, Two, vec[100005], result;
int n, Count[100005], chk[100005], Cur;

/*
처음과 끝은 주어진 수들중 1번밖에 나오지 않는다. 1번만 나오는 수 하나는 시작, 나머지는
끝으로 잡는다. 2번째 수와 마지막 바로 앞에 수는 2번 밖에 나오지 않는다. 2개의 수중에서
시작으로 했던 수와 같이 등장하는 수를 2번째로 잡는다.
이제 첫번째 두번째 수와 같이 등장하는 수를 세번째로 잡고 네번째는 두번째, 세번째와
같이 나오는 수로 잡고.... 이러한 방식으로 나머지 수들을 채우면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int num;
            scanf("%d", &num);
            //등장 횟수 카운트
            Count[num]++;
            //i번째 구간에 num이 들어감
            arr[i].push_back(num);
            //num은 i번째 구간에 속함
            vec[num].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(Count[i] == 1)
            One.push_back(i);
        else if(Count[i] == 2)
            Two.push_back(i);
    }
    chk[One[0]] = 1;
    result.push_back(One[0]);
    Cur = vec[One[0]][0];
    for(int i = 0; i < arr[Cur].size(); i++)
    {
        if(Count[arr[Cur][i]] == 2)
        {
            result.push_back(arr[Cur][i]);
            chk[arr[Cur][i]] = 1;
        }
    }
    for(int i = 0; i < arr[Cur].size(); i++)
    {
        if(Count[arr[Cur][i]] == 3)
        {
            result.push_back(arr[Cur][i]);
            chk[arr[Cur][i]] = 1;
        }
    }
    int idx = 0;
    while(1)
    {
        if(idx == n - 3)
            break;
        for(int i = 0; i < vec[result[idx]].size(); i++)
        {
            for(int j = 0; j < 3; j++)
            {
                Cur = vec[result[idx]][i];
                //체크가 안된건 이제 나올 차례
                if(chk[arr[Cur][j]] == 0)
                {
                    chk[arr[Cur][j]] = 1;
                    result.push_back(arr[Cur][j]);
                }
            }
        }
        idx++;
    }
    for(int i = 0; i < Two.size(); i++)
    {
        if(chk[Two[i]] == 0)
            result.push_back(Two[i]);
    }
    result.push_back(One[1]);
    for(int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
}