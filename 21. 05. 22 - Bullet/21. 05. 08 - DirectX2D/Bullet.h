#pragma once

class Bullet
{
public:
	Bullet(float x, float y, float speed);
	~Bullet();

private:
	BaseTexture* m_Texture;

	UINT m_CurrentFrameX;
	D2D_VECTOR_2F m_Position;
	float m_Speed;
	bool m_IsReverse;

	int m_CurrentFrame;

public:
	bool Update();
	void Render();

};

