#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Line[15], result[15], End; //End 변수에 마지막 인덱스 저장

//해당 배열 인덱스에 사람을 넣는다
//넣기전에 그 인덱스에 사람이 있다면 한칸씩 오른쪽으로 움직이고 해당 인덱스에 넣는다
int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &Line[i]);
    }
    for(int i = N; i >= 1; i--)
    {
        //자리에 사람이 존재시
        if(result[Line[i]] != 0)
        {
            //한칸씩 오른쪽으로 이동
            for(int j = End; j >= Line[i]; j--)
            {
                result[j + 1] = result[j];
            }
            End++;
        }
        //인덱스에 사람을 넣는다
        result[Line[i]] = i;
        End = max(End, Line[i]);
    }
    for(int i = 0; i < N; i++)
    {
        printf("%d ", result[i]);
    }
}