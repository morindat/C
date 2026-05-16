/*
 * Huffman Compression Program
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long BYTECOUNTER;

typedef struct htree {
  unsigned char c;
  BYTECOUNTER cfreq;
  struct htree *parent;
  struct htree *right;
  struct htree *left;
}huffman;

huffman ht[512];
huffman *root;
char out8;
int ct8;

/*bits -> output file*/
void outbit(FILE *fo, int bit) {
  if (ct8 == 8 || bit == -1) {
    fputc(out8, fo);
    ct8 = 0;
  }
  out8 = (out8 << 1) | bit;
  ct8++;
}

/*character value -> bit stream*/
void compress(FILE *fo, huffman *h,huffman *child) {
  if (h->parent != NULL) {compress(fo, h->parent, h);}
  if (child) {
    if (child == h->right) {outbit(fo, 0);} 
    else {if (child == h->left) outbit(fo, 1);}
 }
}

void buildtree(void)
{
 /*frequency array -> Huffman tree*/

 int treect = 256;
 int i;
 huffman *h1,*h2;
 while(1)
 {h1=h2=NULL;
  for(i=0;i<treect;i++)   
  {if (ht+i != h1) 
   {if (ht[i].cfreq > 0 && ht[i].parent==NULL)
    {if (h1 == NULL || ht[i].cfreq < h1->cfreq)
     {if (h2 == NULL || h1->cfreq < h2->cfreq)
       h2 = h1;
      h1 = ht+i;
     }
     else 
      if (h2 == NULL || ht[i].cfreq < h2->cfreq)
       h2 = ht+i;
    }
   }
  }
  if (h2 == NULL)
  {root = h1;
   break;
  }
  /*combine and add*/
  h1->parent = ht+treect;
  h2->parent = ht+treect;
  ht[treect].cfreq = h1->cfreq + h2->cfreq;
  ht[treect].right = h1;
  ht[treect].left = h2;
  treect++;
 }
}

void main(int argc, char *argv[]) {
  FILE *fi, *fo;
  int c;
  BYTECOUNTER bytectr = 0;
  long freqctr = 0;

  /*error messages*/
  if (argc != 3) {
    printf("\nusage: compress infile outfile");
    if(argc>3)
      printf("\nOnly the first two filenames are going to be used."); 
    if(argc==1) {
      printf("\nEnter Input filename :");
      gets(argv[1]);
      argc++;
    }
    if(argc==2) {
      printf("\nEnter Output filename :");
      gets(argv[2]);
      argc++;
    }
  }
  if ((fi = fopen(argv[1], "rb")) == NULL) {
    printf("\nCannot open %s", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((fo = fopen(argv[2], "wb")) == NULL) {
    printf("\nCannot open %s", argv[2]);
    fclose(fi);
    exit(EXIT_FAILURE);
  }


  /*input file : read and count character frequency*/
  while ((c = fgetc(fi)) != EOF) {
    c &= 255;
    if (ht[c].cfreq == 0) {
      freqctr++;
      ht[c].c = c;
    }
    ht[c].cfreq++;
    bytectr++;
  }

  fwrite(&bytectr, sizeof bytectr, 1, fo); /*byte count -> output file*/
  fwrite(&freqctr, sizeof freqctr, 1, fo); /*frequency count -> output file*/

  /*frequency array -> output file*/
  for (c = 0; c < 256; c++) {
    if (ht[c].cfreq > 0) {
      fwrite(&ht[c].c, sizeof(char), 1, fo);
      fwrite(&ht[c].cfreq, sizeof(BYTECOUNTER), 1, fo);
    }
  }

  buildtree();

  /*compress(finally !)*/
  fseek(fi, 0L, 0);
  while ((c = fgetc(fi)) != EOF)
    compress(fo, ht + (c & 255), NULL);

  outbit(fo, -1);
  fcloseall();
  printf("\nDone.\n");
}
