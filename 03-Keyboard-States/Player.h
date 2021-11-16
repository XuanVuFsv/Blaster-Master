#pragma once
#include "GameObject.h"

#define PLAYER_WIDTH 24
#define PLAYER_HEIGHT 31

#define PLAYER_WALKING_SPEED		0.1f
#define PLAYER_JUMP_SPEED_Y		0.5f
#define PLAYER_GRAVITY			0.1f

//#define PLAYER_ANI_IDLE_RIGHT		0
//#define PLAYER_ANI_IDLE_LEFT			1
//#define PLAYER_ANI_WALKING_RIGHT		2
//#define PLAYER_ANI_WALKING_LEFT		3

//#define PLAYER_STATE_IDLE			0
//#define PLAYER_STATE_WALKING_RIGHT	100
//#define PLAYER_STATE_WALKING_LEFT	200
//#define PLAYER_STATE_JUMP			300

class CPlayer : public CGameObject
{
protected:
	int currentAnimation;
	int currentState;
	State* listState;
public: 
	void Update(DWORD dt);
	void Render();
	void SetPlayerMovement(int state, int direction);
	void SetCurrentAnimation(int ani) { this->currentAnimation = ani; };
	int GetCurrentAnimation() { return this->currentAnimation; };
	void SetCurrentState(int state) { this->currentState = state; };
	int GetCurrentState() { return this->currentState; };
	void InitPlayerAnimation();
};