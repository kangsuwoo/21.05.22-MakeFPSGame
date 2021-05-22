#pragma once
#include "BulletManager.h"

class Player
{
	enum Status {
		IDLE = 0,
		MOVE,
		ATTACK,
		DEATH
	};

public:
	Player();
	~Player();

private:
	BulletManager* m_Bullets;
	
	BaseTexture* m_Texture;
	bool m_IsLeft;
	UINT m_CurrentFrameX;
	UINT m_CurrentFrameY;

public:
	void Update();
	void Render();

public:
	Status CurrentStatus;

	D2D_VECTOR_2F Position;
	float Rotation;
	D2D_VECTOR_2F Scale;
	float Opacity;
};

