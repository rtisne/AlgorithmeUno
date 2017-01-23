#ifndef CARD_H
#define CARD_H
#include <sstream>

class Card
{
public:
	Card(int _color, int _number, int _id){
		color = _color;
		number = _number;
		id = _id;
		visit = false;
	}
	int getColor() const{
		return color;
	}
	int getNumber() const{
		return number;
	}
	int getId() const{
		return id;
	}
	bool getVisit() const{
		return visit;
	}
	void setVisit(bool _visit){
		visit = _visit;
	}
    std::string toString(){
        std::ostringstream oss;
        oss << "(" << color << ",";
        oss << number << ")";
  	    return oss.str();
    }
	bool operator==(Card const &c) const{
		return (this->id == c.getId());
	}
	bool operator<(Card const &c) const{
		return (this->id < c.getId());
	}
private:
	int color;
	int number;
	int id;
	bool visit;
};


#endif
