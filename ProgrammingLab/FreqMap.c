# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# define MAX 26


int main (){
    char str[10] = "justiin";
    int len = strlen(str);
    int freq[MAX];

    for (int i = 0; i < MAX; i++){
        freq[i] = 0;
    }


    for (int i = 0; i < len; i++){
        char c = tolower(str[i]);
        freq[c - 'a']++;
    }

    for (int i = 0; i < MAX; i++){
        if (freq[i] > 0){
            printf("%c : %d \n", i + 'a', freq[i]);
        }
    }
    printf("\n");


    return 0;
}