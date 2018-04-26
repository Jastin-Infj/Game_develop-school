#pragma once
#include "Object\Object.h"
#include "Kard\Kard.h"

class Kard;

class Player : public Object
{
public:
	Player();
	~Player();
	void Initialize();
	void Create(Vec2, Vec2, Vec2 , Vec2);//���W�@�傫���@�摜���@���W�@�傫��
	void Update();
	void Move();						//�J�[�\���̓���
	void Kard_Open();					//�J�[�h���J��
	void Finalize();
	void Render();
	Vec2 Get_Pos();						//�J�[�\���̏��������Ă��� �g�p�Ȃ�
	void Set_Pointa(Kard*);			//�J�[�h�̏����󂯎��
private:
	//�ǉ��ϐ�//
	Texture image;
	std::string FilePath;

	//�摜�����
	Vec2 Src_Pos;
	Vec2 Src_Scale;

	//�ړ���
	const Vec2 moveVec = Vec2(160,210);

	//�J�[�h�̏��
	std::vector<Kard*> k_pointa;
};