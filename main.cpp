
#include "funkcijos.h"
int main() {

    char ranka_failas;
    do {
        cout << "Ar duomenis rasytite ranka ar nuskaitysite is failo(R/F)?" << endl;
        cin >> ranka_failas;
        if (ranka_failas &&
            (ranka_failas == 'R' || ranka_failas == 'r' || ranka_failas == 'F' || ranka_failas == 'f')) {
            if (ranka_failas == 'R' || ranka_failas == 'r') {
                s_kiekis = Studentu_kiekis();
                for (int eiles_nr = 0; eiles_nr < s_kiekis; eiles_nr++) {
                    ivedimas(eiles_nr);



                }
                info = 1;

                sort(stud.begin(),stud.end(), palyginimas);
                isvestis(info);
            } else {
                stud.push_back(duomenys);
                readfromFile(stud);
                info = 2;
                sort(stud.begin(),stud.end(), palyginimas);
                isvestis(info);
            }


        } else {
            cout << "Iveskite R arba F" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (ranka_failas != 'R' and ranka_failas != 'r' and ranka_failas != 'F' and ranka_failas != 'f');


}
