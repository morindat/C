# include <stdio.h>
# include <stdlib.h>


void k_sum(int *arr, int n, int k, int target, int index, int start, int current_sum, int *temp){

    if (index == k){
        if (current_sum == target){
            printf("Found : ");
            for (int i = 0; i < k; i++){
                printf("%d ", temp[i]);
            }
            printf("\n");
        }
        return;
    }

    if (start >= n) return;

    for(int i = start; i < n; i++){
        temp[index] = arr[i];
        k_sum(arr, n, k, target, index + 1, i + 1, current_sum + arr[i], temp);
    }

}


int main(){
    int nums[5] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 4;
    int target = 9;

    int temp[10]; // temporary array to store combination

    printf("Combinations that sum to %d using %d numbers:\n", target, k);
    k_sum(nums, n, k, target, 0, 0, 0, temp);

    return 0;
}