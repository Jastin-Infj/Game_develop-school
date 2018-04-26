#pragma once
#include "Object\Object.h"
class Kard : public Object
{
public:
	Kard();
	~Kard();
	void Initialize();
	void Create(Vec2, Vec2,Vec2);//座標　大きさ　画像元の大きさ
	void Update();
	void Render();
	void Finalize();
	void CheckHit();			//カーソルと接触をしているのか？
	std::map<int, Vec2>number;	//カードの識別番号によってSrcの画像元を変更させる
private:
	enum State
	{
		NON,  //めくられていない
	    ON    //めくっている
	};
	State state; //カードの状態を表す状態

	//画像元情報
	Vec2 Src_Pos;	//カードの画像元座標
	Vec2 Src_Scale;	//カードの画像元サイズ

	//カード情報//
	std::string  FilePath;		//ファイル名パス
	Texture image;				//画像読み込み
	
	//カーソルが当たっているときのフラグ
	bool Corsol;
};