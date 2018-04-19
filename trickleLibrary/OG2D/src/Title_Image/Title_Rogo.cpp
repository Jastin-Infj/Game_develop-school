#include "Title_Rogo.h"

Title_Rogo::Title_Rogo()
{

}
Title_Rogo::~Title_Rogo()
{

}
void Title_Rogo::Initialize()
{
	//マップサイズの格納
	Map_size = Vec2(240, 120);

	FilePath = "title.png";
	image.TextureCreate(FilePath);
	CreateObject(Objform::Cube, Vec2(640 / 2, 100), Map_size, 0);
}
void Title_Rogo::Update()
{
	
	//easingは後回し
}
void Title_Rogo::Render()
{
	Box2D draw(position, Scale * 2);
	draw.OffsetSize();
	Box2D src(0.0f,0.0f,Map_size.x , Map_size.y);
	image.Draw(draw,src);
}
void Title_Rogo::Finalize()
{
	image.Finalize();
}
