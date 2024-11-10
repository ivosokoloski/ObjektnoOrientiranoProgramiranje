//Да се напише програма во која од стандарден влез се внесува бројот N (бројот на трансакции), а потоа N трансакциски сметки и како резултат ги печати идентификацискиот број и вкупната сума (со провизија) на сите трансакции платени со кредитна картичка. Во случај да нема трансакција платена со кредитна картичка да се испечати "No credit card transaction".
//
//Во структурата Трансакција (Transaction) треба да се чуваат следните информации:
//- Идентификациски број (int)
//- Платена сума (int)
//- Провизија (int)
//- Дали е платено со дебитна или кредитна картичка (0 - дебитна, 1 - кредитна)
//
//Ограничување: 0 < N < 100
//
//Write a program which from standard input receives the integer N (Number of transactions), followed by information about N transactions, and outputs the identification number and total sum (with commission) of all the transactions paid with a credit card. In edge cases where there are no transactions which have been paid with a credit card, output "No credit card transaction".
//
//________________________________________________________________
//
//        The structure Transaction must have the following information:
//
//- Identification number (int)
//
//- Paid amount (int)
//
//- Commission (int)
//
//- Was the transaction paid with a debit or credit card (0 - debit, 1 - credit)
//
//
//
//Input limit: 0 < N < 100
//
//
//
//Input format:
//
//N
//
//        id1 sum1 commission1 type1
//
//        ...
//
//        idn sumn Commissionn typen
//
//        Структура на влезните податоци:
//N
//        id1 sum1 commission1 type1
//        ...
//        idn sumn Commissionn typen



#include <iostream>
using namespace std;
enum T{
    debit=0,credit=1
};
struct transaction{
    int idnumber;
    int paid;
    int commision;
    T type;
    int sum;





};
void printt(transaction transactions[],int size,int type[]){
    for(int i=0;i<size;i++){
        int sum=0;
        sum=transactions[i].paid+transactions[i].commision;
        if(type[i]==1){
            cout<<transactions[i].idnumber<<" "<<sum<<endl;
        }
    }
    for(int i=0;i<size;i++){
        if(type[i]==1){
            return;
        }
    }
    cout<<"No credit card transaction";
}

int main(){
    transaction transactions[100];
    int size;
    cin>>size;
    int debit=0;
    int credit=1;
    int type[100];
    for(int i=0;i<size;i++){
        cin>>transactions[i].idnumber>>transactions[i].paid>>transactions[i].commision>>type[i];
    }
    printt(transactions,size,type);

}