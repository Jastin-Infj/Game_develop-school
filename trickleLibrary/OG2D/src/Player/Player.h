#pragma once
#include "Object\Object.h"
#include "Kard\Kard.h"

class Kard;

class Player : public Object
{
public:
	Player();
	~Player();
	void Initialize();
	void Create(Vec2, Vec2, Vec2 , Vec2);//座標　大きさ　画像元　座標　大きさ
	void Update();
	void Move();						//カーソルの動き
	void Kard_Open();					//カードを開く
	void Finalize();
	void Render();
	Vec2 Get_Pos();						//カーソルの情報を持ってくる 使用なし
	void Set_Pointa(Kard*);			//カードの情報を受け取る
private:
	//追加変数//
	Texture image;
	std::string FilePath;

	//画像元情報
	Vec2 Src_Pos;
	Vec2 Src_Scale;

	//移動量
	const Vec2 moveVec = Vec2(160,210);

	//カードの情報
	std::vector<Kard*> k_pointa;
};