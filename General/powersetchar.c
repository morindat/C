# include <stdio.h>

int main (){
    char set[3];
    int i, j;

    printf("Enter the three elements of the set: \n");
    for (i = 0; i < 3; i++){
        printf("Element %d: ", i + 1);
        scanf(" %c", &set[i]);
    }

    printf("\nThe power sets are: \n");
    for(i = 0; i < 8; i ++){
        printf("{ ");
        for(j = 0; j < 3; j++){
            if (i & (1 << j)){
                printf("%c ", set[j]);
            }
        }
        
        printf("}\n");

    }


    return 0;
}