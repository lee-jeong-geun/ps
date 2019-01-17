
/*
트라이를 이용한 방식과 정렬을 이용한 방식과 해시를 이용한 방식이 있다.
트라이를 이용하는 방식은 트라이에 저장을 하면서 탐색을 할때 현재 문자열이 다른 문자열에 속해
있거나 현재 문자열에 다른 문자열이 속해 있다면 일관성이 없다는 것이다.
정렬을 이용한 방식은 문자열들을 오름차순으로 정렬 후 현재 문자열과 다음 문자열의 앞부분은 같고
현재 문자열 길이가 짧은걸 찾는 방식이다.
해시를 이용하는 방식은 트라이와 비슷하다.
모든 번호들의 접두사들을 해시함수를 통하여 테이블에 저장 후 속해있는지를 파악하는 방식이다.
*/

//트라이 이용
#include <cstdio>
#include <iostream>
using namespace std;
typedef struct node
{
	int flag;
	int last;
	node *link[10];
} Node;
Node pool[100005];
int poolidx;

//동적할당 하지 않고 배열 인덱스로 할당
Node *alloc()
{
	pool[poolidx].flag = 0;
	pool[poolidx].last = 0;
	for (int i = 0; i < 10; i++)
	{
		pool[poolidx].link[i] = NULL;
	}
	return &pool[poolidx++];
}

typedef struct nodetrie
{
	Node *Root;
	int result;
	nodetrie()
	{
		result = 0;
		Root = alloc();
	}
	void insertNode(Node *Cur, char *str)
	{
		if (*str == 0)
		{
			Cur->last = 1;
			//이미 방문한 노드가 있다면 일관성x
			if (Cur->flag == 1)
			{
				result = 1;
			}
			return;
		}
		//어떤 번호의 마지막 문자라면 일관성x
		if (Cur->last == 1)
		{
			result = 1;
			return;
		}
		if (Cur->link[*str - '0'] == NULL)
		{
			Cur->link[*str - '0'] = alloc();
		}
		insertNode(Cur->link[*str - '0'], str + 1);
		//방문 체크
		Cur->link[*str - '0']->flag = 1;
	}
	void clear()
	{
		result = 0;
		poolidx = 0;
		Root = alloc();
	}
} Trie;
Trie trie;
int n;
char res[2][5] = { "YES", "NO" };

int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 0; testcase < T; testcase++)
	{
		scanf("%d", &n);
		trie.clear();
		for (int i = 0; i < n; i++)
		{
			char phone[15];
			scanf("%s", phone);
			trie.insertNode(trie.Root, phone);
		}
		printf("%s\n", res[trie.result]);
	}
}

//정렬 이용
#include <cstdio>
#include <iostream>
using namespace std;
int n, flag;
char phone[10005][15];

//초기화
void init()
{
	flag = 0;
	for (int i = 0; i < 10005; i++)
	{
		phone[i][0] = '\0';
	}
}

//문자열 길이 구하는 함수
int strlen(char *str1)
{
	int len = 0;
	while (*str1 != 0)
	{
		len++;
		str1++;
	}
	return len;
}

//문자열 비교
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

//문자열 복사
void strcpy(char *str1, char *str2)
{
	int idx = 0;
	while (*str2 != 0)
	{
		str1[idx] = *str2;
		str2++;
		idx++;
	}
	str1[idx] = '\0';
}

//정렬 비교 함수
bool comp(char *str1, char *str2)
{
	if (strcmp(str1, str2) == 1)
	{
		return 0;
	}
	if (strcmp(str1, str2) == -1)
	{
		return 1;
	}
	return 0;
}

void swap(char *str1, char *str2)
{
	char temp[15];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

//퀵정렬
void sort(int left, int right)
{
	char pivot[15];
	int leftidx, rightidx;
	leftidx = left;
	rightidx = right;
	strcpy(pivot, phone[(left + right) / 2]);
	while (leftidx <= rightidx)
	{
		while (comp(phone[leftidx], pivot))
		{
			leftidx++;
		}
		while (comp(pivot, phone[rightidx]))
		{
			rightidx--;
		}
		if (leftidx <= rightidx)
		{
			swap(phone[leftidx], phone[rightidx]);
			leftidx++;
			rightidx--;
		}
	}
	if (left < rightidx)
	{
		sort(left, rightidx);
	}
	if (leftidx < right)
	{
		sort(leftidx, right);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 0; testcase < T; testcase++)
	{
		init();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", phone[i]);
		}
		sort(0, n - 1);
		for (int i = 0; i < n - 1; i++)
		{
			int length, count = 0;
			length = strlen(phone[i]);
			for (int j = 0; j < length; j++)
			{
				//현재 문자열의 문자가 다음 문자열의 문자와 같으면 카운트
				if (phone[i][j] == phone[i + 1][j])
				{
					count++;
				}
			}
			//카운트한 숫자가 현재 문자열과 같다면 일관성X
			if (count == length)
			{
				flag = 1;
				printf("NO\n");
				break;
			}
		}
		if (flag == 0)
		{
			printf("YES\n");
		}
	}
}


//해시 이용
#include <cstdio>
#include <iostream>
using namespace std;
typedef struct node
{
	//두번째 해시값
	int hcount;
	int endFlag;
	node *link;
}Node;
Node pool[700505];
int poolIdx;

Node* alloc()
{
	return &pool[poolIdx++];
}

//각 해시 함수의 모듈러
int Mod = 100003, Mod2 = 1000000007;
int n, result;
char phone[10005][13];

int strlen(char *str)
{
	int length = 0;
	while (*str != 0)
	{
		length++;
		str++;
	}
	return length;
}

void strcpy(char *str1, char *str2)
{
	while (*str2 != 0)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = 0;
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

//충돌시 체이닝 하기 위한 리스트
typedef struct listnode
{
	Node *Head;
	listnode()
	{
		Head = alloc();
		Head->endFlag = -1;
		Head->link = 0;
	}
	void init()
	{
		Head = alloc();
		Head->endFlag = -1;
		Head->link = 0;
	}
	void insertNode(int hcount, int endFlag)
	{
		Node *newnode;
		newnode = alloc();
		newnode->hcount = hcount;
		newnode->endFlag = endFlag;
		newnode->link = Head->link;
		Head->link = newnode;
	}
	int searchNode(int hcount)
	{
		Node *tnode;
		tnode = Head->link;
		while (tnode != 0)
		{
			//검색을 할 때 두번째 해시값까지 같은 경우는 동일한 것으로 간주
			if (tnode->hcount == hcount)
			{
				if (tnode->endFlag == 1)
				{
					result = 1;
				}
				return 1;
			}
			tnode = tnode->link;
		}
		return 0;
	}
}List;
List hashTable[100015];

int Hash(int hcount, char word)
{
	long long result = hcount;
	result = (result * 17000023 + word - '0') % Mod;
	return result;
}

int Hash2(int hcount, char word)
{
	long long result = hcount;
	result = (result * 37000039 + word - '0') % Mod2;
	return result;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int testcase = 0; testcase < t; testcase++)
	{
		result = 0;
		scanf("%d", &n);
        poolIdx = 0;
		for (int i = 0; i < Mod; i++)
		{
			hashTable[i].init();
		}
		for (int i = 0; i < n; i++)
		{
			int hcount = 1, hcount2 = 1, length, endFlag = 0;
			scanf("%s", phone[i]);
			length = strlen(phone[i]);
			for (int j = 0; j < length; j++)
			{
				hcount = Hash(hcount, phone[i][j]);
				hcount2 = Hash2(hcount2, phone[i][j]);
				//마지막 번호인경우
				if (j == length - 1)
				{
					endFlag = 1;
				}
				//동일한게 하나도 없는 경우
				if (hashTable[hcount].searchNode(hcount2) == 0)
				{
					hashTable[hcount].insertNode(hcount2, endFlag);
				}
				else
				{
					if (j == length - 1)
					{
						result = 1;
					}
				}
			}
		}
		result == 0 ? printf("YES\n") : printf("NO\n");
	}
}