#include "Task_Game.h"

//別タスクや別オブジェクトを生成する場合ここにそのclassの書かれたhをインクルードする
#include "Asset\Enemy.h"
#include "Asset\Boll.h"
#include "Asset\Player.h"
#include "Back\GameBack.h"

#include "Task_Ending.h"
bool Game::Initialize()
{
	//-----------------------------
	//生成時に処理する初期化処理を記述
	//-----------------------------
	this->taskName = "Game";		//検索時に使うための名を登録する
	__super::Init(taskName);		//TaskObject内の処理を行う
									//生成例
	auto back = GameBack::Create();
	return true;
}

void Game::UpDate()
{
	//--------------------
	//更新時に行う処理を記述
	//--------------------
}

void Game::Render2D()
{
	//--------------------
	//描画時に行う処理を記述
	//--------------------
}
bool Game::Finalize()
{
	//-----------------------------------------
	//このオブジェクトが消滅するときに行う処理を記述
	//-----------------------------------------
	//次のタスクを作るかかつアプリケーションが終了予定かどうか
	if (this->GetNextTask() && !OGge->GetDeleteEngine())
	{

	}
	return true;
}
//----------------------------
//ここから下はclass名のみ変更する
//ほかは変更しないこと
//----------------------------
Game::Game()
{

}

Game::~Game()
{
	this->Finalize();
}

Game::SP Game::Create(bool flag_)
{

	Game::SP to = Game::SP(new Game());
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