//
// Created by Laurynas on 10/1/2023.
//
#ifndef STRUKTUROS_H_INCLUDED
#define STRUKTUROS_H_INCLUDED

#include "bibliotekos.h"
#include "funkcijos.h"
class Studentai {



private:
    string Cvardas ;
    string Cpavarde ;
    vector<int> Cnd; //namu darbai
    int Cegzaminas;
    float Cvid ;
    float Cmed ;
    //int studentu_kiekis = 0;
    float Cgalutinis;


public:
    Studentai(){
        Cvardas = "";
        Cpavarde = "";
        Cegzaminas = 0;
        Cvid = 0;
        Cmed = 0;
        Cgalutinis = 0;
        Cnd.clear();

    }

    Studentai(const Studentai& s) {
        Cvardas = s.Cvardas;
        Cpavarde = s.Cpavarde;
        copy(s.Cnd.begin(), s.Cnd.end(), back_inserter(Cnd));
        Cegzaminas = s.Cegzaminas;
        Cvid = s.Cvid;
        Cmed = s.Cmed;
        Cgalutinis = s.Cgalutinis;
    }
    // Copy assignment operator

    Studentai& operator=(const Studentai& s) {
        if (this != &s) {
            Cvardas = s.Cvardas;
            Cpavarde = s.Cpavarde;
            copy(s.Cnd.begin(), s.Cnd.end(), back_inserter(Cnd));
            Cegzaminas = s.Cegzaminas;
            Cvid = s.Cvid;
            Cmed = s.Cmed;
            Cgalutinis = s.Cgalutinis;
        }
        return *this;
    }
    ~Studentai(){ clearNd(); }// destructor

        inline string getVardas() const
        { return Cvardas; }
        void setVardas(string vardas) { Cvardas = std::move(vardas); }
        inline string getPavarde() const { return Cpavarde; }
        void setPavarde(string pavarde) { Cpavarde= std::move(pavarde); }

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
    void setGalutinis(float galutinis) { Cgalutinis = galutinis; }
    void inputData(std::istream& in);
    void Galutinis (int input );
    void Vidurkis();
    void Mediana();
    void ivedimas ();
    void isvestis (vector<Studentai> vektorius, int pasirinkimas);
    void readfromFile( string filename, vector<Studentai> &stud);

   void Failu_kurimas (vector<Studentai> vektorius ,string failo_vardas, int pasirinkimas);
   friend std::ostream& operator<<(std::ostream& out, const Studentai& student);
   friend std::istream& operator>>(std::istream& in,Studentai& s);



};


// Modify the friend function


bool palyginimas_vardas( Studentai a, Studentai b);
bool palyginimas_pavarde( Studentai a, Studentai b);
bool palyginimas_galutinis( Studentai a, Studentai b);

#endif