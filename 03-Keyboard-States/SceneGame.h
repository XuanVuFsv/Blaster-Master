#ifndef __SCENEGAME_H__
#define __SCENEGAME_H__

#include "Scene.h"
#include "Turtle.h"

//#define LEFT_MAP -100
//#define TOP_MAP -100
//#define RIGHT_MAP 628
//#define BOT_MAP 580

#define LEFT_MAP 0
#define TOP_MAP 0
#define RIGHT_MAP 528
#define BOT_MAP 480
#define MAP_WIDTH 1000
#define MAP_HEIGHT 1500

class SceneGame : public Scene
{
private:

	/*Xử lí liên quan tạo ghost*/
	int CountEnemyGhost; // số lượng ghost hiện tại
	DWORD TimeCreateGhost; // thời điểm bắt đầu tạo ghost
	DWORD TimeWaitProcessCreateGhost; // Thời điểm bắt đầu chờ xử lí việc tạo ghost
	bool isWaitProcessCreateGhost; // chờ xử lí việc tạo ghost
	bool isAllowCheckTimeWaitProcessCreateGhost = false; // cho phép kt thời gian chờ xử lí tạo ghost

	CPlayer* player;
	Camera* camera;

	vector<CGameObject*> listObj;
	vector <CGameObject*> listEnemy;

public:
	SceneGame();
	~SceneGame();

	void KeyState(BYTE* state) {};
	void OnKeyDown(int KeyCode) {};
	void OnKeyUp(int KeyCode) {};
	void LoadResources();
	void SetPlayer(CPlayer* _player) { player = _player; };

	void InitGame(CPlayer* _player); // khởi tạo lại như chơi từ đầu
	//void ResetResource(); // reset lai resource khi simon mất 1 mạng



	void Update(DWORD dt);
	void Render();


	//void LoadMap(eType);



	//void CheckCollision();
	//void CheckCollisionWeapon(vector<GameObject*> listObj);
	//void CheckCollisionSimonWithItem();
	//void CheckCollisionSimonWithObjectHidden();
	//void CheckCollisionWithEnemy();
	//void CheckCollisionSimonWithEnemy();
	//void CheckCollisionSimonWithGate();
	//void CheckCollisionWithBoss();
	//Item* GetNewItem(int Id, eType Type, float X, float Y);


	//void ProcessClearState3(DWORD dt);
	//void ProcessInvisibilityPotion(DWORD dt);
	//void ProcessCross(DWORD dt);

	//void ReplayMusicGame();
};

#endif