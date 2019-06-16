#include <cstdio>
#include <iostream>
using namespace std;
int W, H, x, y, flag;
double result;

/*
직사각형에서 어떤 한점과 그점을 직사각형의 중심에 대칭 시켜서 나온 점을 선으로 그어서 
직사각형을 2등분 하면 반드시 똑같은 넓이의 사각형이 2개 나온다. 따라서 넓이는
주어진 직사각형의 2분의 1이고 같은 넓이를 가질수 있게 하는 직선들이 2개 이상되는 조건은
주어진 점이 직사각형의 중심에 있을때다. 중심에 있는 조건은 직사각형의 변들이 짝수이고
주어진 점이 직사각형 변들의 절반에 있을때다.
*/

int main()
{
    scanf("%d %d %d %d", &W, &H, &x, &y);
    result = (double)H * W / 2;
    if(W % 2 == 0 && H % 2 == 0 && W / 2 == x && H / 2 == y)
        flag = 1;
    printf("%0.6lf %d", result, flag);
}