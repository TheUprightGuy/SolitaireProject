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
			_card->SetCardUnderThis(FirstCard);
		}
	}

	void RemoveFromStack(Card* _card)
	{

	}
	
	bool IsEmpty()
	{
		if (FirstCard == NULL)
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
};