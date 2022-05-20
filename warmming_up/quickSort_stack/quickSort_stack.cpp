
#include <stdio.h>
#include <stack>

using namespace std;

#define MAX_SIZE  9
#define SWAP(x,y,temp) ((temp) = (x), (x) = (y), (y)=(temp))

// Stack
// 0. stack 에 array  lef / right를 push 한다.

// 1. Stack 에서 partition(left / right) 를 획득한다. 
// 1.1 pivot 은 array[left]
// 2. (while) rigth < left 가 될 때까지  왼쪽은 작은 값 오른쪽은 큰값으로 swap 한다.
// 3.  array[left] 깂과 right값을 교환 한다.
// 4. Stack에 partition 값을 넣는다. 



int devide(int list[], int left, int right) {
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

quickSort(int array[],stack s,left,right) {

    s.push(make_pair<int,int>(left,right));

    while (s.empty) {
        pair<int,int> partition = stack.pop();

        /* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
        if(partition.left<partition.right){

            q = devide(array,left,right);

            stack.push(make_pair<int,int>(left,q-1));
            stack.push(make_pair<int,int>(right,q+1));
        }
    }
}

int main(){
  int i;

  int list[MAX_SIZE] = {5, 3, 8, 4, 9, 1, 6, 2, 7};

  // 퀵 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 8)
  quick_sort(list, 0, n-1);

  // 정렬 결과 출력
  for(i=0; i<n; i++){
    printf("%d\n", list[i]);
  }

  return 0;
}
