#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<int, int> M;
int n, m;

/*
n개의 종류가 완성될때 1을 출력하고 n개의 종류에 대해서 1개씩 개수를 줄이면 된다.
*/

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int num;
        scanf("%d", &num);
        M[num]++;
        //n개가 안될때
        if(M.size() != n)
        {
            printf("0");
        }
        else
        {
            printf("1");
            for(int j = 1; j <= n; j++)
            {
                //각각의 종류에 대해서 1개씩 감소
                M[j]--;
                if(M[j] == 0)
                {
                    M.erase(j);
                }
            }
        }
    }
}