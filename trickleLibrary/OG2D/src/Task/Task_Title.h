#pragma once
//______________________________//
//|�^�C�g���^�X�N               |//
//|�����F2018/03/20���q��       |//
//|____________________________|//
#include "Win\WinMain.h"
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"
#include "Back\Back.h"
#include "Title_Image\TItle_Rogo.h"
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
	Back back;
private:
	//�ǉ��ϐ�//
	Title_Rogo title_rogo;
};