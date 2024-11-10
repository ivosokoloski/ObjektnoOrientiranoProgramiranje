//Да се напише класа Chocolate која ги содржи следните податоци за еден чоколаден производ:
//name - име на чоколадото, низа од најмногу 100 знаци;
//price - стандардна малопродажна цена на еден пакет од чоколадите
//За класата да се напишат default конструктор и конструктор со параметри.
//Да се преоптовари операторот << за да ги печати објектите од класата во следниот формат: [name]: $[price].
//Потоа да се дефинира класата ChocolateFactory, која ги содржи следните податоци за фабрика за чоколадо:
//products - динамички алоцирана низа од Chocolate објекти
//weeklyProduction - динамички алоцирана низа од цели броеви, така што weeklyProduction[i] означува колку пакети од products[i] фабриката произведува неделно
//        numProducts - број на типови чоколади кои фабриката ги нуди.
//За класата да се дефинираат конструктор со параметри, деструктор, како и следните методи:
//weeklyIncome() која ја пресметува вкупната вредност на чоколадите кои фабриката ги произведува неделно
//оператори < и > за споредба на две фабрики според неделната заработка
//        оператор + кој како резултат дава нова фабрика со комбинираното производство на двете фабрики
//оператор << за печатење на објектот во следниот формат:
//[product0] x [weeklyProduction0]
//[product1] x [weeklyProduction2]
//...
//[productN] x [weeklyProductionN]
//$[weeklyIncome]/wk
//Write a class Chocolate that contains the following data for a chocolate bar:
//name - the name of the chocolate, a string of up to 100 characters;
//price - the standard retail price of a package of chocolates
//        To the class, write a default constructor and a parameterized constructor. Overload the << operator to print objects from the class in the following format: [name]: $[price].
//Then define the class ChocolateFactory, which contains the following data for a chocolate factory:
//products - a dynamically allocated array of Chocolate objects
//        weeklyProduction - a dynamically allocated array of integers, where weeklyProduction[i] indicates how many packages of products[i] the factory produces weekly
//numProducts - the number of types of chocolates the factory offers.
//For the class, define a parameterized constructor, destructor, as well as the following methods:
//weeklyIncome() which calculates the total value of chocolates the factory produces weekly
//        operators < and > for comparing two factories based on weekly earnings
//        operator + which results in a new factory with combined production of the two factories
//operator << for printing the object in the following format:
//[product0] x [weeklyProduction0]
//[product1] x [weeklyProduction2]
//
//[productN] x [weeklyProductionN]
//
//$[weeklyIncome]/wk
//


#include<iostream>
#include<cstring>
using namespace std;
class Chocolate{
private:
    char name[100];
    int price;
public:
    Chocolate(char *name="", int price=0) {
        strcpy(this->name, name);
        this->price = price;
    }

    friend ostream &operator<<(ostream &os, const Chocolate &chocolate) {
        os << chocolate.name << ": $" << chocolate.price;
        return os;
    }

    friend class ChocolateFactory;

};
class ChocolateFactory{
private:
    Chocolate *products;
    int *weeklyProduction;
    int numProducts;
public:
    ChocolateFactory(Chocolate *products, int *weeklyProduction, int numProducts){
        this->products=new Chocolate[numProducts];
        this->weeklyProduction=new int[numProducts];
        for(int i=0;i<numProducts;i++){
            this->products[i]=products[i];
            this->weeklyProduction[i]=weeklyProduction[i];
        }

        this->numProducts=numProducts;
    }

    ~ChocolateFactory() {

    }

    int weeklyIncome()const{
        float sum=0;
        for(int i=0;i<numProducts;i++){
            sum+=products[i].price*weeklyProduction[i];
        }
        return sum;
    }
    bool operator<(const ChocolateFactory& C){
        return this->weeklyIncome()<C.weeklyIncome();
    }
    bool operator>(ChocolateFactory C){
        return !(*this<C);
    }
    ChocolateFactory operator+(ChocolateFactory  &C) {
        ChocolateFactory Cho (products,weeklyProduction,numProducts+C.numProducts);
        for (int i = numProducts; i < numProducts + C.numProducts; ++i) {
            Cho.products[i] = C.products[i-C.numProducts];
            Cho.weeklyProduction[i] = C.weeklyProduction[i-C.numProducts];
        }
        return Cho;
    }

    friend ostream &operator<<(ostream &os,const ChocolateFactory &factory) {
        for (int i = 0; i < factory.numProducts; ++i) {
            os<<factory.products[i]<<" x "<<factory.weeklyProduction[i]<<endl;
        }
        os<<"$"<<factory.weeklyIncome()<<"/wk"<<endl;
        return os;

    }


};

int main() {
    int testCase;
    char name[100];
    int price;

    Chocolate products[100];
    int weeklyProduction[100];

    cin >> testCase;
    if (testCase == 0) {
        cout<<"Testing Chocolate print operator:"<<endl;
        for (int i = 0; i < 10; ++i) {
            cin>>name>>price;
            cout<<Chocolate(name,price)<<endl;
        }
    }
    else if (testCase == 1) {
        cout<<"Testing ChocolateFactory print operator:"<<endl;

        for (int i = 0; i < 10; ++i) {
            cin>>name>>price;
            products[i] = Chocolate(name, price);
            cin>>weeklyProduction[i];
        }

        ChocolateFactory cf(products,weeklyProduction,10);
        cout<<cf<<endl;
    }
    else if (testCase == 2) {
        cout<<"Testing ChocolateFactory comparison operators:"<<endl;

        for (int i = 0; i < 3; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf1 = ChocolateFactory(products,weeklyProduction,3);

        for (int i = 0; i < 4; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf2 = ChocolateFactory(products,weeklyProduction,4);

        cout<<cf1<<cf2;

        cout<<"< operator: "<< (cf1<cf2 ? "PASS" : "FAIL") <<endl;
        cout<<"> operator: "<< (cf2>cf1 ? "PASS" : "FAIL") <<endl;
    }
    else if (testCase == 3) {
        cout<<"Testing ChocolateFactory sum operator:"<<endl;

        for (int i = 0; i < 5; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf1 = ChocolateFactory(products,weeklyProduction,5);
        for (int i = 0; i < 5; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf2 = ChocolateFactory(products,weeklyProduction,5);

        cout<<cf1+cf2;
    }
}