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

	void Push(Card& _card)
	{

	}

	void Pop(Card& _card)
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