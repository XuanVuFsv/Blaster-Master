#include "Camera.h"

Camera::Camera(int w, int h/*, int b_left, int b_right*/)
{
	_width = w;
	_height = h;
	isAllowFollowPlayer = true;

	// Biên mặc định ban đầu là kích thước MAP
	_boundaryLeft = 0;
	_boundaryRight = 0;
	_boundaryTop = 0;
	_boundaryBot = 0;
	//SetBoundaryBackup(_boundaryLeft, _boundaryRight);
	vx = 0;
}

Camera::~Camera()
{
}

void Camera::Update(DWORD dt)
{
	this->dt = dt;

	//float dx = vx * dt;
	_xCam += vx * dt;
	_yCam += -vy * dt;

	if (_xCam < _boundaryLeft)
		_xCam = _boundaryLeft;

	if (_xCam > _boundaryRight)
		_xCam = _boundaryRight;

	if (_yCam < _boundaryBot)
		_yCam = _boundaryBot;

	if (_yCam > _boundaryTop)
		_yCam = _boundaryTop;
}

D3DXVECTOR2 Camera::Transform(float xWorld, float yWorld)
{
	return D3DXVECTOR2(xWorld - _xCam, -yWorld + _yCam);
}

void Camera::SetPosition(float x, float y)
{
	_xCam = x;
	_yCam = y;
}

float Camera::GetXCam()
{
	return _xCam;
}

float Camera::GetYCam()
{
	return _yCam;
}


int Camera::GetWidth()
{
	return _width;
}

int Camera::GetHeight()
{
	return _height;
}

//bool Camera::checkObjectInCamera(float x, float y, float w, float h)
//{
//	if (x + w < _xCam || _xCam + _width < x)
//		return false;
//	if (y + h < _yCam || _yCam + _height < y)
//		return false;
//	return true;
//}

bool Camera::AllowFollowPlayer()
{
	return isAllowFollowPlayer;
}

void Camera::SetAllowFollowPlayer(bool isFollow)
{
	isAllowFollowPlayer = isFollow;
}

void Camera::SetBoundary(float left, float right, float top, float bot)
{
	_boundaryLeft = left;
	_boundaryRight = right;
	_boundaryTop = top;
	_boundaryBot = bot;
}

float Camera::GetBoundaryRight()
{
	return _boundaryRight;
}

float Camera::GetBoundaryLeft()
{
	return _boundaryLeft;
}
