//Да се креира структура Engine во која што ќе се чуваат податоци за коњска сила / horsepower (int) и вртежен момент / torque (int).
//Потоа, да се креира структура Car во која што ќе  се чуваат податоци името на производителот (char array) ,
//        која година е произведена колата (int) и кој мотор / engine (Engine) која што го користи/
//На почетокот се внесува број N што озналува колку коли ќе се читаат од влез.
//Да се направи функцијата:
//void printCars(...)
//која што ќе ги земе двете коли кои имаат најмала коњска сила, и од нив две, ќе ја испечати колата што има поголем вртежен момент.
//___________________________________
//        Create an Engine structure that will store horsepower (int) and torque (int) data.
//Then, create a structure Car in which the data of the manufacturer's name (char array), which year the car was manufactured
//(int) and which engine (Engine) that uses it/ will be stored.
//At the beginning, a number N is entered that indicates how many cars will be read from the input.
//Then, make the function:
//void cars to print (...)
//which will take as argument the two cars that have the lowest horsepower, and of those two, it will print the car that has the torque printed.

#include <iostream>
using namespace std;
struct Engine{
    int horsepower;
    int torque;
};
struct car{
    char name[100];
    int year;
    Engine engine;

    void readcars(){
        cin>>name>>year>>engine.horsepower>>engine.torque;
    }
    void printcar(){
        cout<<"Manufacturer: "<<name<<endl;
        cout<<"Horsepower: "<<engine.horsepower<<endl;
        cout<<"Torque: "<<engine.torque;

    }
};

void lowest(car cars[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(cars[j].engine.horsepower>cars[j+1].engine.horsepower){
                car tmp=cars[j];
                cars[j]=cars[j+1];
                cars[j+1]=tmp;
            }
        }
    }

    if(cars[0].engine.torque>cars[1].engine.torque){
        cars[0].printcar();
    }else{
        cars[1].printcar();
    }
}

int main(){

    car cars[100];
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        cars[i].readcars();
    }
    lowest(cars,size);

}