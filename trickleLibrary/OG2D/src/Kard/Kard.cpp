#include "Kard.h"
using namespace std;
Kard::Kard()
{
	FilePath = "Card.png";

	int size = 300;		//�摜����X���W

	//�J�[�h�̉摜���̏��𑗂�
	for (int i = 1; i <= 6; ++i) 
	{
		number[i] = Vec2(size * (i - 1), 0);
	}
	number[0] = Vec2(size * 6, 0);
}
Kard::~Kard()
{

}
void Kard::Initialize()
{
	image.TextureCreate(FilePath);
	
}
void Kard::Create(Vec2 pos , Vec2 scale,Vec2 src_scale)
{
	CreateObject(Cube, pos, scale, 0);
	Src_Pos = number[0];   //�J�[�h�������
	Src_Scale = src_scale;
	state = State::NON;		//�J�[�h�̂߂����Ă��Ȃ�
	this->Corsol = false;	//�J�[�\���ƐڐG���Ă���
}
void Kard::Update()
{
	//�J�[�\���ƐڐG�����Ă�����E�E�E�@�܂��̓J�[�\�������̍��W�l�܂ł�����E�E�E

	//����{�^���������ꂽ��E�E�Enumber�̔z�u��ω�������
}
void Kard::Render()
{
	Box2D draw(position, Scale);
	draw.OffsetSize();
	Box2D src(Src_Pos,Src_Scale);
	src.OffsetSize();
	image.Draw(draw, src);
}
void Kard::Finalize()
{
	image.Finalize();
}
//�����@�ǂݍ��݂���X�^�[�g����@false