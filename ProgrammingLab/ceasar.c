# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

void ceaser_cipher(char s[], int k){
    k = (k % 26 + 26) % 26;

    for (int i = 0; s[i] != '\0'; i++){
        char ch = s[i];

        if (isupper(ch)){
            s[i] = 'A' + ((ch - 'A' + k) % 26);
        } else if (islower(ch)){
            s[i] = 'a' + ((ch - 'a' + k) % 26);
        }
        // else do nothing
    }
}

void ceaser_decrypt(char s[], int k){
    // Normalize k so its always in range 26
    k = (k % 26 + 26) % 26;

    for (int i = 0; s[i] != '\0'; i++){
        char ch = s[i];

        if (isupper(ch)){
            s[i] = 'A' + ((ch - 'A' - k + 26) % 26);
        } else if (islower(ch)){
            s[i] = 'a' + ((ch - 'a' - k + 26) % 26);
        }
    }
}


int main(){
    char s[100] = "Hello World";
    int k = 3;

    ceaser_cipher(s, k);
    printf("Encoded string: %s\n", s);

    ceaser_decrypt(s, k);
    printf("Decypted string: %s\n", s);


    return 0;
}