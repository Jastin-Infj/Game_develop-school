#include "Task_Title.h"

void Title::Initialize()
{
	std::cout << "Title初期化" << std::endl;

	back.Initialize();
	title_rogo.Initialize();
}

TaskFlag Title::Update()
{
	TaskFlag nowtask = Task_Title;
	//Sキーが押されたら・・・
	if (gameEngine->in.key.down(Input::KeyBoard::S))
	{
		nowtask = Task_Game;
	}
	return nowtask;
}

void Title::Render2D()
{
	back.Render();
	title_rogo.Render();
}

void Title::Finalize()
{
	std::cout << "Title解放" << std::endl;
	title_rogo.Finalize();
	back.Finalize();
}