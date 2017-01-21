#include <vector>
#include <iostream>
#include "card.hpp"

using namespace std;

std::vector<Card> bruteForceRecursive(Card actualCardPicked, std::vector<Card> cards){
    int max = 0;
    std::vector<Card> cardsPickMax;
    cardsPickMax.push_back(actualCardPicked);
    for(unsigned int i = 0; i < cards.size(); i++){
        if((cards[i].getColor() == cardsPickMax.back().getColor() || cards[i].getNumber() == cardsPickMax.back().getNumber()) && cards[i].getVisit() == false){
            cards[i].setVisit(true);
            std::vector<Card> bestMap = bruteForceRecursive(cards[i], cards);
            if((int)(bestMap.size()) > max){
                max = bestMap.size();
                bestMap.push_back(cards[i]);
                cardsPickMax = bestMap;
            }
        }
    }
    return cardsPickMax;
}
std::vector<Card>  bruteForce(std::vector<Card> cards){
    int max = 0;
    std::vector<Card>  cardsPickMax;
    for(unsigned int i = 0; i < cards.size(); i++){
        std::vector<Card> remainingCardsNext;
        remainingCardsNext.push_back(cards[i]);
        cards[i].setVisit(true);
        std::vector<Card>  bestEnd = bruteForceRecursive(cards[i] , cards);
        if((int)(bestEnd.size()) > max){
            max = bestEnd.size();
            bestEnd.push_back(cards[i]);
            cardsPickMax = bestEnd;
        }
    }
    return cardsPickMax;
}
