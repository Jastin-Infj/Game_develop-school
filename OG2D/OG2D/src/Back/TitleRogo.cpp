#include "TItleRogo.h"
//別タスクや別オブジェクトを生成する場合ここにそのclassの書かれたhをインクルードする

bool Rogo::Initialize()
{
	//-----------------------------
	//生成時に処理する初期化処理を記述
	//-----------------------------
	this->taskName = "Rogo";		//検索時に使うための名を登録する
	__super::Init(taskName);		//TaskObject内の処理を行う
	this->filePath = "title2.png";
	this->image.Create(filePath);
	{
		Vec2 windowsize = OGge->window->GetSize();
		this->CreateObject(Cube, Vec2(0.f, windowsize.y /2 - 300), Vec2(425, 283), 0);
	}
	easingflag = false;
	SetDrawOrder(0.1f);
	std::cout << "タイトルロゴ　初期化" << std::endl;
	return true;
}
void Rogo::UpDate()
{
	//--------------------
	//更新時に行う処理を記述
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
	//描画時に行う処理を記述
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
	//このオブジェクトが消滅するときに行う処理を記述
	//-----------------------------------------

	image.Finalize();
	return true;
}
bool Rogo::GetEasingFlag()
{
	return this->easingflag;
}
//----------------------------
//ここから下はclass名のみ変更する
//ほかは変更しないこと
//----------------------------
Rogo::Rogo()
{
	std::cout << "タイトルロゴ　生成" << std::endl;
}

Rogo::~Rogo()
{
	this->Finalize();
	std::cout << "タイトルロゴ　解放" << std::endl;
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