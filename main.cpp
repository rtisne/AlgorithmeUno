#include <iostream>
#include <map>
#include "generator.cpp"
#include "solver.cpp"
#include "parser.cpp"

using namespace std;
int main (int argc, char *argv[]){
	parserFile(argv[1]);
    map<int,pair<int,int>> cards = generator(200,200,20);
    
    for (const auto &card : cards)
        cout << "Id Card : " << card.first << " / Color : " << card.second.first << " / Number : " << card.second.second << endl;

    map<int,pair<int,int>> bestMap = solver(cards);

    cout << "Best Map Count : " << bestMap.size() << endl;
    for (const auto &card : bestMap)
        cout << "Id Card : " << card.first << " / Color : " << card.second.first << " / Number : " << card.second.second << endl;
}
