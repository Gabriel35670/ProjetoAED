#include "fCompl.h"


void sort(int v[],int n){
 
    int minimo,j=0,i;
    int pos_minimo;
    while(j < n){
        minimo = v[j];
        pos_minimo = j;
        i = j+1;
        while(i<n){
            if(minimo > v[i]){
                minimo = v[i];
                pos_minimo = i;
            }
            i++;
        }
        v[pos_minimo] = v[j];
        v[j] = minimo;
        j++;

    }
}

bool bBinaria(int v[],int n, int alvo,int i){

    int e,m,d;
    e = -1;
    d = n;
    while(e < d-1){
        m = (e+d)/2;
        if(v[m] == alvo && m != i)
            return true;

        if(v[m] < alvo)
            e = m;
        else
            d = m;
    }


    return false;
}