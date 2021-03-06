//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//

#if !defined(__GAME_H__)
#define __GAME_H__

// Library Includes
#include <windows.h>

// Local Includes
#include "clock.h"

// Types

// Constants

// Prototypes
class CBackBuffer;

class CGame
{
    // Member Functions
public:
    ~CGame();

    bool Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight);

    void Draw();
    void Process(float _fDeltaTick);

    void ExecuteOneFrame();

    CBackBuffer* GetBackBuffer();
    HINSTANCE GetAppInstance();
    HWND GetWindow();

    // Singleton Methods
    static CGame& GetInstance();
    static void DestroyInstance();


	void GetMouse(POINT* _point) { m_mouseCoords = _point; };
	void SetMouseX(int* _iX) { m_mouseX = _iX; }
	void SetMouseY(int* _iY) { m_mouseY = _iY; }

	void GetInput(int iButton);
protected:

private:
    CGame();
    CGame(const CGame& _kr);
    CGame& operator= (const CGame& _kr);

    // Member Variables
	POINT* m_mouseCoords;
	int * m_mouseX;
	int * m_mouseY;

public:

protected:
    CClock* m_pClock;

    CBackBuffer* m_pBackBuffer;

    //Application data
    HINSTANCE m_hApplicationInstance;
    HWND m_hMainWindow;

    // Singleton Instance
    static CGame* s_pGame;

private:

};

#endif    // __GAME_H__
