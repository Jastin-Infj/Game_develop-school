#include "Enemy.h"
//�ʃ^�X�N��ʃI�u�W�F�N�g�𐶐�����ꍇ�����ɂ���class�̏����ꂽh���C���N���[�h����

bool Enemy::Initialize()
{
	//-----------------------------
	//�������ɏ������鏉�����������L�q
	//-----------------------------
	this->taskName = "";			//�������Ɏg�����߂̖���o�^����
	__super::Init(taskName);		//TaskObject���̏������s��



	return true;
}
void Enemy::UpDate()
{
	//--------------------
	//�X�V���ɍs���������L�q
	//--------------------
}

void Enemy::Render2D()
{
	//--------------------
	//�`�掞�ɍs���������L�q
	//--------------------

}

bool Enemy::Finalize()
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
Enemy::Enemy()
{

}

Enemy::~Enemy()
{
	this->Finalize();
}

Enemy::SP Enemy::Create(bool flag_)
{
	Enemy::SP to = Enemy::SP(new Enemy());
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