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
        void setVardas(string vardas) { vardas = Cvardas; }    // get'eriai, inline
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

        inline int getEgz() const { return Cegzaminas; }
        void setEgz(int egz) { Cegzaminas = egz; }

        inline float getVid() const { return Cvid; }
    void setRez(float vid) { Cvid = vid; }

        inline float getMed() const { return Cmed; }
    void setCmed(float med ) { Cvid = med; }

        inline double getGalutinis() const { return Cgalutinis; }
    void setMedVid(double galutnis) { Cgalutinis = galutnis; }


}





    void Galutinis (int input ){
        if(input == 1){
            setGalutinis(getVid()) ;
        }
        else {
            setGalutinis(getMed());
        }

    }

    void Vidurkis() {

        double sum_vid = 0;
        if (getNd().size() == 0) {
            setVid(0.6 * getEgzaminas())  ;
        } else {
            for (int i = 0; i < getNd().size(); i++) sum_vid += getNd()[i];
            setVid(((sum_vid / getNd().size()) * 0.4) + (0.6 * getEgzaminas()));
        }
    }

    void Mediana() {
        if (getNd().size() >= 1) {
            sort(getNd().begin(), getNd().end());
            if (getNd().size() % 2 == 0) {
                setMed(getNd()[getNd().size() / 2 - 1] + getNd()[getNd().size() / 2] / 2)  ;
            } else {
                setMed(getNd()[(getNd().size() / 2)]) ;
            }
        } else {
            setMed(0)  ;
        }
        setMed(0.4 * getMed() + 0.6 * getEgzaminas())  ;
    }



    }
;
#endif