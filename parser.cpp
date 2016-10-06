#include <map>
#include <cstdlib>
#include <iostream>
#include <string> 
#include <fstream> 

using namespace std;

map<int,pair<int,int>> parserFile(char* file){
    map<int,pair<int,int>> cards;
    std::ifstream fichier(file); 
    if ( fichier )
    { 
        string ligne; 
		int color;
		int number;
		int i = 0;
		
        while ( std::getline( fichier, ligne ) ) 
        { 
			color = atoi(ligne.substr(0,1).c_str());
			number = atoi(ligne.substr(2,2).c_str());
			cards.insert(pair<int, pair<int,int>>(i,pair<int,int>(color,number)));
			i++;
        } 
    } 

    return cards;
}
