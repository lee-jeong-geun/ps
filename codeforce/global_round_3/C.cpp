#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> vec;
int n, arr[300005], chk[300005], result;

/*
규칙을 잘 찾다 보면 그냥 단순하게 숫자 i의 인덱스가 i가 아닌 경우 계속 스왑 해서 i로 가게 만들면 된다.
이때 어떻게 스왑을 하냐면 숫자 i의 인덱스가 바로 i로 이동 가능 한다면 바로 스왑을 해주고
그게 아니라면 왼쪽 or 오른쪽 끝과 스왑을 한다. 이때 왼쪽, 오른쪽 선택 조건은 단순하게
왼쪽 끝으로 갈수 있다면 가고 그게 아니라면 오른쪽 끝으로 간다. 양쪽 끝으로 간 상태 일때
인덱스 i로 이동 가능 한다면 바로 스왑을 해주고 그게 아니라면 이번에는 반대쪽 끝으로 간다.
왼쪽 끝이였다면 오른쪽, 오른쪽 끝이였다면 왼쪽으로 간다. 이렇게 하면 무조건 인덱스 i로 바로 갈수있게 된다.
이러한 연산들을 1부터 n까지의 숫자에 대해서 돌리면 된다.
*/

//스왑 해주는 모듈
void swapFunc(int a, int b)
{
    result++;
    vec.push_back({a, b});
    chk[arr[a]] = b;
    chk[arr[b]] = a;
    swap(arr[a], arr[b]);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        //해당 숫자의 인덱스 저장
        chk[arr[i]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        //자리에 맞게 있다면 패스
        if(chk[i] == i)
            continue;
        //바로 갈 수 있다면 스왑
        if(abs(chk[i] - i) >= n / 2)
            swapFunc(i, chk[i]);
        else
        {
            //오른쪽 끝으로 갈 수 있는 경우
            if(abs(chk[i] - n) >= n / 2)
                swapFunc(chk[i], n);
            //왼쪽 끝
            else
                swapFunc(chk[i], 1);
            //해당 인덱스로 갈 수 있는 경우
            if(abs(chk[i] - i) >= n / 2)
                swapFunc(chk[i], i);
            else
            {
                //오른쪽 끝으로 가는 경우
                if(abs(chk[i] - n) >= n / 2)
                    swapFunc(chk[i], n);
                //왼쪽 끝으로 가는 경우
                else
                    swapFunc(chk[i], 1);
                //여기까지 왔다는건 해당 인덱스로 바로 갈 수있음
                swapFunc(chk[i], i);
            }
        }
    }
    printf("%d\n", result);
    for(int i = 0; i < vec.size(); i++)
    {
        printf("%d %d\n", vec[i].first, vec[i].second);
    }
}