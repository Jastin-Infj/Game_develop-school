#pragma once
//必要読み込みファイル
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"

class Boll : public GameObject, public TaskObject
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
	virtual ~Boll();
	typedef std::shared_ptr<Boll> SP;
	static Boll::SP Create(bool = true);
	Boll();
	//-------------
	//変更しないこと
	//-------------
	bool Initialize();		//初期化処理
	void UpDate();			//更新処理
	void Render2D();		//描画処理
	bool Finalize();		//解放処理
};