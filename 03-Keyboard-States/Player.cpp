#include "Game.h"
#include "Player.h"

void CPlayer::Update(DWORD dt)
{
	CGameObject::Update(dt);

	// simple fall down
	//vy += PLAYER_GRAVITY;
	//if (y > 100) 
	//{
	//	vy = 0; y = 100.0f;
	//}

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	int BackBufferHeight = CGame::GetInstance()->GetBackBufferHeight();

	// simple screen edge collision!!!
	if (vx > 0 && x > BackBufferWidth - PLAYER_WIDTH) x = BackBufferWidth - PLAYER_WIDTH;
	if (vx < 0 && x < 0) x = 0;
	if (vy > 0 && y > BackBufferHeight - PLAYER_HEIGHT) y = BackBufferHeight - PLAYER_HEIGHT;
	if (vy < 0 && y < 0) y = 0;
}

void CPlayer::Render()
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

void CPlayer::SetPlayerMovement(int state, int direction)
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
			vx = PLAYER_WALKING_SPEED;
			vy = 0;
		}
		else if (direction == Direction::DOWN)
		{
			vy = PLAYER_WALKING_SPEED;
			vx = 0;
		}
		else if (direction == Direction::LEFT)
		{
			vx = -PLAYER_WALKING_SPEED;
			vy = 0;
		}
		else if (direction == Direction::UP)
		{
			vy = -PLAYER_WALKING_SPEED;
			vx = 0;
		}
	}
	//else
	//{
	//	if (y == 100) vy = -PLAYER_JUMP_SPEED_Y;
	//}
	
	//switch (state)
	//{
	//case PLAYER_STATE_WALKING_RIGHT:
	//	vx = PLAYER_WALKING_SPEED;
	//	nx = 1;
	//	break;
	//case PLAYER_STATE_WALKING_LEFT: 
	//	vx = -PLAYER_WALKING_SPEED;
	//	nx = -1;
	//	break;
	//case PLAYER_STATE_JUMP: 
	//	if (y==100)
	//		vy = -PLAYER_JUMP_SPEED_Y;

	//case PLAYER_STATE_IDLE: 
	//	vx = 0;
	//	break;
	//}
}

void CPlayer::InitPlayerAnimation()
{

}


