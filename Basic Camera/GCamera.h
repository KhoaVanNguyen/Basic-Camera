#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Global.h"
#include "GSprite.h"
#include "GameObject.h"
#include <DirectXMath.h>
class GCamera
{
private:
	float angle;
	int height;
	int width;
	DirectX::XMFLOAT3 scaleFactors;
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DMATRIX viewMatrix;

	GameObject *followingObject;
public:
	D3DXVECTOR2 viewport;		//Thiết lập tọa độ của camera	
	int _maxSize, _minSize;

	GCamera();
	GCamera(int width, int height, float angle, DirectX::XMFLOAT3);


	D3DXVECTOR3 CenterSprite(int x, int y);	//Tìm tọa độ center của sprite
	void UpdateCamera(int x);		
	void UpdateCamera(int &w, int &h);
	
	void SetSizeMap(int _max, int _min);
	D3DXVECTOR2 Transform(int x, int y);//Hàm transform, chuyển tọa độ viewport về tọa độ world
	
	// function
	void Update();
	void Follow(GameObject *following);
	void Unfollow();
	bool IsFollowing() const;
	void SetTransform(LPDIRECT3DDEVICE9);
};

#endif