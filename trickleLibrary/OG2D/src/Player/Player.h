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
	//�ǉ��ϐ�//
	Texture image;
	std::string FilePath;
};