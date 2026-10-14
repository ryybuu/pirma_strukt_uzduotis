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
    cout << "Pasirinkima iveskite konsoleje ir paspauskite enter." << endl;
    stars();
    cout << "1. Valiutos kurso palyginimas su euru." << endl;
    cout << "2. Valiutos pirkimas (EUR -> pasirinkta  valiuta)." << endl;
    cout << "3. Valiutas pardavimas (pasirinkta valiuta -> EUR)." << endl;
    cout << "4. Iseiti." << endl;
    stars();
}


int main() {
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
                        cout << format("1 EUR = {:.2f} GBP", GBP_Bendras) << endl;
                        break;
                    case 2:
                        cout << format("1 EUR = {:.2f} USD", USD_Bendras) << endl;
                        break;
                    case 3:
                        cout << format("1 EUR = {:.2f} INR", INR_Bendras) << endl;
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Ivestas neteisingas pasirinkimas, griztama i pagrindini meniu..." << endl;
                        break;
                };
                break;
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