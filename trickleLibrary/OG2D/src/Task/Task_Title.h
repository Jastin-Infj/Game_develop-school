#pragma once
//______________________________//
//|タイトルタスク               |//
//|履歴：2018/03/20金子翔       |//
//|____________________________|//
#include "Win\WinMain.h"
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"
#include "Map\Map.h"
#include "CollisionManager\CollisionManager.h"
class Title
{
public:
	void Initialize();
	TaskFlag Update();
	void Render2D();
	void Finalize();

	//☆☆☆☆//
	//追加変数//
	//☆☆☆☆//
	CollisionManager cm;
	Map map;

};