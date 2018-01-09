#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int idx;
    char Name[25];
}Data;
Data poket[100005];
char poketName[100005][25];
int N, M;

/*
범위가 크므로 brute force하게 접근하면 시간 초과가 난다.
따라서 포켓몬의 이름을 정렬후 이분탐색을 이용해서 탐색을 하면 된다.
숫자 입력시 포켓몬의 이름을 출력 해주기 위해 배열 하나를 만들어서 
그 배열 idx에 있는 이름을 바로 출력 해주었다.
이름 입력시 포켓몬의 번호를 출력하는건 이분탐색을 이용 했다.
*/

void strcpy(char *str1, char *str2)
{
    while(*str2 != 0)
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = NULL;
}

int strcmp(char *str1, char *str2)
{
    while(*str1 != 0 || *str2 != 0)
    {
        if(*str1 > *str2)
        {
            return 1;
        }
        else if(*str1 < *str2)
        {
            return -1;
        }
        str1++;
        str2++;
    }
    return 0;
}

//문자열 오름 차순 정렬
bool comp(Data t, Data u)
{
    if(strcmp(t.Name, u.Name) == 1)
    {
        return 0;
    }
    else if(strcmp(t.Name, u.Name) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


//퀵 소트
void sort(int left, int right)
{
    Data pivot;
    int leftidx, rightidx;
    leftidx = left;
    rightidx = right;
    pivot = poket[(left + right) / 2];
    while(leftidx <= rightidx)
    {
        while(comp(poket[leftidx], pivot))
        {
            leftidx++;
        }
        while(comp(pivot, poket[rightidx]))
        {
            rightidx--;
        }
        if(leftidx <= rightidx)
        {
            Data temp;
            temp = poket[leftidx];
            poket[leftidx] = poket[rightidx];
            poket[rightidx] = temp;
            leftidx++;
            rightidx--;
        }
    }
    if(left < rightidx)
    {
        sort(left, rightidx);
    }
    if(leftidx < right)
    {
        sort(leftidx, right);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%s", poket[i].Name);
        poket[i].idx = i + 1;
        strcpy(poketName[i + 1], poket[i].Name);
    }
    sort(0, N - 1);
    for(int i = 0; i < M; i++)
    {
        char Input[25];
        scanf("%s", Input);
        //숫자 입력시 포켓몬 이름 출력
        if(Input[0] <= '9')
        {
            int hap = 0, idx = 0;
            while(Input[idx] != 0)
            {
                hap *= 10;
                hap += Input[idx] - '0';
                idx++;
            }
            printf("%s\n", poketName[hap]);
        }
        //이름 입력시 이분탐색을 이용해 번호 출력
        else
        {
            int l, r;
            l = 0;
            r = N - 1;
            while(l <= r)
            {
                int mid;
                mid = (l + r) / 2;
                //탐색 완료
                if(strcmp(poket[mid].Name, Input) == 0)
                {
                    printf("%d\n", poket[mid].idx);
                    break;
                }
                //찾고자 하는 포켓몬 이름보다 뒤 일 경우
                else if(strcmp(poket[mid].Name, Input) == 1)
                {
                    r = mid - 1;
                }
                //찾고자 하는 포켓몬 이름보다 앞 일 경우
                else
                {
                    l = mid + 1;
                }
            }
        }
    }
}