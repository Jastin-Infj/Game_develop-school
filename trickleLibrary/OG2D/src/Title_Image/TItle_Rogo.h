#pragma once
#include "Object\Object.h"
#include "OGSystem\Easing\easing.hpp"
class Title_Rogo : Object
{
public:
	Title_Rogo();
	~Title_Rogo();
	void Initialize();
	void Update();
	void Finalize();
	void Render();

private:
	//�ǉ��ϐ�//
	Texture image;
	std::string FilePath;

	Easing easing;
	Vec2 Map_size;
};