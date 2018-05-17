#include "TItleRogo.h"
//�ʃ^�X�N��ʃI�u�W�F�N�g�𐶐�����ꍇ�����ɂ���class�̏����ꂽh���C���N���[�h����

bool Rogo::Initialize()
{
	//-----------------------------
	//�������ɏ������鏉�����������L�q
	//-----------------------------
	this->taskName = "Rogo";		//�������Ɏg�����߂̖���o�^����
	__super::Init(taskName);		//TaskObject���̏������s��
	this->filePath = "title2.png";
	this->image.Create(filePath);
	{
		Vec2 windowsize = OGge->window->GetSize();
		this->CreateObject(Cube, Vec2(0.f, windowsize.y /2 - 300), Vec2(425, 283), 0);
	}
	easingflag = false;
	SetDrawOrder(0.1f);
	std::cout << "�^�C�g�����S�@������" << std::endl;
	return true;
}
void Rogo::UpDate()
{
	//--------------------
	//�X�V���ɍs���������L�q
	//--------------------
	easingflag = Move();
}
bool Rogo::Move()
{
	Vec2 windowsize = OGge->window->GetSize();
	position.x = easing.quint.Out(easing.Time(14), -200, windowsize.x - windowsize.x / 2, 14);
	if (!easing.isplay())
	{
		return true;
	}
	return false;
}
void Rogo::Render2D()
{
	//--------------------
	//�`�掞�ɍs���������L�q
	//--------------------
	Box2D draw(position, Scale);
	draw.OffsetSize();
	Box2D src = this->Src;
	src.OffsetSize();
	image.Draw(draw, src);
}

bool Rogo::Finalize()
{
	//-----------------------------------------
	//���̃I�u�W�F�N�g�����ł���Ƃ��ɍs���������L�q
	//-----------------------------------------

	image.Finalize();
	return true;
}
bool Rogo::GetEasingFlag()
{
	return this->easingflag;
}
//----------------------------
//�������牺��class���̂ݕύX����
//�ق��͕ύX���Ȃ�����
//----------------------------
Rogo::Rogo()
{
	std::cout << "�^�C�g�����S�@����" << std::endl;
}

Rogo::~Rogo()
{
	this->Finalize();
	std::cout << "�^�C�g�����S�@���" << std::endl;
}

Rogo::SP Rogo::Create(bool flag_)
{
	Rogo::SP to = Rogo::SP(new Rogo());
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