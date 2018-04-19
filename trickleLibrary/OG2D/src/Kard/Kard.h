#pragma once
#include "Object\Object.h"
class Kard : public Object
{
public:
	Kard();
	~Kard();
	void Initialize();
	void Update();
	void Render();
	void Finalize();
private:

	enum State
	{
		NON,  //�߂����Ă��Ȃ�
	    ON    //�߂����Ă���
	};
	State state; //�J�[�h�̏�Ԃ�\�����

	//�J�[�h���//
	int number;			   //�ԍ�;
	int mark;			   //�}�[�N
	std::string  FilePath; //�t�@�C�����p�X
	Texture image;	       //�摜�ǂݍ���
};