#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef struct _data
{
	int x;
	int y;
	int dir;
	int memory;
}Data;
int R, C, rflag, chk[25][25][5][20];
char zone[25][25];
int arrA[4] = { 0, 1, 0, -1 };
int arrB[4] = { -1, 0, 1, 0 };

/*
각각의 문자에 맞게 구현을 하면 된다.
'?' 이 문자는 문제에서 상하좌우 4방향 중 하나로 무작위로 바뀐다지만 확률은 동일하므로
4방향으로 퍼진다고 생각을 하면 된다.
그리고 x, y, 방향, 메모리 값을 이용해서 방문 확인을 하면 된다.
*/

void init()
{
	memset(chk, 0, sizeof chk);
	rflag = 0;
}

void func()
{
	queue<Data>q;
	q.push({ 0, 0, 1, 0 });
	chk[0][0][1][0] = 1;
	while (!q.empty())
	{
		Data temp, next;
		temp = q.front();
		q.pop();
		if (zone[temp.y][temp.x] == '<')
		{
			temp.dir = 3;
		}
		else if (zone[temp.y][temp.x] == '>')
		{
			temp.dir = 1;
		}
		else if (zone[temp.y][temp.x] == '^')
		{
			temp.dir = 0;
		}
		else if (zone[temp.y][temp.x] == 'v')
		{
			temp.dir = 2;
		}
		else if (zone[temp.y][temp.x] == '_')
		{
			if (temp.memory == 0)
			{
				temp.dir = 1;
			}
			else
			{
				temp.dir = 3;
			}
		}
		else if (zone[temp.y][temp.x] == '|')
		{
			if (temp.memory == 0)
			{
				temp.dir = 2;
			}
			else
			{
				temp.dir = 0;
			}
		}
        //4방향 퍼짐
		else if (zone[temp.y][temp.x] == '?')
		{
			for (int i = 0; i < 4; i++)
			{
                //맵 밖을 벗어나면 반대 방향으로 이동
				next.x = (temp.x + arrA[i] + C) % C;
				next.y = (temp.y + arrB[i] + R) % R;
				next.dir = i;
				next.memory = temp.memory;
                //방문 확인
				if (chk[next.y][next.x][next.dir][next.memory] == 0)
				{
					chk[next.y][next.x][next.dir][next.memory] = 1;
					q.push(next);
				}
			}
			continue;
		}
		else if (zone[temp.y][temp.x] == '.')
		{
			temp.dir = temp.dir;
		}
        //종료
		else if (zone[temp.y][temp.x] == '@')
		{
			rflag = 1;
			return;
		}
		else if (zone[temp.y][temp.x] == '+')
		{
			temp.memory = (temp.memory + 1) % 16;
		}
		else if (zone[temp.y][temp.x] == '-')
		{
			temp.memory = (temp.memory + 15) % 16;
		}
		else
		{
			temp.memory = zone[temp.y][temp.x] - '0';
		}
		next.x = (temp.x + arrA[temp.dir] + C) % C;
		next.y = (temp.y + arrB[temp.dir] + R) % R;
		next.dir = temp.dir;
		next.memory = temp.memory;
		if (chk[next.y][next.x][next.dir][next.memory] == 0)
		{
			chk[next.y][next.x][next.dir][next.memory] = 1;
			q.push(next);
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
        int flag = 0;
		init();
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				scanf(" %c", &zone[i][j]);
                if(zone[i][j] == '@')
                {
                    flag = 1;
                }
			}
		}
        //종료 문자가 있는경우에 실행
        if(flag == 1)
        {
		    func();
        }
		printf("#%d ", testcase);
		if (rflag == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}