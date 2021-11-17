#ifndef __SCENE_H__
#define __SCENE_H__

#include <Windows.h>
#include "GameObject.h"
#include "Player.h"

class Scene
{
public:
	Scene();


	virtual void KeyState(BYTE* state) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;

	virtual void LoadResources() = 0;
	virtual void InitGame(CPlayer* _player) = 0;
	virtual void Update(DWORD dt) = 0;
	virtual void Render() = 0;


	virtual ~Scene();

};

#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) \
if(ptr) \
{\
	delete (ptr); \
	ptr = nullptr; \
} \

#endif

#endif