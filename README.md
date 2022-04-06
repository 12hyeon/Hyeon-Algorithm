# Algorithm_practice

int N = 5;
int arr[M][2] = {{0,3},{2,6},{4,4},{6,5},{8,2}};

int total(int* a, int n) {
    int result = 0;
    for(int i=0; i<n; i++) {
        result += a[i][0] + a[i][1];
    }
    return result;
}

void printer(int* a, int n) {
    printf("   ");
    for(int i=0; i < end; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i=0; i<n; i++) {
        printf(" %s ", i+64);
        for (int j=0; j<end; j++) {
            if (result[i][j] == 1) { printf(" = "); }
            else { printf("   "); }
        }
        printf("\n");
    }
}

void FCFS()
{
    int a = arr;
    int n = 5
    int max = 8;
    int arr[n][max*100] = {0};
    int total_n = total(a, n)
    printf("%d",total);
    int state, end;
    for (int i=0; i<total; i++) {
        state = 0;
        for (int j=0; j<n; j++) {
            if(a[j][0] <= i && a[j][1] > 0 && state == 0) {
                state = j; break;
            }
        }
        if (state != 0) {
            result[i] = j;
            a[state][1] -= 1;
        }
        if (a[n-1] == 0) {
            end += 1;
            break;
        }
    }
    printer(a, n);
}
