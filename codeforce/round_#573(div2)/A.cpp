#include <bits/stdc++.h>
using namespace std;
int x, op[5] = {0, 3, 1, 2}, result;
char str[5] = "DCBA";

/*
증가x, 1증가, 2증가 했을 때 가장 큰값을 찾으면 된다.
*/

int main()
{
    scanf("%d", &x);
    result = op[x % 4];
    result = max(result, op[(x + 1) % 4]);
    result = max(result, op[(x + 2) % 4]);
    if(op[x % 4] == result)
        printf("0 %c", str[result]);
    else if(op[(x + 1) % 4] == result)
        printf("1 %c", str[result]);
    else
        printf("2 %c", str[result]);
}