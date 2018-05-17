#pragma once
//必要読み込みファイル
#include "OGSystem\OGsystem.h"

class Title : public TaskObject
{
	//-------------------------------------------
	//各自で制作するときに使用するものはここに記述する
	//-------------------------------------------
public:
private:

	//------------------
	//固定化されている処理
	//------------------
public:
	std::string taskName;
	virtual ~Title();
	typedef std::shared_ptr<Title> SP;
	static Title::SP Create(bool = true);
	Title();
	//-------------
	//変更しないこと
	//-------------
	bool Initialize();		//初期化処理
	void UpDate();			//更新処理
	void Render2D();		//描画処理
	bool Finalize();		//解放処理
};