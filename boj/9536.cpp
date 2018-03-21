#include <cstdio>
#include <iostream>

#define NULL 0
#define Mod  9991

using namespace std;
typedef struct node
{
	char word[105];
	node *link;
}Node;

char sound[20005];
Node Sound[105], chk[10005];
int sidx;

/*
각 문자열들을 빠르게 매칭시키기 위해 해시를 사용 하였다.
충돌 방지를 위해 연결리스트를 사용하였다.
해시 테이블에 저장 되어있지 않은 문자열만 출력을 하면 된다.
*/

int strlen(char *str)
{
	int len = 0;
	while (*str != NULL)
	{
		len++;
		str++;
	}
	return len;
}

void strcpy(char *str1, char *str2)
{
	while (*str2 != NULL)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = NULL;
}

int strcmp(char *str1, char *str2)
{
	while (*str1 != 0 || *str2 != 0)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		str1++;
		str2++;
	}
	return 0;
}

//해시 함수
int Hash(char *str)
{
	int length;
	long long result = 37;
	length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		result = (result * 1234731 + str[i] - 'a') % Mod;
	}
	return result;
}

Node* createNode(char *str)
{
	Node *newnode = new Node();
	strcpy(newnode->word, str);
	newnode->link = NULL;
	return newnode;
}

void init()
{
	for (int i = 0; i < 10001; i++)
	{
		if (chk[i].link == NULL)
		{
			Node *newnode;
			newnode = createNode("1");
			chk[i].link = newnode;
		}
		else
		{
			Node *tnode, *ttnode;
			tnode = chk[i].link;
			while (tnode != NULL)
			{
				ttnode = tnode;
				tnode = tnode->link;
				delete ttnode;
            }
            chk[i].link->link = NULL;
		}
	}
	sidx = 0;
}

//해시 충돌이 날 경우 리스트에 연결 시킴
void Hashing(char *str)
{
	int Hcount;
	Hcount = Hash(str);
	Node *tnode, *ttnode;
    tnode = chk[Hcount].link;
	while (tnode != NULL)
	{
		if (strcmp(tnode->word, str) == 0)
		{
			return;
		}
		ttnode = tnode;
		tnode = tnode->link;
	}
	ttnode->link = createNode(str);
}

int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	for (int testcase = 0; testcase < T; testcase++)
	{
		init();
		gets(sound);
		int length = 0;
		length = strlen(sound);
		sound[length++] = ' ';
		sound[length] = NULL;
		//입력 받은 문자열 전처리 과정
		for (int i = 0; i < length; i++)
		{
			char temp[105];
			int tidx = 0;
			for (int j = i; j < length; j++)
			{
				if (sound[j] != ' ')
				{
					temp[tidx++] = sound[j];
				}
				else
				{
					temp[tidx] = NULL;
					strcpy(Sound[sidx++].word, temp);
					i = j;
					break;
				}
			}
		}
        while (1)
		{
			int count = 0, ttidx = 0, tlength;
			char tsound[105], ttemp[105];
            gets(tsound);
			if (strcmp(tsound, "what does the fox say?") == 0)
			{
				break;
			}
			//질문이 나오기 전까지 문자열들 해시테이블에 저장
            tlength = strlen(tsound);
			for (int i = 0; i < tlength; i++)
			{
				if (count == 2)
				{
					ttemp[ttidx++] = tsound[i];
				}
				if (tsound[i] == ' ')
				{
					count++;
				}
            }
			ttemp[ttidx] = NULL;
            Hashing(ttemp);
		}
		for (int i = 0; i < sidx; i++)
		{
			int hcount, flag = 0;
			hcount = Hash(Sound[i].word);
			Node *tnode;
			tnode = chk[hcount].link;
			while (tnode != NULL)
			{
				if (strcmp(tnode->word, Sound[i].word) == 0)
				{
					flag = 1;
					break;
				}
				tnode = tnode->link;
			}
			//해시테이블에 없으면 출력
			if (flag == 0)
			{
				printf("%s ", Sound[i].word);
			}
		}
		printf("\n");
	}
}