# include <stdio.h>
# include <ctype.h>

# define ALPHA 26

void buildFreqMap(FILE* file, int freq[ALPHA]){
    int c;
    
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)){
            c = tolower(c);
            freq[c-'a']++;
        }
    }
}


void printFreqMap(FILE* file, int freq[ALPHA]) {
    fprintf(file, "Character frequencies:\n");
    for (int i = 0; i < ALPHA; i++) {
        if (freq[i] > 0) {
            fprintf(file, "'%c' : %d\n", i + 'a', freq[i]);
        }
    }
}


int main (){
    FILE *output_file;
    int freq[ALPHA] = {0};

    output_file = fopen("output.txt", "w");

    if(output_file == NULL){
        printf("failed to open the file");
        return 1;
    }

    fprintf(output_file, "Hello World!\n");
    fprintf(output_file, "I am new here, what about you? are you new here too?\n");

    fclose(output_file);

    // Open for reading
    
    output_file = fopen("output.txt", "r");
    if(output_file == NULL){
        printf("failed to open the file");
        return 1;
    }

    buildFreqMap(output_file, freq);
    printFreqMap(stdout, freq);
    fclose(output_file);

    // printing to file
    output_file = fopen("output.txt", "a");
    printFreqMap(output_file, freq);

    fclose(output_file);
    return 0;
}