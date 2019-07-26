#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<pair<int, int>, pair<int, int>>> vec;
int N, segTree[30000 * 4 + 5], CountTree[30000 * 4 + 5], result;

/*
주어진 지도들의 칸들을 하나씩 카운트 하기에는 30000*30000 이라서 불가능하다.
따라서 각 지도들의 세로선들을 스캔해가는 방식으로 면적을 카운트하면 된다.
우선 주어진 지도들의 세로를 배열에 저장한다.
이때 각 세로들은 해당 세로선이 위치한 x좌표, 세로선의 시작위치, 끝위치, 지도의 시작 끝 구분으로
구성된다. 배열에 다 저장한 다음 x좌표를 기준으로 정렬을 하고 세로선들을 스위핑 하면된다.
임의의 세로선 i에 대해서 i+1의 세로선을 만날경우 세로선은 i위치의 x좌표에서 i+1위치의 x좌표로
이동했으니 i세로선의 길이 * 이동한 x좌표를 하면 i -> i+1 사이의 면적이 된다.
이동한 세로선들을 매번 카운트하기에는 시간이 오래 걸리니 y좌표를 0 ~ 30000까지의 구간을 가진
세그먼트 트리를 이용하여 0 ~ 30000의 구간에 세로선들이 얼마나 면적을 차지하고 있는지 저장하면 된다.
예를 들어 임의의 세로선 i의 y좌표가 3 ~ 8까지라면 세그먼트 트리의 3 ~ 8까지의 구간에는 6이 저장 되어있다.
또 다른 세로선인 i+1이 9 ~ 14까지 동시에 존재한다면 9 ~ 14까지의 구간에는 6이 저장 되어있고
결국은 0 ~ 30000에는 12가 저장 되어있다. 이제 중복을 처리해야 하는데 간단하게 세로선의 개수를 저장하는
세그먼트 트리 하나를 더 만들어서 거기에 새로운 세로선이 들어갈 때 마다 개수를 1증가 시키면 되고
끝나는 세로선을 만날 때 마다 -1시키면 된다.
*/

void update(int start, int end, int val, int left, int right, int node)
{
    if(start > right || end < left)
        return;
    //해당 구간에 속한 경우 세로선을 증감 시킴
    if(start <= left && right <= end)
        CountTree[node] += val;
    else
    {
        int mid = (left + right) / 2;
        update(start, end, val, left, mid, node * 2);
        update(start, end, val, mid + 1, right, node * 2 + 1);
    }
    //세로선이 하나도 존재하지 않는 경우
    if(CountTree[node] == 0)
    {
        //리프노드라면 0으로 만듬
        if(left == right)
            segTree[node] = 0;
        //그게 아니라면 양쪽 구간의 합을 저장
        else
            segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }
    //세로선이 존재한다는 말은 곧 그 구간 전체의 y좌표를 사용 한다는 뜻
    else
        segTree[node] = right - left + 1;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        vec.push_back({{x1, y1}, {y2, -1}});
        vec.push_back({{x2, y1}, {y2, 1}});
    }
    //x좌표 순으로 정렬
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++)
    {
        //이동한 x좌표만큼 존재하는 y좌표를 곱함
        if(i > 0)
            result += (vec[i].first.first - vec[i - 1].first.first) * segTree[1];
        //시작하는 세로선인 경우 추가, 끝나는 세로선인 경우 삭제
        update(vec[i].first.second, vec[i].second.first - 1, vec[i].second.second, 0, 30000, 1);
    }
    printf("%d", result);
}