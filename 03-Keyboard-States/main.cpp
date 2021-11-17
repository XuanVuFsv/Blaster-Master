/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102
	
	SAMPLE 03 - KEYBOARD AND OBJECT STATE

	This sample illustrates how to:

		1/ Process keyboard input
		2/ Control object state with keyboard events
================================================================ */

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Textures.h"

#include "SceneGame.h"

#include "Player.h"
#include "Turtle.h"

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"02 - Sprite animation"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(200, 200, 255)
#define SCREEN_WIDTH 528
#define SCREEN_HEIGHT 480

#define MAX_FRAME_RATE 90

#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20

CGame *game;
CPlayer *player;
SceneManager* _sceneManager;

class CSampleKeyHander: public CKeyEventHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};

CSampleKeyHander * keyHandler; 

void CSampleKeyHander::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_SPACE:
		player->SetPlayerMovement(State::JUMP, 0);
		break;
	}
}

void CSampleKeyHander::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
}

void CSampleKeyHander::KeyState(BYTE *states)
{
	if (game->IsKeyDown(DIK_RIGHT))
		player->SetPlayerMovement(State::WALK, Direction::RIGHT);
	else if (game->IsKeyDown(DIK_LEFT))
		player->SetPlayerMovement(State::WALK, Direction::LEFT);
	else if (game->IsKeyDown(DIK_UP))
		player->SetPlayerMovement(State::WALK, Direction::UP);
	else if (game->IsKeyDown(DIK_DOWN))
		player->SetPlayerMovement(State::WALK, Direction::DOWN);
	else player->SetPlayerMovement(State::IDLE, 0);
}

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
	In this example: load textures, sprites, animations and player object
*/
void LoadResources()
{
	CTextures * textures = CTextures::GetInstance();

	textures->Add(ID_TEX_MARIO, L"textures\\player.png", D3DCOLOR_XRGB(0, 57, 115));
	textures->Add(ID_TEX_ENEMY, L"textures\\enemy.png", D3DCOLOR_XRGB(0, 57, 115));

	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	
	LPDIRECT3DTEXTURE9 texPlayer = textures->Get(ID_TEX_MARIO);
	LPDIRECT3DTEXTURE9 texTurtle = textures->Get(ID_TEX_ENEMY);


#pragma region Init Player Animation
	//Player left
	sprites->Add(10001, 209, 69, 231, 100, texPlayer);
	sprites->Add(10002, 234, 69, 256, 100, texPlayer);
	sprites->Add(10003, 259, 69, 281, 100, texPlayer);

	//right
	sprites->Add(10011, 283, 69, 306, 100, texPlayer);
	sprites->Add(10012, 309, 69, 331, 100, texPlayer);
	sprites->Add(10013, 334, 69, 356, 100, texPlayer);

	//down
	sprites->Add(10021, 209, 4, 231, 35, texPlayer);
	sprites->Add(10022, 234, 4, 256, 35, texPlayer);
	sprites->Add(10023, 259, 4, 281, 35, texPlayer);

	//up
	sprites->Add(10031, 208, 37, 231, 67, texPlayer);
	sprites->Add(10032, 233, 37, 256, 67, texPlayer);
	sprites->Add(10033, 258, 37, 281, 67, texPlayer);

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

	player = new CPlayer();
	_sceneManager->InitGame(player);

	CPlayer::AddAnimation(500);		// left
	CPlayer::AddAnimation(501);		// right
	CPlayer::AddAnimation(502);		// down
	CPlayer::AddAnimation(503);		// up

	player->SetPosition(0.0f, 100.0f);

#pragma endregion

#pragma region Enemyanimation

	sprites->Add(20001, 84, 1150, 101, 1166, texTurtle);
	sprites->Add(20002, 104, 1151, 121, 1166, texTurtle);
	sprites->Add(20003, 132, 1151, 149, 1166, texTurtle);

	LPANIMATION turtlAni;

	turtlAni = new CAnimation(100);
	turtlAni->Add(20001);
	turtlAni->Add(20002);
	turtlAni->Add(20003);
	animations->Add(601, turtlAni);
	CTurtle::AddAnimation(601);

#pragma endregion
	//for (int i = 0; i < 5; i++)
	//{
	//	CTurtle* turtle;
	//	turtle = new CTurtle();

	//	turtle->SetPosition(100.0f, 100.0f);
	//	CTurtle::AddTurtle(turtle);
	//}

}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	_sceneManager->Update(dt);
	//player->Update(dt, listEnemy);
	//turtle->Update(dt);
}

/*
	Render a frame 
*/
void Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		player->Render();
		_sceneManager->Render();
		//turtle->Render();

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
	wc.hIcon = NULL;
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
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

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

			game->ProcessKeyboard();
			
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

	game = CGame::GetInstance();
	game->Init(hWnd);

	_sceneManager = SceneManager::GetInstance();
	_sceneManager->SetScene(new SceneGame());

	keyHandler = new CSampleKeyHander();
	game->InitKeyboard(keyHandler);


	LoadResources();
	Run();

	return 0;
}