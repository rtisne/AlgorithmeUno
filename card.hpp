#ifndef CARD_H
#define CARD_H
  
class Card 
{ 
public:
	Card(int _color, int _number){
		color = _color;
		number = _number;
		visit = false;
	}
	int getColor() const{
		return color;
	}
	int getNumber() const{
		return number;
	}
	bool getVisit() const{
		return visit;
	}
	void setVisit(bool _visit){
		visit = _visit;
	}
private:
	int color;
	int number;
	bool visit;
}; 


#endif
