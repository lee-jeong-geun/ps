#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
int n, x, XOR, Exp, chk[1000005];

/*
연속된 구간들의 XOR값이 0, x가 나오면 안된다.
0이 안나오게 하려면 연속된 서로 다른 구간의 XOR값이 같으면 안된다.
x가 안나오게 하려면 a ^ m == x가 되는 m값이 안나오게 하면 된다. 이때 m값은
a ^ x를 하게 되면 나온다. 이런 방식을 이용하여 연속된 모든 구간들의 값이 서로 달라야 하고
연속된 구간의 XOR이 m이 안나오게 (a, m)쌍중에서 한개의 원소만 나오게끔 하면 된다.
*/

int main()
{
    scanf("%d %d", &n, &x);
    //나올수 있는 최대 원소
    Exp = 1 << n;
    chk[0] = 1;
    //1 ~ exp - 1까지 모두 다른 원소
    //또한 1 ~ exp - 1까지 확인 하면서 (i, i ^ x)중 반대편이 쌍이 안나온 경우를 탐색
    for(int i = 1; i < Exp; i++)
    {
        if(chk[i ^ x] == 0)
        {
            chk[i] = 1;
            vec.push_back(XOR ^ i);
            XOR = i;
        }
    }
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
}