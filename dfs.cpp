#include <vector>
#include <iostream>
#include "card.hpp"

using namespace std;

std::vector<std::vector<Card> > dfs(std::vector<Card> randomCards){
	
	std::vector<std::vector<Card> > potatoes;
	std::vector<Card> stackCards;
	for(unsigned int i = 0; i < randomCards.size(); i++){
		if(randomCards[i].getVisit() == false)
		{
			randomCards[i].setVisit(true);
			stackCards.push_back(randomCards[i]);
			bool new_card = false;
			bool first_card = true;
			while(!stackCards.empty()){
				for(unsigned int j = 0; j < randomCards.size(); j++){
					if((randomCards[j].getColor() == stackCards.back().getColor() || randomCards[j].getNumber() == stackCards.back().getNumber()) && randomCards[j].getVisit() == false){
						randomCards[j].setVisit(true);
						stackCards.push_back(randomCards[j]);
						new_card = true;
						first_card = false;
						j = 0;
					}
				}
				if(new_card == true || first_card == true){
					new_card = false;
					potatoes.push_back(stackCards);
				}
				stackCards.pop_back();
			}
		}
	}
return potatoes;
}
