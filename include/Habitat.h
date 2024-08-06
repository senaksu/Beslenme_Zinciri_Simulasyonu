#ifndef HABITAT_H
#define HABITAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Bitki.h>
#include <Bocek.h>
#include <Sinek.h>
#include <Pire.h>
#include <Canli.h>

struct HABITAT {
    int satir_sayisi;
    int sutun_sayisi;
    
    void (*yokEt)(struct HABITAT*);
    void (*goster)(struct HABITAT*, struct CANLI***);
    void (*guncelle)(struct HABITAT*, struct CANLI***);
};
struct HABITAT* habitatOlustur(int, int);

void print(struct HABITAT*, struct CANLI***);

void update(struct HABITAT*, struct CANLI***);

void habitatYokEt(struct HABITAT*);

#endif