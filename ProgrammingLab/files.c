# include <stdlib.h>
# include <string.h>
# include <stdio.h>




int main(){
    char input[200];
    int freq[26];

    for (int i = 0; i < 26; i++){
        freq[i] = 0;
    }

    FILE *file = fopen("file.txt", "w");

    if(!file){
        fprintf(stderr, "Error opening the file\n");
        return 1;
    }

    printf("Please write a message: ");
    fgets(input, sizeof(input), stdin);

    fprintf(file, "%s", input);
    fclose(file);

    file = fopen("file.txt", "r");
    int c;
    while((c = fgetc(file)) != EOF){
        if (c >= 'a' && c <= 'z'){
            freq[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z'){
            freq[c - 'A']++;
        }
        
    }

    for (int i = 0; i < 26; i++){
        if (freq[i] != 0){
            printf("%c = %d\n", 'a' + i, freq[i]);
        }
    }

    fclose(file);

    file = fopen("file.txt", "a");

    for (int i = 0; i < 26; i++){
        if (freq[i] != 0){
            fprintf(file, "%c = %d\n", 'a' + i, freq[i]);
        }
    }
    fclose(file);
    
    return 0;
}