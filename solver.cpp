#include <tr1/unordered_map>
#include <iostream>
#include <map>

using namespace std;

unordered_map<int,pair<int,int>> solverRecursive(pair<int,pair<int,int>> actualCardPicked, unordered_map<int,pair<int,int>> remainingCards){
    int max = 0;
    unordered_map<int,pair<int,int>> cardsPickMax = {{actualCardPicked.first, actualCardPicked.second}};
    for(const auto &nextCard : remainingCards){
        if(nextCard.second.first == actualCardPicked.second.first || nextCard.second.second == actualCardPicked.second.second){
            map<int,pair<int,int>> remainingCardsNext = remainingCards;
            remainingCardsNext.erase(nextCard.first);
            unordered_map<int,pair<int,int>> bestMap = solverRecursive(nextCard, remainingCardsNext);
            if(bestMap.size() > max){
                max = bestMap.size();
                bestMap.insert(actualCardPicked);
                cardsPickMax = bestMap;
            }
        }
    }
    return cardsPickMax;
}
unordered_map<int,pair<int,int>> solver(unordered_map<int,pair<int,int>> cards){
    int max = 0;
    unordered_map<int,pair<int,int>> cardsPickMax;
    for(const auto &card : cards){
        unordered_map<int,pair<int,int>> remainingCardsNext = cards;
        remainingCardsNext.erase(card.first);
        unordered_map<int,pair<int,int>> bestEnd = solverRecursive(card , remainingCardsNext);
        if(bestEnd.size() > max){
            max = bestEnd.size();
            bestEnd.insert(card);
            cardsPickMax = bestEnd;
        }
    }
    return cardsPickMax;
}
