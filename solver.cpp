#include <map>
#include <iostream>

using namespace std;

map<int,pair<int,int>> solverRecursive(pair<int,pair<int,int>> actualCardPicked, map<int,pair<int,int>> remainingCards){
    int max = 0;
    map<int,pair<int,int>> cardsPickMax = {{actualCardPicked.first, actualCardPicked.second}};
    for(const auto &nextCard : remainingCards){
        if(nextCard.second.first == actualCardPicked.second.first || nextCard.second.second == actualCardPicked.second.second){
            map<int,pair<int,int>> remainingCardsNext = remainingCards;
            remainingCardsNext.erase(nextCard.first);
            map<int,pair<int,int>> bestMap = solverRecursive(nextCard, remainingCardsNext);
            if(bestMap.size() > max){
                max = bestMap.size();
                bestMap.insert(actualCardPicked);
                cardsPickMax = bestMap;
            }
        }
    }
    return cardsPickMax;
}
map<int,pair<int,int>> solver(map<int,pair<int,int>> cards){
    int max = 0;
    map<int,pair<int,int>> cardsPickMax;
    for(const auto &card : cards){
        map<int,pair<int,int>> remainingCardsNext = cards;
        remainingCardsNext.erase(card.first);
        map<int,pair<int,int>> bestEnd = solverRecursive(card , remainingCardsNext);
        if(bestEnd.size() > max){
            max = bestEnd.size();
            bestEnd.insert(card);
            cardsPickMax = bestEnd;
        }
    }
    return cardsPickMax;
}
