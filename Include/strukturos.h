//
// Created by Laurynas on 10/1/2023.
//
#ifndef STRUKTUROS_H_INCLUDED
#define STRUKTUROS_H_INCLUDED


#include "bibliotekos.h"

struct Duomenys {
    string vardas = "";
    string pavarde = "";
    vector<double> nd; //namu darbai
    int egzaminas = 0;
    float vid = 0;
    float med = 0;
    int studentu_kiekis = 0;
    float galutinis = 0;

    void Galutinis (int input ){
        if(input == 1){
            galutinis = vid ;
        }
        else {
            galutinis = med;
        }

    }

    void Vidurkis() {

        double sum_vid = 0;
        if (nd.size() == 0) {
            vid = 0.6 * egzaminas;
        } else {
            for (int i = 0; i < nd.size(); i++) sum_vid += nd[i];
            vid = ((sum_vid / nd.size()) * 0.4) + (0.6 * egzaminas);
        }
    }

    void Mediana() {
        if (nd.size() >= 1) {
            sort(nd.begin(), nd.end());
            if (nd.size() % 2 == 0) {
                med = nd[nd.size() / 2 - 1] + nd[nd.size() / 2] / 2;
            } else {
                med = nd[(nd.size() / 2)];
            }
        } else {
            med = 0;
        }
        med = 0.4 * med + 0.6 * egzaminas;
    }



    }
;
#endif