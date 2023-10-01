//
// Created by Laurynas on 10/1/2023.
//

#pragma once
#ifndef UZDUOTIS_NR_1_FUNKCIJOS_H
#define UZDUOTIS_NR_1_FUNKCIJOS_H

#endif //UZDUOTIS_NR_1_FUNKCIJOS_H
#include "bibliotekos.h"
#include "strukturos.h"

void isvestis ();
int Studentu_kiekis();
void ivedimas (int i);
int s_kiekis ;
void readfromFile(vector<Duomenys> &sar);
vector <Duomenys> stud;
Duomenys duomenys;

int Studentu_kiekis() {

    int studentu_sk = 0;
    cout << "Iveskite studentu kieki: " << endl;cin >> studentu_sk;
    do {

        if (studentu_sk && studentu_sk > 0) {
            return studentu_sk;}
        else {
            cout << "Neteisingai ivestas studentu skaicius, bandykite dar karta\n"
                    "Iveskite studentu kieki: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> studentu_sk;}

    }
    while (!(studentu_sk && studentu_sk > 0));}



void ivedimas ( int i) {
    stud.push_back(Duomenys());
    char bent_vienas_nd_ranka;
    cout << "Iveskite studento varda : " << endl;cin >> stud[i].vardas;
    cout << "Iveskite studento pavarde : " << endl;cin >> stud[i].pavarde;


    do {
        cout << "Ar bus bent 1 namu darbas?(T/N)" << endl;cin >> bent_vienas_nd_ranka;
        if (bent_vienas_nd_ranka && (bent_vienas_nd_ranka == 'T' || bent_vienas_nd_ranka == 't' || bent_vienas_nd_ranka == 'N' ||bent_vienas_nd_ranka == 'n')) {
            if (bent_vienas_nd_ranka == 'N' || bent_vienas_nd_ranka == 'n') {
                continue;
            } else {
                char ranka_auto;

                cout << "Kaip ivesite pazymius (jeigu ranka rasykite R, jei auto rasykite A :" << endl;
                cin >> ranka_auto;
                do {
                    if (ranka_auto and
                        (ranka_auto == 'R' or ranka_auto == 'r' or ranka_auto == 'A' or ranka_auto == 'a')) {
                        continue;
                    } else {
                        cout << "Irasykite R arba A !" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cin >> ranka_auto;
                    }
                } while (!(ranka_auto and
                           (ranka_auto == 'R' or ranka_auto == 'r' or ranka_auto == 'A' or ranka_auto == 'a')));
                char tp;
                int uzsibaigimas = 0;
                if (ranka_auto == 'R' or ranka_auto == 'r') {


                    while (uzsibaigimas == 0) {
                        int namu_d = 0;
                        int namu_d_eile = stud[i].nd.size();
                        do {
                            cout << "Iveskite nr. " << namu_d_eile + 1 << " pazymi: " << endl;
                            cin >> namu_d;
                            //if(namu_d != 0){
                            if (namu_d > 0 and namu_d <= 10) {
                                stud[i].nd.push_back(namu_d);
                                cout << "Ar bus dar pazymiu ? (T/N)" << endl;
                                cin >> tp;
                                do {
                                    if (tp and (tp == 'T' or tp == 't' or tp == 'n' or tp == 'N')) {
                                        if (tp == 'T' or tp == 't') {
                                            continue;
                                        }
                                        if (tp == 'n' or tp == 'N') {
                                            uzsibaigimas = 1;
                                        }
                                    } else {
                                        cout << "Iveskite tinkama atsakyma T arba N !" << endl;
                                        cin.clear();
                                        cin.ignore(10000, '\n');
                                    }
                                } while (tp != 'T' and tp != 't' and tp != 'n' and tp != 'N');
                            } else {
                                cout << "Iveskite tinkama skaicius nuo 1 iki 10!" << endl;
                                cin.clear();
                                cin.ignore(10000, '\n');
                            }


                        } while (namu_d == 0);
                    }
                }

                else{
                    int nd_skaicius = 0;
                    int sk = 0;
                    // random gen

                    do {
                        cout << "Iveskite kiek namu darbu noresite sugeneruoti" << endl;
                        cin >> nd_skaicius;
                        srand((unsigned) time(0));
                        if (nd_skaicius and nd_skaicius > 0) {
                            for (int e = 0; e < nd_skaicius; e++) {
                                sk = (rand() % 10) + 1;
                                stud[i].nd.push_back(sk);

                            }

                        } else {
                            cout << "Iveskite skaiciu didesni nei 1! : " << endl;
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    } while (nd_skaicius < 0 or nd_skaicius == 0);
                }

            }

        }

        else{
            cout << "Iveskite T arba N !" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }while(bent_vienas_nd_ranka && (bent_vienas_nd_ranka != 'T' and bent_vienas_nd_ranka != 'N' and bent_vienas_nd_ranka != 'n' and bent_vienas_nd_ranka != 't'));
    char bent_vienas_egz;

    do{
        cout<<" Ar turi studentas egzamino rezultata (T/N)?"<<endl; cin>>bent_vienas_egz;
        if (bent_vienas_egz == 'T'|| bent_vienas_egz == 't'|| bent_vienas_egz == 'N' || bent_vienas_egz == 'n'){
            if (bent_vienas_egz == 'T'|| bent_vienas_egz == 't'){

                char egz_ivedimas; int egz = 0 ;
                cout << "Ar norite ranka ivesti egzamina ar auto (R/A)"<<endl; cin>> egz_ivedimas;
                do{
                    if(egz_ivedimas and( egz_ivedimas == 'R'|| egz_ivedimas == 'r'|| egz_ivedimas == 'A' || egz_ivedimas == 'a')){
                        if (egz_ivedimas=='R' or egz_ivedimas == 'r' )
                        {

                            do{
                                cout << "Iveskite egzamino rezultata:"<< endl ; cin>> egz;
                                if(egz and egz > 0 and egz <=10){
                                    stud[i].egzaminas = egz;

                                }
                                else{
                                    cout<< "Iveskite nenulini skaiciu, nuo 1 iki 10!"<<endl ;cin.clear();
                                    cin.ignore(10000, '\n'); }}
                            while(!egz or egz > 10 or egz <0 );

                        }
                        else{
                            srand((unsigned )time(0));
                            egz = (rand() % 10) + 1;
                            stud[i].egzaminas = egz;
                        }
                    }
                    else{
                        cout<<"Iveskite tinkama pasirinkima (R/A)!"<<endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cin >> egz;

                    }


                }while(egz_ivedimas != 'A' && egz_ivedimas != 'a' && egz_ivedimas != 'R' && egz_ivedimas != 'r');
            }
            else {
                stud[i].egzaminas = 0;
            }
        }
        else{
            cout<< "Iveskite T arba N! "<<endl; cin.clear();cin.ignore(10000,'\n');
        }
    }
    while(bent_vienas_egz != 'T' and bent_vienas_egz != 't' and bent_vienas_egz != 'N' and  bent_vienas_egz != 'n');

    stud[i].Vidurkis();
    stud[i].Mediana();


}
void isvestis ( ) {



    int pasirinkimas;
    cout << "Ar norite vidurkio - 1 , medianos - 2 ar abieju - 3 ? :" << endl; cin >> pasirinkimas;
    do {
        if (pasirinkimas && (pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3)) {



            if (pasirinkimas == 1) {
                cout<< setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(17)<<"Galutinis(vid)"<<endl;
                for (int i = 0; s_kiekis > i; i++) {
                    cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                         << std::setprecision(2) << stud[i].vid << setw(17);}

            } else if (pasirinkimas == 2) {
                cout<< setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<< setw(20)<<"Galutinis(med)"<<endl;
                for (int i = 0; s_kiekis > i; i++) {
                    cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                         << std::setprecision(2) << stud[i].med << endl;
                }
            } else {
                cout<< setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(17)<<"Galutinis(vid)"<< setw(20)<<"Galutinis(med)"<<endl;
                for (int i = 0; s_kiekis > i; i++) {
                    cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                         << std::setprecision(2) << stud[i].vid << setw(17) << stud[i].med << endl;
                }
            }

        }
        else {
            cout << "Iveskite nenulini skaiciu, nuo 1 iki 3!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pasirinkimas;
        }
    }while (pasirinkimas != 1 and pasirinkimas != 2 and pasirinkimas != 3);


}

void readfromFile(vector<Duomenys> &stud){
    string filename="kursiokai.txt";
    try{
        ifstream fileread(filename);cout << "1" << endl;
        if(!fileread.fail()){
            int sk;cout<<"2"<<endl;
            string line;
            string temp,pirmaEil;cout<<"3"<<endl;
            int kiekNd = -3;
            getline(fileread >> std::ws, pirmaEil);
            std::stringstream iss(pirmaEil); cout<<"4"<<endl;
            while(iss >> temp)
            {
                kiekNd++; cout<<"lol"<<endl;
            }cout<<"5"<<endl;
            while(std::getline(fileread >> std::ws, line)){
                Duomenys s ;
                std::stringstream iss(line);
                iss>> s.vardas; cout<<"6"<<endl;
                iss >> s.pavarde;
                for(int i = 0; i < kiekNd; i++){
                    iss>> sk;
                    s.nd.push_back(sk);cout<<"7"<<endl;
                }
                iss >> sk;
                s.egzaminas=sk;cout<<"8"<<endl;
                s.Vidurkis();
                s.Mediana();
                stud.push_back(duomenys);
            }

        }
        else{
            throw std::runtime_error(filename);
        }

    }
    catch(std::exception &e){
        cout << "Ivyko problema nuskaitant faila: " << e.what() << "\n";
        std::exit(0);
    }
}
