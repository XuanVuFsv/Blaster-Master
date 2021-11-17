#include "SceneGame.h"
#include <ctime>
#include <cstdlib>


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
	player = _player;
	for (int i = 0; i < 10; i++)
	{
		//srand(time(NULL));
		//float x = rand() % (33 - 0 + 1) + 0;
		//float y = rand() % (30 - 0 + 1) + 0;

		CTurtle* turtle = new CTurtle();
		//turtle->SetPosition(x * 16, y * 16);
		turtle->SetPosition(64 * i + 128, 64 * i + 256);
		listEnemy.push_back(turtle);
	}
}

void SceneGame::Render()
{
	for (UINT i = 0; i < listEnemy.size(); i++)
	{
		listEnemy[i]->Render();
	}
}

void SceneGame::Update(DWORD dt)
{
	player->Update(dt, &listObj);
	for (UINT i = 0; i < listEnemy.size(); i++)
	{
		CGameObject* enemy = listEnemy[i];
		enemy->Update(dt, &listObj);
	}
}