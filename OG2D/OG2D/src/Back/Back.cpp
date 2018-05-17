#include "Back.h"
//別タスクや別オブジェクトを生成する場合ここにそのclassの書かれたhをインクルードする

bool Back::Initialize()
{
	//-----------------------------
	//生成時に処理する初期化処理を記述
	//-----------------------------
	this->taskName = "Back";		//検索時に使うための名を登録する
	__super::Init(taskName);		//TaskObject内の処理を行う

	this->filePath = "back.jpg";
	this->image.Create(filePath);
	this->CreateObject(Cube, Vec2(0, 0), OGge->window->GetSize(), 0);
	SetDrawOrder(0.f);
	std::cout << "背景　初期化" << std::endl;
	return true;
}
void Back::UpDate()
{
	//--------------------
	//更新時に行う処理を記述
	//--------------------
}

void Back::Render2D()
{
	//--------------------
	//描画時に行う処理を記述
	//--------------------
	Box2D draw(position,Scale);
	draw.OffsetSize();
	Box2D src = this->Src;
	src.OffsetSize();
	image.Draw(draw, src);
}

bool Back::Finalize()
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
Back::Back()
{
	std::cout << "背景　生成" << std::endl;
}

Back::~Back()
{
	this->Finalize();
	std::cout << "背景　解放" << std::endl;
}

Back::SP Back::Create(bool flag_)
{
	Back::SP to = Back::SP(new Back());
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