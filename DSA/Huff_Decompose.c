/*
 * Huffman Decompression program
*/
#include <stdio.h>
#include <stdlib.h>


typedef unsigned long BYTECOUNTER;

typedef struct htree
{unsigned char c;
 BYTECOUNTER cfreq;
 struct htree *parent;
 struct htree *right;
 struct htree *left;
}huffman;

huffman ht[512];
huffman *root;
int in8,ct8 = 8;

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


static int inbit(FILE *fi)
{
 /*read a bit at a time from a file*/

 int obit;
 if (ct8 == 8)
 {in8 = fgetc(fi);
  ct8 = 0;
 }
 obit = in8 & 0x80;
 in8 <<= 1;
 ct8++;
 return obit;
}


static int decompress(FILE *fi, struct htree *h)
{
 /*file bits->characters*/

 while (h->right != NULL)
  if (inbit(fi))
   h = h->left;
  else
   h = h->right;
 return h->c;
}

void main(int argc, char *argv[])
{FILE *fi, *fo;
 unsigned char c;
 BYTECOUNTER bytectr;
 long freqctr;

 /*error messages*/
 if (argc != 3)
 {printf("\nusage: extract infile outfile");
  if(argc>3)
       printf("\nOnly the first two filenames are going to be used."); 
  if(argc==1)
      {printf("\nEnter Input filename :");
        gets(argv[1]);
        argc++;
      }
  if(argc==2)
      {printf("\nEnter Output filename :");
        gets(argv[2]);
        argc++;
      }
 }
 if ((fi = fopen(argv[1], "rb")) == NULL)
 {printf("\nCannot open %s", argv[1]);
  exit(EXIT_FAILURE);
 }
 if ((fo = fopen(argv[2], "wb")) == NULL)
 {printf("\nCannot open %s", argv[2]);
  fclose(fi);
  exit(EXIT_FAILURE);
 }

 fread(&bytectr, sizeof bytectr, 1, fi); /*read byte count*/
 fread(&freqctr, sizeof freqctr, 1, fi); /*read frequency count*/

 /**/
 while (freqctr--)   
 {fread(&c, sizeof(char), 1, fi);
  ht[c].c = c;
  fread(&ht[c].cfreq, sizeof(BYTECOUNTER), 1, fi);
 }

 buildtree();

 /*decompress*/
 while (bytectr--)
  fputc(decompress(fi, root), fo);
 fcloseall();
 printf("\nDone.\n");
}