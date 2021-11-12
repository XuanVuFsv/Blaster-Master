/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102
	
	SAMPLE 02 - SPRITE AND ANIMATION

	This sample illustrates how to:

		1/ Render a sprite (within a sprite sheet)
		2/ How to manage sprites/animations in a game
		3/ Enhance CGameObject with sprite animation
================================================================ */

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "Textures.h"
#include "AutoPlayer.h"


#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"02 - Sprite animation"
#define WINDOW_ICON_PATH L"mario.ico"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(200, 200, 255)
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define MAX_FRAME_RATE 60

#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20

CAutoPlayer *autoPlayer;
#define MARIO_START_X 10.0f
#define MARIO_START_Y 130.0f
#define MARIO_START_VX 0.1f

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

/*
	Load all game resources 
	In this example: load textures, sprites, animations and autoPlayer object
*/
void LoadResources()
{
	CTextures * textures = CTextures::GetInstance();

	textures->Add(ID_TEX_MARIO, L"textures\\player.png",D3DCOLOR_XRGB(176, 224, 248));
	//textures->Add(ID_ENEMY_TEXTURE, L"textures\\enemies.png", D3DCOLOR_XRGB(156, 219, 239));
	//textures->Add(ID_TEX_MISC, L"textures\\misc.png", D3DCOLOR_XRGB(156, 219, 239));


	CSprites * sprites = CSprites::GetInstance();
	
	LPDIRECT3DTEXTURE9 texAutoPlayer = textures->Get(ID_TEX_MARIO);

	// readline => id, left, top, right 

	//sprites->Add(10001, 246, 154, 259, 181, texAutoPlayer);
	//sprites->Add(10002, 275, 154, 290, 181, texAutoPlayer);
	//sprites->Add(10003, 304, 154, 321, 181, texAutoPlayer);

	//sprites->Add(10011, 186, 154, 199, 181, texAutoPlayer);
	//sprites->Add(10012, 155, 154, 170, 181, texAutoPlayer);
	//sprites->Add(10013, 125, 154, 140, 181, texAutoPlayer);

	//Player left
	sprites->Add(10001, 209, 69, 231, 100, texAutoPlayer);
	sprites->Add(10002, 234, 69, 256, 100, texAutoPlayer);
	sprites->Add(10003, 259, 69, 281, 100, texAutoPlayer);

	//right
	sprites->Add(10011, 282, 69, 307, 100, texAutoPlayer);
	sprites->Add(10012, 308, 69, 332, 100, texAutoPlayer);
	sprites->Add(10013, 333, 69, 357, 100, texAutoPlayer);

	//down
	sprites->Add(10021, 209, 3, 231, 35, texAutoPlayer);
	sprites->Add(10022, 234, 3, 256, 35, texAutoPlayer);
	sprites->Add(10023, 259, 3, 281, 35, texAutoPlayer);

	//up
	sprites->Add(10031, 209, 36, 231, 67, texAutoPlayer);
	sprites->Add(10032, 234, 36, 256, 67, texAutoPlayer);
	sprites->Add(10033, 259, 36, 281, 67, texAutoPlayer);

	/*LPDIRECT3DTEXTURE9 texMisc = textures->Get(ID_TEX_MISC);
	sprites->Add(20001, 300, 117, 315, 132, texMisc);
	sprites->Add(20002, 318, 117, 333, 132, texMisc);
	sprites->Add(20003, 336, 117, 351, 132, texMisc);
	sprites->Add(20004, 354, 117, 369, 132, texMisc);*/
	

	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;

	ani = new CAnimation(100);
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	animations->Add(500, ani);

	ani = new CAnimation(100);
	ani->Add(10011);
	ani->Add(10012);
	ani->Add(10013);
	animations->Add(501, ani);

	ani = new CAnimation(100);
	ani->Add(10021);
	ani->Add(10022);
	ani->Add(10023);
	animations->Add(502, ani);

	ani = new CAnimation(100);
	ani->Add(10031);
	ani->Add(10032);
	ani->Add(10033);
	animations->Add(503, ani);

	/*
	ani = new CAnimation(100);
	ani->Add(20001,1000);
	ani->Add(20002);
	ani->Add(20003);
	ani->Add(20004);
	animations->Add(510, ani);
	*/
	
	autoPlayer = new CAutoPlayer(MARIO_START_X, MARIO_START_Y, MARIO_START_VX);
}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	autoPlayer->Update(dt);
}

/*
	Render a frame 
*/
void Render()
{
	CGame * game = CGame::GetInstance();
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		autoPlayer->Render();

		DebugOutTitle(L"01 - Sprite %0.1f %0.1f", autoPlayer->GetX(), autoPlayer->GetY());

		//
		// TEST SPRITE DRAW
		//

		/*
		CTextures *textures = CTextures::GetInstance();

		D3DXVECTOR3 p(20, 20, 0);
		RECT r;
		r.left = 274;
		r.top = 234;
		r.right = 292;
		r.bottom = 264;
		spriteHandler->Draw(textures->Get(ID_TEX_MARIO), &r, NULL, &p, D3DCOLOR_XRGB(255, 255, 255));
		*/

		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = (HICON)LoadImage(hInstance, WINDOW_ICON_PATH, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd)
	{
		DWORD ErrCode = GetLastError();
		DebugOut(L"[ERROR] CreateWindow failed! ErrCode: %d\nAt: %s %d \n", ErrCode, _W(__FILE__), __LINE__);
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	SetDebugWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);	
	}

	return 1;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	CGame *game = CGame::GetInstance();
	game->Init(hWnd);

	LoadResources();
	Run();

	return 0;
}