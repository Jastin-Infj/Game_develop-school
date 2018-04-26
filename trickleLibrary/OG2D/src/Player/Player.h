#pragma once
#include "Object\Object.h"

class Player : public Object
{
public:
	Player()
	{

	}
	~Player()
	{

	}
	void Initialize();
	void Update();
	void Finalize();
	void Render();

private:
	//’Ç‰Á•Ï”//
	Texture image;
	std::string FilePath;
};