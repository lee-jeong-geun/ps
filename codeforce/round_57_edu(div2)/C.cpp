#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int chk[185];

/*
파이 / 점의 개수를 하면 해당 다각형의 최소 각도가 나오게 된다.
또한 파이 * (점의 개수 - 2) / 점의 개수를 하면 해당 다각형의 최대 각도가 나오게 된다.
그리고 나올수 있는 각도는 최대 179까지이므로 1부터 179까지 모든 각도들을 배열에 저장하면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    memset(chk, -1, sizeof chk);
    //360일때 179도가 나옴
    for(int i = 3; i <= 360; i++)
    {
        int temp;
        temp = (180 * i - 360) / i;
        //최대 각도가 정수인 경우
        if((180 * i - 360) % i == 0)
        {
            //배열에 저장
            if(chk[temp] == -1)
            {
                chk[temp] = i;
            }
        }
        if(180 % i == 0)
        {
            //최소 각도부터 최대 각도까지 배열에 저장
            for(int j = 180 / i; j <= temp; j += 180 / i)
            {
                if(chk[j] == -1)
                {
                    chk[j] = i;
                }
            }
        }
    }
    for(int i = 0; i < T; i++)
    {
        int ang;
        scanf("%d", &ang);
        printf("%d\n", chk[ang]);
    }
}