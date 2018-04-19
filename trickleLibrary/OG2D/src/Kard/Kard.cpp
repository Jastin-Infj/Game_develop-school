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

	//回転する場合があるので意識しておく
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
//履歴　読み込みからスタートせよ　false