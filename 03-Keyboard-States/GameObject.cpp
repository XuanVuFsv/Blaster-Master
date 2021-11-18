#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprites.h"

vector<LPANIMATION> CGameObject::animations;

CGameObject::CGameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;	
}

void CGameObject::Update(DWORD dt, vector<LPGAMEOBJECT>* listObject)
{
	x += vx*dt;
	y += -vy*dt;
}

//void CGameObject::Render()
//{
//
//}

void CGameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	animations.push_back(ani);
}

//RECT CGameObject::GetBounding()
//{
//	//return sprite->GetBounding();
//}

CGameObject::~CGameObject()
{
}