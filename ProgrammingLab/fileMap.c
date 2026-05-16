# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# define MAX 256

void buildFreqMap(FILE* file, int freq[]){
    for (int i = 0; i < MAX; i++){
        freq[i] = 0;
    }

    int c;
    while ((c = fgetc(file)) != EOF){
        freq[c]++;
    }
}

void printFreqMap(FILE *out, int freq[]){
    for (int i = 0; i < MAX; i++){
        if (freq[i] > 0){
            if (isprint(i)){
                fprintf(out, "'%c' : %d\n", i, freq[i]);
            } else {
                fprintf(out, "ASCII %d : %d\n", i, freq[i]);
            }
        }
    }
}


int main (){
    FILE *file;
    file = fopen("file.txt", "w");

    int freq[MAX];

    if (file == NULL){
        printf("failed to open the file");
        return 1;
    }

    fprintf(file, "Hello, this is Justin and welcome to C programming. Today i will be learning how to output frequency of letters in a file.\n");
    fputs("Ride along as we navigate the wonders of C programming.\n", file);
    fclose(file);

    // Next steps??
    // Open file.txt for read
    // Build a freq map
    // open out.txt for write and output the freq map into it

    file = fopen("file.txt", "r");

    if (file == NULL){
        printf("File opening unsuccessful\n");
        return 1;
    }

    buildFreqMap(file, freq);
    
    FILE *out = fopen("out.txt", "w");
    if (out == NULL){
        printf("failed to open file\n");
        return 1;
    }

    fprintf(out, "Character Frequencies:\n");
    printFreqMap(out, freq);
    printFreqMap(stderr, freq);

    // close both files
    fclose(file);
    fclose(out);


    return 0;
}