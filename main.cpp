
#include "funkcija.h"

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
                info = 1;

                sort(stud.begin(),stud.end(), palyginimas);
                isvestis(info);
            }
            else if (ranka_failas == 'g' || ranka_failas == 'G'){
                int studentu_mase = Studentu_kiekis();
                int nd_kiekis = Nd_kiekis();
                studentu_generavimas(studentu_mase, nd_kiekis);
                stud.push_back(duomenys);
                readfromFile(failo_pav,stud);
                sort(stud.begin(),stud.end(), palyginimas);
                Kategorija(studentu_kiekis);
                Studentu_skaldymas();
                Failu_kurimas (kieti,"kieti.txt");
                Failu_kurimas(vargsai,"vargsai.txt");
            }

            else {
                stud.push_back(duomenys);
                readfromFile("kursiokai.txt",stud );
                info = 2;
                sort(stud.begin(),stud.end(), palyginimas);
                isvestis(info);
            }


        } else {
            cout << "Iveskite R arba f arba G" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (ranka_failas != 'R' and ranka_failas != 'r' and ranka_failas != 'F' and ranka_failas != 'f' and ranka_failas != 'g' and ranka_failas != 'G');

    system("pause");






}
