#include "stdafx.h"
#include "Player.h"

Player::Player()
	: m_IsLeft(false),
	m_CurrentFrameX(0), m_CurrentFrameY(0),
	Rotation(0.0f),
	Opacity(1.0f),
	CurrentStatus(IDLE)
{
	Position = { 100.0f, 550.0f };

	m_Texture = _Texture->LoadTexture(
		"캐릭터", L"../_Resources/Untitled-11.png",
		10, 4);
	Scale = { 70, 64 };

	m_Bullets = new BulletManager();
}

Player::~Player()
{
	SAFE_DELETE(m_Bullets);
}

static int CurrentFrame = 0;
void Player::Update()
{
	bool isChange = false;
	if (_KeyCode->GetKey(VK_LEFT) || _KeyCode->GetKey('A'))
	{
		Position.x -= 2.0f;
		m_IsLeft = true;

		if (CurrentStatus != MOVE) {
			isChange = true;
			CurrentStatus = MOVE;
		}
	}
	else if (_KeyCode->GetKey(VK_RIGHT) || _KeyCode->GetKey('D'))
	{
		Position.x += 2.0f;
		m_IsLeft = false;

		if (CurrentStatus != MOVE) {
			isChange = true;
			CurrentStatus = MOVE;
		}
	}
	else {
		if (CurrentStatus != IDLE)
		{
			isChange = true;
			CurrentStatus = IDLE;
		}
	}

	if (_KeyCode->GetKeyDown(VK_SPACE))
	{


		if (CurrentStatus != ATTACK) {
			isChange = true;
			CurrentStatus = ATTACK;
		}
	}

	if (isChange) CurrentFrame = 0;
	else CurrentFrame++;

	//	FSM -> 유한 기계 상태
	switch (CurrentStatus)
	{
		case IDLE:
		{
			m_CurrentFrameX = 0;
		}
		break;

		case MOVE:
		{
			m_CurrentFrameY = 1;

			if (isChange) m_CurrentFrameX = 0;
			if (CurrentFrame % 9 == 0)
			{
				CurrentFrame = 0;
				m_CurrentFrameX++;
				if (m_CurrentFrameX == 7 + 1)
					m_CurrentFrameX = 2;
			}
		}
		break;

		case ATTACK:
		{
			m_CurrentFrameY = 2;

			if (isChange) m_CurrentFrameX = 0;
			if (CurrentFrame % 9 == 0)
			{
				CurrentFrame = 0;
				m_CurrentFrameX++;
				if (m_CurrentFrameX == 7 + 1)
					m_CurrentFrameX = 2;
			}

			m_Bullets->Shoot(Position.x + 2.5f, Position.y, m_IsLeft ? -5.0f : 5.0f);

		}
		break;

	}

	m_Bullets->Update();
}

void Player::Render()
{
	//	프레임 렌더할 때 중요한 것
	//	포지션, 프레임 포지션, 리버스 유무, 크기, 투명도
	m_Texture->DrawFrame(
		Position.x, Position.y,
		m_CurrentFrameX, m_CurrentFrameY,
		Scale.x, Scale.y,
		m_IsLeft,
		Rotation,
		Opacity);

	m_Bullets->Render();
}
