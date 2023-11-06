//
// Created by Laurynas on 10/13/2023.
//

#ifndef UZDUOTIS_NR_1_FUNKCIJOS_H
#define UZDUOTIS_NR_1_FUNKCIJOS_H


#include "strukturos.h"
void isvestis (vector<Duomenys> vektorius, int pasirinkimas);
void isvestis_list (list<Duomenys> listas, int pasirinkimas);
int Studentu_kiekis();
int Nd_kiekis();
void ivedimas (int studentu_kiekis);
void ivedimas_list ( int studentu_kiekis);
void studentu_generavimas(int st_k, int  namu_d);
void Studentu_skaldymas ();
void Studentu_skaldymas_list();//list variantas
void readfromFile( string filename, vector<Duomenys> &stud);
void readfromFileList( string filename, list<Duomenys> &stud_list); //listu variantas
bool palyginimas_vardas(Duomenys a, Duomenys b);
bool palyginimas_pavarde( Duomenys a, Duomenys b);
bool palyginimas_galutinis( Duomenys a, Duomenys b);
void Kategorija(int studentu_k,int med_ar_vid);
void Kategorija_list(int med_ar_vid);// listu variantas
void Failu_kurimas (vector<Duomenys> vektorius, string failo_vardas, int pasirinkimas);
void Failu_kurimas_list (list<Duomenys> listas, string failo_vardas, int pasirinkimas);
int Konsole_ar_failas ();
int Isvesties_pasirinkimas ();
void Koks_failo_pav ();
void Koks_failo_pav_list ();
void Fake_main();
int Vid_ar_med();
int List_Vektor();
void Sortingas (int vek_ar_list, int sortingo_tipas);
int Rusiavimo_tipas();

extern vector <Duomenys> stud;
extern vector<Duomenys> kieti;
extern vector<Duomenys> vargsai;
extern Duomenys duomenys;
extern list<Duomenys> stud_list;
extern list<Duomenys> kieti_list;
extern list<Duomenys> vargsai_list;
extern int studentu_kiekis ;
extern string failo_pav ;
extern std::chrono::duration<double> laikas_kat;
extern std::chrono::duration<double> laikas_failo;

#endif //UZDUOTIS_NR_1_FUNKCIJOS_H
