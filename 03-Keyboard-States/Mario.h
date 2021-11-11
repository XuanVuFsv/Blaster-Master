#pragma once
#include "GameObject.h"

#define MARIO_WIDTH 24
#define MARIO_HEIGHT 31

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_GRAVITY			0.1f

//#define MARIO_ANI_IDLE_RIGHT		0
//#define MARIO_ANI_IDLE_LEFT			1
//#define MARIO_ANI_WALKING_RIGHT		2
//#define MARIO_ANI_WALKING_LEFT		3

//#define MARIO_STATE_IDLE			0
//#define MARIO_STATE_WALKING_RIGHT	100
//#define MARIO_STATE_WALKING_LEFT	200
//#define MARIO_STATE_JUMP			300

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
	JUMP = 2
};

class CMario : public CGameObject
{
protected:
	int currentAnimation;
public: 
	void Update(DWORD dt);
	void Render();
	void SetPlayerMovement(int state, int direction);
	void SetCurrentAnimation(int ani) { this->currentAnimation = ani; };
	int GetCurrentAnimation() { return this->currentAnimation; };
};