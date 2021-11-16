#pragma once
#include "GameObject.h"

#define TURTLE_WIDTH 16
#define TURTLE_HEIGHT 16

#define TURTLE_WALKING_SPEED	0.1f
#define MAX_DISTANCE			16

//#define TURTLE_ANI_IDLE_RIGHT		0
//#define TURTLE_ANI_IDLE_LEFT			1
//#define TURTLE_ANI_WALKING_RIGHT		2
//#define TURTLE_ANI_WALKING_LEFT		3

//#define TURTLE_STATE_IDLE			0
//#define TURTLE_STATE_WALKING_RIGHT	100
//#define TURTLE_STATE_WALKING_LEFT	200
//#define TURTLE_STATE_JUMP			300

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
	SHOOT = 3,
	DIE = 5
};

class CTurtle : public CGameObject
{
protected:
	int currentAnimation;
	int currentState;
	State* listState;
public:
	void Update(DWORD dt);
	void Render();
	void SetTurtleMovement(int state, int direction);
	void SetCurrentAnimation(int ani) { this->currentAnimation = ani; };
	int GetCurrentAnimation() { return this->currentAnimation; };
	void SetCurrentState(int state) { this->currentState = state; };
	int GetCurrentState() { return this->currentState; };
	void InitTurtleAnimation();
};