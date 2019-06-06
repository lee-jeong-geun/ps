#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
stack<long long> s;
int l, n, flag;
long long result;
char op[5];

/*
스택을 이용하여 for연산 결과들을 전부 push한다.
for연산을 할 때 스택의 top에 있는 값 * n을 하여 이 값이 1 << 32 미만이라면 push하고
이상이라면 1 << 32를 push한다.
end연산은 pop만 하면 되고 add 연산은 스택의 top에 있는 값만 더하면 되는데 이때 결과값이
1 << 32 이상인 경우 overflow를 출력 하도록 하면 된다.
스택이 비어있는 경우의 예외를 처리하기 위해 스택에 1을 push한다. 이렇게 하면 
for연산 없이 add연산만 있는 경우의 예외를 처리 하기 쉽고 for연산을 하거나 end연산 할 때
훨씬 깔끔 해진다.
*/

int main()
{
    scanf("%d", &l);
    s.push(1);
    for(int i = 0; i < l; i++)
    {
        scanf("%s", op);
        if(op[0] == 'a')
        {
            result += s.top();
            if(result >= (1ll << 32))
                flag = 1;
        }
        else if(op[0] == 'f')
        {
            scanf(" %d", &n);
            if(s.top() * n < (1ll << 32))
                s.push(s.top() * n);
            else
                s.push(1ll << 32);
        }
        else
            s.pop();
    }
    if(flag == 1)
        printf("OVERFLOW!!!");
    else
        printf("%lld", result);
}