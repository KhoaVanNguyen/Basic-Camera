#include "GCamera.h"

//GCamera::GCamera()
//{
//	/*viewport.x = 1;
//	viewport.y = G_ScreenHeight;*/
//}
GCamera::~GCamera() {

}
GCamera::GCamera(int width, int heigt, float angle, DirectX::XMFLOAT3 scaleFactors) {
	this->width = width;
	this->height = height;
	this->angle = angle;
	this->scaleFactors = scaleFactors;

	D3DXMatrixOrthoLH(&orthographicMatrix, width, -height, 0.0f, 1.0f);
	D3DXMatrixIdentity(&identityMatrix);

}
void GCamera::SetSizeMap(int _max, int _min)
{
	_maxSize = _max;
	_minSize = _min;
}
D3DXVECTOR2 GCamera::Transform(int x, int y)
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity (&matrix);
	matrix._22 = -1;
	matrix._41 = -viewport.x;
	matrix._42 = viewport.y;

	D3DXVECTOR3 pos3(x ,y ,1);	
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform (&MatrixResult,&pos3,&matrix);

	D3DXVECTOR2 result = D3DXVECTOR2 (MatrixResult.x,MatrixResult.y);
	return result;
}

D3DXVECTOR3 GCamera::CenterSprite(int x, int y)
{
	D3DXVECTOR3 pCenter = D3DXVECTOR3(x/2, y/2, 0);
	return pCenter;
}

void GCamera::UpdateCamera(int &w, int &h)
{
	//Tự viết dự vào hướng dẫn của GV LT
}
void GCamera::Update() {
	int cameraX = this->width / 2, cameraY = this->height / 2;
	if (this->followingObject && this->followingObject->IsInitialized())
	{
		cameraX = this->followingObject->x;
		cameraY = this->followingObject->y;
	}

	this->viewMatrix = D3DXMATRIX(
		scaleFactors.x * cos(angle), scaleFactors.x * sin(angle), 0, 0,
		-scaleFactors.y * sin(angle), scaleFactors.y * cos(angle), 0, 0,
		0, 0, scaleFactors.z, 0,
		-cameraX * scaleFactors.x * cos(angle) + cameraY * scaleFactors.y * sin(angle), -cameraX * scaleFactors.y * sin(angle) - cameraY * scaleFactors.y * cos(angle), 0, 1
	);
}
void GCamera::Follow(GameObject *gameObject) {
	this->followingObject = gameObject;
}
void GCamera::Unfollow() {
	this->followingObject = nullptr;
}
bool GCamera::IsFollowing() const
{
	return this->followingObject != nullptr;
}
void GCamera::SetTransform(LPDIRECT3DDEVICE9 d3ddev) const {
	d3ddev->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
	d3ddev->SetTransform(D3DTS_WORLD, &identityMatrix);
	d3ddev->SetTransform(D3DTS_VIEW, &viewMatrix);	

}