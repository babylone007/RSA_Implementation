/* Header file for all include declaration of the original rsa.c program */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


/* RSA implementation of a variable size length */

#define     size    10          /* KEY size, it can be changed to upgrade the key size */
#define     max     0x100         /* 256 = 2^8 pour uint8_t = 0x100 IN HEX  */

struct _word{
    uint8_t val[size];          /* unit8_t : unsigned int of 8 bits */
    int l;
};

typedef struct _word word;       /* word = struct _word, "a short name" */

void init(word *x);
void affiche(word *x, char * nom);   /* char * : tableau de n char (n=*) */
void remplir(word *x, int l);
void copy(word *cop, word *past);     /* copy tab cop in tab past */
void add(word *r, word *a, word *b);    /* r = a + b */

/*
void addition(word *r, word *a, word *b)
{
    int i, ln, ret;
    ret = 0;
    ln = (a->l >= b->l)? a->l:b->l;

    for (i = 0; i < ln; ++i){
        r->val[i] = a->val[i] + b->val[i] + ret;
        ret = ((a->val[i] + b->val[i] + ret) > max)? 1:0;
    }

    r->l = (ret)? ln+1:ln;
    if (r->l > size){
        printf("%s\n", "BOF");
        exit(-1);
    }
    r->val[i] = ret;
}
*/
