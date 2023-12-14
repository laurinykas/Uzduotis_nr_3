//
// Created by Laurynas on 10/13/2023.
//

#ifndef UZDUOTIS_NR_1_FUNKCIJOS_H
#define UZDUOTIS_NR_1_FUNKCIJOS_H


#include "Studentai.h"


int Studentu_kiekis();
int Nd_kiekis();
void studentu_generavimas(int st_k, int  namu_d);
void Studentu_skaldymas();
void Kategorija(int studentu_k,int med_ar_vid, int konteineris);
int Konsole_ar_failas ();
int Isvesties_pasirinkimas ();
void Koks_failo_pav (int konteineris);
void Fake_main();
int Vid_ar_med();
void Sortingas ( int sortingo_tipas);
int Rusiavimo_tipas();


extern vector <Studentai> stud;
extern vector<Studentai> kieti;
extern vector<Studentai> vargsai;
extern Studentai duomenys;
extern int studentu_kiekis ;


#endif //UZDUOTIS_NR_1_FUNKCIJOS_H
