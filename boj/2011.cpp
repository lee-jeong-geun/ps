#include <bits/stdc++.h>
using namespace std;
string word;
int memo[5005], Mod = 1000000;

/*
예제 25114에서 2 5 114나 25 114처럼 114가 중복이 될수 있다. 중복된 것들을 메모이제이션 하면 된다.
조건을 잘 나눠야 하는데 27처럼 26보다 크면 안되고 0으로 시작해서도 안된다.
*/

int func(int idx)
{
    if(idx == word.size())
        return 1;
    int &ret = memo[idx];
    if(ret != -1)
        return ret;
    ret = 0;
    //0이 아닌 경우
    if(word[idx] != '0')
    {
        //한글자만 이동
        ret = (ret + func(idx + 1)) % Mod;
        //2글자 이동할 때 문자열을 벗어나면 안되고 26보다 커서도 안됨
        if(idx + 1 < word.size() && (word[idx] == '1' || word[idx] == '2' && word[idx + 1] <= '6'))
            ret = (ret + func(idx + 2)) % Mod;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> word;
    memset(memo, -1, sizeof memo);
    cout << func(0);
}