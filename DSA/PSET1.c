# include <stdio.h>

void swap (int* a, int* b){
    *a = *a + *b; // sum
    *b = *a - *b; // og a
    *a = *a - *b;
}

void coolSwap (int* a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main(){

    // int x = 10;
    // int y = 20;
    // int* q = &y;
    // int* p = &x;

    // printf("%d\n", *p);
    // p = q; // now p stores the memory location of y, so now p if dereferenced should have the value 20
    // printf("%d\n", *p); // 20

    // *q = *p + *q; // *q is 20 and *p is 20; = 40
    // printf("%d\n", *q); // 40 

    // printf("%d\n", *p); // why is this 40?? is it because it points to the memory location where the value y is? 
    // printf("%d\n", y); // Okay then i see why coz y is now 40 so *p being 40 makes sense
    // *p = *p + x; // p is 20 and x is 10 so 30?
    // printf("%d\n", *p);

    // printf("%d\n", x); // the value of x remains unchanged

    // printf("%p\n", p); // should be the same as q
    // printf("%p\n", q); // yeah it is
    // printf("%p\n", &x); // localion of x
    // printf("%d", *p); // 50? absolutely

    // pointer to a pointer

    // int x = 10;
    // int *p = &x ; // memory location of x
    // int ** pp = &p ; // pointer to the pointer p should be the same as &x
    // printf ("%p\n", p); // not the same as the below line? why??
    // printf("%p\n", pp); // not evenn when i did &x
    // printf ("%d\n", *&* p) ;
    // printf ("%d\n", **& pp );
    // printf ("%d\n", *&** pp ) ;

    // int x = 10;
    // int* p = &x;
    // int** pp = &p;

    // // value of x using pp
    // printf("%p\n", pp);    // address of p
    // printf("%p\n", *pp);   // value of p = address of x
    // printf("%d\n", **pp);  // value of x = 10

    // int arr[3] = {1, 2, 3};
    // int* p = arr; 

    // for (int i = 0; i < 3; i++){
    //     printf("%d: ", *(p + i)); // what???
    //     printf("%p ", (p + i));
    // }

    // printf("\n");
    // int x = 20;
    // void* ptr = &x;

    // // printf("%p", *ptr); // not allowed
    // // type cast to allow printing

    // printf("%d", *(int*)ptr);

    int x = 5, y = 9;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    coolSwap(&x, &y);
    printf("x=%d, y=%d\n", x, y);


    return 0;
}