#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int n, r;
double result, angle;

/*
규칙을 잘 보면 n각형을 만들고 n각형의 한 변의 길이를 구하면 된다.
*/

int main()
{
    scanf("%d %d", &n, &r);
    //각도
    angle = 3.141592653589793238 / n;
    //변의 길이 구함
    printf("%0.10lf", sin(angle) * r / (1 - sin(angle)));
}