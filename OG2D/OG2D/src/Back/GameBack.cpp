#include "GameBack.h"
//�ʃ^�X�N��ʃI�u�W�F�N�g�𐶐�����ꍇ�����ɂ���class�̏����ꂽh���C���N���[�h����

bool GameBack::Initialize()
{
	//-----------------------------
	//�������ɏ������鏉�����������L�q
	//-----------------------------
	this->taskName = "GameBack";	//�������Ɏg�����߂̖���o�^����
	this->filePath = "map.png";
	__super::Init(taskName);		//TaskObject���̏������s��
	{
		Vec2 windowsize = OGge->window->GetSize();
		this->CreateObject(Cube, Vec2(0, 0), windowsize, 0);
	}
	SetDrawOrder(0.f);
	image.Create(filePath);
	return true;
}
void GameBack::UpDate()
{
	//--------------------
	//�X�V���ɍs���������L�q
	//--------------------
}

void GameBack::Render2D()
{
	//--------------------
	//�`�掞�ɍs���������L�q
	//--------------------
	Box2D draw(position, Scale);
	draw.OffsetSize();
	Box2D src = this->Src;
	src.OffsetSize();
	image.Draw(draw,src);
}

bool GameBack::Finalize()
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
GameBack::GameBack()
{

}

GameBack::~GameBack()
{
	this->Finalize();
}

GameBack::SP GameBack::Create(bool flag_)
{
	GameBack::SP to = GameBack::SP(new GameBack());
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