#pragma once
//必要読み込みファイル
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"

class Enemy : public GameObject, public TaskObject
{
	//-------------------------------------------
	//各自で制作するときに使用するものはここに記述する
	//-------------------------------------------
public:

private:
	Texture image;

	//------------------
	//固定化されている処理
	//------------------
public:
	std::string taskName;
	virtual ~Enemy();
	typedef std::shared_ptr<Enemy> SP;
	static Enemy::SP Create(bool = true);
	Enemy();
	//-------------
	//変更しないこと
	//-------------
	bool Initialize();		//初期化処理
	void UpDate();			//更新処理
	void Render2D();		//描画処理
	bool Finalize();		//解放処理
};