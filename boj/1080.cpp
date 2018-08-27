#include <cstdio>
#include <iostream>
using namespace std;
int N, M, A[55][55], B[55][55];
int arrA[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int arrB[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

/*
A행렬에서 B행렬로 바꿀때 토글 시키는 순서는 중요하지 않다.
순서가 달라도 토글 시키는 행, 열만 같다면 결과는 똑같다.
즉 순서를 뒤죽박죽 하거나 차례대로 해도 뒤집은 갯수는 똑같다는 말이다.
A행렬과 B행렬을 맨왼쪽 상단부터 비교해가면서 같으면 넘어가고 다르면
해당 원소의 우측 하단의 원소를 뒤집으면 된다. 이런식으로 계속 뒤집어 준다면
B행렬을 만들수 있다. 우측 하단의 원소를 뒤집는 이유는 현재 확인하는 원소보다 앞의 원소들에서
B행렬의 상태랑 동일하게 맞춰왔기 때문에 앞의 원소들을 건들면 안되는데 우측 하단의 원소에서 
뒤집는다면 3*3이기 때문에 앞의 원소들을 건들지 않게된다.
*/

//토글 시키는 함수
void change(int x, int y)
{
    for(int i = 0; i < 9; i++)
    {
        A[y + arrB[i]][x + arrA[i]] ^= 1;
    }
}

int func()
{
    int hap = 0;
    for(int i = 0; i < N - 2; i++)
    {
        for(int j = 0; j < M - 2; j++)
        {
            if(A[i][j] != B[i][j])
            {
                int x, y;
                x = j + 1;
                y = i + 1;
                change(x, y);
                hap++;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(A[i][j] != B[i][j])
            {
                hap = -1;
            }
        }
    }
    return hap;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%1d", &A[i][j]);
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%1d", &B[i][j]);
        }
    }
    printf("%d", func());
}