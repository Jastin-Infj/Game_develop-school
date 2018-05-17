#include "Enemy.h"
//別タスクや別オブジェクトを生成する場合ここにそのclassの書かれたhをインクルードする

bool Enemy::Initialize()
{
	//-----------------------------
	//生成時に処理する初期化処理を記述
	//-----------------------------
	this->taskName = "";			//検索時に使うための名を登録する
	__super::Init(taskName);		//TaskObject内の処理を行う



	return true;
}
void Enemy::UpDate()
{
	//--------------------
	//更新時に行う処理を記述
	//--------------------
}

void Enemy::Render2D()
{
	//--------------------
	//描画時に行う処理を記述
	//--------------------

}

bool Enemy::Finalize()
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
Enemy::Enemy()
{

}

Enemy::~Enemy()
{
	this->Finalize();
}

Enemy::SP Enemy::Create(bool flag_)
{
	Enemy::SP to = Enemy::SP(new Enemy());
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