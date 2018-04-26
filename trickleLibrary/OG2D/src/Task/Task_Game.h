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
#include "Kard\Kard.h"
#include "Map\Map.h"
#include "Player\Player.h"

class Game
{
public:
	Game();
	~Game();
	void Initialize();
	TaskFlag Update();
	void Render2D();
	void Finalize();
	//��������//
	//�ǉ��ϐ�//
	//��������//
	//std::vector<Bucket*> bucket;
	CollisionManager cm;
	Map map;
private:
	Back back;
	//---------------------------------------------------------------------
	//�����o�[�֐�
	//--------------------------------------------------------------------
	Kard kard[3][6];//18��
	Player player;
	//----------------------------------------------------------------------
	//�Q�[�����//
};