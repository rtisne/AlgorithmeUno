#include <map>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

map<int,pair<int,int>> generator(int nbColor, int nbNumber, int nbCard){
    srand(time(NULL));
    map<int,pair<int,int>> cards;
    for(int i = 0; i < nbCard; i++)
    {
        int color = rand() % nbColor;
        int number = rand() % nbNumber;
        cards.insert(pair<int, pair<int,int>>(i,pair<int,int>(color,number)));
    }

    return cards;
}
