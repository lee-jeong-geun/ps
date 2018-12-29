#include <cstdio>
#include <iostream>
using namespace std;
int N, segTree[2][400005], Cow[100005], chk[50005];
long long result;

/*
어떤 소의 한점과 한점 사이에 다른 소의 한점만 있는 경우 무조건 만나게 되는 경우가 된다.
모든 소들에 대해서 한점과 한점 사이에 어떤것이 있는지 파악을 하면 되는데 하나씩 다 파악하는 경우는
O(N^2)의 시간복잡도가 되므로 시간 초과가 나게 된다.
따라서 세그먼트 트리를 이용하여 구간으로 확인을 하면 된다.
잘 보면 어떤 소의 첫번째 지점과 두번째 지점 사이에 다른 소들의 첫번째 지점이 몇개가 있는지를 파악하면 된다.
세그먼트 트리를 두개 만들어서 첫번재 트리에는 각 구간에 대하여 첫번째 지점의 개수를 담고 두번째 트리에는 
각 구간에 대하여 두번째 지점의 개수를 담으면 된다.
그래서 어떤 소의 첫번째 지점과 두번째 지점 사이의 구간에 대하여 그 구간에 속해있는 첫번째 지점 개수에서
두번째 지점 개수를 빼주면 순수하게 첫번째 지점이 몇개 있는지를 구할 수 있다. 이것을 하고
해당 소의 두번째 지점이 속하는 구간들의 개수를 하나씩 줄여주면 된다.
쌍을 구하는 것이기 때문에 뒤의 소들은 이미 앞의 소들에 의하여 쌍이 구해졌으므로 중복으로 세면 안되기 때문에 지운다.
*/

//세그먼트 트리 구간 업데이트
int update(int start, int left, int right, int node, int flag, int value)
{
    if(start < left || start > right)
    {
        return segTree[flag][node];
    }
    if(left == right)
    {
        return segTree[flag][node] += value;
    }
    int mid;
    mid = (left + right) / 2;
    return segTree[flag][node] = update(start, left, mid, node * 2, flag, value) + update(start, mid + 1, right, node * 2 + 1, flag, value);
}

//구간의 개수 구하는 쿼리
int query(int start, int end, int left, int right, int node, int flag)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(start <= left && right <= end)
    {
        return segTree[flag][node];
    }
    int mid;
    mid = (left + right) / 2;
    return query(start, end, left, mid, node * 2, flag) + query(start, end, mid + 1, right, node * 2 + 1, flag);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N * 2; i++)
    {
        scanf("%d", &Cow[i]);
        //첫번째 두번째 각각 트리에 저장
        update(i, 0, N * 2 - 1, 1, chk[Cow[i]], 1);
        chk[Cow[i]]++;
        //두번째 점일 경우
        if(chk[Cow[i]] == 2)
        {
            //두번째 점의 인덱스를 배열에 저장
            chk[Cow[i]] = i;
        }
    }
    for(int i = 0; i < N * 2; i++)
    {
        //첫번째 점에 대하여 쿼리 실행
        if(i < chk[Cow[i]])
        {
            //s = 첫번째, e = 두번째
            int s, e;
            s = query(i, chk[Cow[i]], 0, N * 2 - 1, 1, 0);
            e = query(i, chk[Cow[i]], 0, N * 2 - 1, 1, 1);
            result += s - e;
            //해당 소의 두번째 지점이 속한 구간들이 가지고 있는 개수 1감소
            update(chk[Cow[i]], 0, N * 2 - 1, 1, 1, -1);
        }
    }
    printf("%lld", result);
}