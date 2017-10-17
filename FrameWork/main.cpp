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

//Library Includes
#include <windows.h>
#include <windowsx.h>

//Local Includes
#include "Game.h"
#include "Clock.h"
#include "utils.h"

#define WINDOW_CLASS_NAME L"BSENGGFRAMEWORK"

LRESULT CALLBACK
WindowProc(HWND _hWnd, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam)
{
	static POINT mouseCoords = {100, 100};
	static int mouseX = 0;
	static int mouseY = 0;

	static bool bDragging = false;
    switch (_uiMsg)
    {
		case WM_LBUTTONDOWN:
		{
//			MessageBox(_hWnd, L"AYYLMAO", NULL, MB_HELP);
			bDragging = true;
		}
		break;
		case WM_LBUTTONUP:
		{
			bDragging = false;
		}
		break;
		case WM_MOUSEMOVE:
		{
			if (bDragging)
			{
				mouseX = static_cast<int>(LOWORD(_lParam));
				mouseY = static_cast<int>(HIWORD(_lParam));

				CGame::GetInstance().GetMouseX(&mouseX);
				CGame::GetInstance().GetMouseY(&mouseY);
			}	
		}
		break;
        case WM_DESTROY:
        {
            PostQuitMessage(0);

            return(0);
        }
        break;

        default:break;
    } 

    return (DefWindowProc(_hWnd, _uiMsg, _wParam, _lParam));
}

HWND 
CreateAndRegisterWindow(HINSTANCE _hInstance, int _iWidth, int _iHeight, LPCWSTR _pcTitle)
{
    WNDCLASSEX winclass;

    winclass.cbSize = sizeof(WNDCLASSEX);
    winclass.style = CS_HREDRAW | CS_VREDRAW;
    winclass.lpfnWndProc = WindowProc;
    winclass.cbClsExtra = 0;
    winclass.cbWndExtra = 0;
    winclass.hInstance = _hInstance;
    winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    winclass.hbrBackground = static_cast<HBRUSH> (GetStockObject(NULL_BRUSH));
    winclass.lpszMenuName = NULL;
    winclass.lpszClassName = WINDOW_CLASS_NAME;
    winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&winclass))
    {
        // Failed to register.
        return (0);
    }

    HWND hwnd; 
    hwnd = CreateWindowEx(NULL,
                  WINDOW_CLASS_NAME,
                  _pcTitle,
              WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, 
                  CW_USEDEFAULT, CW_USEDEFAULT,
                  _iWidth, _iHeight,
                  NULL,
                  NULL,
                  _hInstance,
                  NULL);
    
    if (!hwnd)
    {
        // Failed to create.
        return (0);
    }

    return (hwnd);
}

int WINAPI
WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdline, int _iCmdshow)
{
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));

    const int kiWidth = 400;
    const int kiHeight = 400;

    HWND hwnd = CreateAndRegisterWindow(_hInstance, kiWidth, kiHeight, L"BSENGG Framework");

    CGame& rGame = CGame::GetInstance();

    if (!rGame.Initialise(_hInstance, hwnd, kiWidth, kiHeight))
    {
        // Failed
        return (0);
    }

    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            rGame.ExecuteOneFrame();
        }
    }

    CGame::DestroyInstance();

    return (static_cast<int>(msg.wParam));
}
