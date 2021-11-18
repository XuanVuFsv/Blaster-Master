#ifndef __CAMERA_H__
#define __CAMERA_H__
#include <Windows.h>
#include <d3dx9.h>

class Camera
{
protected:

	float _xCam;
	float _yCam;

	int _width;
	int _height;

	float _boundaryLeft;
	float _boundaryRight;
	float _boundaryTop;
	float _boundaryBot;

	float vx = 0;
	float vy = 0;
	DWORD dt;

	bool isAllowFollowPlayer;

public:
	Camera(int w, int h);
	~Camera();

	void Update(DWORD dt);

	D3DXVECTOR2 Transform(float, float);

	void SetPosition(float x, float y);
	void SetCameraVelocity(float _vx, float _vy) { vx = _vx; vy = _vy; };

	float GetXCam();
	float GetYCam();
	int GetWidth();
	int GetHeight();

	//bool checkObjectInCamera(float x, float y, float w, float h);

	bool AllowFollowPlayer();
	void SetAllowFollowPlayer(bool b);

	void SetBoundary(float left, float right, float top, float bot);
	float GetBoundaryRight();
	float GetBoundaryLeft();
};

#endif



