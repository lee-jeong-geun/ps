#include <bits/stdc++.h>
using namespace std;
vector<int> Count, vec;
int Sum;

/*
어떻게 하든 수들을 전부 쓰게 하는게 목표다.
0 1 2 3이 있으면 답으로 가는 방법중 하나는 0을 가장 먼저 사용하는 방식이다.
0 1 0 1... 이런방식으로 0을 다 사용하면 자연스럽게 남는것은 1 2 3이고 1을 다사용 그다음은
2를 다사용... 이런식으로 전부 사용하도록 하면 된다. 하지만 0과 1은 없고 2 3만 있을 수도 있으니
모든 수에 대해서 시작으로 하고 i - 1의 수가 존재하면 i - 1를 사용하고 없으면 i + 1사용 그것도 없으면
멈추는 방식으로 하면 된다.
*/

int main()
{
    Count.push_back(0);
    for(int i = 0; i < 4; i++)
    {
        int num;
        scanf("%d", &num);
        Count.push_back(num);
        Sum += num;
    }
    Count.push_back(0);
    for(int i = 1; i <= 4; i++)
    {
        vector<int> tCount;
        int idx = i;
        vec.clear();
        if(Count[i] == 0)
            continue;
        vec.push_back(i);
        tCount = Count;
        tCount[i]--;
        while(1)
        {
            //둘다 없으면 종료
            if(tCount[idx - 1] == 0 && tCount[idx + 1] == 0)
                break;
            //i - 1이 존재하면 사용
            if(tCount[idx - 1] != 0)
                idx--;
            //i + 1이 존재하면 사용
            else if(tCount[idx + 1] != 0)
                idx++;
            vec.push_back(idx);
            tCount[idx]--;
        }
        if(vec.size() == Sum)
        {
            printf("YES\n");
            for(int j = 0; j < vec.size(); j++)
            {
                printf("%d ", vec[j] - 1);
            }
            return 0;
        }
    }
    printf("NO");
}