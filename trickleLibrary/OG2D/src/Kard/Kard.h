#pragma once
#include "Object\Object.h"
class Kard : public Object
{
public:
	Kard();
	~Kard();
	void Initialize();
	void Update();
	void Render();
	void Finalize();
private:

	enum State
	{
		NON,  //めくられていない
	    ON    //めくっている
	};
	State state; //カードの状態を表す状態

	//カード情報//
	int number;			   //番号;
	int mark;			   //マーク
	std::string  FilePath; //ファイル名パス
	Texture image;	       //画像読み込み
};