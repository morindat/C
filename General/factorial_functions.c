# include <stdio.h>

int fact(int n){
    if(!n){
        return 1;
    }
    else{
        int factorial = n * fact(n-1);
        return factorial;
    }
}

int facto(int n){
    int factor = 1;

    if(!n){
        return 1;
    }
    else{
        for(int i = 1; i <= n; i ++){
            factor *= i;
        }
    }
    return factor;
}

char Geo(int n){
    if(!n){
        return 'N';
    }
    else{
        return 'Y';
    }
}

void table(){
    printf("%-5s | %-25s | %-25s | %-15s\n", "i", "recursive factorial", "iterative factorial", "Similarity [Y/N]");
    printf("-------------------------------------------------------------------------------- \n");

    for(int i = 1; i <= 7; i++){
        printf("%-5d | %-25d | %-25d | %-15c \n", i, fact(i), facto(i), Geo(fact(i) == facto(i)));
    }
    printf("\n");
}

int main(){
    int n = 7;
    int res = fact(n);
    int res2 = facto(n);

    printf("\n");
    printf("Factorial recursively: %d\n", res);
    printf("Factorial iteratively: %d\n", res2);
    printf("\n");

    table();

    return 0;
}