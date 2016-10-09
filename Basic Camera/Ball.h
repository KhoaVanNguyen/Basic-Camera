#pragma once
#include "GameObject.h"
class Ball : public GameObject
{	
public:
	virtual void Move();
	virtual bool IsInitialized();
	virtual void InitPosition();
	void ResetPosition();
	int IsScore();
	Ball();
	~Ball();
};

