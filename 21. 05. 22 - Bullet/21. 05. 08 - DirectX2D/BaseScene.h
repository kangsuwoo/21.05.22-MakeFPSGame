#pragma once
#include "Player.h"

//	IScene �̶�� �༮�� ������ָ�
//	�� �༮�� �� �̾�! ��� �˷��ְԵȴ� (Start, Update, Render)
class BaseScene : public IScene
{
public:
	BaseScene();
	~BaseScene();

private:
	Player* m_Player;

public:
	// IScene��(��) ���� ��ӵ�
	virtual HRESULT Start() override;
	virtual void Update() override;
	virtual void Render() override;
};

