#include <cstdio>
#include <iostream>
using namespace std;
char b, result[30];

/*
주어진 문제에 맞게 구현하면 된다.
*/

int main()
{
    result['A' - 'A'] = 'T';
    result['T' - 'A'] = 'A';
    result['C' - 'A'] = 'G';
    result['G' - 'A'] = 'C';
    scanf("%c", &b);
    printf("%c", result[b - 'A']);
}