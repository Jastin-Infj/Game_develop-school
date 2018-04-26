#include "Kard.h"
using namespace std;
Kard::Kard()
{
	FilePath = "Card.png";

	int size = 300;		//画像元のX座標

	//カードの画像元の情報を送る
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
	Src_Pos = number[0];   //カードが裏状態
	Src_Scale = src_scale;
	state = State::NON;		//カードのめくられていない
	this->Corsol = false;	//カーソルと接触している
}
void Kard::Update()
{
	//カーソルと接触をしていたら・・・　またはカーソルがその座標値まできたら・・・

	//決定ボタンを押されたら・・・numberの配置を変化させる
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
//履歴　読み込みからスタートせよ　false