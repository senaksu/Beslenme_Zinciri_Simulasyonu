#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI{
    struct CANLI* super;
    
    void (*yoket)(struct BITKI*);
};

struct BITKI* bitkiOlustur(int);
void bitkiYokEt(struct BITKI*);
#endif