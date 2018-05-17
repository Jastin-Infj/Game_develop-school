#include "Back.h"
//�ʃ^�X�N��ʃI�u�W�F�N�g�𐶐�����ꍇ�����ɂ���class�̏����ꂽh���C���N���[�h����

bool Back::Initialize()
{
	//-----------------------------
	//�������ɏ������鏉�����������L�q
	//-----------------------------
	this->taskName = "Back";		//�������Ɏg�����߂̖���o�^����
	__super::Init(taskName);		//TaskObject���̏������s��

	this->filePath = "back.jpg";
	this->image.Create(filePath);
	this->CreateObject(Cube, Vec2(0, 0), OGge->window->GetSize(), 0);
	SetDrawOrder(0.f);
	std::cout << "�w�i�@������" << std::endl;
	return true;
}
void Back::UpDate()
{
	//--------------------
	//�X�V���ɍs���������L�q
	//--------------------
}

void Back::Render2D()
{
	//--------------------
	//�`�掞�ɍs���������L�q
	//--------------------
	Box2D draw(position,Scale);
	draw.OffsetSize();
	Box2D src = this->Src;
	src.OffsetSize();
	image.Draw(draw, src);
}

bool Back::Finalize()
{
	//-----------------------------------------
	//���̃I�u�W�F�N�g�����ł���Ƃ��ɍs���������L�q
	//-----------------------------------------
	image.Finalize();
	return true;
}

//----------------------------
//�������牺��class���̂ݕύX����
//�ق��͕ύX���Ȃ�����
//----------------------------
Back::Back()
{
	std::cout << "�w�i�@����" << std::endl;
}

Back::~Back()
{
	this->Finalize();
	std::cout << "�w�i�@���" << std::endl;
}

Back::SP Back::Create(bool flag_)
{
	Back::SP to = Back::SP(new Back());
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