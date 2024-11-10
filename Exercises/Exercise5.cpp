//Да се креира структура Воз во која се чуваат податоци за релацијата по која се движи возот (низа од најмногу 50 знаци),
// предвиден бројот на километри што треба да се поминат (реален број), како и бројот на патници во возот (цел број).
//Потоа да се креирa структура ZeleznickaStanica во која се чуваат податоци за градот во кој се наоѓа (низа од 20 знаци),
// низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).
//Треба да се направи функција со потпис
//void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)
//во која се печати релацијата и бројот на километри на возот што поминува најкратка релација (најмалку километри), а поаѓа од железничката станица од градот што се проследува како влезен аргумент. Ако има повеќе возови со ист најмал број на километри, да се испечати релацијата на последниот таков.
//Забелешка: Задачата да се реши во програмскиот јазик C++


#include<iostream>
#include <cstring>
using namespace std;
struct Voz{
    char relacij[100];
    float km;
    int patnici;
};
struct ZeleznickaStanica{
    char grad[100];
    Voz vozovi[100];
    int n;

};
void najkratkaRelacija(ZeleznickaStanica* zs, int n, char *grad) {
    float min=1000000;
    int z=0;
    int k=0;
    for(int i=0;i<n;i++){
        if (strcmp(zs[i].grad, grad) == 0){
            for(int j=0;j<zs[i].n;j++) {
                if (min >= zs[i].vozovi[j].km) {
                    min = zs[i].vozovi[j].km;
                    z=i;
                    k=j;

                }
            }
            break;
        }
    }

    cout << "Najkratka relacija: " <<zs[z].vozovi[k].relacij <<" (" << min << " km) ";
}




int main() {

    int n;
    cin >> n;

    ZeleznickaStanica zStanica[100];
    for (int i = 0; i < n; i++) {
        cin >> zStanica[i].grad;
        cin >> zStanica[i].n;
        for (int j = 0; j < zStanica[i].n; j++) {
            cin >> zStanica[i].vozovi[j].relacij >> zStanica[i].vozovi[j].km >> zStanica[i].vozovi[j].patnici;
        }
    }

    char grad[100];
    cin >> grad;

    najkratkaRelacija(zStanica, n, grad);
    return 0;
}
