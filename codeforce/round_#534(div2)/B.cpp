#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
int Count;
char s[100005];

/*
같은 종류이면서 2개가 붙어있는 소문자들을 번갈아 가면서 지우는 것이다.
지웠다면 떨어진 문자열을 합치면서 계속 지워야 한다.
스택을 이용하여 스택의 top에 있는 문자와 같으면 스택에서 pop해줬고
다르면 스택에 push하면서 몇번을 지웠는지 카운트 후 그게 홀수 인지 짝수인지 판단 하였다.
홀수라면 승리 짝수라면 패배이다.
*/

int main()
{
    int length;
    scanf("%s", s);
    length = strlen(s);
    stack<char> st;
    st.push(s[0]);
    for(int i = 1; i < length; i++)
    {
        if(st.size() > 0 && st.top() == s[i])
        {
            st.pop();
            Count++;
        }
        else
        {
            st.push(s[i]);
        }
    }
    if(Count % 2 == 0)
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }
}