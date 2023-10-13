//
// Created by Laurynas on 10/13/2023.
//

#ifndef UZDUOTIS_NR_1_FUNKCIJOS_H
#define UZDUOTIS_NR_1_FUNKCIJOS_H


#include "strukturos.h"

void isvestis (int isvesties_tipas);
int Studentu_kiekis();
int Nd_kiekis();
void ivedimas (int studentu_kiekis);
void studentu_generavimas(int st_k, int  namu_d);
void Studentu_skaldymas ();
void readfromFile( string filename, vector<Duomenys> &stud);
bool palyginimas(Duomenys a, Duomenys b);
void Kategorija(int studentu_k);
void Failu_kurimas (vector<Duomenys> vektorius, string failo_vardas);

extern vector <Duomenys> stud;
extern vector<Duomenys> kieti;
extern vector<Duomenys> vargsai;
extern Duomenys duomenys;
extern int studentu_kiekis ;
extern int info;
extern string failo_pav ;
extern std::chrono::duration<double> laikas_kat;
extern std::chrono::duration<double> laikas_failo;
#endif //UZDUOTIS_NR_1_FUNKCIJOS_H
