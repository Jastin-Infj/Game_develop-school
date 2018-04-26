#pragma once
#include "Object\Object.h"

#include "Player\Player.h"

class Player;

class Kard : public Object
{
public:
	//���̑�
	enum State
	{
		NON,  //�߂����Ă��Ȃ�
		ON    //�߂����Ă���
	};
public:
	Kard();
	~Kard();
	void Initialize();
	void Create(Vec2, Vec2,Vec2);//���W�@�傫���@�摜���̑傫��
	void Update();
	void Render();
	void Finalize();
	bool CheckHit();			//�J�[�\���ƐڐG�����Ă���̂��H
	void Set_Pointa(Object*);	//�^�[�Q�b�g�̏����󂯎��
	std::map<int, Vec2>number;	//�J�[�h�̎��ʔԍ��ɂ����Src�̉摜����ύX������
	void Set_State(State);		//�X�e�[�g�����ł���
	State Get_State();			//�X�e�[�g��Ԃ�
	void Kard_Open();			//�J�[�h���I�[�v��������
	
private:
	State state; //�J�[�h�̏�Ԃ�\�����
	//�摜�����
	Vec2 Src_Pos;	//�J�[�h�̉摜�����W
	Vec2 Src_Scale;	//�J�[�h�̉摜���T�C�Y

	//�J�[�h���//
	std::string  FilePath;		//�t�@�C�����p�X
	Texture image;				//�摜�ǂݍ���
	//Player�̏��
	Player* p_pointa;

	//�����_���őI�΂ꂽ�l
	int Random;

	//�J�[�\�����������Ă���Ƃ��̃t���O
	bool Corsol;

	//�J�[�h�̊J���J�E���^
	int moveCnt;
};