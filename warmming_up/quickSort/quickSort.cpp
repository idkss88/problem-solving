#include <stdio.h>
#define MAX_SIZE  9
#define SWAP(x,y,temp) ((temp) = (x), (x) = (y), (y)=(temp))


int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;

    low = left;
    high = right +1;
    pivot = list[left];


    do {
        do {
            low++;
        } while (low <= right && list[low] < pivot);

        do {
            high--;
        } while (high >= left && list[high] > pivot);

        if (low < high) {
            SWAP(list[low], list[high],temp);
        }

    } while(low<high);
 // low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
    SWAP(list[left], list[high],temp);

    return high;
}

// 퀵 정렬
void quick_sort(int list[], int left, int right){

  /* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
  if(left<right){
    // partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
    int q = partition(list, left, right); // q: 피벗의 위치

    // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
    quick_sort(list, left, q-1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
    quick_sort(list, q+1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
  }

}
int main(){
  int i;
  int n = MAX_SIZE;
  int list[n] = {5, 3, 8, 4, 9, 1, 6, 2, 7};

  // 퀵 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 8)
  quick_sort(list, 0, n-1);

  // 정렬 결과 출력
  for(i=0; i<n; i++){
    printf("%d\n", list[i]);
  }

  return 0;
}
