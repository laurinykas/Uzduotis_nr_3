
#include "funkcijos.h"
 vector <Duomenys> stud;
 vector<Duomenys> kieti;
 vector<Duomenys> vargsai;
 Duomenys duomenys;
 int studentu_kiekis = 0;

 string failo_pav ;
 std::chrono::duration<double> laikas_kat;
 std::chrono::duration<double> laikas_failo;

int main() {


    char ranka_failas;
    do {
        cout << "Ar duomenis rasytite ranka , nuskaitysite is failo kursiokai.txt ar noresite sugeneruoti atsitiktini?(R - ranka, F- is failo, G - generuoti )?" << endl;
        cin >> ranka_failas;
        if (ranka_failas &&
            (ranka_failas == 'R' || ranka_failas == 'r' || ranka_failas == 'F' || ranka_failas == 'f'|| ranka_failas == 'G'||ranka_failas == 'g')) {
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
                            Kategorija(studentu_kiekis);
                            Studentu_skaldymas();
                            //sortinti reiktu pagal vidurki
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
                /*
                stud.push_back(duomenys);
                start = hrClock ::now();
                readfromFile(failo_pav,stud);
                end = hrClock ::now(); laikas = end - start;
                cout << studentu_mase << " studentu failo nuskaitymas uztruko : " << laikas.count()<< "s"<< endl;
                sort(stud.begin(),stud.end(), palyginimas);// iskirti sort laika
                Kategorija(studentu_kiekis);
                start = hrClock::now();
                Studentu_skaldymas();
                end = hrClock::now();
                laikas = end - start + laikas_kat;
                cout << studentu_mase <<" studentu failo surusiavimas uztruko : " << laikas.count() << " s"<< endl;
                Failu_kurimas (kieti,"kieti.txt");
                Failu_kurimas(vargsai,"vargsai.txt");
                cout << studentu_mase <<" isrusiuotu studentu failu sukurimas uztruko : "<< laikas_failo.count() <<" s"<< endl;*/
               main();
            }

            else {
                int isvedimas = Isvesties_pasirinkimas();
                stud.push_back(duomenys);//
                Koks_failo_pav ();
                stud.erase(stud.begin());
                sort(stud.begin(),stud.end(), palyginimas);
                isvestis(stud,isvedimas);
            }


        } else {
            cout << "Iveskite R arba f arba G" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (ranka_failas != 'R' and ranka_failas != 'r' and ranka_failas != 'F' and ranka_failas != 'f' and ranka_failas != 'g' and ranka_failas != 'G');

    system("pause");






}
