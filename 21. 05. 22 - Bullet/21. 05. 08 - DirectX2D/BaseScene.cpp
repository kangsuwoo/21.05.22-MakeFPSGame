#include "stdafx.h"
#include "BaseScene.h"

BaseScene::BaseScene()
{
}

BaseScene::~BaseScene()
{
	//	delete m_Player;
	SAFE_DELETE(m_Player);
}

HRESULT BaseScene::Start()
{
	m_Player = new Player();

	return S_OK;
}

void BaseScene::Update()
{
	m_Player->Update();
}

void BaseScene::Render()
{
	m_Player->Render();
}
