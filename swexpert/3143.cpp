#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char A[10005], B[105];
int result;

/*
문자열 비교 문제이다.
A문자열에 B문자열이 몇개 들어있는지 확인 하면 된다.
A문자열에서 B문자열을 찾다가 실패하면 일치한 개수 만큼 점프하면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        int Alength, Blength;
        result = 0;
        scanf("%s %s", A, B);
        Alength = strlen(A);
        Blength = strlen(B);
        for(int i = 0; i < Alength; i++)
        {
            //B의첫글자와 일치시
            if(A[i] == B[0])
            {
                //몇개 일치 했는지 카운트
                int count = 0;
                for(int j = 0; j < Blength; j++)
                {
                    //일치 할 때마다 카운트
                    if(A[i + j] == B[j])
                    {
                        count++;
                    }
                    //불일치시 빠져나옴
                    else
                    {
                        //A문자열 일치한 개수만큼 점프
                        i += count - 1;
                        result += count - 1;
                        break;
                    }
                }
                if(count == Blength)
                {
                    i += Blength - 1;
                }
            }
            result++;
        }
        printf("#%d %d\n", testcase, result);
    }
}