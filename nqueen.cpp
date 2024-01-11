#include<stdio.h>
#include<stdlib.h>

int x[10];

int place(int queeno, int i) {
	int j;
    for(j = 0; j < queeno; j++) {
        if(x[j] == i || abs(x[j] - i) == abs(j - queeno)) {
            return 0;
        }
    }
    return 1;
}
void nqueen(int queeno, int n) {
	int i,j;
    for(i = 0; i < n; i++) {
        if(place(queeno, i+1)) {
            x[queeno] = i+1;
            if(queeno == n-1) {
                for(j = 0; j < n; j++) {
                    printf("%d ", x[j]);
                }
                printf("\n");
            } else {
                nqueen(queeno + 1, n);
            }
        }
    }
}

int main() {
    int n, i = 0;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nqueen(i, n);
    return 0;
}
