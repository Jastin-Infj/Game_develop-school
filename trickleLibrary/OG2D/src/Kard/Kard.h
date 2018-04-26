#pragma once
#include "Object\Object.h"
class Kard : public Object
{
public:
	Kard();
	~Kard();
	void Initialize();
	void Create(Vec2, Vec2,Vec2);//���W�@�傫���@�摜���̑傫��
	void Update();
	void Render();
	void Finalize();
	void CheckHit();			//�J�[�\���ƐڐG�����Ă���̂��H
	std::map<int, Vec2>number;	//�J�[�h�̎��ʔԍ��ɂ����Src�̉摜����ύX������
private:
	enum State
	{
		NON,  //�߂����Ă��Ȃ�
	    ON    //�߂����Ă���
	};
	State state; //�J�[�h�̏�Ԃ�\�����

	//�摜�����
	Vec2 Src_Pos;	//�J�[�h�̉摜�����W
	Vec2 Src_Scale;	//�J�[�h�̉摜���T�C�Y

	//�J�[�h���//
	std::string  FilePath;		//�t�@�C�����p�X
	Texture image;				//�摜�ǂݍ���
	
	//�J�[�\�����������Ă���Ƃ��̃t���O
	bool Corsol;
};