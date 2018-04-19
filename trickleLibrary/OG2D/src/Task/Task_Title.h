#pragma once
//______________________________//
//|�^�C�g���^�X�N               |//
//|�����F2018/03/20���q��       |//
//|____________________________|//
#include "Win\WinMain.h"
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"
#include "Map\Map.h"
#include "CollisionManager\CollisionManager.h"
class Title
{
public:
	void Initialize();
	TaskFlag Update();
	void Render2D();
	void Finalize();

	//��������//
	//�ǉ��ϐ�//
	//��������//
	CollisionManager cm;
	Map map;

};