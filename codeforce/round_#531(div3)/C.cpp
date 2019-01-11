#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int n, x, y, result;

/*
x가 y보다 큰 경우는 아무리 문을 수리해도 다 부수기 때문에 문 전체를 없앨 수 있다.
x가 y이하인 경우는 x가 아무리 부숴도 다 수리 하기 때문에 수리하기 전에 부술수 있는 것들을
찾아야 한다. 따라서 우선순위 큐를 전체중에 가장 작은 값을 찾아내어 부수고 또 전체중에 가장 작은 값을
수리하면 된다.
*/

int main()
{
    priority_queue<int> pq;
    scanf("%d %d %d", &n, &x, &y);
    for(int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        pq.push(-num);
    }
    if(x > y)
    {
        printf("%d", n);
        return 0;
    }
    int flag = 0;
    for(int i = 0; i < n * 2; i++)
    {
        //큐가 비어있으면 종료
        if(pq.size() == 0)
        {
            break;
        }
        int temp;
        temp = pq.top() * -1;
        pq.pop();
        //부수는 턴
        if(flag == 0)
        {
            //부쉈을때 0이하인 경우
            if(temp - x <= 0)
            {
                result++;
            }
            //그게 아니라면 다시 넣음
            else
            {
                pq.push(-(temp - x));
            }
        }
        //수리
        else
        {
            pq.push(-(temp + y));
        }
        flag = !flag;
    }
    printf("%d", result);
}