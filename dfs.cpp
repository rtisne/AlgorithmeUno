#include <vector>
#include <iostream>
#include <stack>
#include "card.hpp"

using namespace std;

std::vector<stack<Card> > dfs(std::vector<Card> randomCards){
	
	std::vector<stack<Card> > potatoes;
	std::stack<Card> stackCards;
	srand(time(NULL));
    int random = rand() % randomCards.size();
	//for(unsigned int i = 0; i < randomCards.size(); i++){
		randomCards[random].setVisit(true);
		stackCards.push(randomCards[random]);
		while(!stackCards.empty()){
			for(unsigned int j = 0; j < randomCards.size(); j++){
				if((randomCards[j].getColor() == stackCards.top().getColor() || randomCards[j].getNumber() == stackCards.top().getNumber()) && randomCards[j].getVisit() == false){
					randomCards[j].setVisit(true);
					stackCards.push(randomCards[j]);
					j = 0;
				}
			}
			potatoes.push_back(stackCards);
			stackCards.pop();
		}
	//}
return potatoes;
}
