//
// Created by Laurynas on 10/1/2023.
//
#ifndef STRUKTUROS_H_INCLUDED
#define STRUKTUROS_H_INCLUDED


#include "bibliotekos.h"

class Studentai {



private:
    string Cvardas = "";
    string Cpavarde = "";
    vector<int> Cnd; //namu darbai
    int Cegzaminas = 0;
    float Cvid = 0;
    float Cmed = 0;
    //int studentu_kiekis = 0;
    float Cgalutinis = 0;


public:


        inline string getVardas() const
        { return Cvardas; }
        void setVardas(string vardas) { Cvardas = vardas; }    // get'eriai, inline
        inline string getPavarde() const { return Cpavarde; }// get'eriai, inline
        void setPavarde(string pavarde) { Cpavarde= pavarde; }

        double getNd(int i) const { return Cnd.at(i); }
        void setNd(int nd,int index) { Cnd[index]=nd; }
        void addNd(int nd){
            Cnd.reserve(Cnd.size() + 1);
            Cnd.push_back(nd); }
        void clearNd() { Cnd.clear(); }
        inline int getNdSize() { return Cnd.size(); }
        void sortNd() { sort(Cnd.begin(), Cnd.end()); }

        inline int getEgzaminas() const { return Cegzaminas; }
        void setEgzaminas(int egzaminas) { Cegzaminas = egzaminas; }

        inline float getVid() const { return Cvid; }
    void setVid(float vid) { Cvid = vid; }

        inline float getMed() const { return Cmed; }
    void setMed(float med ) { Cmed = med; }

        inline double getGalutinis() const { return Cgalutinis; }
    void setGalutinis(double galutinis) { Cgalutinis = galutinis; }

    void Galutinis (int input );
    void Vidurkis();
    void Mediana();
    void ivedimas ( int studentu_kiekis);
    void isvestis (vector<Studentai> vektorius, int pasirinkimas);
    void readfromFile( string filename, vector<Studentai> &stud);
    bool palyginimas_vardas( Studentai a, Studentai b);
    bool palyginimas_pavarde( Studentai a, Studentai b);
    bool palyginimas_galutinis( Studentai a, Studentai b);
    void Failu_kurimas (vector<Studentai> vektorius, string failo_vardas, int pasirinkimas);
    void Studentu_skaldymas();
    void Skaldymas2_Vector();




}
;
#endif