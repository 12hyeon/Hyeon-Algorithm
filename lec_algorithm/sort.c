#include <time.h>
#include <stdlib.h>
#include <stdio.h>

// Exchange sort

void exchangesort(int n, int* a) {
    int tmp;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i] > a[j]) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

// Mergesort
void mergesort(int low, int high, int *S) {
    if (low+1<high) { // 시작 인덱스, 끝 인덱스+1
        int mid = (low+high)/2; 
        mergesort(low,mid,S);
        mergesort(mid,high,S);
        merge(low, mid, high, S);
    }

}

void merge(int low, int mid, int high, int *S) {
    int new[high-low];
    int i=low, j=mid, k=0;
    while (i<mid && j<high) {
        if (S[i] < S[j]) {
            new[k] = S[i];
            i++;
        }
        else {
            new[k] = S[j];
            j++;
        }
        k++;
    }
    if (i >= mid) {
        for (; j<high; j++) {
            new[k] = S[j];
            k++;
        }
    }
    else {
        for (; i<mid; i++) {
            new[k] = S[i];
            k++;
        }
    }
    for (int x=low; x<high; x++) {
        S[x] = new[x-low];
    }
}

// Quicksort
void quicksort(int low, int high, int* S) {
    int pivot;
    if (high > low) {
        partition(low, high, &pivot, S);
        quicksort(low, pivot, S);
        quicksort(pivot+1, high, S);
    }
}

void partition (int low, int high, int *pivot, int* S) {
    int i, j, tmp;
    int pivotitem = S[low];
    j = low;
    for (i=low+1; i<high; i++) {
        if (S[i] < pivotitem) {
            j++;
            tmp = S[i];
            S[i] = S[j];
            S[j] = tmp;
        }
    }
    *pivot = j;
    tmp = S[low];
    S[low] = S[*pivot];
    S[*pivot] = tmp;
}


// Heapsort

typedef struct {
    int heap[10000+1];
    int size;
} heaptype;


heaptype* createheap() {
    heaptype* h = (heaptype*)malloc(sizeof(heaptype));
    h->size = 0;
    return h;
}

void insertheap(heaptype* h, int n) {
    h->size += 1;
    int i = h->size;
    h->heap[i] = n; // 마지막에 자리에 추가
}

void removeheap(int n, heaptype* H, int* result) {
    for (int i=n; i>=1; i--) {
        result[i] = root(H);
    }
}
void makeheap(int n, heaptype* h) {
    h->size = n;
    for (int i=n/2; i>=1; i--) {
        siftdown(h,i);
    }
}

void siftdown(heaptype* h, int i) {
    int key = h->heap[i], b_child;
    int par = i, spot = 0;
    while (2*par <= h->size && !spot) { // 왼쪽 자식 존재
        if (2*par < h->size && h->heap[2*par] < h->heap[2*par+1]) {
            // 오른쪽 자식 존재 + 비교
            b_child = 2*par+1; // 오른쪽이 더 큰 값
        }
        else {
            b_child = 2*par; // 왼쪽이 더 큰 값 or  왼쪽만 존재
        }

        if(key < h->heap[b_child]) { // key가 b_child보다 작은 경우
            h->heap[par] = h->heap[b_child]; // 내려가기
            par = b_child;
        }
        else {
            spot = 1;
        }
    }
    h->heap[par] = key;
}

int root (heaptype* h) {
    int key = h->heap[1];
    h->heap[1] = h->heap[h->size];
    h->size -= 1;
    siftdown(h,1);
    return key;
}

void heapsort(int n, heaptype* h, int* new) {
    makeheap(n,h);
    removeheap(n,h,new);
}

// Radix sort
/*
struct node {
    int key;
    node* link;
}node;

void radixsort(node* master, int num) {
    node* list[10];
    for(int i=0; i<num; i++) {
        distribute(master, list, i);
        coalesce(master, list);
    }
}

void distribute(node* master, node* list, int i) {
    for(int j=0; j<10; j++) {
        list[j] = NULL;
    }
    node* p = master;
    while (p != NULL) {
        //j = ;
        p = p->link;
    }
}

void coalesce(node* master, node* list) {
    master = NULL;
    for(int j=0; j<10; j++) {
        //
    }
}
*/

int main() {
    int a[10000];
    int num[5] = {100,500,1000,5000,10000};
    int S[5][10000], value;

    clock_t end, start;
    for(int n=0; n<5; n++) {
        long time[5] = {0.0};
        for(int m=0; m<5; m++) {
            for (int i=0; i<num[n]; i++) {
                value = abs(rand())%100;
                for (int j=0; j<5; j++) {
                    S[j][i] = value;
                }
            }
            
            start = clock();
            exchangesort(num[n], S[0]);
            end = clock();
            time[0] += (end-start);
            /*
            printf("exchange sort %d times : %d\n", num[n], (end-start));
            for (int x=0; x<num[n]; x++) {
                printf("%2d ", S[0][x]);
            }
            printf("\n");
            */

            start = clock();
            mergesort(0, num[n], S[1]);
            end = clock();
            time[1] += (end-start);
            /*
            printf("merge sort %d times : %d\n", num[n], (end-start));
            for (int x=0; x<num[n]; x++) {
                printf("%2d ", S[1][x]);
            }
            printf("\n");
            */

            start = clock();
            quicksort(0, num[n], S[2]);
            end = clock();
            time[2] += (end-start);
            /*
            printf("quick sort %d times : %d\n", num[n], (end-start));
            for (int x=0; x<num[n]; x++) {
                printf("%2d ", S[2][x]);
            }
            printf("\n");
            */

            int new[10000];
            heaptype* h = createheap();
            start = clock();
            for (int x=0; x<num[n]; x++) {
                insertheap(h, S[3][x]);
            }
            heapsort(h->size,h,new);
            end = clock();
            time[3] += (end-start);
            /*
            printf("heap sort %d times : %d\n", num[n], (end-start));
            for (int x=1; x<=num[n]; x++) {
                printf("%2d ", new[x]);
            }
            printf("\n");
            */
        }
        printf("exchange sort %d times : %d\n", num[n], time[0]/5);
        printf("merge sort %d times : %d\n", num[n], time[1]/5);
        printf("quick sort %d times : %d\n", num[n], time[2]/5);
        printf("heap sort %d times : %d\n", num[n], time[3]);
        printf("\n");
    }
}

// 미완성 구현사항
// Radix sort

typedef struct {
    int key;
    struct node* link;
}node;

void insertnode(node* master, int i) {
    node* n, *now = master;
    n->key = i;
    n->link = NULL;
    if (now == NULL) {
        now = n;
    }
    else {
        while (now != NULL) {
            now = now->link;
        }
        now =
    }
}

node* radixsort(node* master, int num) {
    int list[10];
    for(int i=0; i<num; i++) {
        distribute(master, list, i);
        coalesce(master, list);
    }
    return master;
}

void distribute(node* master, int* list, int i) {
    for(int j=0; j<10; j++) {
        list[j] = NULL;
    }
    node* p = master;
    node* n;
    int j;
    while (p != NULL) {
        j = p->key;
        n = list[j%10];
        if (n != NULL) {
            while (n != NULL) {
                n = n->link;
            }
        }
        n->key = j;
        n->link = NULL;
        p = p->link;
    }
}

coalesce(node* master, int* list) {
    master = NULL;
    node* n;
    for(int j=0; j<10; j++) {
        if (master != NULL) {
            while (master != NULL) {
                master = master->link;
            }
        }
        if (list[j] != NULL) {
            n = list[j];
            master->key = n->key;
            master->link = n->link;
        }
    }
}

