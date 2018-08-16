#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int N, Number[500005], Same[500005];
long long result;

/*
스택을 이용하여 스택에 top에 있는 값과 현재 보고 있는 Number 인덱스의 수와 비교 해서
Number 인덱스의 수가 더 크면 같거나 작은 수가 나올 때 까지 pop을 한다.
어떤 방법을 쓰든 현재 인덱스 앞에 있는 수들, 즉 스택에 있는 수들은 인덱스 다음의 수들을 못본다.
따라서 제거를 하는데 제거를 하면서 카운트를 해준다. 같은 값들도 처리해야 하므로 카운트를 할 때 중복된
값들도 같이 카운트 해줘야 한다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Number[i]);
    }
    for(int i = 0; i < N; i++)
    {
        //스택이 비어있지 않고 top이 인덱스보다 작을때
        while(s.size() != 0 && Number[s.top()] < Number[i])
        {
            int temp;
            //top인덱스 보다 뒤에있는 인덱스들  - 중복된 값 - 자기자신 - 1(바로 뒤는 한쌍 가능)
            temp = (int)s.size() - Same[s.top()] - 2;
            if(temp < 0)
            {
                temp = 0;
            }
            //현재 인덱스 - top 인덱스 - top뒤에 인덱스들 중 불가능한 쌍 개수
            result += i - s.top() - temp;
            s.pop();
        }
        //중복이면 카운트
        if(s.size() != 0 && Number[s.top()] == Number[i])
        {
            Same[i] = Same[s.top()] + 1;
        }
        s.push(i);
    }
    while(!s.empty())
    {
        int temp;
        temp = (int)s.size() - Same[s.top()] - 2;
        if(temp < 0)
        {
            temp = 0;
        }
        result += N - 1 - s.top() - temp;
        s.pop();
    }
    printf("%lld", result);
}