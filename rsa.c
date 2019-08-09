#include "rsa.h"

int main()
{
    word x;
    word y;
    word r;
    int test;

    init(&x);
    remplir(&x, 5);
    remplir(&y, 4);
    // printf("%d\n", x.l);
    affiche(&x, "x");
    // copy(&x,&y);
    affiche(&y, "y");

    // add(&r, &x, &y);
    // affiche(&r, "r");
    // test = compare(&x, &y);
    // compare(&x, &y);
    // printf("%d\n", compare(&x, &y));
    sub(&r, &x, &y);
    affiche(&r, "r");

    return 0;
}

/* init : initialization */
void init(word *x)
{
    int i;
    for (i = 0; i < size; ++i){
        x->val[i] = 0;
    }
    x->l = 0;
}

/* remplir le tableau jusqu'a l <= size */
/* remplire avec des données alzatoire pour faire des tests */
void remplir(word *x, int l)
{
    int i;
    for (i = 0; i < l; ++i){
        //x->val[i] = 0xFF;//rand() % max;    /* Test of BoF */
        x->val[i] = rand() % max;    /* max = uint8_t = 8 bits = de 0,1 ..., 255 = 256 choix */
    }
    x->l = l;
}

/* affichage à l'inverse car c'est de l'hexa */
void affiche(word *x, char * nom)
{
    int i;
    printf("%s\t=\t", nom);
    for (i = (x->l)-1; i >= 0; --i){
        printf("%02x ", x->val[i]);
    }
    printf("\n");
    // printf("%d\n", x->l);
}

void copy(word *cop, word *past)
{
    int i;
    for (i = 0; i < cop->l; ++i){
        past->val[i] = cop->val[i];
    }
    past->l = cop->l;
}

/* Instruction for the implementation :
    - 3 octets :
    - gestion de retenue
    - cas de a+b > de max
    - sense d'affichafe hexa
*/


void add(word *r, word *a, word *b)
{
    int longeur = (a->l >= b->l)? a->l:b->l;
    int i;
    int retenue = 0;

    for (i = 0; i < longeur; ++i){
        r->val[i] = a->val[i] + b->val[i] + retenue;    /* retenue de i-1 qu'on va utilisé pour i */
        retenue = ((a->val[i] + b->val[i] + retenue) > max)? 1:0;
    }
    r->l = (retenue)? longeur+1:longeur;
    if (r->l > size){
        printf("Error in function ADD : BOF of the table size.\n");
        exit (1); /* to do : customize error cods */
    }
    /* We assigne the value to the result table only if there is n't a BOF */
    r->val[i] = retenue;

}


/*
update() : make sure that the zero in left of the
2 possible solutions :
    - Compare the length of each vector, and if there are even, compare the largest
    deux symboles until you find which is biger.
    - Clculate the value of each victor (sum of each element multiply it by it's base)
*/
int compare(word *a, word *b)
{
    // int A, B;
    //
    // int i, base;
    //
    // for (i = 0; i < a->l; ++i){
    //     A += a->val[i];
    // }
    // for (i = 0; i < b->l; ++i){
    //     B += b->val[i];
    // }
    // printf("%d\n", A);
    // printf("%d\n", B);
    //
    // if (A > B)
    //     return 1;
    // else if (A < B)
    //     return -1;
    // else
    //     return 0;

    if (a->l > b->l)
        return 1;
    else if (a->l < b->l)
        return -1;
    else if (a->l == b->l){
        int i =  a->l;
        for(i; i > 0; --i){
            if (a->val[i] > b->val[i]){
                return 1;
                break;
            }
            else if (a->val[i] < b->val[i]){
                return -1;
                break;
            }
        }
    }
}
/*  sub() : substraction operation
    - a must be bigger than b to do the substractio
    - handle the rest of the substraction (on the i+1 operation)
    - when ai < bi we use the max verialble (e.g 10, 0x100 in hex)
        (max - bi)+ ai - rest
*/
void sub(word *r, word *a, word *b)
{
    int i , rest;
    rest = i = 0;

    if (compare(a, b) == 1){
        r->l = a->l;
        for (i; i < a->l; ++i){
            if (a->val[i] >= b->val[i]){
                r->val[i] = a->val[i] - b->val[i] - rest;
                rest = 0;
            }
            else if (a->val[i] < b->val[i]){
                r->val[i] = (max - b->val[i]) + a->val[i] - rest;  /* ri = (bi - max) +ai - rest */
                rest = 1;
            }
        }
    }
    else if(compare(a, b) == -1)
        printf("Error in function SUB : a < b.\n");
    else
        printf("Error in function SUB : a = b.\n");
}
