#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


/* RSA implementation of a variable size length */

#define     size    10          /* KEY size */
#define     max     0x100         /* 256 = 2^8 pour uint8_t = 0x100 IN HEX  */

struct _word{
    uint8_t val[size];
    int l;
};

typedef struct _word word;       /* word = struct _word */

void init(word x);
void affiche(word x, char * nom);   /* char * : tableau de n char (n=*) */
void remplir(word x, int l);
void copy(word cop, word past);     /* copy tab cop in tab past */

int main()
{
    word x;

    init(x);
    remplir(x, 5);
    printf("%d\n", x.l);
    // affiche(x, "x");
    return 0;
}

/* init : initialization */
void init(word x)
{
    int i;
    for (i = 0; i < size; ++i){
        x.val[i] = 0;
    }
    x.l = 0;
}

/* remplir le tableau jusqu'a l <= size */
void remplir(word x, int l)
{
    int i;
    for (i = 0; i < l; ++i){
        x.val[i] = rand() % max;    /* max = uint8_t = 8 bits = de 0,1 ..., 255 = 256 choix */
    }
    x.l = l;
}

void affiche(word x, char * nom)
{
    int i;
    printf("%s\t=\t", nom);
    for (i = 0; i < x.l; ++i){
        printf("%02x ", x.val[i]);
    }
    printf("\n");
    //printf("%d\n", x.l);
}
