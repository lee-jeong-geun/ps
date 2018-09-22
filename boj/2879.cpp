#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
int N, tab[1005], result;
stack<int> s;

/*
탭 삭제 구간, 탭 추가 구간으로 구간을 나눠야 한다.
각각의 구간은 탭을 삭제 하든 추가하든 최대크기의 개수만큼 탭을 해야 한다.
5, 6, 7 이렇게 탭을 추가 해야 하면 5, 6 상관없이 무조건 7번을 추가 해야 한다.
즉 오름차순으로 되어있는 구간인 경우에는 구간의 최대값만 취하면 된다.
따라서 스택을 이용하여 top보다 큰 경우는 top을 pop해주고 큰 숫자를 push해주면 된다.
단 top보다 작은 값인 경우에는 top - 작은 값을 top을 pop해주고 push해주면 된다.
마지막에 스택에 있는 값들을 다 더 해주면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &tab[i]);
    }
    for(int i = 0; i < N; i++)
    {
        int cor, temp;
        scanf("%d", &cor);
        //음수 = 추가
        //양수 = 삭제
        temp = tab[i] - cor;
        if(i != 0)
        {
            //추가인 경우
            if(s.top() < 0 && temp < 0)
            {
                //오름차순인 경우(음수라 부호가 반대)
                if(s.top() >= temp)
                {
                    s.pop();
                }
                else
                {
                    int ttemp;
                    ttemp = s.top() - temp;
                    s.pop();
                    s.push(ttemp);
                }
            }
            //삭제인 경우
            else if(s.top() > 0 && temp > 0)
            {
                //오름차순인 경우
                if(s.top() <= temp)
                {
                    s.pop();
                }
                else
                {
                    int ttemp;
                    ttemp = s.top() - temp;
                    s.pop();
                    s.push(ttemp);
                }
            }
        }
        s.push(temp);
    }
    //결과 더하기
    while(!s.empty())
    {
        int temp;
        temp = s.top();
        s.pop();
        if(temp < 0)
        {
            temp *= -1;
        }
        result += temp;
    }
    printf("%d", result);
}