#include "generator.cpp"
#include "bruteForce.cpp"
#include "card.hpp"
#include "dfs.cpp"

using namespace std;

bool getIntersectCard(Card c1, Card c2){

  if(c1.getColor() == c2.getColor() && c1.getNumber() == c2.getNumber()){
    return true;
  }
  return false;
}
int main (int argc, char *argv[]){
   std::vector<Card> cards = generator(4,13,10);
   std::vector<Card> brute = bruteForce(cards);
   std::vector<std::vector<Card> > dfs_patate = dfs(cards);
   cout << " <<<<<< Generator >>>>>>" << endl;
    for(unsigned int i = 0 ; i < cards.size();i++){
    	cout << " Color : " << cards[i].getColor() << " / Number : " << cards[i].getNumber() << endl;
    }
   cout << "<<<<<<< Brute Force >>>>>>" << endl;
  for(unsigned int i = 0 ; i < brute.size();i++){
      cout << " Color : " << brute[i].getColor() << " / Number : " << brute[i].getNumber() << endl;
    }
   cout << " <<<<<< DFS >>>>>>" << endl;
    for(unsigned int v = 0; v < dfs_patate.size(); v++)
    {
      cout << "Patate " << v << ":" << endl;
      for(unsigned int i = 0; i < dfs_patate[v].size(); i++)
      {
        cout << " Color : " << dfs_patate[v][i].getColor() << " / Number : " << dfs_patate[v][i].getNumber() << endl;
      }
    }
}
