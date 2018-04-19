#pragma once
//______________________________//
//|�^�X�N�T���v��               |//
//|�����F2018/03/20���q��       |//
//|�����F2018/04/17����N�@    |//
//|____________________________|//
#include "Win\WinMain.h"
#include "CollisionManager\CollisionManager.h"
#include "OGSystem\OGsystem.h"
#include "Back\Back.h"

class Game
{
public:
	void Initialize();
	TaskFlag Update();
	void Render2D();
	void Finalize();
	//��������//
	//�ǉ��ϐ�//
	//��������//
	//std::vector<Bucket*> bucket;
	CollisionManager cm;
private:
	Back back;
	//---------------------------------------------------------------------
	//�����o�[�֐�
	//---------------------------------------------------------------------
};