/* btree */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int M 5;
typedef struct node* nodeP;
typedef struct node {
    nodeP p[M]; // 서브트리
    int n; // 노드 개수 
    int data[M - 1]; // 값의 수 
}node;
nodeP root = NULL;
 
// 처리 결과
enum KeyStatus { InsertFail, SearchFail, Success, InsertIt, LessKeys };

 
void insert(int);
void delNode(int);
enum KeyStatus ins(nodeP, int, int*, nodeP*);
int searchPos(int, int *, int );
enum KeyStatus del(nodeP, int);
 
// 메인 함수
void main(int ac, char* av[])
{
 
    int data,choice = 0,value,size,range;
    
    // 데이터 개수 & 데이터 범위
    scanf("%d ", &size);
    scanf("%d ", &range);
 
    for (int i = 0; i < size; i++) {
        insert(data); // 랜덤한 값 넣기
    }

    while (choice != 0) {
        scanf("%d ", &value); // 삭제할 값
        delNode(data);
        scanf("%d ", &choice); // 삭제할 값 여부
    }
    printf("종료!\n");

}
