/* Header file for all include declaration of the original rsa.c program */

/* Code Error
    1 : in add(), r = a + b > size, the vector length is larger than the maximum
        size specified by the global "size" variable.
    2 :
    3 :
*/

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
void affiche(word *x, char * nom);      /* char * : tableau de n char (n=*) */
void remplir(word *x, int l);           /* fel a word with value */
void copy(word *cop, word *past);       /* copy tab cop in tab past */
void add(word *r, word *a, word *b);    /* r = a + b */
int compare(word *a, word *b);          /* compare a to b */
void sub(word *r, word *a, word *b);              /* r = a - b */
