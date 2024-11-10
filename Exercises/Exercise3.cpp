//Да се напише програма во која од стандарден влез се внесува бројот N (бројот на фудбалски тимови) и информациите за N-те фудбалски тимови.
//Една структура за Фудбалски тим (FootballTeam) треба да ги чува следните информации:
//- Името на тимот (низа од карактери)
//- Низа од играчи (претставени преку структурата FootballPlayer, при што еден тим секогаш ќе има 11 играчи)
//Во структурата Фудбалски играч (FootballPlayer) треба да се чуваат следните информации:
//- Името на играчот (низа од карактери)
//- Број на дресот (int)
//- Број на дадени голови (int)
//Ограничување: 0 < N < 100
//Ваша задача е да направите функција void bestTeam(FootballTeam * teams, int n) која ќе го печати тимот со
//најмногу дадени голови (во случај да има повеќе тима со ист број на голови треба да се печати првиот што е внесен).
//
//_______________________________
//Write a program in which the number N (the number of football teams) and the information about the N football teams are entered from standard input.
//A structure for FootballTeam should store the following information:
//- Team name (character string)
//- Array of players (represented via the FootballPlayer structure, where a team will always have 11 players)
//The following information should be stored in the FootballPlayer structure:
//- Player name (character string)
//- Jersey number (int)
//- Number of goals scored (int)
//Limit: 0 < N < 100
//Your task is to make a function void bestTeam(FootballTeam * teams, int n) that will print the team with the most given goals
//(in case there are more teams with the same number of goals, the first entered should be printed).
//
//
//


#include <iostream>
using namespace std;
struct player{
    char name[100];
    int number;
    int goals;
};
struct team{
    char name[100];
    player p;

};
void best(team teams[], int size, int goalss[]){
    team besst=teams[0];
    int max=goalss[0];
    for(int i=0;i<size;i++){
        if(max<goalss[i]){
            max=goalss[i];
            besst=teams[i];
        }
    }
    cout<<"Najdobar tim e: "<<besst.name;

}


int main(){
    team teams[100];
    int size;
    cin>>size;
    int goalss[100]{0};
    for(int i=0;i<size;i++){
        cin>>teams[i].name;
        for(int j=0;j<11;j++){
            cin>>teams[i].p.name>>teams[i].p.number>>teams[i].p.goals;
            goalss[i]+=teams[i].p.goals;
        }
    }
    best(teams,size,goalss);
}