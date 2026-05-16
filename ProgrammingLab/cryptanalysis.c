# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

# define ALPHA 26

void freqMap(const char *text, int freq[ALPHA]){
    for (int i = 0; i < ALPHA; i++){
        freq[i] = 0;
    }

    for (int i = 0; text[i] != '\0'; i++){
        char c = toupper(text[i]);
        if (isalpha(c)){
            freq[c - 'A']++;
        }
    }
}

void freqPercentage(const int freq[ALPHA], double percent[ALPHA], int tot_letters){
    for (int i = 0; i < ALPHA; i++){
        if (tot_letters > 0){
            percent[i] = (freq[i] * 100) / (double)tot_letters;
        }
        
        else {
            percent[i] = 0.0;
        }
    }
}

void print(const int freq[ALPHA], const double percent[ALPHA]){
    printf("Letter | Count  | Percentage\n");
    printf("----------------------------\n");

    for (int i = 0; i < ALPHA; i++){
        if (freq[i] > 0) {
            printf ("  %c    |  %3d   |  %6.2f%%\n", i + 'A', freq[i], percent[i]);
        }
    }
}

int countLetters (const char* text){
    int total = 0;
    for (int i = 0; text[i] != '\0'; i++){
        if (isalpha(text[i])){
            total++;
        }
    }

    return total;
}


int main(){

    const char* ciphertext = "XUBBE MEHBT";
    
    int freq[ALPHA];
    double percent[ALPHA];

    // build the freq map and get total
    freqMap(ciphertext, freq);
    int total_letters = countLetters(ciphertext);
    printf("%d\n", total_letters);

    // calculate %
    freqPercentage(freq, percent, total_letters);

    print(freq, percent);


    return 0;
}