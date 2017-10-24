#include "card.h"
#include <cstdlib>

class Stack
{
private:
	Card* FirstCard;
	Card* LastCard;

public:
	Stack()
	{
		FirstCard = NULL;
		LastCard = NULL;
	}

	~Stack(){}


	void PlaceOnStack(Card* _card)
	{
		//Card becomes first on stack
		if (FirstCard == NULL)
		{
			FirstCard = _card;
			_card->SetCardUnderThis(NULL);
		}
		else
		{
			FirstCard->SetCardAboveThis(_card);
			_card->SetCardUnderThis(FirstCard);
		}
	}

	void RemoveFromStack(Card* _card)
	{
		Card* cardunder = _card->GetCardUnderThis;
		cardunder->SetCardAboveThis(NULL);
		if (_card->GetCardUnderThis == NULL)
		
		_card->SetCardUnderThis(NULL);


	}
	
	bool IsEmpty()
	{
		if (FirstCard == NULL){return (true);}
		else{return (false);}
	}
};