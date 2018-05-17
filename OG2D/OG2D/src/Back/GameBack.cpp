#include "GameBack.h"
//別タスクや別オブジェクトを生成する場合ここにそのclassの書かれたhをインクルードする

bool GameBack::Initialize()
{
	//-----------------------------
	//生成時に処理する初期化処理を記述
	//-----------------------------
	this->taskName = "GameBack";	//検索時に使うための名を登録する
	this->filePath = "map.png";
	__super::Init(taskName);		//TaskObject内の処理を行う
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
	//更新時に行う処理を記述
	//--------------------
}

void GameBack::Render2D()
{
	//--------------------
	//描画時に行う処理を記述
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
	//このオブジェクトが消滅するときに行う処理を記述
	//-----------------------------------------
	image.Finalize();
	return true;
}

//----------------------------
//ここから下はclass名のみ変更する
//ほかは変更しないこと
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