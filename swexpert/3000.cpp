#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, A, Maxheap[200005], Minheap[200005], MaxCur, MinCur, Mid, Number[5];
long long result = 0;

/*
중간값을 구하는 가장 기본적인 방법은 매번 수를 받을때 마다 정렬을 하면 된다.
하지만 수는 최대 20만개가 입력 되므로 매번 정렬을 한다고 했을때 시간 복잡도는
O(N^2 log N)이 나오게 된다. 20만의 제곱이므로 무조건 시간 초과가 나게 된다.
매번 정렬하는 방법 말고 최대힙, 최소힙을 이용하여 수를 입력 받을때마다 중간값을 
기준으로 크면 최소힙에 저장, 작으면 최대힙에 저장을 한다. 저장 후 두개의 힙 중 하나가
다른 하나보다 2개 더 많으면 균형이 안맞으므로 중간 값을 수가 적은 힙에 푸쉬를 하고
수가 많은 힙에서 팝을 하고 그 값을 중간값에 넣는다. 이렇게 하면 중간 값을 정렬없이 항상
구할 수 있다.
*/

void init()
{
    result = 0;
    for(int i = 0; i < 200005; i++)
    {
        Maxheap[i] = 0;
        Minheap[i] = 1234567890;
    }
    MaxCur = 0;
    MinCur = 0;
}

//최대힙
void Maxpush(int num)
{
    Maxheap[++MaxCur] = num;
    int point = MaxCur;
    while(point != 1)
    {
        if(Maxheap[point] <= Maxheap[point / 2])
        {
            break;
        }
        swap(Maxheap[point], Maxheap[point / 2]);
        point /= 2;
    }
}

void Maxpop()
{
    Maxheap[1] = Maxheap[MaxCur];
    Maxheap[MaxCur--] = 0;
    int point = 1;
    while(point * 2 <= MaxCur)
    {
        int tpoint = point * 2;
        if(Maxheap[tpoint] < Maxheap[tpoint + 1])
        {
            tpoint++;
        }
        if(Maxheap[point] >= Maxheap[tpoint])
        {
            break;
        }
        swap(Maxheap[point], Maxheap[tpoint]);
        point = tpoint;
    }
}

int Maxtop()
{
    return Maxheap[1];
}

//최소힙
void Minpush(int num)
{
    Minheap[++MinCur] = num;
    int point = MinCur;
    while(point != 1)
    {
        if(Minheap[point] >= Minheap[point / 2])
        {
            break;
        }
        swap(Minheap[point], Minheap[point / 2]);
        point /= 2;
    }
}

void Minpop()
{
    Minheap[1] = Minheap[MinCur];
    Minheap[MinCur--] = 1234567890;
    int point = 1;
    while(point * 2 <= MinCur)
    {
        int tpoint = point * 2;
        if(Minheap[tpoint] > Minheap[tpoint + 1])
        {
            tpoint++;
        }
        if(Minheap[point] < Minheap[tpoint])
        {
            break;
        }
        swap(Minheap[point], Minheap[tpoint]);
        point = tpoint;
    }
}

int Mintop()
{
    return Minheap[1];
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d %d", &N, &A);
        Mid = A;
        for(int i = 0; i < N; i++)
        {
            scanf("%d %d", &Number[0], &Number[1]);
            for(int j = 0; j < 2; j++)
            {
                if(Number[j] < Mid)
                {
                    Maxpush(Number[j]);
                }
                else
                {
                    Minpush(Number[j]);
                }
            }
            //최대힙이 최소힙보다 수가 많을 경우
            if(MaxCur == MinCur + 2)
            {
                Minpush(Mid);
                Mid = Maxtop();
                Maxpop();
            }
            else if(MaxCur + 2 == MinCur)
            {
                Maxpush(Mid);
                Mid = Mintop();
                Minpop();
            }
            result = (result + Mid) % 20171109;
        }
        printf("#%d %lld\n", testcase, result);
    }
}