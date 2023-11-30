//
// Created by Laurynas on 10/13/2023.
//

#include "../Include/funkcijos.h"
int List_Vektor(){
    int konteineris;
    cout<< "Koki konteineri norite naudoti?: 1 - List, 2 - Vector"<<endl;cin>>konteineris;
    do{
        if(konteineris == 1 or konteineris == 2){
            return konteineris;


        }
        else{
            cout<< "Neteisingai pasirinkote konteineri, turite ivesti 1 arba 2 "<<endl;cin.clear();
            cin.ignore(10000,'\n');
            cin>> konteineris;
        }

    }
    while (konteineris!=1 and konteineris != 2);




}
int Studentu_kiekis() {
    int studentu_sk;

    while (true) {
        cout << "Iveskite studentu kieki: ";
        if (cin >> studentu_sk && studentu_sk > 0) {
            return studentu_sk;
        } else {
            cout << "Neteisingai ivestas studentu skaicius, bandykite dar karta" << std::endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
int Nd_kiekis()  {
    int nd_sk;

    while (true) {
        cout << "Iveskite namu darbu kieki: ";
        if (std::cin >> nd_sk && nd_sk > 0) {
            return nd_sk;
        } else {
            cout << "Neteisingai ivestas namu darbu skaicius, bandykite dar karta" << std::endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
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
    cout << "baigtas failo generavimas"<<endl;

}



void Kategorija(int studentu_k, int med_ar_vid, int konteineris ){
            if (konteineris == 2){
            for(int i=0; i <= studentu_k; i++){
                stud[i].Galutinis (med_ar_vid );

            }}
            else {
                for(auto& student : stud_list){
                    student.Galutinis (med_ar_vid );
                }
            }

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
void Studentu_skaldymas(int konteineris) {
    if(konteineris == 2 ){
    for (auto el : stud) {
        if (el.getGalutinis() >= 5.00){

            kieti.push_back(el);
        } else {
            vargsai.push_back(el);

        }
    }}
    else{
        for (auto el : stud_list) {
            if (el.getGalutinis() >= 5.00){

                kieti_list.push_back(el);
            } else {
                vargsai_list.push_back(el);

            }
        }
    }

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
        if(pasirinkimas &&( pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3)) {
            return pasirinkimas;
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
                readfromFile(failo_pavadinimas,stud,stud_list,2);
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

void Sortingas (int vek_ar_list, int sortingo_tipas){

    if( vek_ar_list == 2){// vektoriai
        if(sortingo_tipas == 1){// pagal varda
            sort(stud.begin(), stud.end(), palyginimas_vardas);
        }
        else if (sortingo_tipas == 2){// pagal pavarde
            sort(stud.begin(), stud.end(), palyginimas_pavarde);
        }
        else {// pagal galutini
            sort(stud.begin(), stud.end(), palyginimas_galutinis);
        }

    }
    else { // listai
        if (sortingo_tipas == 1){ // pagal varda
            stud_list.sort(palyginimas_vardas);
        }
        else if (sortingo_tipas == 2){ // pagal pavarde
            stud_list.sort(palyginimas_pavarde);
        }
        else {// pagal galutini
            stud_list.sort(palyginimas_galutinis);
        }

    }

}
int Rusiavimo_tipas() {
    int pasirinkimas;
    cout << "Kaip noresite rusiuoti 1 - pagal varda, 2 - pagal pavarde, 3- pagal galutini bala ? :" << endl;
    cin >> pasirinkimas;
    do{
        if(pasirinkimas &&( pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3)){
            return pasirinkimas;


        }
        else{
            cout << "Iveskite nenulini skaiciu, nuo 1 iki 3!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pasirinkimas;


        }
    }while (pasirinkimas != 1 and pasirinkimas != 2 and pasirinkimas != 3);


}



void Skaldymas2(int konteineris ) {
    if (konteineris == 2 ){
        auto isVargsas = [](const Studentai &student) {
            return student.getGalutinis() < 5.00;
        };

        auto partitionIter = std::partition(stud.begin(), stud.end(), isVargsas);

        vargsai.assign(stud.begin(), partitionIter);
        kieti.assign(partitionIter, stud.end());

        stud.clear();
    }
    else{
        auto isVargsasList = [](const Studentai &student) {
            return student.getGalutinis() < 5.00;
        };

        auto partitionIter = std::partition(stud_list.begin(), stud_list.end(), isVargsasList);

        vargsai_list.assign(stud_list.begin(), partitionIter);
        kieti_list.assign(partitionIter, stud_list.end());

        stud.clear();
    }
    }




void Skaldymas3(int konteineris ) {
    if (konteineris == 2){
        auto partitionPredicate = [](const Studentai& el) {
            return el.getGalutinis() >= 5.00;
        };

        auto partitionPoint = std::partition(stud.begin(), stud.end(), partitionPredicate);

        // Now, stud is partitioned into "kieti" (passed) before partitionPoint
        // and "vargsai" (struggling) after partitionPoint.

        kieti.assign(stud.begin(), partitionPoint);
        vargsai.assign(partitionPoint, stud.end());
}
    else {
        auto partitionPredicate = [](const Studentai& el) {
            return el.getGalutinis() >= 5.00;
        };

        auto partitionPoint = std::partition(stud_list.begin(), stud_list.end(), partitionPredicate);

        // Now, stud is partitioned into "kieti" (passed) before partitionPoint
        // and "vargsai" (struggling) after partitionPoint.

        kieti_list.assign(stud_list.begin(), partitionPoint);
        vargsai_list.assign(partitionPoint, stud_list.end());
    }

    }




void MegaSkirstymas(int konteineris , int strategija ){


        if(strategija == 1){ //
            Studentu_skaldymas(konteineris);
        }
        else if(strategija == 2){
            Skaldymas2(konteineris);
        }
        else{ // 3 strategija vektor
            Skaldymas3(konteineris);
        }
    }



int SkirstymoStrategijosPas(){
    int pasirinkimas;
    cout << "Pagal kokia strategija noresite rusiuoti failus? 1 - 1 strategija, 2 - 2strategija, 3 - 3 strategija(galioja tik vector konteineriams) " << endl;
    cin >> pasirinkimas;
    do{
        if(pasirinkimas &&( pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3)){
            return pasirinkimas;


        }
        else{
            cout << "Iveskite  1 , 2 arba  3!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pasirinkimas;


        }
    }while (pasirinkimas != 1 and pasirinkimas != 2 and pasirinkimas != 3);



}



void Fake_main(){

    char ranka_failas;
    do {
        cout << "Ar duomenis rasytite ranka , nuskaitysite is failo ar noresite sugeneruoti atsitiktini ar testuoti?(R - ranka, F- is failo, G - generuoti, T - testuoti konteinerius, S - testuoti strategijas )?" << endl;
        cin >> ranka_failas;
        Studentai st ;
        if (ranka_failas &&
            (ranka_failas == 'R' || ranka_failas == 'r' || ranka_failas == 'F' || ranka_failas == 'f'|| ranka_failas == 'G'||ranka_failas == 'g' ||ranka_failas == 'T'||ranka_failas == 't'||ranka_failas == 'S'||ranka_failas =='s')) {
            if (ranka_failas == 'R' || ranka_failas == 'r') {
                int studentu_kiekis = Studentu_kiekis();
                int konteineris = List_Vektor();
                int rusiavimo_tipas =  Rusiavimo_tipas();
                int skirstymo_strat = SkirstymoStrategijosPas();

                if (konteineris == 2) {

                    for (int eiles_nr = 0; eiles_nr < studentu_kiekis; eiles_nr++) {
                        st.ivedimas(eiles_nr);
                        stud.push_back(st);
                    }

                    Sortingas(konteineris,rusiavimo_tipas);
                    char kieti_vargsai;
                    cout << "Ar norite isrusiuoti studentus studentus i vargsus ir kietus ?(T/N)" << endl;
                    cin >> kieti_vargsai;
                    do {
                        if (kieti_vargsai && (kieti_vargsai == 'T' || kieti_vargsai == 't' || kieti_vargsai == 'N' ||
                                              kieti_vargsai == 'n')) {
                            if (kieti_vargsai == 'T' || kieti_vargsai == 't') {
                                int med_ar_int = Vid_ar_med();
                                Kategorija(studentu_kiekis, med_ar_int,konteineris);
                                MegaSkirstymas(konteineris,skirstymo_strat);
                                int konsole_ar_failas = Konsole_ar_failas();
                                if (konsole_ar_failas == 1) {
                                    int isvedimas = Isvesties_pasirinkimas();
                                    cout << "Isvesti vargsai studentai" << endl;
                                    st.isvestis(vargsai,stud_list, isvedimas,konteineris);
                                    cout << "Isvesti kieti studentai" << endl;
                                    st.isvestis(kieti,stud_list, isvedimas,konteineris);
                                } else {
                                    int isvedimas = Isvesties_pasirinkimas();

                                    st.Failu_kurimas(vargsai, "vargsai.txt", isvedimas);
                                    st.Failu_kurimas(kieti, "kieti.txt", isvedimas);

                                }
                            } else {
                                int konsole_ar_failas = Konsole_ar_failas();
                                int isvedimas = Isvesties_pasirinkimas();
                                if (konsole_ar_failas == 1) {

                                    cout << "Isvesti visi studentai :" << endl;
                                    st.isvestis(stud,stud_list, isvedimas,konteineris);
                                } else {
                                    cout << "Sukelti i faila studentai.txt. " << endl;
                                    st.Failu_kurimas(stud,stud_list, "studentai.txt", isvedimas,konteineris);
                                }
                            }
                        } else {
                            cout << " Neteisinga ivestis, iveskite T arba N !" << endl;
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cin >> kieti_vargsai;
                        }

                    } while (kieti_vargsai != 'T' && kieti_vargsai != 't' && kieti_vargsai != 'N' && kieti_vargsai != 'n');

                }
                else {
                    for (int eiles_nr = 0; eiles_nr < studentu_kiekis; eiles_nr++) {
                       st.ivedimas(eiles_nr);
                       stud_list.push_back(st);
                    }

                    Sortingas(konteineris,rusiavimo_tipas);
                    char kieti_vargsai;
                    cout << "Ar norite isrusiuoti studentus studentus i vargsus ir kietus ?(T/N)" << endl;
                    cin >> kieti_vargsai;
                    do {
                        if (kieti_vargsai && (kieti_vargsai == 'T' || kieti_vargsai == 't' || kieti_vargsai == 'N' ||
                                              kieti_vargsai == 'n')) {
                            if (kieti_vargsai == 'T' || kieti_vargsai == 't') {
                                int med_ar_int = Vid_ar_med();
                                Kategorija( studentu_kiekis, med_ar_int,konteineris);
                                MegaSkirstymas(konteineris,skirstymo_strat);
                                int konsole_ar_failas = Konsole_ar_failas();
                                if (konsole_ar_failas == 1) {
                                    int isvedimas = Isvesties_pasirinkimas();
                                    cout << "Isvesti vargsai studentai" << endl;
                                    st.isvestis(stud,vargsai_list, isvedimas,konteineris);
                                    cout << "Isvesti kieti studentai" << endl;
                                    st.isvestis(stud, kieti_list, isvedimas, konteineris);
                                } else {
                                    int isvedimas = Isvesties_pasirinkimas();

                                    st.Failu_kurimas(stud,vargsai_list, "vargsai.txt", isvedimas,konteineris);
                                   st.Failu_kurimas(stud,kieti_list, "kieti.txt", isvedimas,konteineris);

                                }
                            } else {
                                int konsole_ar_failas = Konsole_ar_failas();
                                int isvedimas = Isvesties_pasirinkimas();

                                if (konsole_ar_failas == 1) {

                                    cout << "Isvesti visi studentai :" << endl;
                               st.isvestis(stud,stud_list, isvedimas,konteineris);
                                } else {
                                    cout << "Sukelti i faila studentai.txt. " << endl;
                                    st.Failu_kurimas(stud, stud_list, "studentai.txt", isvedimas, konteineris);
                                }
                            }
                        } else {
                            cout << " Neteisinga ivestis, iveskite T arba N !" << endl;
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cin >> kieti_vargsai;
                        }

                    } while (kieti_vargsai != 'T' && kieti_vargsai != 't' && kieti_vargsai != 'N' && kieti_vargsai != 'n');







                }
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
                Studentai st;
                stud.push_back(duomenys);
                std::chrono::duration<double> laikas;
                int kons_ar_failas = Konsole_ar_failas();
                int isvedimas = Isvesties_pasirinkimas();
                int med_ar_vid = Vid_ar_med();
                int list_vector = List_Vektor();
                int rusiavimo_tipas = Rusiavimo_tipas();
                int skirstymo_strat = SkirstymoStrategijosPas();


                if(list_vector == 2){

                    Koks_failo_pav ();// laikas suskaiciuotas
                    studentu_kiekis = stud.size() -1 ;
                    stud.erase(stud.begin());



                    Kategorija(studentu_kiekis,med_ar_vid);
                    auto start = hrClock::now();
                    Sortingas(list_vector,rusiavimo_tipas);
                    auto end = hrClock::now();laikas = end - start ;
                    cout << studentu_kiekis <<" studentu failo surusiavimas  uztruko : " << laikas.count() << " s"<< endl;
                    start = hrClock::now();
                    //Studentu_skaldymas();
                    MegaSkirstymas(list_vector,skirstymo_strat);
                    end = hrClock::now(); laikas= end - start;
                    cout << studentu_kiekis <<" studentu failo surusiavimas i atskirus vektorius uztriko : " << laikas.count() << " s"<< endl;

                    if(kons_ar_failas == 1){
                        start = hrClock ::now();
                        st.isvestis(vargsai,isvedimas);
                        end = hrClock ::now();
                        laikas = end - start; cout << "vargsu isvedimas truko :" << laikas.count()<<" s"<<endl;
                        start = hrClock ::now();
                        st.isvestis(kieti,isvedimas);
                        end = hrClock ::now();laikas = end - start;
                        cout << "kietu isvedimas truko :" << laikas.count()<<" s"<<endl;

                    }
                    else{
                        start = hrClock ::now();
                        st.Failu_kurimas(vargsai,"vargsai.txt",isvedimas);
                        end = hrClock ::now();laikas = end - start;
                        cout << "vargsu isvedimas truko :" << laikas.count()<<" s"<<endl;
                        start = hrClock ::now();
                        st.Failu_kurimas(kieti,"kieti.txt",isvedimas);
                        end = hrClock ::now();laikas = end - start;
                        cout << "kietu isvedimas truko :" << laikas.count()<<" s"<<endl;

                    }
                }else {
                    Koks_failo_pav_list();// laikas suskaiciuotas
                    studentu_kiekis = stud_list.size()  ;
                    auto start = hrClock::now();
                   Kategorija_list(med_ar_vid);
                    Sortingas(list_vector,rusiavimo_tipas);
                    auto end = hrClock::now(); laikas = end - start;
                    cout << studentu_kiekis <<" studentu failo surusiavimas pagal varda uztruko : " << laikas.count() << " s"<< endl;
                    start = hrClock::now();
                    MegaSkirstymas(list_vector,skirstymo_strat);
                    end = hrClock::now(); laikas= end - start;
                    cout << studentu_kiekis <<" studentu failo surusiavimas i atskirus sarasus uztruko : " << laikas.count() << " s"<< endl;

                    if(kons_ar_failas == 1){
                        start = hrClock ::now();
 //                       isvestis_list(vargsai_list,isvedimas);
                        end = hrClock ::now();
                        laikas = end - start; cout << "vargsu isvedimas truko :" << laikas.count()<<" s"<<endl;
                        start = hrClock ::now();
//                        isvestis_list(kieti_list,isvedimas);
                        end = hrClock ::now();laikas = end - start;
                        cout << "kietu isvedimas truko :" << laikas.count()<<" s"<<endl;

                    }
                    else{
                        start = hrClock ::now();
//                        Failu_kurimas_list(vargsai_list,"vargsai.txt",isvedimas);
                        end = hrClock ::now();laikas = end - start;
                        cout << "vargsu isvedimas truko :" << laikas.count()<<" s"<<endl;
                        start = hrClock ::now();
//                        Failu_kurimas_list(kieti_list,"kieti.txt",isvedimas);
                        end = hrClock ::now();laikas = end - start;
                        cout << "kietu isvedimas truko :" << laikas.count()<<" s"<<endl;

                    }





                }
            }
            else if(ranka_failas == 't' || ranka_failas == 'T'){
                std::chrono::duration<double> rez;
                std::chrono::duration<double> rez2;
                int med_ar_vid = Vid_ar_med();
                int isvedimas = Isvesties_pasirinkimas();
                int rusiavimo_tipas = Rusiavimo_tipas();
                int strat = SkirstymoStrategijosPas();
                //testuoti visus 1000,10000,100000,1000000 ir t.t 5 failus
                int test_fdydziai[5] = {1000, 10000, 100000, 1000000, 10000000};// testo str failo dydziai
                // visus cout padaryt kad graziai butu
                printf("%-40s %-20s %-0s \n", "Veiksmas","Vector laikas (s.)", "List laikas (s.)");
                string filename;
                for (int i = 0; i < 5; i++) {
                    filename ="student" + to_string(test_fdydziai[i]) + ".txt";cout << string(70,'-') << "\n";

                    auto start = hrClock::now();
                    readfromFile(filename,stud); // laiko skaiciavimas
                    auto end = hrClock::now();  rez = end - start;

                    start = hrClock::now();
//                    readfromFileList(filename, stud_list); // laiko skaiciavimas
                    end = hrClock::now();  rez2 = end - start;

                    auto info1 = rez.count();
                    auto info2 = rez2.count();
                    printf("%-40s %-20.8lf %-20.8lf\n", (to_string(test_fdydziai[i]) +" studentu failo nuskaitymas").c_str(), info1,info2);// rezultato printas

                    start = hrClock::now();
                    Kategorija(test_fdydziai[i], med_ar_vid);Sortingas(2,rusiavimo_tipas);
                    MegaSkirstymas(2,strat); end = hrClock::now(); rez = end- start; // visas skaldymas vector
                    // laiko skaiciavimas vector

                    start = hrClock::now();
                    Kategorija_list(med_ar_vid);
                    Sortingas(1,rusiavimo_tipas);
                    MegaSkirstymas(1,strat);end = hrClock::now();rez2 = end- start; // Visas skaldymas list
                    // laiko skaiciavimas list
                    info1 = rez.count();info2 = rez2.count();
                    printf("%-40s %-20.8lf %-20.8lf\n", (to_string(test_fdydziai[i]) +" studentu surusiavimas").c_str(), info1,info2);
                    // rezultato printas

                    start = hrClock::now();
                    st.Failu_kurimas(kieti,"vektor_kieti" + to_string(test_fdydziai[i])  + ".txt", isvedimas );
                    st.Failu_kurimas(vargsai,"vektor_vargsai" + to_string(test_fdydziai[i])  + ".txt", isvedimas );
                    end = hrClock::now(); rez = end- start;

                    // laiko skaciavimas vector
                    start = hrClock::now();
//                    Failu_kurimas_list(kieti_list,"list_kieti" + to_string(test_fdydziai[i])  + ".txt", isvedimas );
//                    Failu_kurimas_list(vargsai_list,"list_vargsai" + to_string(test_fdydziai[i])  + ".txt", isvedimas );
                    end = hrClock::now(); rez2 = end- start;
                    // laiko skaiciavimas list
                    info1 = rez.count();info2 = rez2.count();
                    printf("%-40s %-20.8lf %-20.8lf\n", (to_string(test_fdydziai[i]) +" studentu sukelimas i failus").c_str(), info1,info2);
                    // rezultato printas
                }

            }
            else{
                std::chrono::duration<double> rez;
                std::chrono::duration<double> rez2;
                int med_ar_vid = Vid_ar_med();
                //int isvedimas = Isvesties_pasirinkimas();
                int rusiavimo_tipas = Rusiavimo_tipas();
                int test_fdydziai[5] = {1000, 10000, 100000, 1000000, 10000000};
                printf("%-40s %-20s %+5s \n", "Veiksmas","Vector laikas (s.)", "List laikas (s.)");
                string filename;
                for (int i = 0; i < 5; i++) {
                    filename ="student" + to_string(test_fdydziai[i]) + ".txt";cout << string(70,'-') << "\n";


                    readfromFile(filename,stud); // failo nuskaitymas vector

 //                   readfromFileList(filename, stud_list); // failo nuskaitymas list

                    //auto info1 = rez.count();
                    //auto info2 = rez2.count();
                    //printf("%-40s %-20.8lf %-20.8lf\n", (to_string(test_fdydziai[i]) +" studentu failo nuskaitymas").c_str(), info1,info2);// rezultato printas

                    Kategorija(test_fdydziai[i], med_ar_vid);
                    Sortingas(2,rusiavimo_tipas);
                    auto  tempstud = stud;

                    Kategorija_list(med_ar_vid);
                    Sortingas(1,rusiavimo_tipas);
                    auto tempstud_list = stud_list;

                    auto start = hrClock::now();
                    MegaSkirstymas(2,1);
                    auto end = hrClock::now();
                    stud = tempstud;
                    rez = end- start;
                    // laiko skaiciavimas vector 1 strategija

                    start = hrClock::now();
                    MegaSkirstymas(1,1);
                    end = hrClock::now();
                    rez2 = end- start;
                    stud_list = tempstud_list;
                    // laiko skaiciavimas list 1 strategija

                    auto info1 = rez.count(); auto info2 = rez2.count();
                    printf("%-40s %-20.8lf %-20.8lf\n", (to_string(test_fdydziai[i]) +" studentu dalijimas i grupes (1 strategija)").c_str(), info1,info2);

                    start = hrClock::now();
                    MegaSkirstymas(2,2);
                    end = hrClock::now();
                    stud = tempstud;
                    rez = end- start;
                    // laiko skaiciavimas vector 2 strategija

                    start = hrClock::now();
                    MegaSkirstymas(1,2);
                    end = hrClock::now();
                    rez2 = end- start;
                    stud_list = tempstud_list;
                    // laiko skaiciavimas list 2 strategija

                    info1 = rez.count();  info2 = rez2.count();
                    printf("%-40s %-20.8lf %-20.8lf\n", (to_string(test_fdydziai[i]) +" studentu dalijimas i grupes (2 strategija)").c_str(), info1,info2);

                    start = hrClock::now();
                    MegaSkirstymas(2,3);
                    end = hrClock::now();
                    stud = tempstud;
                    rez = end- start;
                    // laiko skaiciavimas vector 2 strategija
                    info1 = rez.count();
                    printf("%-40s %-20.8lf\n", (to_string(test_fdydziai[i]) +" studentu dalijimas i grupes (3 strategija)").c_str(), info1);

                }




            }
        } else {
            cout << "Iveskite R arba f arba G arba T arba S" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (ranka_failas != 'R' and ranka_failas != 'r' and ranka_failas != 'F' and ranka_failas != 'f' and ranka_failas != 'g' and ranka_failas != 'G' and ranka_failas != 'T' and ranka_failas != 't' and ranka_failas != 's' and ranka_failas != 'S');


}


void Koks_failo_pav_list (){
    system("dir *.txt");
    string failo_pavadinimas;
    std::chrono::duration<double> laikas;
    cout<<"Koki faila noretumete nuskenuoti?"<<endl; cin>> failo_pavadinimas;


    try {
        ifstream fileread(failo_pavadinimas);
        if (!fileread.fail()) {
            auto start  = hrClock::now();
            readfromFileList(failo_pavadinimas,stud_list);
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














