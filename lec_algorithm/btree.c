#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1  
#define FALSE 0
#define t 5 // 5,7,9 수기로 변경

typedef struct node
{
	int key[2 * t - 1]; // 자식 노드 key 최대 개수
	struct node* child[2 * t];
	int leaf, n;  // 길이
}
node;

typedef struct btree
{
	node* root;
}btree;


void btree_Create(btree* T);
void btree_Insert(btree* T, int k);
void btree_Insert_Nonfull(node* x, int k);
int  btree_Search(btree* T, int k);
int  btree_Search_Main(node* x, int k);
void btree_Split_Child(node* x, int i);
void btree_Display(btree* T);
void btree_Display_Main(node* x, int h);
void btree_Delete(btree* T, int k);
void btree_Delete_main(node* x, int k);
int Find_Successor(node* x);
int Find_Predecessor(node* x);
void btree_insert_items(btree* T, int x, int y);

int func_random() {
	int r = rand() % 10000; // 0~9999
	return r;
}

int main()
{
	btree* T = malloc(sizeof(btree));
	btree_Create(T);
	int x;

	clock_t start, end;
	start = clock();

	// 1000개 넣기
	for(int i=0; i<8; i++) {
		x = func_random();
		while (btree_Search(T,x) == 1) {
			x = func_random();
		}

		btree_Insert(T, x);
		btree_Display(T);
	}

	// 넣은 것 확인
	printf("\n======================\n");
	btree_Display(T);
	printf("======================\n");

	// 삭제?
	for(int i=0; i<5; i++) {
		x = func_random();
		btree_Delete(T, x);
		btree_Display(T);
	}
	end = clock();

	printf("\n======================\n");
	btree_Display(T);
	printf("======================\n");
	
	printf("t : %d\n", t);
	printf("[time : %f]\n", (float)(end - start)/CLOCKS_PER_SEC);

	free(T);
}

void btree_insert_items(btree* T, int x, int y) {
	for (int i = x; i < y+1; i++) {
		btree_Insert(T, i);
	}
	btree_Display(T);
}

void btree_Create(btree* T)
{
	node* x = malloc(sizeof(node));
	x->leaf = TRUE;
	x->n = 0;
	T->root = x;
}

void btree_Insert(btree* T, int k)
{
	node* r = T->root;
	if (r->n == 2 * t - 1)
	{
		node* s = malloc(sizeof(node));
		T->root = s;
		s->leaf = FALSE;
		s->n = 0;
		s->child[0] = r;
		btree_Split_Child(s, 0);
		btree_Insert_Nonfull(s, k);
		//printf("insert %d\n", k);
	}
	else
	{
		btree_Insert_Nonfull(r, k);
	}
}

void btree_Insert_Nonfull(node* x, int k)
{
	int i = x->n;
	if (x->leaf)
	{
		i--;
		while (i >= 0 && k < x->key[i])
		{
			x->key[i + 1] = x->key[i];
			i--;
		}
		x->key[i + 1] = k;
		x->n = x->n + 1;
	}
	else {
		while (i >= 1 && k < x->key[i - 1])
		{
			i--;
		}
		if ((x->child[i])->n == 2 * t - 1)
		{
			btree_Split_Child(x, i);
			if (k > x->key[i]) {
				i++;
			}
		}
		btree_Insert_Nonfull(x->child[i], k);
	}
}

int btree_Search(btree* T, int k)
{
	node* r = T->root;
	return btree_Search_Main(r, k);
}


int btree_Search_Main(node* x, int k)
{
	if (x->leaf)
	{
		int i = x->n - 1;
		while (i >= 0 && k < x->key[i])
		{
			i--;
		}
		if (x->key[i] == k)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

void btree_Split_Child(node* x, int i)
{
	node* z = malloc(sizeof(node));
	node* y = x->child[i]; 
	z->leaf = y->leaf;
	z->n = t - 1;
	for (int j = 0; j < t - 1; j++)
	{
		z->key[j] = y->key[j + t];
	}
	if (y->leaf == FALSE)
	{
		for (int j = 0; j < t; j++)
		{
			z->child[j] = y->child[j + t];
		}
	}
	y->n = t - 1;
	for (int j = x->n; j > i; j--)
	{
		x->child[j + 1] = x->child[j];
	}
	x->child[i + 1] = z;
	for (int j = x->n - 1; j > i - 1; j--)
	{
		x->key[j + 1] = x->key[j];
	}
	x->key[i] = y->key[t - 1];
	x->n = x->n + 1;
}
void btree_Display(btree* T)
{
	node* r = T->root;
	btree_Display_Main(r, 1);
}
void btree_Display_Main(node* x, int h)
{
	printf("%d : ", h);
	for (int i = 0; i < x->n; i++)
	{
		printf("%d ", x->key[i]);
	}
	printf("\n");
	if (x->leaf == 0)
	{
		for (int i = 0; i < x->n + 1; i++)
		{
			btree_Display_Main(x->child[i], h + 1);
		}
	}
}
void btree_Delete(btree* T, int k)
{
	node* r = T->root;
	int i = r->n - 1;
	if (r->leaf == 1)
	{
		while (i >= 0 && r->key[i] > k)
		{
			i--;
		}
		if (i >= 0 && r->key[i] == k) {
			for (int j = i + 1; j < r->n; j++)
			{
				r->key[j - 1] = r->key[j];
			}
			r->n--;
			printf("삭제 성공\n");
		}
		else {
			printf("키 없음\n");
		}
		return;
	}
	else {
		if (r->n > 1) {
			btree_Delete_main(r, k);
		}
		else {
			node* left_c = r->child[0];
			node* right_c = r->child[1];
			if (left_c->n == t - 1 && right_c->n == t - 1) {
				left_c->key[t - 1] = r->key[0];
				for (int j = 0; j < t - 1; j++) {
					left_c->key[t + j] = right_c->key[j];
				}
				if (left_c->leaf == FALSE) {
					for (int j = 0; j < t; j++) {
						left_c->child[t + j] = right_c->child[j];
					}
				}
				left_c->n = t * 2 - 1;
				free(right_c);
				T->root = left_c;
				free(r);
				btree_Delete_main(left_c, k);
			}
			else {
				btree_Delete_main(r, k);
			}
		}
	}
}

void btree_Delete_main(node* x, int k) {
	int i = x->n;
	while (i > 0 && x->key[i - 1] >= k) {
		i--;
	}
	if (i < x->n && x->key[i] == k) {
		if (x->leaf == 1) {
			for (int j = i; j < x->n - 1; j++) {
				x->key[j] = x->key[j + 1];
			}
			x->n--;
			return;
		}
		else {
			node* left_c = x->child[i];
			node* right_c = x->child[i + 1];
			if (left_c->n > t - 1) {
				int pre_k = Find_Predecessor(left_c);
				x->key[i] = pre_k;
				btree_Delete_main(left_c, pre_k);
			}
			else if (right_c->n > t - 1) {
				int su_k = Find_Successor(right_c);
				x->key[i] = su_k;
				btree_Delete_main(right_c, su_k);
			}
			else {
				left_c->key[t - 1] = k;
				for (int j = 0; j < t - 1; j++)
				{
					left_c->key[t + j] = right_c->key[j];
				}
				for (int j = 0; j < t; j++) {
					left_c->child[t + j] = right_c->child[j];
				}
				left_c->n = 2 * t - 1;
				for (int j = i; j < x->n - 1; j++) {
					x->key[j] = x->key[j + 1];
				}
				for (int j = i+1; j < x->n; j++) {
					x->child[j] = x->child[j + 1];
				}
				x->n--;
				free(right_c);
				btree_Delete_main(left_c, k);
			}
		}
	}
	else
	{
		node* my_way_c = x->child[i];
		if (my_way_c->n > t - 1)
		{
			btree_Delete_main(my_way_c, k);
		}
		else
		{
			if (i != 0 && (x->child[i - 1])->n > t - 1)
			{
				node* left_c = x->child[i - 1];
				for (int j = t - 2; j >= 0; j--) {
					left_c->key[j + 1] = left_c->key[j];
				}
				if (left_c->leaf == FALSE)
				{
					for (int j = t - 1; j >= 0; j--) {
						left_c->child[j + 1] = left_c->child[j];
					}
				}
				my_way_c->key[0] = x->key[i - 1];
				my_way_c->child[0] = left_c->child[left_c->n];
				my_way_c->n++;
				x->key[i - 1] = left_c->key[left_c->n - 1];
				left_c->n--;
			}
			else if(i!=x->n && (x->child[i+1])->n > t - 1)
			{
				node* right_c = x->child[i + 1];
				my_way_c->key[t - 1] = x->key[i];
				my_way_c->child[t] = right_c->child[0];
				my_way_c->n++;
				x->key[i] = right_c->key[0];
				for(int j =0; j< right_c->n - 1; j++)
				{
					right_c->key[j] = right_c->key[j + 1];
				}
				for (int j = 0; j < right_c->n; j++) {
					right_c->child[j] = right_c->child[j + 1];
				}
				right_c->n--;
			}
			else {//x에 k가 없고, 풍족한 형제가 없을때!!!
				if (i == 0) {
					node* right_c = x->child[i + 1];
					for (int j = 0; j < t - 1; j++) {
						right_c->key[j + t] = right_c->key[j];
						right_c->key[j] = my_way_c->key[j];
					}
					if (right_c->leaf == 0) {
						for (int j = 0; j < t; j++) {
							right_c->child[j + t] = right_c->child[j];
							right_c->child[j] = my_way_c->child[j];
						}
					}
					right_c->key[t - 1] = x->key[i];
					right_c->n = t * 2 - 1;
					for (int j = 0; j < x->n - 1; j++) {
						x->key[j] = x->key[j + 1];
					}
					for (int j = 0; j < x->n; j++)
					{
						x->child[j] = x->child[j + 1];
					}
					free(my_way_c);
					my_way_c = right_c;
					x->n--;
				}
				else {
					node* left_c = x->child[i - 1];
					left_c->key[t - 1] = x->key[i - 1];
					for (int j = 0; j < t - 1; j++) {
						left_c->key[j + t] = my_way_c->key[j];
					}
					if (left_c->leaf == 0) {
						for (int j = 0; j < t; j++) {
							left_c->child[j + t] = my_way_c->child[j];
						}
					}
					left_c->n = 2 * t - 1;
					for (int j = i - 1; j < x->n - 1; j++) {
						x->key[j] = x->key[j + 1];
					}
					for (int j = i; j < x->n; j++) {
						x->child[j] = x->child[j + 1];
					}
					free(my_way_c);
					my_way_c = left_c;
					x->n--;
				}
			}
			btree_Delete_main(my_way_c, k);
		}
	}
	return;
}

int Find_Predecessor(node* x) {
	while (x->leaf == 0) {
		x = x->child[x->n];
	}
	return x->key[x->n - 1];
}

int Find_Successor(node* x) {
	while (x->leaf == 0) {
		x = x->child[0];
	}
	return x->key[0];
}
