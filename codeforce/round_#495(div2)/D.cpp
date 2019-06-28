#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
int t, Count[1000005], tCount[1000005], Max;
long long Sum;

/*
주어진 t값으로 직사각형을 만들 때 방법은 t를 20으로 잡았을 때 1 * 20, 2 * 10, 4 * 5처럼
t의 약수를 이용하여 직사각형을 만들 수 있다. 두개의 변을 만들었으면 이제 0의 좌표를 찾아야 한다.
주어진 수의 최대값은 0과 거리가 제일 먼 값이다. 이것을 이용하여 최대값을 1, 1로 잡고 0의 좌표를
찾아야 하는데 0의 좌표들의 후보는 가로/2이상 이면서 세로/2 이상이여야 한다.
이러한 좌표들의 후보들을 돌면서 주어진 직사각형 원소들의 전체 합과 0의 좌표를 잡았을 때의 직사각형
원소들의 전체 합이 같은지 확인하고 같다면 그때 전체 원소들이 같은지 확인하면 된다.
원소들의 합을 구할 땐 전체 원소를 하나씩 구하면서 합을 구하기에는 시간이 너무 오래 걸리므로
등차수열의 합을 이용하여 O(1)만에 구하면 된다.
*/

//약수 구하는 함수
void chk(int num)
{
    int ret = 0;
    int Sqrt = sqrt(num);
    for(int i = 1; i <= Sqrt; i++)
    {
        if(num % i == 0)
            vec.push_back({i, num / i});
    }
}

int main()
{
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        int num;
        scanf("%d", &num);
        Max = max(Max, num);
        Count[num]++;
        Sum += num;
    }
    chk(t);
    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = vec[i].first; j >= vec[i].first / 2; j--)
        {
            long long s = 0, l, r, temp;
            int y;
            //0의 열 좌표
            y = Max - j + 2;
            //0의 열 좌표가 직사각형의 가로/2 보다 작으면 유효하지 않음
            if(y < vec[i].second / 2)
                continue;
            temp = vec[i].second - y;
            //0이 있는 행의 0의 오른쪽 원소들의 합
            r = temp * (temp + 1) / 2;
            temp = y - 1;
            //0이 있는 행의 0의 왼쪽 원소들의 합
            l = temp * (temp + 1) / 2;
            //0의 아래 행들의 원소들의 합
            s += (vec[i].first - j + 1) * (l + r + l + r + (vec[i].first - j) * vec[i].second) / 2;
            //0의 위 행들의 원소들의 합
            s += (j - 1) * (l + r + vec[i].second + l + r + vec[i].second * (j - 1)) / 2;
            if(Sum == s)
            {
                memset(tCount, 0, sizeof tCount);
                //전체 원소 비교
                for(int k = 1; k <= vec[i].first; k++)
                {
                    for(int l = 1; l <= vec[i].second; l++)
                    {
                        tCount[abs(k - j) + abs(l - y)]++;
                    }
                }
                int flag = 0;
                for(int i = 1; i <= Max; i++)
                {
                    if(tCount[i] != Count[i])
                        flag = 1;
                }
                if(flag == 0)
                {
                    printf("%d %d\n%d %d", vec[i].first, vec[i].second, j, y);
                    return 0;
                }
            }
        }
    }
    printf("-1");
}