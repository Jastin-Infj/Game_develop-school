#pragma once
#include "Object\Object.h"
#include "easing\easing.hpp"
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
	//í«â¡ïœêî//
	Texture image;
	std::string FilePath;

	ci_ext::Easing easingX;
	ci_ext::Easing easingY;

	Vec2 Map_size;
};