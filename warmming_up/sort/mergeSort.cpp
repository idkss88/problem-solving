#include <iostream>


int number = 8;

int size;
int sorted[8];
int count = 0;

void merge(int a[], int m, int middle, int n) {
    int i = m;
    int j = middle +1;
    int k = m;

    //작은 순서로 배열에 삽입

    while( i <= middle && j <= n) {
        if ( a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;    
        } else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > middle) {
        while(j <= n) {
            sorted[k++] = a[j++];
        }
    } else if (j > n) {
        while(i<= middle)  {
            sorted[k++] = a[i++];
        }
    }

    for (int t = m ; t <= n; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort(int a[], int m, int n) {
    // 이외의 경우는 크기가 1인 경우
    if (m < n) {
        int middle =  (m + n)/2;
        mergeSort(a,m,middle);
        mergeSort(a,middle+1,n);

        merge(a,m,middle,n);

    }
}

int main(void) {
    int array[8] = {7,6,5,8,4,5,9,1};
    mergeSort(array, 0, number -1);

    for (int i = 0 ; i < 8 ; i++) {
        printf("%d", array[i]);
    }

    printf("\n");



}