#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include "Scene.h"

class SceneManager
{
private:
	static SceneManager* _Instance;
	Scene* _scene;

public:
	SceneManager();
	~SceneManager();


	static SceneManager* GetInstance();

	void SetScene(Scene* x);

	void KeyState(BYTE* state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);

	void LoadResources();
	void InitGame(CPlayer* player);
	void Update(DWORD dt);
	void Render();


	Scene* GetScene();

};

#endif