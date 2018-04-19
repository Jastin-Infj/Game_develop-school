#include "Task_Title.h"

void Title::Initialize()
{
	std::cout << "Title������" << std::endl;
	map.LoadMap("test.txt");
}

TaskFlag Title::Update()
{
	TaskFlag nowtask = Task_Title;

	return nowtask;
}

void Title::Render2D()
{
	map.MapRender();
}

void Title::Finalize()
{
	std::cout << "Title���" << std::endl;
	map.Finalize();

	cm.Destroy();
}