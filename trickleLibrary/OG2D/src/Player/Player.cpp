#include "Player.h"
using namespace std;
Player::Player()
{
	//‹¤’Ê‚µ‚Ä‚¢‚é‚à‚Ì‚Í‚±‚±‚É“ü—Í‚·‚é
	FilePath = "card.png";
	objectTag = "Player";
}
Player::~Player()
{

}
void Player::Create(Vec2 pos, Vec2 scale, Vec2 src_pos, Vec2 src_scale)
{
	CreateObject(Cube, pos, scale, 0);
	Src_Pos = src_pos;
	Src_Scale = src_scale;
}
void Player::Initialize()
{
	image.TextureCreate(FilePath);
}
void Player::Update()
{
	Move();
	Kard_Open();
}
void Player::Render()
{
	Box2D draw(position, Scale);
	draw.OffsetSize();
	Box2D src(Src_Pos, Src_Scale);
	src.OffsetSize();
	image.Draw(draw, src);
}
void Player::Finalize()
{
	image.Finalize();
	k_pointa.clear();
}
void Player::Move()
{
	if (gameEngine->in.key.down(Input::KeyBoard::LEFT))
	{
		position.x -= moveVec.x;
	}
	if (gameEngine->in.key.down(Input::KeyBoard::RIGHT))
	{
		position.x += moveVec.x;
	}
	if (gameEngine->in.key.down(Input::KeyBoard::UP))
	{
		position.y -= moveVec.y;
	}
	if (gameEngine->in.key.down(Input::KeyBoard::DOWN))
	{
		position.y += moveVec.y;
	}
}
Vec2 Player::Get_Pos()
{
	return position;
}
void Player::Set_Pointa(Kard* obj)
{
	k_pointa.push_back((Kard*)obj);
}
void Player::Kard_Open()
{
	if (gameEngine->in.key.down(Input::KeyBoard::Z))
	{
		for (auto k : k_pointa)
		{
			//‚ ‚½‚è‚È‚ç‚ÎEEE‚Í‚¸‚·‚à‚ ‚é‚Æ—Ç‚¢
			if (k->CheckHit())
			{
				//k->Set_State(Kard::State::ON);
				k->Kard_Open();
			}
		}
	}
}
