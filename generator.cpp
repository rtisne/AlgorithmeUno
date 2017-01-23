#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include "card.hpp"

using namespace std;

std::vector<Card> generator(int nbColor, int nbNumber, int nbCard){
    srand(time(NULL));
    std::vector<Card> randomCards;
    for(int i = 0; i < nbCard; i++)
    {
        int color = rand() % nbColor;
        int number = rand() % nbNumber;
        Card c = Card(color,number,i);
        randomCards.push_back(c);
    }

    return randomCards;
}
