# Uzduotis-nr-1
## v0.3 
### nauji dalykai
* Implementuotas std::list konteineris.
* Pasirinkus studento rašymo ranka funckiją galima taip pat gaunamas objekto adresas.
* Įdėta galimybė testuoti konteinerių greitį.
* Galima pasirinkti į kokį konteinerį įrašysite duomenis.
* 
### std::vector ir std::list konteinerių palyginimo rezultatai

![Screenshot_1](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/d1e92756-5aa9-4eb6-b7c0-dcac1237d786)
![image](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/d26ef658-e736-4783-aee6-975f88f91c5d)

* Vidutinis laikas 1k studentų : 0.0110898 s.
* Vidutinis laikas 10k studentų : 0.12564285 s.
* Vidutinis laikas 100k studentų : 1.57843795 s.
* Vidutinis laikas 1mil. studentų : 18.1561645 s.
* Vidutinis laikas 10mil. studentų : 202.8593495 s. 
### Testavimui buvo naudoti:
*  CPU : AMD Ryzen 7 5800H
* RAM : 16.0 GB 3200 MHz
* SSD: 475 GB
  

## v0.2.1
* Galima generuoti daug kartų studentų failus.
* Galima pasirinkti, kokius failus nori naudotojas nuskaityti.

## v0.2 
* Galimybė sugeneruoti atsitiktinius studentus į failą.
* Yra studentų vektoriaus rūšiavimas į kietus ir vargšus studentus
  (studentai, kurių galutinis balas yra didesnis ar lygus 5 yra skaitomi kietais studentas, o tų kurių mažesnis - vargšais).
* Galimybė išrašyti studentų galutinius balus į failus.
* Dabar yra matuojami įvairūs programos procesai (studentus generuojančio failo kūrimas, failo nuskaitymas, studentų rūšiavimas, naujų failų kūrimas).

### Programos greičiai su skirtingais studentų kiekiais
* Kai studentų yra 1 tūkst. ir namų darbų kiekis - 6
![1k_6nd](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/ef805dd6-036c-40a2-a704-5f26f6ad0f52)
* Kai studentų yra 10 tūkst. ir namų darbų kiekis - 6
![10k_6nd](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/436c36b9-466d-4a25-8381-f326903b8f51)
* Kai studentų yra 100 tūkst. ir namų darbų kiekis - 6
![100k_6nd](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/68b93e4f-1c8e-4110-91bc-df5de26c32c8)
* Kai studentų yra 1 mil. ir namų darbų kiekis - 6
![1mil_6nd](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/56e4f1ea-1a90-4463-aaa1-07558df7fe6a)
* Kai studentų yra 10 mil. ir namų darbų kiekis - 6
![10mil_6_nd](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/e4da4830-9bad-4926-afce-0569ca2a4e4f)


## v0.1.1
* Galimybė nuskaityti studentus iš failo.
* Įdėta naudotojo apsauga, jei failas neegzistuotų.
* Studentai dabar yra ir rūšiuojami.

## v.pradine 
### Programos galimybės
* Programa paima studentų vardus ir pavardes, surenka namų  darbų pažymius, bei egzamino balą ir apskaičiuoją medianą su vidurkiu.
* Šitoje galima duomenis suvesti ranka, bet kai kuriuos duomenis(namų darbų balus ir egzamino balą) sugeneruoti atsitiktinai.
* Yra įdėti saugumo garantai, kad programa veiktų tvarkingai( pažymiai yra visada skaičiai nuo 1 iki 10 ir t.t).
* Galima suvesti neribotą kiekį namų darbų ir studentų .
