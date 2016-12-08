#include "generator.cpp"
#include "card.hpp"
#include "dfs.cpp"

using namespace std;


int main (int argc, char *argv[]){
   std::vector<Card> cards = generator(4,13,10);
   std::vector<stack<Card> > test = dfs(cards);
    for(unsigned int i = 0 ; i < cards.size();i++){
    	cout << " Color : " << cards[i].getColor() << " / Number : " << cards[i].getNumber() << endl;
    }
    // for (const auto &card : cards)
    //     cout << "Id Card : " << card.first << " / Color : " << card.second.color << " / Number : " << card.second.number << endl;

  //  unordered_map<int,pair<int,int>> bestMap = dfs(cards);

 //   cout << "Best Map Count : " << bestMap.size() << endl;
  //  for (const auto &card : bestMap)
   //     cout << "Id Card : " << card.first << " / Color : " << card.second.first << " / Number : " << card.second.second << endl;
}
