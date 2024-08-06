#include "Canli.h"

struct CANLI* canliOlustur(int sayi) {
    struct CANLI* this;
    this = (struct CANLI*)malloc(sizeof(struct CANLI));
    this->deger = sayi;
    
    if (sayi > 0 && sayi < 10)
        this->sembol = 'B';
    else if (sayi > 9 && sayi < 21)
        this->sembol = 'C';
    else if (sayi > 20 && sayi < 51)
        this->sembol = 'S';
    else if (sayi > 50 && sayi < 100)
        this->sembol = 'P';  

    this->yokEt = &canliYokEt;
    this->gorunum = &gorunum;
    
    return this;
}

char* gorunum(struct CANLI* this, void* p) {
    int toplamUzunluk = 50;
    char* str = (char*)malloc(sizeof(char) * toplamUzunluk + 1);
    sprintf(str, "\n\nCanli Degeri: %d\nCanli Sembolu: %c",
                    this->deger,
                    this->sembol);
    return str;
}

void canliYokEt(struct CANLI* this) {
    if (this == NULL) return;
    free(this);
}
