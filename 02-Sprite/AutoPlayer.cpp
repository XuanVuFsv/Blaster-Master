#include "Game.h"
#include "AutoPlayer.h"

CAutoPlayer::CAutoPlayer(float x, float y, float vx) :CGameObject(x, y)
{
	this->vx = this->vy = vx;
	CAutoPlayer::SetState(Direction::RIGHT);
};

void CAutoPlayer::Update(DWORD dt)
{
	CGameObject::Update(dt);

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	int BackBufferHeight = CGame::GetInstance()->GetBackBufferHeight();
	if ((x <= 0 || x >= BackBufferWidth - AUTOPLAYER_WIDTH) && !isVertical) {

		//vx = -vx;
		//vx = 0;
		//vy = -1;

		if (x <= 0)
		{
			x = 0;
			CAutoPlayer::SetState(Direction::UP);
		}
		else if (x >= BackBufferWidth - AUTOPLAYER_WIDTH)
		{
			x = (float)(BackBufferWidth - AUTOPLAYER_WIDTH);
			CAutoPlayer::SetState(Direction::DOWN);
		}
	}
	else if ((y <= 0 || y >= BackBufferHeight - AUTOPLAYER_HEIGHT) && isVertical) {

		//vx = -vx;
		//vy = 0;
		//vx = -1;

		if (y <= 0)
		{
			y = 0;
			CAutoPlayer::SetState(Direction::RIGHT);
		}
		else if (y >= BackBufferHeight - AUTOPLAYER_HEIGHT)
		{
			y = (float)(BackBufferHeight - AUTOPLAYER_HEIGHT);
			CAutoPlayer::SetState(Direction::LEFT);

		}
	}
}

void CAutoPlayer::Render()
{
	LPANIMATION ani;

	//[RED FLAG][TODO]: Student needs to think about how to associate this animation/asset to AutoPlayer!!
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
	//	if (nx > 0) ani = AUTOPLAYER_ANI_IDLE_RIGHT;
	//	else ani = AUTOPLAYER_ANI_IDLE_LEFT;
	//}
	//else if (vx > 0)
	//	ani = AUTOPLAYER_ANI_WALKING_RIGHT;
	//else ani = AUTOPLAYER_ANI_WALKING_LEFT;

	//animations[ani]->Render(x, y);
}

void CAutoPlayer::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case Direction::RIGHT:
		//vx = AUTOPLAYER_WALKING_SPEED;
		//vy = AUTOPLAYER_WALKING_SPEED;
		vx = AUTOPLAYER_WALKING_SPEED;
		vy = 0;
		isVertical = false;
		break;
	case Direction::DOWN:
		//vx = -AUTOPLAYER_WALKING_SPEED;
		//vy = AUTOPLAYER_WALKING_SPEED;
		vx = 0;
		vy = AUTOPLAYER_WALKING_SPEED;
		isVertical = true;
		break;
	case Direction::LEFT:
		//vx = -AUTOPLAYER_WALKING_SPEED;
		//vy = -AUTOPLAYER_WALKING_SPEED;
		vx = -AUTOPLAYER_WALKING_SPEED;
		vy = 0;
		isVertical = false;
		break;
	case Direction::UP:
		//vx = AUTOPLAYER_WALKING_SPEED;
		//vy = -AUTOPLAYER_WALKING_SPEED;
		vx = 0;
		vy = -AUTOPLAYER_WALKING_SPEED;
		isVertical = true;
		break;
	}
}

