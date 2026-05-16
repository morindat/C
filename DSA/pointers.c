# include <stdio.h>
# include <stdlib.h>

int main(){
    int arr[5] =  {2, 4, 5, 6, 7};
    int* ptr = arr; 

    for (int i = 0; i < 5; i++){
        printf("%d: %p\n", i, (void*)(ptr + i));
    }
}