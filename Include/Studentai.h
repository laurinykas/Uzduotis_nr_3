//
// Created by Laurynas on 10/1/2023.
//
#ifndef STRUKTUROS_H_INCLUDED
#define STRUKTUROS_H_INCLUDED

#include "bibliotekos.h"
#include "funkcijos.h"

 class Zmogus
{
protected:
    string Cvardas_;
    string Cpavarde_;
public:
    virtual void setVardas(string vardas) = 0;
    virtual void setPavarde(string pavarde) = 0;
    inline string getVardas() const { return Cvardas_; }
    inline string getPavarde() const { return Cpavarde_; }

    Zmogus()
    {
        Cvardas_ = "";
        Cpavarde_ = "";
    }
};








class Studentai: public Zmogus {



private:
    string Cvardas ;
    string Cpavarde ;
    vector<int> Cnd; //namu darbai
    int Cegzaminas;
    float Cvid ;
    float Cmed ;
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
    // move

    Studentai(const Studentai& s):Cvardas(s.Cvardas),Cpavarde(s.Cpavarde),Cnd(s.Cnd),Cegzaminas(s.Cegzaminas),Cvid(s.Cvid),Cmed(s.Cmed),Cgalutinis(s.Cgalutinis){}


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
    ~Studentai(){ }// destructor

        inline string getVardas() const
        { return Cvardas; }
        void setVardas(string vardas) { Cvardas = std::move(vardas); }
        inline string getPavarde() const { return Cpavarde; }
        void setPavarde(string pavarde) { Cpavarde= std::move(pavarde); }

        double getNd(int i) const { return Cnd.at(i); }
        void addNd(int nd){
            Cnd.reserve(Cnd.size() + 1);
            Cnd.push_back(nd); }
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

    void Galutinis (int input );
    void Vidurkis();
    void Mediana();

    void isvestis (vector<Studentai> vektorius);
    void readfromFile( string filename, vector<Studentai> &stud);
    static void ivedimas(int studentu_kiekis);
   void Failu_kurimas (vector<Studentai> vektorius ,string failo_vardas, int pasirinkimas);
   friend std::istream& operator>>(std::istream& in,Studentai& s );
   friend std::ostream& operator<<(std::ostream& out,const Studentai& student);



};





bool palyginimas_vardas( Studentai a, Studentai b);
bool palyginimas_pavarde( Studentai a, Studentai b);
bool palyginimas_galutinis( Studentai a, Studentai b);

#endif