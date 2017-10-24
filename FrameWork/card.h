#ifndef __CARD_H__
#define __CARD_H__

#endif // !__CARD_H

#include <cstdlib>
#include "sprite.h"

class Card : CSprite
{
private:
	int Number; // 1-10, 11-14 = Jack Queen King Ace
	int Suit; //1 = Hearts, 2 = Diamonds, 3 = Clubs, 4 = Diamonds
	bool FaceUp;
	
	Card* CardAboveThis; // Card above this card
	Card* CardUnderThis; // Card underneath this card
	
	bool Faceup;

public:
	Card()
	{
		Number = 0;
		Suit = 0;

		CardAboveThis = NULL;
		CardUnderThis = NULL;

		Faceup = false;
	}

	~Card(){}

	int GetNumber() { return(Number); }
	void SetNumber(int _number){Number = _number;}

	int GetSuit(){return(Suit);}
	void SetSuit(int _suit){Suit = _suit;}

	Card* GetCardAboveThis(){return(CardAboveThis);}
	void SetCardAbove(Card* _CardAboveThis) { CardAboveThis = _CardAboveThis; }
	
	Card* GetCardUnderThis(){return(CardUnderThis);}
	void SetCardUnderThis(Card* _CardUnderThis) { CardUnderThis = _CardUnderThis; }

	bool GetFaceup() { return(Faceup); }
	void SetFaceup(bool _Faceup) { Faceup = _Faceup; }



};