#include "Task_Game.h"

//�ʃ^�X�N��ʃI�u�W�F�N�g�𐶐�����ꍇ�����ɂ���class�̏����ꂽh���C���N���[�h����
#include "Asset\Enemy.h"
#include "Asset\Boll.h"
#include "Asset\Player.h"
#include "Back\GameBack.h"

#include "Task_Ending.h"
bool Game::Initialize()
{
	//-----------------------------
	//�������ɏ������鏉�����������L�q
	//-----------------------------
	this->taskName = "Game";		//�������Ɏg�����߂̖���o�^����
	__super::Init(taskName);		//TaskObject���̏������s��
									//������
	auto back = GameBack::Create();
	return true;
}

void Game::UpDate()
{
	//--------------------
	//�X�V���ɍs���������L�q
	//--------------------
}

void Game::Render2D()
{
	//--------------------
	//�`�掞�ɍs���������L�q
	//--------------------
}
bool Game::Finalize()
{
	//-----------------------------------------
	//���̃I�u�W�F�N�g�����ł���Ƃ��ɍs���������L�q
	//-----------------------------------------
	//���̃^�X�N����邩���A�v���P�[�V�������I���\�肩�ǂ���
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{

	}
	return true;
}
//----------------------------
//�������牺��class���̂ݕύX����
//�ق��͕ύX���Ȃ�����
//----------------------------
Game::Game()
{

}

Game::~Game()
{
	this->Finalize();
}

Game::SP Game::Create(bool flag_)
{

	Game::SP to = Game::SP(new Game());
	if (to)
	{
		to->me = to;
		if (flag_)
		{
			OGge->SetTaskObject(to);
		}
		if (!to->Initialize())
		{
			to->Kill();
		}
		return to;
	}
	return nullptr;
}