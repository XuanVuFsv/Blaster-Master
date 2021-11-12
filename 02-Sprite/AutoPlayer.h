#pragma once

#include "GameObject.h"

#define AUTOPLAYER_WIDTH 24
#define AUTOPLAYER_HEIGHT 31

#define AUTOPLAYER_WALKING_SPEED		0.1f
#define AUTOPLAYER_JUMP_SPEED_Y		0.5f
#define AUTOPLAYER_GRAVITY			0.1f

#define AUTOPLAYER_ANI_IDLE_RIGHT		0
#define AUTOPLAYER_ANI_IDLE_LEFT			1
#define AUTOPLAYER_ANI_WALKING_RIGHT		2
#define AUTOPLAYER_ANI_WALKING_LEFT		3

//#define AUTOPLAYER_STATE_WALKING_RIGHT	100
//#define AUTOPLAYER_STATE_WALKING_LEFT	200
//#define AUTOPLAYER_STATE_JUMP			300

enum  Direction
{
	RIGHT = 100,
	DOWN = 200,
	LEFT = 300,
	UP = 400
};

class CAutoPlayer : public CGameObject
{
protected:
	//float vx;
	bool isVertical = false;
public:
	CAutoPlayer(float x, float y, float vx);
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};
