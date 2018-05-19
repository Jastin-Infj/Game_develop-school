#include "Task_Title.h"
//別タスクや別オブジェクトを生成する場合ここにそのclassの書かれたhをインクルードする
#include "Task_Game.h"

#include "Back\Back.h"
#include "Back\TItleRogo.h"
bool Title::Initialize()
{
	//-----------------------------
	//生成時に処理する初期化処理を記述
	//-----------------------------
	this->taskName = "Title";			//検索時に使うための名を登録する
	__super::Init(taskName);		//TaskObject内の処理を行う
	//生成例

	auto back = Back::Create();
	auto rogo = Rogo::Create();

	std::cout << "タイトル　初期化" << std::endl;
	return true;
}

void Title::UpDate()
{
	//--------------------
	//更新時に行う処理を記述
	//--------------------
	auto rogo = OGge->GetTask<Rogo>("Rogo");
	if (rogo != nullptr)
	{
		if (rogo->GetEasingFlag())
		{
			if (OGge->in->key.down(Input::KeyBoard::S))
			{
				Kill();
			}
		}
	}
}

void Title::Render2D()
{
	//--------------------
	//描画時に行う処理を記述
	//--------------------
}
bool Title::Finalize()
{
	//-----------------------------------------
	//このオブジェクトが消滅するときに行う処理を記述
	//-----------------------------------------
	//次のタスクを作るかかつアプリケーションが終了予定かどうか
	auto back = OGge->GetTask<Back>("Back");
	if (back)
	{
		back->Kill();
	}
	auto rogo = OGge->GetTask<Rogo>("Rogo");
	if (rogo)
	{
		rogo->Kill();
	}

	return true;
}
//----------------------------
//ここから下はclass名のみ変更する
//ほかは変更しないこと
//----------------------------
Title::Title()
{
	std::cout << "タイトル　生成" << std::endl;
}

Title::~Title()
{
	Finalize();
	std::cout << "タイトル　解放" << std::endl;
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{
		auto game = Game::Create();
	}
} 

Title::SP Title::Create(bool flag_)
{

	Title::SP to = Title::SP(new Title());
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