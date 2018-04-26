#pragma once
#include "Object\Object.h"

#include "Player\Player.h"

class Player;

class Kard : public Object
{
public:
	//その他
	enum State
	{
		NON,  //めくられていない
		ON    //めくっている
	};
public:
	Kard();
	~Kard();
	void Initialize();
	void Create(Vec2, Vec2,Vec2);//座標　大きさ　画像元の大きさ
	void Update();
	void Render();
	void Finalize();
	bool CheckHit();			//カーソルと接触をしているのか？
	void Set_Pointa(Object*);	//ターゲットの情報を受け取る
	std::map<int, Vec2>number;	//カードの識別番号によってSrcの画像元を変更させる
	void Set_State(State);		//ステートを代入できる
	State Get_State();			//ステートを返す
	void Kard_Open();			//カードをオープンさせる
	
private:
	State state; //カードの状態を表す状態
	//画像元情報
	Vec2 Src_Pos;	//カードの画像元座標
	Vec2 Src_Scale;	//カードの画像元サイズ

	//カード情報//
	std::string  FilePath;		//ファイル名パス
	Texture image;				//画像読み込み
	//Playerの情報
	Player* p_pointa;

	//ランダムで選ばれた値
	int Random;

	//カーソルが当たっているときのフラグ
	bool Corsol;

	//カードの開くカウンタ
	int moveCnt;
};