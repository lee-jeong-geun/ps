#include <cstdio>
#include <iostream>
using namespace std;
int n, x, y, result;
char Bit[200005];

/*
주어진 수를 10 ^ x로 나눈 나머지가 10 ^ y가 되도록 만들면 된다.
10 ^ x로 나눈 나머지는 주어진 수의 뒤에서부터 x개만 확인하면 되므로 
x개를 확인하면서 뒤에서 y번째 수만 1이 되도록 만들어야 한다.
*/

int main()
{
    scanf("%d %d %d %s", &n, &x, &y, Bit);
    for(int i = 0; i < x; i++)
    {
        //10 ^ y로 나눈 나머지가 없어야 함
        if(i < y)
        {
            if(Bit[n - 1 - i] == '1')
            {
                result++;
            }
        }
        else
        {
            //y번째 수가 1이여야 함
            if(i == y && Bit[n - 1 - i] == '0')
            {
                result++;
            }
            //10 ^ y로 나눈 몫이 1이여야 함
            else if(i > y && Bit[n - 1 - i] == '1')
            {
                result++;
            }
        }
    }
    printf("%d", result);
}