#include "../Include/funkcijos.h"
#include "../Include/Studentai.h"


void Studentai::Galutinis (int input ){
    if(input == 1){
        setGalutinis(getVid()) ;
    }
    else {
        setGalutinis(getMed());
    }

}

void Studentai::Vidurkis() {

    double sum_vid = 0;
    if (getNdSize() == 0) {
        setVid(  0.6 * getEgzaminas() ) ;
    } else {
        for (int i = 0; i < getNdSize(); i++) sum_vid += getNd(i);
        setVid(((sum_vid / getNdSize()) * 0.4) + (0.6 * getEgzaminas()));
    }
}
void Studentai::Mediana() {
    int n = getNdSize();
    if (n >= 1) {
        sortNd();
        if (n % 2 == 0) {
            setMed(Cnd[n / 2 - 1] + Cnd[n / 2] / 2) ;
        } else {
            setMed(Cnd[n / 2]) ;
        }
    } else {
        setMed(0)  ;
    }
    setMed(0.4 * getMed() + 0.6 * getEgzaminas())  ;
}



void Studentai::ivedimas ( int studentu_kiekis) {

    char bent_vienas_nd_ranka;
    string name;
    cout << "Iveskite studento varda : " << endl; cin >> name ;setVardas(name);
    cout << "Iveskite studento pavarde : " << endl;cin >> name;setPavarde(name);


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

                        do {
                            int namu_d_eile = getNdSize();
                            cout << "Iveskite nr. " << namu_d_eile + 1 << " pazymi: " << endl;
                            cin >> namu_d;
                            //if(namu_d != 0){
                            if (namu_d > 0 and namu_d <= 10) {
                                addNd(namu_d);
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
                                addNd(sk);

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
                                    setEgzaminas(egz);

                                }
                                else{
                                    cout<< "Iveskite nenulini skaiciu, nuo 1 iki 10!"<<endl ;cin.clear();
                                    cin.ignore(10000, '\n'); }}
                            while(!egz or egz > 10 or egz <0 );

                        }
                        else{
                            srand((unsigned )time(0));
                            egz = (rand() % 10) + 1;
                            setEgzaminas(egz);
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
                setEgzaminas(0);
            }
        }
        else{
            cout<< "Iveskite T arba N! "<<endl; cin.clear();cin.ignore(10000,'\n');
        }
    }
    while(bent_vienas_egz != 'T' and bent_vienas_egz != 't' and bent_vienas_egz != 'N' and  bent_vienas_egz != 'n');

    Vidurkis();
    Mediana();
}
void Studentai::isvestis (vector<Studentai> vektorius, int pasirinkimas) {

    stringstream buffer;

    if (pasirinkimas == 1) {
        buffer << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)"<<setw(20)<< "Objekto adresas" << endl;
        buffer << "____________________________________________________________________" << endl;
        for (int i = 0; vektorius.size() > i; i++) {
            buffer << setw(20) << vektorius[i].getVardas() << setw(20) << vektorius[i].getPavarde() << setw(17) << std::fixed
                   << std::setprecision(2) << vektorius[i].getVid() << setw(23) <<std::addressof(vektorius[i])<< endl;
        }

    }

    else if (pasirinkimas == 2) {
        buffer << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(med)"<<setw(20)<< "Objekto adresas" << endl;
        buffer << "_____________________________________________________________________" << endl;
        for (int i = 0; vektorius.size() > i; i++) {
            buffer << setw(20) << vektorius[i].getVardas() << setw(20) << vektorius[i].getPavarde() << setw(17) << std::fixed
                   << std::setprecision(2) << vektorius[i].getMed()<< setw(23) <<std::addressof(vektorius[i]) << endl;
        }

    }
    else {
        buffer << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)"<<setw(20)<< "Galutinis(med)" << setw(20)
               <<  "Objekto adresas"<< endl;
        buffer << "___________________________________________________________________________________________" << endl;
        for (int i = 0; vektorius.size() > i; i++) {
            buffer << setw(20) << vektorius[i].getVardas() << setw(20) << vektorius[i].getPavarde() << setw(17) << std::fixed
                   << std::setprecision(2) << vektorius[i].getVid() << setw(17) << vektorius[i].getMed() << setw(23) <<std::addressof(vektorius[i]) << endl;
        }

    }
    cout<<buffer.str();




}