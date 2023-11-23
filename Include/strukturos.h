//
// Created by Laurynas on 10/1/2023.
//
#ifndef STRUKTUROS_H_INCLUDED
#define STRUKTUROS_H_INCLUDED


#include "bibliotekos.h"

class Duomenys {
public:
    Duomenys() : vardas(""), pavarde(""), egzaminas(0), vid(0), med(0), studentu_kiekis(0), galutinis(0) {}

    void setVardas(const std::string& v) {
        vardas = v;
    }

    void setPavarde(const std::string& p) {
        pavarde = p;
    }

    void setNamai(const std::vector<double>& nd_values) {
        nd = nd_values;
    }

    void setEgzaminas(int e) {
        egzaminas = e;
    }

    void setStudentuKiekis(int k) {
        studentu_kiekis = k;
    }

    void calculateGalutinis(int input) {
        if (input == 1) {
            galutinis = vid;
        } else {
            galutinis = med;
        }
    }

    void calculateVidurkis() {
        double sum_vid = 0;
        if (nd.empty()) {
            vid = 0.6 * egzaminas;
        } else {
            for (const auto& value : nd) {
                sum_vid += value;
            }
            vid = ((sum_vid / nd.size()) * 0.4) + (0.6 * egzaminas);
        }
    }

    void calculateMediana() {
        if (!nd.empty()) {
            sort(nd.begin(), nd.end());
            if (nd.size() % 2 == 0) {
                med = (nd[nd.size() / 2 - 1] + nd[nd.size() / 2]) / 2;
            } else {
                med = nd[nd.size() / 2];
            }
        } else {
            med = 0;
        }
        med = 0.4 * med + 0.6 * egzaminas;
    }

private:
    std::string vardas;
    std::string pavarde;
    std::vector<double> nd; // namu darbai
    int egzaminas;
    float vid;
    float med;
    int studentu_kiekis;
    float galutinis;
};
#endif