#include "Task_Title.h"
//�ʃ^�X�N��ʃI�u�W�F�N�g�𐶐�����ꍇ�����ɂ���class�̏����ꂽh���C���N���[�h����
#include "Task_Game.h"

#include "Back\Back.h"
#include "Back\TItleRogo.h"
bool Title::Initialize()
{
	//-----------------------------
	//�������ɏ������鏉�����������L�q
	//-----------------------------
	this->taskName = "Title";			//�������Ɏg�����߂̖���o�^����
	__super::Init(taskName);		//TaskObject���̏������s��
	//������

	auto back = Back::Create();
	auto rogo = Rogo::Create();

	std::cout << "�^�C�g���@������" << std::endl;
	return true;
}

void Title::UpDate()
{
	//--------------------
	//�X�V���ɍs���������L�q
	//--------------------
	auto rogo = OGge->GetTask<Rogo>("Rogo");
	if (rogo != nullptr)
	{
		if (rogo->GetEasingFlag())
		{
			if (OGge->in->key.down(Input::KeyBoard::S))
			{
				Kill();
			}
		}
	}
}

void Title::Render2D()
{
	//--------------------
	//�`�掞�ɍs���������L�q
	//--------------------
}
bool Title::Finalize()
{
	//-----------------------------------------
	//���̃I�u�W�F�N�g�����ł���Ƃ��ɍs���������L�q
	//-----------------------------------------
	//���̃^�X�N����邩���A�v���P�[�V�������I���\�肩�ǂ���
	auto back = OGge->GetTask<Back>("Back");
	if (back)
	{
		back->Kill();
	}
	auto rogo = OGge->GetTask<Rogo>("Rogo");
	if (rogo)
	{
		rogo->Kill();
	}

	return true;
}
//----------------------------
//�������牺��class���̂ݕύX����
//�ق��͕ύX���Ȃ�����
//----------------------------
Title::Title()
{
	std::cout << "�^�C�g���@����" << std::endl;
}

Title::~Title()
{
	Finalize();
	std::cout << "�^�C�g���@���" << std::endl;
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		auto game = Game::Create();
	}
} 

Title::SP Title::Create(bool flag_)
{

	Title::SP to = Title::SP(new Title());
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