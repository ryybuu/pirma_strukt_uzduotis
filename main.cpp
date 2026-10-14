#include <windows.h>
#include <iostream>
#include <format>
#include <iomanip>
using namespace std;


void stars () {
    for (int i = 1; i < 50; i++) {
        cout << "*";
    }
    cout<<endl;
}

void valiutos_meniu () {
    stars();
    cout << "1. GBP" << endl;
    cout << "2. USD" << endl;
    cout << "3. INR" << endl;
    cout << "4. Grizti i pagrindini meniu" << endl;
    stars();
}

void main_menu() {
    cout << endl;
    stars();
    cout << "                     MENIU" << endl;
    stars();
    cout << "1. Valiutos kurso palyginimas su euru." << endl;
    cout << "2. Valiutos pirkimas (EUR -> pasirinkta  valiuta)." << endl;
    cout << "3. Valiutos pardavimas (pasirinkta valiuta -> EUR)." << endl;
    cout << "4. Iseiti." << endl;
    stars();
    cout << "Pasirinkima iveskite cia:" << endl;
}


int main() {
    // Prideti console nustatymai, kad matytusi valiutu simboliai. Veikia kartu su #include <windows.h>
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const double GBP_Bendras = 0.8729;
    const double GBP_Pirkti = 0.8600;
    const double GBP_Parduoti  = 0.9220;

    const double USD_Bendras   = 1.1793;
    const double USD_Pirkti    = 1.1460;
    const double USD_Parduoti  = 1.2340;

    const double INR_Bendras   = 104.6918;
    const double INR_Pirkti    = 101.3862;
    const double INR_Parduoti  = 107.8546;

    int meniu_ivestis;
    int ivesties_klaidos = 0;
    double nupirkta_suma = 0;
    double parduota_suma = 0;

    do {
        main_menu();
        cin >> meniu_ivestis;

        switch (meniu_ivestis) {
            case 1:
                int lyginimo_ivestis;
                stars();
                cout << "Pasirinkite valiuta, kuria norite palyginti su euru: " << endl;
                valiutos_meniu();
                cin >> lyginimo_ivestis;
                switch (lyginimo_ivestis) {
                    case 1:
                        cout << format("1 € = £{:.2f}", GBP_Bendras) << endl;
                        cout << format("£1 = {:.2f} €", 1 / GBP_Bendras) << endl;
                        break;
                    case 2:
                        cout << format("1 € = ${:.2f}", USD_Bendras) << endl;
                        cout << format("$1 = {:.2f} €", 1 / USD_Bendras) << endl;
                        break;
                    case 3:
                        cout << format("1 € = ₹{:.2f}", INR_Bendras) << endl;
                        cout << format("₹1 = {:.2f} €", 1 / INR_Bendras) << endl;
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Ivestas neteisingas pasirinkimas, griztama i pagrindini meniu..." << endl;
                        break;
                };
                break;
            case 2: {
                int pirkimo_meniu_ivestis;
                double pirkimo_ivestis;
                int klaidu_kiekis = 0;
                cout << "Iveskite kuria valiuta norite pirkti:" << endl;
                valiutos_meniu();
                cin >> pirkimo_meniu_ivestis;
                switch (pirkimo_meniu_ivestis) {
                    case 1:
                        cout << "Iveskite uz kiek EUR noretumete pirkti GBP:" << endl;
                        do {
                            cin >> pirkimo_ivestis;
                            if (pirkimo_ivestis <= 0 ) {
                                cout << "Klaida! Ivesta valiutos suma turi buti daugiau uz 0." << endl;
                                klaidu_kiekis++;

                                if (klaidu_kiekis < 3) {
                                    cout << "Iveskite EUR suma dar karta. Liko bandymu: " << 3 - klaidu_kiekis << endl;
                                }
                            }

                        } while (pirkimo_ivestis <= 0 && klaidu_kiekis < 3);

                        if (klaidu_kiekis == 3) {
                            cout << "Neteisinga suma ivesta per daug kartu. Griztama i pagrindini meniu..." << endl;
                            break;
                        }
                        nupirkta_suma = pirkimo_ivestis * GBP_Pirkti;
                        cout << format("Uz {0} € buvo nupirkta £{1:.2f}", pirkimo_ivestis,nupirkta_suma) << endl;
                        cout << "Griztama i pagrindini meniu..." << endl;
                        break;
                    case 2:
                        cout << "Iveskite uz kiek EUR noretumete pirkti USD:" << endl;
                        do {
                            cin >> pirkimo_ivestis;
                            if (pirkimo_ivestis <= 0 ) {
                                cout << "Klaida! Ivesta valiutos suma turi buti daugiau uz 0." << endl;
                                klaidu_kiekis++;

                                if (klaidu_kiekis < 3) {
                                    cout << "Iveskite EUR suma dar karta. Liko bandymu: " << 3 - klaidu_kiekis << endl;
                                }
                            }

                        } while (pirkimo_ivestis <= 0 && klaidu_kiekis < 3);

                        if (klaidu_kiekis == 3) {
                            cout << "Neteisinga suma ivesta per daug kartu. Griztama i pagrindini meniu..." << endl;
                            break;
                        }
                        nupirkta_suma = pirkimo_ivestis * USD_Pirkti;
                        cout << format("Uz {0} € buvo nupirkta ${1:.2f}", pirkimo_ivestis,nupirkta_suma) << endl;
                        cout << "Griztama i pagrindini meniu..." << endl;
                        break;
                    case 3:
                        cout << "Iveskite uz kiek EUR noretumete pirkti INR: " << endl;
                        do {
                            cin >> pirkimo_ivestis;
                            if (pirkimo_ivestis <= 0 ) {
                                cout << "Klaida! Ivesta valiutos suma turi buti daugiau uz 0." << endl;
                                klaidu_kiekis++;

                                if (klaidu_kiekis < 3) {
                                    cout << "Iveskite EUR suma dar karta. Liko bandymu: " << 3 - klaidu_kiekis << endl;
                                }
                            }

                        } while (pirkimo_ivestis <= 0 && klaidu_kiekis < 3);

                        if (klaidu_kiekis == 3) {
                            cout << "Neteisinga suma ivesta per daug kartu. Griztama i pagrindini meniu..." << endl;
                            break;
                        }
                        nupirkta_suma = pirkimo_ivestis * INR_Pirkti;
                        cout << format("Uz {0} € buvo nupirkta ₹{1:.2f}", pirkimo_ivestis,nupirkta_suma) << endl;
                        cout << "Griztama i pagrindini meniu..." << endl;
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Ivestas neteisingas pasirinkimas, griztama i pagrindini meniu..." << endl;
                        break;
                };
            }
                break;
            case 3: {
                int pardavimo_meniu_ivestis;
                double pardavimo_ivestis;
                int klaidu_kiekis = 0;
                cout << "Iveskite kuria valiuta norite parduoti: " << endl;
                valiutos_meniu();
                cin >> pardavimo_meniu_ivestis;
                switch (pardavimo_meniu_ivestis) {
                    case 1:
                        cout << "Iveskite kiek GBP noretumete parduoti: ";
                        do {
                            cin >> pardavimo_ivestis;
                            if (pardavimo_ivestis <= 0 ) {
                                cout << "Klaida! Ivesta valiutos suma turi buti daugiau uz 0." << endl;
                                klaidu_kiekis++;

                                if (klaidu_kiekis < 3) {
                                    cout << "Iveskite GBP suma dar karta. Liko bandymu: " << 3 - klaidu_kiekis << endl;
                                }
                            }

                        } while (pardavimo_ivestis <= 0 && klaidu_kiekis < 3);

                        if (klaidu_kiekis == 3) {
                            cout << "Neteisinga suma ivesta per daug kartu. Griztama i pagrindini meniu..." << endl;
                            break;
                        }
                        parduota_suma = pardavimo_ivestis / GBP_Parduoti;
                        cout << format("£{0} buvo parduota uz {1:.2f} €", pardavimo_ivestis,parduota_suma) << endl;
                        cout << "Griztama i pagrindini meniu..." << endl;
                        break;
                    case 2:
                        cout << "Iveskite kiek USD noretumete parduoti: ";
                        do {
                            cin >> pardavimo_ivestis;
                            if (pardavimo_ivestis <= 0 ) {
                                cout << "Klaida! Ivesta valiutos suma turi buti daugiau uz 0." << endl;
                                klaidu_kiekis++;

                                if (klaidu_kiekis < 3) {
                                    cout << "Iveskite USD suma dar karta. Liko bandymu: " << 3 - klaidu_kiekis << endl;
                                }
                            }

                        } while (pardavimo_ivestis <= 0 && klaidu_kiekis < 3);

                        if (klaidu_kiekis == 3) {
                            cout << "Neteisinga suma ivesta per daug kartu. Griztama i pagrindini meniu..." << endl;
                            break;
                        }
                        parduota_suma = pardavimo_ivestis / USD_Parduoti;
                        cout << format("${0} buvo parduota uz {1:.2f} €", pardavimo_ivestis,parduota_suma) << endl;
                        cout << "Griztama i pagrindini meniu..." << endl;
                        break;
                    case 3:
                        cout << "Iveskite kiek INR noretumete parduoti:" << endl;
                        do {
                            cin >> pardavimo_ivestis;
                            if (pardavimo_ivestis <= 0 ) {
                                cout << "Klaida! Ivesta valiutos suma turi buti daugiau uz 0." << endl;
                                klaidu_kiekis++;

                                if (klaidu_kiekis < 3) {
                                    cout << "Iveskite INR suma dar karta. Liko bandymu: " << 3 - klaidu_kiekis << endl;
                                }
                            }

                        } while (pardavimo_ivestis <= 0 && klaidu_kiekis < 3);

                        if (klaidu_kiekis == 3) {
                            cout << "Neteisinga suma ivesta per daug kartu. Griztama i pagrindini meniu..." << endl;
                            break;
                        }
                        parduota_suma = pardavimo_ivestis / INR_Parduoti;
                        cout << format("₹{0} buvo parduota uz {1:.2f} €", pardavimo_ivestis,parduota_suma) << endl;
                        cout << "Griztama i pagrindini meniu..." << endl;
                        break;
                }
                break;
            }
            case 4:
                cout << "Programa isjungiama..." << endl;
                break;
            default:
                cout << "Turite ivesti viena is meniu pasirinkimu!" << endl;
                ivesties_klaidos++;
                    break;
        }


    } while (meniu_ivestis != 4 && ivesties_klaidos < 3);

    if (ivesties_klaidos == 3) cout << "Neteisingas pasirinkimas buvo ivestas 3 kartus, programa isjungiama.";

    return 0;
}