#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Sprites.h"


using namespace std;

class CGameObject
{
protected:

	float x;
	float y;

	float vx;
	float vy;

	int state;

	static vector<LPANIMATION> animations;

public:
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	float GetX() { return x; }
	float GetY() { return y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }

	void SetState(int state) { this->state = state; }
	int GetState() { return this->state; }


	static void AddAnimation(int aniId);

	CGameObject(float x, float y);

	virtual void Update(DWORD dt);
	virtual void Render();
	~CGameObject();
};