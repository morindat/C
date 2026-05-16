# include <stdio.h>

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if (i != n - 1){
            printf(", ");
        }
    }
    print("\n");
}

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++){
        printf("Enter a number to populate the array at position %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // print array
    printArray(arr, 5);
}