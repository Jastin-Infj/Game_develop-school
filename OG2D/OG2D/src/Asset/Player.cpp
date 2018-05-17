#include "Player.h"
//別タスクや別オブジェクトを生成する場合ここにそのclassの書かれたhをインクルードする

bool Player::Initialize()
{
	//-----------------------------
	//生成時に処理する初期化処理を記述
	//-----------------------------
	this->taskName = "";			//検索時に使うための名を登録する
	__super::Init(taskName);		//TaskObject内の処理を行う



	return true;
}
void Player::UpDate()
{
	//--------------------
	//更新時に行う処理を記述
	//--------------------
}

void Player::Render2D()
{
	//--------------------
	//描画時に行う処理を記述
	//--------------------

}

bool Player::Finalize()
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
Player::Player()
{

}

Player::~Player()
{
	this->Finalize();
}

Player::SP Player::Create(bool flag_)
{
	Player::SP to = Player::SP(new Player());
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