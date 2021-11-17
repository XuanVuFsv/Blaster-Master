#include "Game.h"
#include "Turtle.h"

//CTurtle::CTurtle()
//{
//
//}

CTurtle::~CTurtle()
{

}


void CTurtle::Update(DWORD dt, vector<LPGAMEOBJECT>* listObject)
{
	CGameObject::Update(dt);
	CTurtle::SetState(Direction::RIGHT);

	//int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	//int BackBufferHeight = CGame::GetInstance()->GetBackBufferHeight();

	// simple screen edge collision!!!
	if ((vx > 0 && x > MAX_DISTANCE) || (vx < 0 && x < -MAX_DISTANCE)) vx *= -1;
}

void CTurtle::Render()
{
	animations[4]->Render(x, y, CGameObject::GetState());
}

void CTurtle::SetTurtleMovement(int state, int direction)
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
			vx = TURTLE_WALKING_SPEED;
			vy = 0;
		}
		else if (direction == Direction::DOWN)
		{

		}
		else if (direction == Direction::LEFT)
		{
			vx = -TURTLE_WALKING_SPEED;
			vy = 0;
		}
		else if (direction == Direction::UP)
		{

		}
	}
}


void CTurtle::InitTurtleAnimation()
{

}


