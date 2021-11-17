#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Sprites.h"

using namespace std;

enum Direction
{
	RIGHT = 100,
	DOWN = 200,
	LEFT = 300,
	UP = 400
};

enum State
{
	IDLE = 0,
	WALK = 1,
	JUMP = 2,
	SHOOT = 3,
	HIKE = 4,
	DIE = 5
};

class CGameObject;
typedef CGameObject* LPGAMEOBJECT;

class CGameObject
{
protected:

	float x; 
	float y;

	float vx;
	float vy;

	int nx;	 

	int state;	
	int direction;

	static vector<LPANIMATION> animations;

public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }

	void SetState(int state) { this->state = state; }
	int GetState() { return this->state; }
	void SetDirection(int direction) { this->direction = direction; }
	int GetDirection() { return this->direction; }

	static void AddAnimation(int aniId);

	CGameObject();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *listObject = NULL);
	virtual void Render() = 0;

	//void Render();
	~CGameObject();
};