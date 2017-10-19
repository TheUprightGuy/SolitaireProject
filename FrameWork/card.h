#ifndef __CARD_H__

#include <Windows.h>
#include "sprite.h"

class CCard : public CSprite
{
public:
	CCard() {  }
	~CCard() {  }

	void SetCardNum(int _iCardNum) { m_iCardNum = _iCardNum; }
	int GetCardNum() { return m_iCardNum; }

private:
	int m_iCardNum;
	//Enum for suits
	bool FaceUp;
};

#endif // !__CARD_H__

