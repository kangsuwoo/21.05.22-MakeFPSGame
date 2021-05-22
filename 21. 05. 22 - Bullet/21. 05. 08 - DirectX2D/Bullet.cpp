#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(float x, float y, float speed)
	: m_Position({x, 575.0f }), m_Speed(speed)
{
	m_IsReverse = m_Speed < 0;
	m_Texture = _Texture->LoadTexture("Bullet", L"../_Resources/Bullet.png");
}

Bullet::~Bullet()
{
}

bool Bullet::Update()
{
	m_Position.x += m_Speed;

	if (m_Position.x <= -m_Texture->GetSize().width || m_Position.x > _Application->Width + m_Texture->GetSize().width)
		return false;

	return true;
}

void Bullet::Render()
{
	m_Texture->Draw(m_Position.x, m_Position.y, 10, 10);
}
