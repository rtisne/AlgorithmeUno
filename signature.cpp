#include <vector>
#include <algorithm>
#include <iterator> 
#include <string>
#include <iostream>
#include "card.hpp"



void signatureCalculator(std::vector<Card> cards,std::vector<Card> result, Card card);


struct Signature {
	std::vector<Card> card;
	std::vector<Card> use;
	string type;
	int size;
	
	Signature(std::vector<Card> c, std::vector<Card> u, string t, int s): card(c),use(u),type(t),size(s){}
};

std::vector<Signature> listSignature;
std::vector<std::vector<Card> > signaturesResult;
void calculSign(vector<Card> result, vector<Card> intersec);
bool equalSignature(Signature s1,std::vector<Card> v1, std::vector<Card> v2, string t);


std::vector<Card> intersection (std::vector<Card> p1, std::vector<Card> p2){
	std::vector<Card> tmp;
	
	set_intersection(p1.begin(),p1.end(),p2.begin(),p2.end(),back_inserter(tmp));

   return tmp;
}

void signature(std::vector<Card> p1,std::vector<Card> p2){
	signaturesResult.clear();
	std::vector<Card> intersec = intersection(p1,p2);
	for(unsigned int i = 0; i < p2.size(); i++){
		std::vector<Card> tmp = p2;
		tmp.erase(tmp.begin() + i);
		std::vector<Card> result;
		result.push_back(p2.at(i));
		signatureCalculator(tmp,result, p2.at(i));
	}
	for(unsigned int i = 0; i < signaturesResult.size(); i++){
		calculSign(signaturesResult.at(i), intersec);
	} 
}

void signatureCalculator(std::vector<Card> cards,std::vector<Card> result, Card card){
	if(!cards.empty()){
		for(unsigned int i = 0 ; i < cards.size(); i++){
			if(cards[i].getColor() == card.getColor() || cards[i].getNumber() == card.getNumber()){
				std::vector<Card> tmp = cards;
				tmp.erase(tmp.begin() + i);
				std::vector<Card> nextResult = result;
				nextResult.push_back(cards.at(i));
				signatureCalculator(tmp, nextResult, cards.at(i));
			}
		}
	}
	signaturesResult.push_back(result);
}

bool equalSignature(Signature s1,std::vector<Card> v1, std::vector<Card> v2, string t){
	return(s1.card == v1 && s1.use == v2 && s1.type == t);
}

void calculSign(std::vector<Card> result, std::vector<Card> intersec){
	string type;
	vector<Card> lis;
	vector<Card> used;
	Card first = result.front();
	Card last = result.back();
	if(find(intersec.begin(), intersec.end(), first) != intersec.end() && find(intersec.begin(), intersec.end(), last) != intersec.end()){
		type = "A";
		lis.push_back(first);
		lis.push_back(last);
		for(unsigned int i = 0; i < result.size(); i++){
			if(find(intersec.begin(), intersec.end(), result.at(i)) != intersec.end() && !(find(lis.begin(),lis.end(),result.at(i)) != lis.end())) {
				used.push_back(result.at(i));
				}
			}
		}
	else if(find(intersec.begin(), intersec.end(),first) != intersec.end()) {
		type = "B";
		lis.push_back(first);
		for(unsigned int i = 0; i < result.size(); i++){
			if(find(intersec.begin(), intersec.end(), result.at(i)) != intersec.end() && !(find(lis.begin(),lis.end(),result.at(i)) != lis.end())) {
				used.push_back(result.at(i));
			}
		}
	}
	
	bool found = false;
	for(unsigned int i = 0; i < listSignature.size(); i++){
		if(equalSignature(listSignature[i],lis,used,type)){
			if(listSignature[i].size < (int)result.size()) {
				listSignature[i].size = result.size();
			}
			found = true;
		}
	}
	 if(!found && result.size() > 1){
		listSignature.push_back(Signature(lis,used,type,result.size()));
	 }
}

