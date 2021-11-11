#include "Game.h"
#include "Mario.h"

CMario::CMario(float x, float y, float vx) :CGameObject(x, y)
{
	this->vx = this->vy = vx;
	CMario::SetState(Direction::RIGHT);
};

void CMario::Update(DWORD dt)
{
	CGameObject::Update(dt);

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	int BackBufferHeight = CGame::GetInstance()->GetBackBufferHeight();
	if ((x <= 0 || x >= BackBufferWidth - MARIO_WIDTH) && !isVertical) {

		//vx = -vx;
		//vx = 0;
		//vy = -1;

		if (x <= 0)
		{
			x = 0;
			CMario::SetState(Direction::UP);
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
			CMario::SetState(Direction::DOWN);
		}
	}
	else if ((y <= 0 || y >= BackBufferHeight - MARIO_HEIGHT) && isVertical) {

		//vx = -vx;
		//vy = 0;
		//vx = -1;

		if (y <= 0)
		{
			y = 0;
			CMario::SetState(Direction::RIGHT);
		}
		else if (y >= BackBufferHeight - MARIO_HEIGHT)
		{
			y = (float)(BackBufferHeight - MARIO_HEIGHT);
			CMario::SetState(Direction::LEFT);

		}
	}
}

void CMario::Render()
{
	LPANIMATION ani;

	//[RED FLAG][TODO]: Student needs to think about how to associate this animation/asset to Mario!!
	if (vx != 0)
	{
		if (vx < 0) ani = CAnimations::GetInstance()->Get(500); //left
		else ani = CAnimations::GetInstance()->Get(501); // right
	}
	else
	{
		if (vy > 0) ani = CAnimations::GetInstance()->Get(502); //down
		else ani = CAnimations::GetInstance()->Get(503); //up
	}

	ani->Render(x, y);

	//int ani;
	//if (vx == 0)
	//{
	//	if (nx > 0) ani = MARIO_ANI_IDLE_RIGHT;
	//	else ani = MARIO_ANI_IDLE_LEFT;
	//}
	//else if (vx > 0)
	//	ani = MARIO_ANI_WALKING_RIGHT;
	//else ani = MARIO_ANI_WALKING_LEFT;

	//animations[ani]->Render(x, y);
}

void CMario::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case Direction::RIGHT:
		//vx = MARIO_WALKING_SPEED;
		//vy = MARIO_WALKING_SPEED;
		vx = MARIO_WALKING_SPEED;
		vy = 0;
		isVertical = false;
		break;
	case Direction::DOWN:
		//vx = -MARIO_WALKING_SPEED;
		//vy = MARIO_WALKING_SPEED;
		vx = 0;
		vy = MARIO_WALKING_SPEED;
		isVertical = true;
		break;
	case Direction::LEFT:
		//vx = -MARIO_WALKING_SPEED;
		//vy = -MARIO_WALKING_SPEED;
		vx = -MARIO_WALKING_SPEED;
		vy = 0;
		isVertical = false;
		break;
	case Direction::UP:
		//vx = MARIO_WALKING_SPEED;
		//vy = -MARIO_WALKING_SPEED;
		vx = 0;
		vy = -MARIO_WALKING_SPEED;
		isVertical = true;
		break;
	}
}

