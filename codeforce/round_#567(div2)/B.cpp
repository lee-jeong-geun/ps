#include <bits/stdc++.h>
using namespace std;
int L;
string word, s1, s2, result;

/*
주어진 단어의 중간부터 시작하여 오른쪽으로 이동하면서 0이아닌 값을 만났을경우 그곳에서 반으로 
나눠서 왼쪽, 오른쪽의 합을 계산하면 된다.
반대쪽도 마찬가지로 절반에서 왼쪽으로 이동하면서 합을 계산한다.
두개의 합중에 작은게 정답이다.
*/

//big-integer 구현
string Sum(string a, string b)
{
    string ret;
    //항상 a의 길이가 길도록 설정
    if(a.size() < b.size())
        swap(a, b);
    //계산하기 편하게 반전 시킴
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    //올림 체크
    int carry = 0;
    for(int i = 0; i < a.size(); i++)
    {
        //계산하기 편하게 0을 삽입
        if(b.size() == i)
            b += '0';
        ret += a[i] + b[i] + carry - '0';
        carry = 0;
        //9보다 큰 경우
        if(ret.back() > '9')
        {
            carry = 1;
            ret.back() = ret.back() - 10;
        }
    }
    if(carry > 0)
        ret += carry + '0';
    //계산을 마쳤으면 다시 반전
    reverse(ret.begin(), ret.end());
    return ret;
}

//비교 함수
string comp(string a, string b)
{
    //a가 비어있을 수 있음
    if(a.size() == 0)
        return b;
    //b의 길이가 짧으면 b가 더 작음
    if(a.size() > b.size())
        return b;
    else if(a.size() < b.size())
        return a;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] < b[i])
            return a;
        else if(a[i] > b[i])
            return b;
    }
    return a;
}

int main()
{
    cin >> L >> word;
    //절반에서 오른쪽으로 이동
    for(int i = L / 2; i < L; i++)
    {
        //0이 아닌 경우
        if(word[i] != '0')
        {
            //s1은 0부터 i - 1까지
            //s2는 i부터 끝까지
            s1 = string(word.begin(), word.begin() + i);
            s2 = string(word.begin() + i, word.end());
            break;
        }
    }
    //합계산
    result = Sum(s1, s2);
    //절반에서 왼쪽으로 이동
    for(int i = L / 2 + 1; i >= 0; i--)
    {
        if(word[i] != '0')
        {
            s1 = string(word.begin(), word.begin() + i);
            s2 = string(word.begin() + i, word.end());
            break;
        }
    }
    //두개의 합중 작은것
    cout << comp(result, Sum(s1, s2)) << endl;
}