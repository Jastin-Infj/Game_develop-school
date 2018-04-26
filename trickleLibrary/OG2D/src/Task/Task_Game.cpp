#include "Task_Game.h"
using namespace std;
#define ADD_FUNCTION(a) \
	[](std::vector<Object*>* objs_) { a(objs_); }
//-------------------------------------------------------------------------------------------------
void Game::Initialize()
{
	cout << "Game‰Šú‰»" << endl;
	back.Initialize();



	//ƒJ[ƒh‚Ì¶¬
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 6; ++x)
		{
			kard[y][x].Create(Vec2(0 + x * 150 + x * 10 ,0 + y * 200 + y * 10), Vec2(150, 200),Vec2(300,400));
			kard[y][x].Initialize();
		}
	}
}
//-------------------------------------------------------------------------------------------------
TaskFlag Game::Update()
{
	TaskFlag nowTask = Task_Game;

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
}
//-------------------------------------------------------------------------------------------------