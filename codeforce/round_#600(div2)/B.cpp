#include <bits/stdc++.h>
using namespace std;
set<int> s1, s2;
vector<int> vec;
int n, result;

/*
set 2개를 이용해서 하나는 현재 건물에 누가있는지 저장을 하고
다른 하나는 날이 바뀌기 전에 누가 건물에서 나왔는지 저장을 하면 된다.
날을 바꾸는 조건은 건물에 한명도 없을 경우 바꾸면 된다.
*/

int main()
{
    scanf("%d", &n);
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        //들어옴
        if(num > 0)
        {
            //이미 건물에 있는 사람인 경우 잘못됨
            if(s1.find(num) != s1.end())
                result = 1;
            //최근에 건물을 빠져 나왔고 다시 들어가는 상황(날을 바꿔야 하는 상황)
            if(s2.find(num) != s2.end())
            {
                //건물에 사람이 남아있는 경우 잘못됨
                if(s1.size() != 0)
                    result = 1;
            }
            s1.insert(num);
            s2.erase(num);
        }
        //나감
        else
        {
            //건물에 없는 경우
            if(s1.find(-num) == s1.end())
                result = 1;
            s1.erase(-num);
            s2.insert(-num);
            //건물에 한명도 없으면 날을 바꿈
            if(s1.size() == 0)
            {
                vec.push_back(count + 1);
                s2.clear();
                count = -1;
            }
        }
        count++;
    }
    //건물에 사람이 있으면 잘못됨
    if(result == 1 || s1.size() != 0)
    {
        printf("-1");
        return 0;
    }
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
}