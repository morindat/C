# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "heap.h"

HeapNode heap[MAX_HEAP];
int heap_size = 0;

void log_heap_state(const char* operation){
    FILE *fp = fopen("heap_log2.txt", "a");
    if (!fp) return;

    fprintf(fp, "%s\n", operation);

    for (int i = 0; i < heap_size; i++){
        fprintf(fp, "%s", heap[i].event_id);
        if (i < heap_size - 1){
            fprintf(fp, ", ");
        }
    }
    fprintf(fp, "\n\n");
    fclose(fp);
}

/*
TODO:

I need to implement a few things for this max heap program

1. Sift up and sift down functions 
2. Decrease functions

Nipe hela man
I need hela man
mbona hutumi hela man
hela iko wapi asee
mbona iyo hela haijatumwa adi leo asee
fanya kunitumia hela asee
this is the only thing that i deem important at this moments in life
send me the fucking money broooo
vhat are you doing vroo
dahh sawa bhana kama hamna hela
why dont you try one too and see how it tastes like
*/