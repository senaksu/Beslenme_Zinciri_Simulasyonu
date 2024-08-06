#ifndef CANLI_H
#define CANLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CANLI {
    int deger;
    char sembol;

    char* (*gorunum)(struct CANLI*, void*);
    void (*yokEt)(struct CANLI*);
};

struct CANLI* canliOlustur(int);
char* gorunum(struct CANLI*, void*);
void canliYokEt(struct CANLI*);
#endif