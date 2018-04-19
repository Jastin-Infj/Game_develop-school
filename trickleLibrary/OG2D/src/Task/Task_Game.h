#pragma once
//______________________________//
//|タスクサンプル               |//
//|履歴：2018/03/20金子翔       |//
//|履歴：2018/04/17劉韋君　    |//
//|____________________________|//
#include "Win\WinMain.h"
#include "CollisionManager\CollisionManager.h"
#include "OGSystem\OGsystem.h"
#include "Back\Back.h"

class Game
{
public:
	void Initialize();
	TaskFlag Update();
	void Render2D();
	void Finalize();
	//☆☆☆☆//
	//追加変数//
	//☆☆☆☆//
	//std::vector<Bucket*> bucket;
	CollisionManager cm;
private:
	Back back;
	//---------------------------------------------------------------------
	//メンバー関数
	//---------------------------------------------------------------------
};