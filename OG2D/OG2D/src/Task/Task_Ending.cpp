#include "Task_Ending.h"
//�ʃ^�X�N��ʃI�u�W�F�N�g�𐶐�����ꍇ�����ɂ���class�̏����ꂽh���C���N���[�h����

bool Ending::Initialize()
{
	//-----------------------------
	//�������ɏ������鏉�����������L�q
	//-----------------------------
	this->taskName = "";			//�������Ɏg�����߂̖���o�^����
	__super::Init(taskName);		//TaskObject���̏������s��
									//������

	return true;
}

void Ending::UpDate()
{
	//--------------------
	//�X�V���ɍs���������L�q
	//--------------------
}

void Ending::Render2D()
{
	//--------------------
	//�`�掞�ɍs���������L�q
	//--------------------
}
bool Ending::Finalize()
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
Ending::Ending()
{

}

Ending::~Ending()
{
	this->Finalize();
}

Ending::SP Ending::Create(bool flag_)
{

	Ending::SP to = Ending::SP(new Ending());
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