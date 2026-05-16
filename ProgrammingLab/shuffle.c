# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

void shuffle(int arr[], int n){
    // loop backward
    // assign j (indexes) any random int from 0, to i inclusively
    // swap arr[i] and arr[j]
    if (n <= 1){
        return;
    }

    for (int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void shuffleStr(char arr[], int n){
    // loop backward
    // assign j (indexes) any random int from 0, to i inclusively
    // swap arr[i] and arr[j]
    if (n <= 1){
        return;
    }

    for (int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void reverse(int arr[], int start, int end){
    while (start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int arr[], int k, int n){
    if (n <= 1){
        return;
    }

    reverse(arr, 0, k - 1); 
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);

}
void rev(char str[], int start, int end){
    while (start < end){
        int temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void rotateStr(char s[], int k, int len){
    if (len <= 1){
        return;
    }

    rev(s, 0, k - 1);
    rev(s, k, len - 1);
    rev(s, 0, len - 1);
}

void print(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    srand(time(0));
    int arr[5];
    int n = 5;

    for (int i = 0; i < n; i++){
        arr[i] = i * 2 + i;
    }

    printf("Original array: ");
    print(arr, n);
    rotate(arr, 4, n);
    printf("Rotated array: ");
    print(arr, n);
    
    printf("Shuffled array: ");
    shuffle(arr, n);
    print(arr, n);  

    char myStr[] = "programming";
    int len = strlen(myStr);
    printf("Original string: %s\n", myStr);

    rotateStr(myStr, 4, len);
    printf("shuffled string: %s\n", myStr);

    shuffleStr(myStr, len); 
    printf("Shuffled string: %s\n", myStr);

    return 0;
}