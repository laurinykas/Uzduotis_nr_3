//
// Created by Laurynas on 10/13/2023.
//

#include "funkcijos.h"

int Studentu_kiekis() {

    int studentu_sk ;
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
    while (!(studentu_sk || studentu_sk < 0));
}
int Nd_kiekis() {

    int nd_sk ;
    cout << "Iveskite namu darbu  kieki: " << endl;cin >> nd_sk;
    do {

        if (nd_sk && nd_sk > 0) {
            return nd_sk;}
        else {
            cout << "Neteisingai ivestas namu darbu skaicius, bandykite dar karta\n"
                    "Iveskite namu darbu kieki: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> nd_sk;}

    }
    while (!(nd_sk || nd_sk < 0));
}


void ivedimas ( int studentu_kiekis) {
    stud.push_back(Duomenys());
    char bent_vienas_nd_ranka;
    cout << "Iveskite studento varda : " << endl;cin >> stud[studentu_kiekis].vardas;
    cout << "Iveskite studento pavarde : " << endl;cin >> stud[studentu_kiekis].pavarde;


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
                        int namu_d_eile = stud[studentu_kiekis].nd.size();
                        do {
                            cout << "Iveskite nr. " << namu_d_eile + 1 << " pazymi: " << endl;
                            cin >> namu_d;
                            //if(namu_d != 0){
                            if (namu_d > 0 and namu_d <= 10) {
                                stud[studentu_kiekis].nd.push_back(namu_d);
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
                                stud[studentu_kiekis].nd.push_back(sk);

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
                                    stud[studentu_kiekis].egzaminas = egz;

                                }
                                else{
                                    cout<< "Iveskite nenulini skaiciu, nuo 1 iki 10!"<<endl ;cin.clear();
                                    cin.ignore(10000, '\n'); }}
                            while(!egz or egz > 10 or egz <0 );

                        }
                        else{
                            srand((unsigned )time(0));
                            egz = (rand() % 10) + 1;
                            stud[studentu_kiekis].egzaminas = egz;
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
                stud[studentu_kiekis].egzaminas = 0;
            }
        }
        else{
            cout<< "Iveskite T arba N! "<<endl; cin.clear();cin.ignore(10000,'\n');
        }
    }
    while(bent_vienas_egz != 'T' and bent_vienas_egz != 't' and bent_vienas_egz != 'N' and  bent_vienas_egz != 'n');

    stud[studentu_kiekis].Vidurkis();
    stud[studentu_kiekis].Mediana();


}
void isvestis (int isvesties_tipas ) {


    int pasirinkimas;
    cout << "Ar norite vidurkio - 1 , medianos - 2 ar abieju - 3 ? :" << endl;
    cin >> pasirinkimas;
    do {
        if (pasirinkimas && (pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3)) {

            if (pasirinkimas == 1) {
                cout << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)" << endl;
                cout << "____________________________________________________________________" << endl;
                if (isvesties_tipas == 1) {
                    for (int i = 0; studentu_kiekis > i; i++) {
                        cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                             << std::setprecision(2) << stud[i].vid << setw(17) << endl;
                    }

                } else {
                    for (int i = 1; studentu_kiekis >= i; i++) {
                        cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                             << std::setprecision(2) << stud[i].vid << setw(17) << endl;
                    }

                }
            } else if (pasirinkimas == 2) {
                cout << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(med)" << endl;
                cout << "_____________________________________________________________________" << endl;
                if (isvesties_tipas == 1) {
                    for (int i = 0; studentu_kiekis > i; i++) {
                        cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                             << std::setprecision(2) << stud[i].med << endl;
                    }
                } else {
                    for (int i = 1; studentu_kiekis >= i; i++) {
                        cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                             << std::setprecision(2) << stud[i].med << endl;
                    }
                }
            } else {
                cout << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)" << setw(20)
                     << "Galutinis(med)" << endl;
                cout << "___________________________________________________________________________________________" << endl;
                if (isvesties_tipas == 1) {
                    for (int i = 0; studentu_kiekis > i; i++) {
                        cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                             << std::setprecision(2) << stud[i].vid << setw(17) << stud[i].med << endl;
                    }
                } else {
                    for (int i = 1; studentu_kiekis >= i; i++) {
                        cout << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(17) << std::fixed
                             << std::setprecision(2) << stud[i].vid << setw(17) << stud[i].med << endl;
                    }
                }
            }

        }else {
            cout << "Iveskite nenulini skaiciu, nuo 1 iki 3!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pasirinkimas;
        }

    }while (pasirinkimas != 1 and pasirinkimas != 2 and pasirinkimas != 3);



}
void readfromFile( string filename, vector<Duomenys> &stud){

    try{
        ifstream fileread(filename);
        if(!fileread.fail()){
            int sk;
            string line;
            string temp,pirmaEil;
            int kiekNd = -3;
            getline(fileread >> std::ws, pirmaEil);
            stringstream iss(pirmaEil);
            while(iss >> temp)
            {
                kiekNd++;
            }
            while((std::getline(fileread >> std::ws, line))){
                Duomenys s ;
                stringstream iss(line);
                iss>> s.vardas;
                iss >> s.pavarde;
                for(int i = 0; i < kiekNd; i++){
                    iss>> sk;
                    s.nd.push_back(sk);
                }
                iss >> sk;
                s.egzaminas=sk;
                s.Vidurkis();
                s.Mediana();
                studentu_kiekis++;
                stud.push_back(s);
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
bool palyginimas( Duomenys a, Duomenys b){
    if (a.vardas == b.vardas){

        return a.pavarde < b.pavarde;}

    return a.vardas < b.vardas;
}


void studentu_generavimas(int studentu_kiekis, int  namu_d){
    string failo_vardas = "student" + to_string(studentu_kiekis) + ".txt";
    stringstream eilute;
    ofstream out (failo_vardas);
    eilute << "Vardas" << setw(15) << "Pavarde";
    for (int i=0;i < namu_d; i++){
        eilute << setw(15) << "ND" << i+1;


    }
    eilute << setw(15) << "Egz" <<endl;
    srand((unsigned )time(0));
    for(int i=0; i < studentu_kiekis; i++){
        eilute << "Vardas" << i+1 << setw(15) << "Pavarde" << i+1;
        for(int j=0; j<namu_d; j++){
            eilute << setw(15) << (rand() % 10) + 1;

        }
        eilute << setw(15) << (rand() % 10) + 1 <<endl;

    }
    out <<eilute.str();
    eilute.clear();
    out.close();
    failo_pav = failo_vardas;
    cout << "baigtas failo generavimas"<<endl;

}



void Kategorija(int studentu_k){
    std::chrono::duration<double> laikas;
    int med_ar_vid;
    cout<< "Ar galutiniam balui naudosite vidurki ar mediana(1 - vidurkis, 2 - mediana)?"<<endl; cin>>med_ar_vid;
    do{
        if(med_ar_vid && (med_ar_vid == 1 || med_ar_vid == 2)){
            auto start = hrClock ::now();
            for(int i=0; i <= studentu_k; i++){
                stud[i].Galutinis (med_ar_vid );

            }
            auto end =hrClock :: now();
            laikas = end - start;
            laikas_kat = laikas;

        }
        else{
            cout<< "Kladinga ivestis, bandykite dar karta (Iveskite 1 arba 2 )"<<endl;
            cin.clear();
            cin.ignore(10000 , '\n');
            cin >> med_ar_vid;
        }


    }
    while(med_ar_vid != 1 && med_ar_vid != 2);
}
void Studentu_skaldymas() {
    vector<Duomenys> temporaryStorage; // Create a temporary vector
    stud.erase(stud.begin());
    for (auto el : stud) {
        if (el.galutinis >= 5.00){

            kieti.push_back(el);
        } else {
            vargsai.push_back(el);

        }

        // Store the student in the temporary vector
        temporaryStorage.push_back(el);
    }

    // Restore the students in the stud vector
    stud = temporaryStorage;
}




void Failu_kurimas (vector<Duomenys> vektorius, string failo_vardas) {

    std::chrono::duration<double> laikas;
    ofstream out(failo_vardas);
    stringstream eilute;
    int pasirinkimas;
    cout << "Ar norite vidurkio - 1 , medianos - 2 ar abieju - 3 ? :" << endl;
    cin >> pasirinkimas;
    do {
        if (pasirinkimas ) {
            auto start = hrClock ::now();
            if (pasirinkimas == 1) {
                eilute << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)" << endl;
                eilute << left << "______________________________________________________________________________" << endl;
                for (int i = 0; i < vektorius.size(); i++) {
                    eilute << left << setw(20) << vektorius[i].vardas << setw(20) << vektorius[i].pavarde << setw(17)
                           << std::fixed
                           << std::setprecision(2) << vektorius[i].vid << setw(17) << endl;


                }


            } else if (pasirinkimas == 2) {
                eilute << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(med)" << endl;
                eilute << left << "________________________________________________________________________________" << endl;
                for (int i = 0; i < vektorius.size(); i++) {
                    eilute << left << setw(20) << vektorius[i].vardas << setw(20) << vektorius[i].pavarde << setw(17)
                           << std::fixed
                           << std::setprecision(2) << vektorius[i].med << setw(17) << endl;


                }


            } else {
                eilute << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)"
                       << setw(20) << "Galutinis(med)" << endl;
                eilute << left << "________________________________________________________________________" << endl;
                for (int i = 0; i < vektorius.size(); i++) {
                    eilute << left << setw(20) << vektorius[i].vardas << setw(20) << vektorius[i].pavarde << setw(17)
                           << std::fixed
                           << std::setprecision(2) << vektorius[i].vid << setw(17) << vektorius[i].med << endl;

                }

            }

            auto end = hrClock ::now();
            laikas = end - start + laikas_failo;
            laikas_failo = laikas;

        } else {
            cout << "Iveskite nenulini skaiciu, nuo 1 iki 3!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pasirinkimas;
        }
        out << eilute.str();
        eilute.clear();
        out.close();




    } while (pasirinkimas != 1 and pasirinkimas != 2 and pasirinkimas != 3);


}



