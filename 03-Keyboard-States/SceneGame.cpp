#include "SceneGame.h"
#include <ctime>
#include <cstdlib>
#include "define.h"


SceneGame::SceneGame()
{
	LoadResources();

}

SceneGame::~SceneGame()
{
	//SAFE_DELETE(TileMap);
	//SAFE_DELETE(board);
	//SAFE_DELETE(gridGame);
}

void SceneGame::LoadResources()
{
	//InitGame();
}

void SceneGame::InitGame(CPlayer* _player)
{
	camera = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT);
	camera->SetPosition(0, SCREEN_HEIGHT);
	camera->SetBoundary(0, MAP_WIDTH, MAP_HEIGHT, 0);
	player = _player;
	player->SetCamera(camera);
	player->SetPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	for (int i = 0; i < 10; i++)
	{
		//srand(time(NULL));
		//float x = rand() % (33 - 0 + 1) + 0;
		//float y = rand() % (30 - 0 + 1) + 0;

		CTurtle* turtle = new CTurtle();
		//turtle->SetPosition(x * 16, y * 16);
		turtle->SetPosition(100 * i, 100 * i);
		listEnemy.push_back(turtle);
	}
}

void SceneGame::Render()
{
	player->Render(camera);
	for (UINT i = 0; i < listEnemy.size(); i++)
	{
		listEnemy[i]->Render(camera);
	}
}

void SceneGame::Update(DWORD dt)
{
	camera->SetCameraVelocity(player->GetVx(), player->GetVy());
	camera->Update(dt);
	player->Update(dt, &listObj);
	for (UINT i = 0; i < listEnemy.size(); i++)
	{
		CGameObject* enemy = listEnemy[i];
		enemy->Update(dt, &listObj);
	}
}