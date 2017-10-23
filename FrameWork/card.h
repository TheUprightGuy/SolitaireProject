#include <cstdlib>

class Card
{
private:
	int Number; // 1-10, 11-14 = Jack Queen King Ace
	int Suit; //1 = Hearts, 2 = Diamonds, 3 = Clubs, 4 = Diamonds
	
	Card* CardAbove; // Card above this card
	Card* CardUnder; // Card underneath this card


public:
	Card()
	{
		Number = 0;
		Suit = 0;

		CardAbove = NULL;
		CardUnder = NULL;
	}

	~Card(){}

	int GetNumber(){return(Number)}
	void SetNumber(int _number){Number = _number;}

	int GetSuit(){return(Suit);}
	void SetSuit(int _suit){Suit = _suit;}

	Card* GetCardAbove(){return(CardAbove);}
	void SetCardAbove(Card* _CardAbove) { CardAbove = _CardAbove; }
	
	Card* GetCardUnder(){return(CardUnder);}
	void SetCardUnder(Card* _CardUnder) { CardUnder = _CardUnder; }





};