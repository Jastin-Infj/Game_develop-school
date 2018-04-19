#include "Kard.h"

const Vec2 MapSize(300.f, 400.f);

Kard::Kard()
{

}
Kard::~Kard()
{

}
void Kard::Initialize()
{
	FilePath = "Card.png";

	//��]����ꍇ������̂ňӎ����Ă���
	CreateObject(Objform::Cube, Vec2(0, 0), MapSize, 0);
}
void Kard::Update()
{

}
void Kard::Render()
{
	Box2D draw(position, Scale);
	draw.OffsetSize();
	Box2D src(draw);
	image.Draw(draw, src);
}
void Kard::Finalize()
{
	image.Finalize();
}
//�����@�ǂݍ��݂���X�^�[�g����@false