#include "Habitat.h"

void print(struct HABITAT* habitat, struct CANLI*** canli_dizisi)
{
    for(int i = 0; i < habitat->satir_sayisi ; i++)
    {
        for(int j = 0; j < habitat->sutun_sayisi ; j++)
        {
            if(canli_dizisi[i][j]!=NULL)
            {
                printf("%c ",canli_dizisi[i][j]->sembol);
            }
            else
            {
                printf("X ");
            }
        }
        printf("\n");
    }
}

void update(struct HABITAT* habitat, struct CANLI*** canli_dizisi)
{
    int savasci1x = -1;
    int savasci1y = -1;
    int savasci2x = -1;
    int savasci2y = -1;

    for(int i = 0; i < habitat->satir_sayisi; i++)
    {
        for(int j = 0; j < habitat->sutun_sayisi; j++)
        {
            if(canli_dizisi[i][j]!=NULL)
            {
                savasci1x = i;
                savasci1y = j;
                i = habitat->satir_sayisi;
                j = habitat->sutun_sayisi;
            }
        }
    }

    for(int loop2i = 0 ;loop2i < habitat->satir_sayisi ; loop2i++)
    {
        for(int loop2j = 0;loop2j < habitat->sutun_sayisi ; loop2j++)
        {   
            if(canli_dizisi[loop2i][loop2j] != NULL)
            {
                if(loop2i == savasci1x && loop2j == savasci1y){}
                else
                {
                savasci2x = loop2i;
                savasci2y = loop2j;
                loop2i = habitat->satir_sayisi;
                loop2j = habitat->sutun_sayisi;
                }
            }
        }
    }
    //printf("Savasci 1( %d , %d )\n", savasci1x , savasci1y);
    //printf("Savasci 2( %d , %d )\n", savasci2x , savasci2y);

    if(savasci2x != -1 && savasci2y != -1)
    {
        if(canli_dizisi[savasci1x][savasci1y]->sembol == 'B')
        {
            if(canli_dizisi[savasci2x][savasci2y]->sembol == 'B')
            {
                if(canli_dizisi[savasci1x][savasci1y]->deger >= canli_dizisi[savasci2x][savasci2y]->deger)
                {
                    canli_dizisi[savasci2x][savasci2y]->yokEt(canli_dizisi[savasci2x][savasci2y]);
                    canli_dizisi[savasci2x][savasci2y]= NULL;
                }
                else
                {
                    canli_dizisi[savasci1x][savasci1y]->yokEt(canli_dizisi[savasci1x][savasci1y]);
                    canli_dizisi[savasci1x][savasci1y]= NULL;
                }
            }
            else if(canli_dizisi[savasci2x][savasci2y]->sembol == 'C')
            {
                canli_dizisi[savasci1x][savasci1y]->yokEt(canli_dizisi[savasci1x][savasci1y]);
                canli_dizisi[savasci1x][savasci1y] = NULL;
            }
            else if(canli_dizisi[savasci2x][savasci2y]->sembol == 'S')
            {
                canli_dizisi[savasci2x][savasci2y]->yokEt(canli_dizisi[savasci2x][savasci2y]);
                canli_dizisi[savasci2x][savasci2y]= NULL;
            }
            else
            {
                canli_dizisi[savasci2x][savasci2y]->yokEt(canli_dizisi[savasci2x][savasci2y]);
                canli_dizisi[savasci2x][savasci2y]= NULL;
            }
        }
        else if(canli_dizisi[savasci1x][savasci1y]->sembol == 'C')
        {
            if(canli_dizisi[savasci2x][savasci2y]->sembol == 'C')
            {
                if(canli_dizisi[savasci1x][savasci1y]->deger >= canli_dizisi[savasci2x][savasci2y]->deger)
                {
                    canli_dizisi[savasci2x][savasci2y]->yokEt(canli_dizisi[savasci2x][savasci2y]);
                    canli_dizisi[savasci2x][savasci2y]= NULL;
                }
                else
                {
                    canli_dizisi[savasci1x][savasci1y]->yokEt(canli_dizisi[savasci1x][savasci1y]);
                    canli_dizisi[savasci1x][savasci1y]= NULL;
                }
            }
            else if(canli_dizisi[savasci2x][savasci2y]->sembol == 'S')
            {
                canli_dizisi[savasci1x][savasci1y]->yokEt(canli_dizisi[savasci1x][savasci1y]);
                canli_dizisi[savasci1x][savasci1y] = NULL;
            }
            else if(canli_dizisi[savasci2x][savasci2y]->sembol == 'B')
            {
                canli_dizisi[savasci2x][savasci2y]->yokEt(canli_dizisi[savasci2x][savasci2y]);
                canli_dizisi[savasci2x][savasci2y]= NULL;
            }
            else
            {
                canli_dizisi[savasci2x][savasci2y]->yokEt(canli_dizisi[savasci2x][savasci2y]);
                canli_dizisi[savasci2x][savasci2y]= NULL;
            }
        }
        else if(canli_dizisi[savasci1x][savasci1y]->sembol == 'S')
        {
            if(canli_dizisi[savasci2x][savasci2y]->sembol == 'S')
            {
                if(canli_dizisi[savasci1x][savasci1y]->deger >= canli_dizisi[savasci2x][savasci2y]->deger)
                {
                    canli_dizisi[savasci2x][savasci2y]->yokEt(canli_dizisi[savasci2x][savasci2y]);
                    canli_dizisi[savasci2x][savasci2y]= NULL;
                }
                else
                {
                    canli_dizisi[savasci1x][savasci1y]->yokEt(canli_dizisi[savasci1x][savasci1y]);
                    canli_dizisi[savasci1x][savasci1y]= NULL;
                }
            }
            else if(canli_dizisi[savasci2x][savasci2y]->sembol == 'B')
            {
                canli_dizisi[savasci1x][savasci1y]->yokEt(canli_dizisi[savasci1x][savasci1y]);
                canli_dizisi[savasci1x][savasci1y] = NULL;
            }
            else if(canli_dizisi[savasci2x][savasci2y]->sembol == 'C')
            {
                canli_dizisi[savasci2x][savasci2y]->yokEt(canli_dizisi[savasci2x][savasci2y]);
                canli_dizisi[savasci2x][savasci2y]= NULL;
            }
            else
            {
                canli_dizisi[savasci2x][savasci2y]->yokEt(canli_dizisi[savasci2x][savasci2y]);
                canli_dizisi[savasci2x][savasci2y]= NULL;
            }
        }
        else
        {
            if(canli_dizisi[savasci2x][savasci2y]->sembol == 'P')
            {
                if(canli_dizisi[savasci1x][savasci1y]->deger >= canli_dizisi[savasci2x][savasci2y]->deger)
                {
                    canli_dizisi[savasci2x][savasci2y]->yokEt(canli_dizisi[savasci2x][savasci2y]);
                    canli_dizisi[savasci2x][savasci2y]= NULL;
                }
                else
                {
                    canli_dizisi[savasci1x][savasci1y]->yokEt(canli_dizisi[savasci1x][savasci1y]);
                    canli_dizisi[savasci1x][savasci1y]= NULL;
                }
            }
            else
            {
                canli_dizisi[savasci1x][savasci1y]->yokEt(canli_dizisi[savasci1x][savasci1y]);
                canli_dizisi[savasci1x][savasci1y]= NULL;
            }        
		}
    }

    else 
    {
        printf("Kazanan: %c : (%d,%d)\n", canli_dizisi[savasci1x][savasci1y]->sembol, savasci1x,savasci1y);
    }
}

struct HABITAT* habitatOlustur(int satir, int sutun)
{
    struct HABITAT* this;
    this = (struct HABITAT*)malloc(sizeof(struct HABITAT));
    this->satir_sayisi = satir;
    this->sutun_sayisi = sutun;

    this->goster = &print;
    this->guncelle = &update;
    this->yokEt = &habitatYokEt;
}

void habitatYokEt(struct HABITAT* this)
{
    if(this == NULL) return;
    free(this);
}