#pragma once
#include "Object\Object.h"

class BackGround :public Object
{
public:
	BackGround()
	{

	}
	~BackGround()
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