#include <bits/stdc++.h>
using namespace std;
int n, op[6] = {4, 8, 15, 16, 23, 42}, Count[7];

/*
4, 8, 15, 16, 23, 42의 순서를 몇개나 만들수 있는지 확인 하면 된다.
확인 하는 방법은 4는 그냥 카운트하고 8부터 42는 바로 앞의 숫자의 카운트가 1이상인 경우에만 카운트를 해준다.
카운트를 할때 자기 앞의 숫자의 카운트를 1감소 시킨다. 이렇게 해서 42가 몇개나 완성되는지 확인 하면 된다.
*/

int main()
{
    scanf("%d", &n);
    int num;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        for(int j = 0; j < 6; j++)
        {
            if(op[j] == num)
            {
                //4인 경우 그냥 카운트
                if(j == 0)
                    Count[j]++;
                else
                {
                    //바로 앞의 숫자의 카운트가 존재 하는 경우
                    if(Count[j - 1] > 0)
                    {
                        Count[j]++;
                        //바로 앞 숫자 카운트 감소
                        Count[j - 1]--;
                    }
                }
            }
        }
    }
    //완성된 순서를 빼줌
    printf("%d", n - Count[5] * 6);
}