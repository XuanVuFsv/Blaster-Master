#include "Game.h"
#include "Mario.h"

void CMario::Update(DWORD dt)
{
	CGameObject::Update(dt);

	// simple fall down
	//vy += MARIO_GRAVITY;
	//if (y > 100) 
	//{
	//	vy = 0; y = 100.0f;
	//}

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	int BackBufferHeight = CGame::GetInstance()->GetBackBufferHeight();

	// simple screen edge collision!!!
	if (vx > 0 && x > BackBufferWidth - MARIO_WIDTH) x = BackBufferWidth - MARIO_WIDTH;
	if (vx < 0 && x < 0) x = 0;
	if (vy > 0 && y > BackBufferHeight - MARIO_HEIGHT) y = BackBufferHeight - MARIO_HEIGHT;
	if (vy < 0 && y < 0) y = 0;
}

void CMario::Render()
{
	int ani = GetCurrentAnimation();

	//if (vx == 0 && vy == 0)
	//{
	//	ani = 500;
	//}
	if (vx != 0)
	{
		if (vx < 0) ani = 0;
		else ani = 1;
	}
	else if (vy != 0)
	{
		if (vy > 0) ani = 2;
		else ani = 3;
	}

	SetCurrentAnimation(ani);
	animations[ani]->Render(x, y, CGameObject::GetState());
}

void CMario::SetPlayerMovement(int state, int direction)
{
	CGameObject::SetState(state);
	if (direction != 0) CGameObject::SetDirection(direction);

	if (state == State::IDLE)
	{
		vx = 0;
		vy = 0;
	}
	else if (state == State::WALK)
	{
		if (direction == Direction::RIGHT)
		{
			vx = MARIO_WALKING_SPEED;
			vy = 0;
		}
		else if (direction == Direction::DOWN)
		{
			vy = MARIO_WALKING_SPEED;
			vx = 0;
		}
		else if (direction == Direction::LEFT)
		{
			vx = -MARIO_WALKING_SPEED;
			vy = 0;
		}
		else if (direction == Direction::UP)
		{
			vy = -MARIO_WALKING_SPEED;
			vx = 0;
		}
	}
	//else
	//{
	//	if (y == 100) vy = -MARIO_JUMP_SPEED_Y;
	//}
	
	//switch (state)
	//{
	//case MARIO_STATE_WALKING_RIGHT:
	//	vx = MARIO_WALKING_SPEED;
	//	nx = 1;
	//	break;
	//case MARIO_STATE_WALKING_LEFT: 
	//	vx = -MARIO_WALKING_SPEED;
	//	nx = -1;
	//	break;
	//case MARIO_STATE_JUMP: 
	//	if (y==100)
	//		vy = -MARIO_JUMP_SPEED_Y;

	//case MARIO_STATE_IDLE: 
	//	vx = 0;
	//	break;
	//}
}

