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
void isvestis (vector<Duomenys> vektorius, int pasirinkimas) {

    stringstream buffer;

            if (pasirinkimas == 1) {
                buffer << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)" << endl;
                buffer << "____________________________________________________________________" << endl;
                for (int i = 0; vektorius.size() > i; i++) {
                    buffer << setw(20) << vektorius[i].vardas << setw(20) << vektorius[i].pavarde << setw(17) << std::fixed
                    << std::setprecision(2) << vektorius[i].vid << setw(17) << endl;
                    }

                }

             else if (pasirinkimas == 2) {
                buffer << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(med)" << endl;
                buffer << "_____________________________________________________________________" << endl;
                for (int i = 0; vektorius.size() > i; i++) {
                    buffer << setw(20) << vektorius[i].vardas << setw(20) << vektorius[i].pavarde << setw(17) << std::fixed
                    << std::setprecision(2) << vektorius[i].med << endl;
                    }

                }
             else {
                buffer << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)" << setw(20)
                     << "Galutinis(med)" << endl;
                buffer << "___________________________________________________________________________________________" << endl;
                for (int i = 0; vektorius.size() > i; i++) {
                    buffer << setw(20) << vektorius[i].vardas << setw(20) << vektorius[i].pavarde << setw(17) << std::fixed
                    << std::setprecision(2) << vektorius[i].vid << setw(17) << vektorius[i].med << endl;
                    }

                    }
            cout<<buffer.str();




}
void readfromFile( string filename, vector<Duomenys> &stud){
    try {
        ifstream fileread(filename);
        if (!fileread.fail()) {

        ifstream fileread(filename);
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
        }else{

            throw std::runtime_error(filename);

        }


    } catch(std::exception &e) {
        cout << "Failas "  << e.what() << "neegzistuoja arba neteisingai irasete pavadinima, paleiskite dar karta programa" << endl;
        std::exit(0);


    }


}

void readfromFileList( string filename, list<Duomenys> &stud_list){
    try {
        ifstream fileread(filename);
        if (!fileread.fail()) {
    ifstream fileread(filename);
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
        stud_list.push_back(s);
    }
        }
            else{
                throw std::runtime_error(filename);

            }


    } catch(std::exception &e) {
            cout << "Failas "  << e.what() << "neegzistuoja arba neteisingai irasete pavadinima, paleiskite dar karta programa" << endl;
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



void Kategorija(int studentu_k, int med_ar_vid){
    std::chrono::duration<double> laikas;



            auto start = hrClock ::now();
            for(int i=0; i <= studentu_k; i++){
                stud[i].Galutinis (med_ar_vid );

            }
            auto end =hrClock :: now();
            laikas = end - start;
            laikas_kat = laikas;


}
void Kategorija_list(int med_ar_vid){
    std::chrono::duration<double> laikas;
            auto start = hrClock ::now();
            for(auto& student : stud_list){
                student.Galutinis (med_ar_vid );

            }
            auto end =hrClock :: now();
            laikas = end - start;
            laikas_kat = laikas;


}
int Vid_ar_med(){
    int med_ar_vid;
    cout<< "Ar galutiniam balui naudosite vidurki ar mediana(1 - vidurkis, 2 - mediana)?"<<endl; cin>> med_ar_vid;
    do{
        if(med_ar_vid && (med_ar_vid == 1 || med_ar_vid == 2)){
            return med_ar_vid;
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
void Studentu_skaldymas_list() {
    vector<Duomenys> temporaryStorage; // Create a temporary vector
    for (auto el : stud_list) {
        if (el.galutinis >= 5.00){

            kieti_list.push_back(el);
        } else {
            vargsai_list.push_back(el);

        }

        // Store the student in the temporary vector
        temporaryStorage.push_back(el);
    }

    // Restore the students in the stud vector
    stud = temporaryStorage;
}




void Failu_kurimas (vector<Duomenys> vektorius, string failo_vardas, int pasirinkimas) {


    ofstream out(failo_vardas);
    stringstream eilute;

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



        out << eilute.str();
        eilute.clear();
        out.close();




    }
void Failu_kurimas_list (list<Duomenys> listas, string failo_vardas, int pasirinkimas) {


    ofstream out(failo_vardas);
    stringstream eilute;

    if (pasirinkimas == 1) {
        eilute << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)" << endl;
        eilute << left << "______________________________________________________________________________" << endl;
        for(auto& student : listas) {
            eilute << left << setw(20) << student.vardas << setw(20) << student.pavarde << setw(17)
                   << std::fixed
                   << std::setprecision(2) << student.vid << setw(17) << endl;


        }


    } else if (pasirinkimas == 2) {
        eilute << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(med)" << endl;
        eilute << left << "________________________________________________________________________________" << endl;
        for(auto& student : listas) {
            eilute << left << setw(20) << student.vardas << setw(20) << student.pavarde << setw(17)
                   << std::fixed
                   << std::setprecision(2) << student.med << setw(17) << endl;


        }


    } else {
        eilute << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)"
               << setw(20) << "Galutinis(med)" << endl;
        eilute << left << "________________________________________________________________________" << endl;
        for(auto& student : listas) {
            eilute << left << setw(20) << student.vardas << setw(20) << student.pavarde << setw(17)
                   << std::fixed
                   << std::setprecision(2) << student.vid << setw(17) << student.med << endl;

        }

    }



    out << eilute.str();
    eilute.clear();
    out.close();




}



int Konsole_ar_failas (){
    char kons_fail;
    int konsol1_failas2;
    cout<< "Ar noresite isvesti i konsole ar i faila ? (K/F)"<< endl; cin>>kons_fail;
    do{
        if (kons_fail){
            if(kons_fail == 'K'|| kons_fail == 'k'){
                konsol1_failas2 = 1;
                return konsol1_failas2;

            }
            else {
                konsol1_failas2 = 2;
                return konsol1_failas2;
            }

        }else{

            cout<< "Iveskite tinkama ivesti K arba F !"<<endl;cin.clear();cin.ignore(1000, '\n');
            cin>> kons_fail;
        }

    }

    while(kons_fail != 'K' && kons_fail != 'k' && kons_fail != 'f' && kons_fail != 'F');


}


int Isvesties_pasirinkimas (){
    int pasirinkimas;
    cout << "Ar norite vidurkio - 1 , medianos - 2 ar abieju - 3 ? :" << endl;
    cin >> pasirinkimas;
    do{
        if(pasirinkimas &&( pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3)){
            if( pasirinkimas == 1){
                return pasirinkimas;
            }
        else if (pasirinkimas == 2){
            return pasirinkimas;
        }
        else{
                return pasirinkimas;
        }


        }
        else{
            cout << "Iveskite nenulini skaiciu, nuo 1 iki 3!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pasirinkimas;


        }
    }while (pasirinkimas != 1 and pasirinkimas != 2 and pasirinkimas != 3);
}
void Koks_failo_pav (){
    system("dir *.txt");
    string failo_pavadinimas;
    std::chrono::duration<double> laikas;
    cout<<"Koki faila noretumete nuskenuoti?"<<endl; cin>> failo_pavadinimas;


        try {
            ifstream fileread(failo_pavadinimas);
            if (!fileread.fail()) {
                auto start  = hrClock::now();
                readfromFile(failo_pavadinimas,stud);
                auto end  = hrClock::now();
                laikas = end- start;
                cout << failo_pavadinimas << " studentu failo nuskaitymas uztruko : " << laikas.count()<< "s" << endl;
            }
            else{
                throw std::runtime_error(failo_pavadinimas);

        }

    }
        catch(std::exception &e) {
            cout << "Failas "  << e.what() << "neegzistuoja arba neteisingai irasete pavadinima, paleiskite dar karta programa" << endl;
            std::exit(0);


        }
    }
void Fake_main(){

    char ranka_failas;
    do {
        cout << "Ar duomenis rasytite ranka , nuskaitysite is failo ar noresite sugeneruoti atsitiktini ar testuoti?(R - ranka, F- is failo, G - generuoti, T - testuoti )?" << endl;
        cin >> ranka_failas;
        if (ranka_failas &&
            (ranka_failas == 'R' || ranka_failas == 'r' || ranka_failas == 'F' || ranka_failas == 'f'|| ranka_failas == 'G'||ranka_failas == 'g' ||ranka_failas == 'T'||ranka_failas == 't')) {
            if (ranka_failas == 'R' || ranka_failas == 'r') {
                studentu_kiekis = Studentu_kiekis();
                for (int eiles_nr = 0; eiles_nr < studentu_kiekis; eiles_nr++) {
                    ivedimas(eiles_nr);

                }
                sort(stud.begin(),stud.end(), palyginimas);
                char kieti_vargsai;
                cout<< "Ar norite isrusiuoti studentus studentus i vargsus ir kietus ?(T/N)"<<endl; cin>> kieti_vargsai;
                do{
                    if (kieti_vargsai && (kieti_vargsai == 'T' || kieti_vargsai == 't' || kieti_vargsai == 'N' || kieti_vargsai == 'n')){
                        if (kieti_vargsai == 'T'||kieti_vargsai == 't'){
                            int med_ar_int = Vid_ar_med();
                            Kategorija(studentu_kiekis,med_ar_int);
                            Studentu_skaldymas();
                            int konsole_ar_failas = Konsole_ar_failas ();
                            if(konsole_ar_failas == 1){
                                // matavimas
                                int isvedimas = Isvesties_pasirinkimas();
                                cout<< "Isvesti vargsai studentai"<<endl;
                                isvestis(vargsai, isvedimas);
                                cout<< "Isvesti kieti studentai"<< endl;
                                isvestis(kieti,isvedimas);
                            }
                            else {
                                int isvedimas = Isvesties_pasirinkimas();
                                // matavimas
                                Failu_kurimas(vargsai,"vargsai.txt",isvedimas);
                                Failu_kurimas(kieti,"kieti.txt",isvedimas);

                            }}
                        else{
                            int konsole_ar_failas = Konsole_ar_failas();
                            int isvedimas = Isvesties_pasirinkimas();
                            sort(stud.begin(),stud.end(), palyginimas);
                            if (konsole_ar_failas == 1){

                                cout<< "Isvesti visi studentai :"<<endl;
                                isvestis(stud,isvedimas);
                            }
                            else{
                                cout<<"Sukelti i faila studentai.txt. "<<endl;
                                Failu_kurimas(stud, "studentai.txt",isvedimas);
                            }
                        }
                    } else {
                        cout<< " Neteisinga ivestis, iveskite T arba N !"<< endl;cin.clear();cin.ignore(10000, '\n');
                        cin>>kieti_vargsai;
                    }

                }
                while(kieti_vargsai != 'T' && kieti_vargsai != 't' && kieti_vargsai != 'N' && kieti_vargsai != 'n' );


            }
            else if (ranka_failas == 'g' || ranka_failas == 'G'){
                std::chrono::duration<double> laikas;
                int studentu_mase = Studentu_kiekis();
                int nd_kiekis = Nd_kiekis();
                auto start = hrClock::now();
                studentu_generavimas(studentu_mase, nd_kiekis);
                auto end = hrClock::now();
                laikas = end - start;
                cout << studentu_mase << " studentu failo generavimas uztruko : " << laikas.count()<< "s" << endl;
                Fake_main();
            }

            else if (ranka_failas == 'f' || ranka_failas == 'F') {
                stud.push_back(duomenys);
                std::chrono::duration<double> laikas;
                int kons_ar_failas = Konsole_ar_failas();
                int isvedimas = Isvesties_pasirinkimas();
                int med_ar_vid = Vid_ar_med();

                Koks_failo_pav ();// laikas suskaiciuotas
                studentu_kiekis = stud.size() -1 ;
                auto start = hrClock::now();
                stud.erase(stud.begin());
                sort(stud.begin(),stud.end(), palyginimas);
                auto end = hrClock::now(); laikas = end - start ;
                cout << studentu_kiekis <<" studentu failo surusiavimas pagal varda uztruko : " << laikas.count() << " s"<< endl;
                Kategorija(studentu_kiekis,med_ar_vid);
                start = hrClock::now();
                Studentu_skaldymas();
                end = hrClock::now(); laikas= end - start;
                cout << studentu_kiekis <<" studentu failo surusiavimas i atskirus vektorius uztriko : " << laikas.count() << " s"<< endl;

                if(kons_ar_failas == 1){
                    start = hrClock ::now();
                    isvestis(vargsai,isvedimas);
                    end = hrClock ::now();
                    laikas = end - start; cout << "vargsu isvedimas truko :" << laikas.count()<<" s"<<endl;
                    start = hrClock ::now();
                    isvestis(kieti,isvedimas);
                    end = hrClock ::now();laikas = end - start;
                    cout << "kietu isvedimas truko :" << laikas.count()<<" s"<<endl;

                }
                else{
                    start = hrClock ::now();
                    Failu_kurimas(vargsai,"vargsai.txt",isvedimas);
                    end = hrClock ::now();laikas = end - start;
                    cout << "vargsu isvedimas truko :" << laikas.count()<<" s"<<endl;
                    start = hrClock ::now();
                    Failu_kurimas(kieti,"kieti.txt",isvedimas);
                    end = hrClock ::now();laikas = end - start;
                    cout << "kietu isvedimas truko :" << laikas.count()<<" s"<<endl;

                }

            }
            else {
                int med_ar_vid = Vid_ar_med();
                int isvedimas = Isvesties_pasirinkimas();
                //testuoti visus 1000,10000,100000,1000000 ir t.t 5 failus
                int test_fdydziai[5] = {1000, 10000, 100000, 1000000, 10000000};// testo str failo dydziai
                // visus cout padaryt kad graziai butu
                printf("%-40s %-20s %-0s \n", "Veiksmas","Vector laikas (s.)", "List laikas (s.)");
                string filename;
                for (int i = 0; i < 5; i++) {
                    filename ="student" + to_string(test_fdydziai[i]) + ".txt";cout << string(70,'-') << "\n";

                    auto start = hrClock::now();
                    readfromFile(filename,stud); // laiko skaiciavimas
                    auto end = hrClock::now(); auto rez = end - start;

                    start = hrClock::now();
                    readfromFileList(filename, stud_list); // laiko skaiciavimas
                    end = hrClock::now(); auto rez2 = end - start;


                    printf("%-40s %-20.8lf %-20.8lf\n", (to_string(test_fdydziai[i]) +" studentu failo nuskaitymas").c_str(), rez.count(),rez2.count());// rezultato printas

                    start = hrClock::now();
                    sort(stud.begin(),stud.end(), palyginimas);
                    Kategorija(i, med_ar_vid);
                    Studentu_skaldymas(); end = hrClock::now(); rez = end- start; // visas skaldymas vector
                    // laiko skaiciavimas vector

                    start = hrClock::now();
                    stud_list.sort(palyginimas);
                    Kategorija_list(med_ar_vid);
                    Studentu_skaldymas_list();end = hrClock::now();rez2 = end- start; // Visas skaldymas list
                    // laiko skaiciavimas list

                    printf("%-40s %-20.8lf %-20.8lf\n", (to_string(test_fdydziai[i]) +" studentu surusiavimas").c_str(), rez.count(),rez2.count());
                    // rezultato printas

                    start = hrClock::now();
                    Failu_kurimas(kieti,"vektor_kieti" + to_string(test_fdydziai[i])  + ".txt", isvedimas );
                    Failu_kurimas(vargsai,"vektor_vargsai" + to_string(test_fdydziai[i])  + ".txt", isvedimas );
                    end = hrClock::now(); rez = end- start;

                    // laiko skaciavimas vector
                    start = hrClock::now();
                    Failu_kurimas_list(kieti_list,"list_kieti" + to_string(test_fdydziai[i])  + ".txt", isvedimas );
                    Failu_kurimas_list(vargsai_list,"list_vargsai" + to_string(test_fdydziai[i])  + ".txt", isvedimas );
                    end = hrClock::now(); rez2 = end- start;
                    // laiko skaiciavimas list
                    printf("%-40s %-20.8lf %-20.8lf\n", (to_string(test_fdydziai[i]) +" studentu sukelimas i failus").c_str(), rez.count(),rez2.count());
                    // rezultato printas
                }

            }
        } else {
            cout << "Iveskite R arba f arba G" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (ranka_failas != 'R' and ranka_failas != 'r' and ranka_failas != 'F' and ranka_failas != 'f' and ranka_failas != 'g' and ranka_failas != 'G' and ranka_failas != 'T' and ranka_failas != 't');

    system("pause");


}



void Testavimas (){






}









