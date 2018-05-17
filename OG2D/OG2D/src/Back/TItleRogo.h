#pragma once
//必要読み込みファイル
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"
class Rogo : public GameObject, public TaskObject
{
	//-------------------------------------------
	//各自で制作するときに使用するものはここに記述する
	//-------------------------------------------
public:

private:
	Texture image;
	std::string filePath;
	Easing  easing;
	bool easingflag;
	const Box2D Src = { Vec2(0,0),Vec2(425,283) };
	//------------------
	//固定化されている処理
	//------------------
private:
	bool Move();
public:
	bool GetEasingFlag();
public:
	std::string taskName;
	virtual ~Rogo();
	typedef std::shared_ptr<Rogo> SP;
	static Rogo::SP Create(bool = true);
	Rogo();
	//-------------
	//変更しないこと
	//-------------
	bool Initialize();		//初期化処理
	void UpDate();			//更新処理
	void Render2D();		//描画処理
	bool Finalize();		//解放処理
};