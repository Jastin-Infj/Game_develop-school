#pragma once
//必要読み込みファイル
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"

class GameBack : public GameObject, public TaskObject
{
	//-------------------------------------------
	//各自で制作するときに使用するものはここに記述する
	//-------------------------------------------
public:

private:
	Texture image;
	std::string filePath;
	const Box2D Src{ Vec2(0,0), Vec2(1024,1024) };
	//------------------
	//固定化されている処理
	//------------------
public:
	std::string taskName;
	virtual ~GameBack();
	typedef std::shared_ptr<GameBack> SP;
	static GameBack::SP Create(bool = true);
	GameBack();
	//-------------
	//変更しないこと
	//-------------
	bool Initialize();		//初期化処理
	void UpDate();			//更新処理
	void Render2D();		//描画処理
	bool Finalize();		//解放処理
};