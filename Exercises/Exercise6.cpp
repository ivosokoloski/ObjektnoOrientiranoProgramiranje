//Да се дефинира класа Ucesnik за учесник во маратон за кој ќе се чуваат информации за:
//име (динамички алоцирана низа од знаци)
//пол (bool)
//возраст (цел број) (5 поени).
//За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени)
//Дополнително за оваа класа да се преоптоварат:
//оператор за споредување > (споредува двајца учесници според возраста) (5 поени)
//операторот за проследување на излезен тек << кој ќе ги печати името, полот (машки/женски) и возраста, секој во посебен ред. (5 поени)
//Да се дефинира класа Maraton за кој се чуваат:
//локација (низа од максимум 100 знаци)
//низа од Ucesnik објекти (динмички алоцирана низа од објекти од класата Ucesnik)
//број на учесници (цел број) (5 поени).
//За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор.
//(10 поени) Исто така да се имплементираат следните методи:
//оператор += за додавање нов Ucesnik на маратонот Maraton. (10 поени)
//prosecnoVozrast() вреќа просечена возраст на учесниците на маратонот (5 поени)
//pecatiPomladi(Ucesnik &u) ги печати сите учесници помлади од учесникот проследен како аргумент на методот. (5 поени)

#include <iostream>
#include <cstring>
using namespace std;
class Ucesnik{
private:
    char *ime;
    bool pol;
    int vozrast;
public:

    Ucesnik(char *ime="", bool pol=true, int vozrast=0){
        this->ime= new char(strlen(ime)+1);
        strcpy(this->ime,ime);
        this->pol=pol;
        this->vozrast=vozrast;
    }
    Ucesnik(const Ucesnik &other){
        this->ime= new char(strlen(other.ime)+1);
        strcpy(this->ime,other.ime);
        this->pol=other.pol;
        this->vozrast=other.vozrast;
    }


    bool operator>(const Ucesnik &u) const{
        return u.vozrast>vozrast;
    }

    friend ostream &operator<<(ostream &os, const Ucesnik &ucesnik) {
        os<<ucesnik.ime<<endl;
        if(!ucesnik.pol){
            os<<"zensko"<<endl;
        }else{
            os<<"masko"<<endl;
        }
        os<<ucesnik.vozrast<<endl;
        return os;
    }

    int getVozrast() const {
        return vozrast;
    }

    char *getIme() const {
        return ime;
    }

    bool isPol() const {
        return pol;
    }
    friend class Maraton;

};
class Maraton{
private:
    char lokacija[100];
    Ucesnik *ucesnici;
    int broj;
    int kapacitet;
public:
    Maraton(const char* lokacija) {
        strcpy(this->lokacija, lokacija);
        broj = 0;
        kapacitet = 10; // initial capacity
        ucesnici = new Ucesnik[kapacitet];
    }

    Maraton(const Maraton& other) {
        strcpy(this->lokacija, other.lokacija);
        broj = other.broj;
        kapacitet = other.kapacitet;
        ucesnici = new Ucesnik[kapacitet];
        for (int i = 0; i < broj; i++) {
            ucesnici[i] = other.ucesnici[i];
        }
    }

    ~Maraton() {
        delete[] ucesnici;
    }

    Maraton& operator+=(const Ucesnik& u) {
        if (broj >= kapacitet) {
            kapacitet *= 2;
            Ucesnik* temp = new Ucesnik[kapacitet];
            for (int i = 0; i < broj; i++) {
                temp[i] = ucesnici[i];
            }
            delete[] ucesnici;
            ucesnici = temp;
        }
        ucesnici[broj++] = u;
        return *this;
    }
    float prosecnoVozrast(){
        float sum=0;
        for(int i=0;i<broj;i++){
            sum+=ucesnici[i].getVozrast();
        }
        return sum/broj;
    }
    void pecatiPomladi(const Ucesnik& u) const {
        for (int i = 0; i < broj; ++i) {
            if (ucesnici[i].getVozrast() < u.getVozrast()) {
                cout << ucesnici[i].getIme() << endl;
                cout<<(ucesnici[i].isPol()?"mashki":"zhenski")<<endl;
                cout<< ucesnici[i].getVozrast()<<endl;

            }
        }
    }

};
int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
    return 0;
}
