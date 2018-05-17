#pragma once
//�K�v�ǂݍ��݃t�@�C��
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"
class Rogo : public GameObject, public TaskObject
{
	//-------------------------------------------
	//�e���Ő��삷��Ƃ��Ɏg�p������̂͂����ɋL�q����
	//-------------------------------------------
public:

private:
	Texture image;
	std::string filePath;
	Easing  easing;
	bool easingflag;
	const Box2D Src = { Vec2(0,0),Vec2(425,283) };
	//------------------
	//�Œ艻����Ă��鏈��
	//------------------
private:
	bool Move();
public:
	bool GetEasingFlag();
public:
	std::string taskName;
	virtual ~Rogo();
	typedef std::shared_ptr<Rogo> SP;
	static Rogo::SP Create(bool = true);
	Rogo();
	//-------------
	//�ύX���Ȃ�����
	//-------------
	bool Initialize();		//����������
	void UpDate();			//�X�V����
	void Render2D();		//�`�揈��
	bool Finalize();		//�������
};