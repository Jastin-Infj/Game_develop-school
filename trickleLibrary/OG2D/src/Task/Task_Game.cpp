#include "Task_Game.h"
#include <time.h>
using namespace std;
#define ADD_FUNCTION(a) \
	[](std::vector<Object*>* objs_) { a(objs_); }
//-------------------------------------------------------------------------------------------------
Game::Game()
{
	
}
Game::~Game()
{

}
void Game::Initialize()
{
	cout << "Game‰Šú‰»" << endl;
	back.Initialize();
	player.Create(Vec2(0, 0), Vec2(150, 200), Vec2(300 * 6, 400),Vec2(300,400));
	player.Initialize();

	//ƒJ[ƒh‚Ì¶¬
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			kard[y][x].Create(Vec2(x * 160 ,y * 210), Vec2(150, 200),Vec2(300,400));
			kard[y][x].Initialize();
			kard[y][x].Set_Pointa(&player);
			player.Set_Pointa(&kard[y][x]);
		}
	}
}
//-------------------------------------------------------------------------------------------------
TaskFlag Game::Update()
{
	TaskFlag nowTask = Task_Game;
	player.Update();
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			kard[y][x].Update();
		}
	}
	if (gameEngine->in.key.down(Input::KeyBoard::S))
	{
		nowTask = Task_Title;
	}

	return nowTask;
}
//-------------------------------------------------------------------------------------------------
void Game::Render2D()
{
	back.Render();
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			kard[y][x].Render();
		}
	}
	player.Render();
}
//-------------------------------------------------------------------------------------------------
void Game::Finalize()
{
	back.Finalize();
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			kard[y][x].Finalize();
		}
	}
	player.Finalize();
}
//-------------------------------------------------------------------------------------------------