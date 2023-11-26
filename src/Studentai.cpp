#include "../Include/funkcijos.h"

void Studentai::Galutinis (int input ){
    if(input == 1){
        setGalutinis(getVid()) ;
    }
    else {
        setGalutinis(getMed());
    }

}

void Studentai::Vidurkis() {

    double sum_vid = 0;
    if (getNdSize() == 0) {
        setVid(  0.6 * getEgzaminas() ) ;
    } else {
        for (int i = 0; i < getNdSize(); i++) sum_vid += getNd(i);
        setVid(((sum_vid / getNdSize()) * 0.4) + (0.6 * getEgzaminas()));
    }
}
void Studentai::Mediana() {
    int n = getNdSize();
    if (n >= 1) {
        sortNd();
        if (n % 2 == 0) {
            setMed(Cnd[n / 2 - 1] + Cnd[n / 2] / 2) ;
        } else {
            setMed(Cnd[n / 2]) ;
        }
    } else {
        setMed(0)  ;
    }
    setMed(0.4 * getMed() + 0.6 * getEgzaminas())  ;
}