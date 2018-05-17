#pragma once
//�K�v�ǂݍ��݃t�@�C��
#include "OGSystem\OGsystem.h"
#include "Object\Object.h"

class Back : public GameObject, public TaskObject
{
	//-------------------------------------------
	//�e���Ő��삷��Ƃ��Ɏg�p������̂͂����ɋL�q����
	//-------------------------------------------
public:

private:
	Texture image;
	std::string filePath;
	const Box2D Src = {Vec2(0,0),Vec2(1024,1024)};
	//------------------
	//�Œ艻����Ă��鏈��
	//------------------
public:
	std::string taskName;
	virtual ~Back();
	typedef std::shared_ptr<Back> SP;
	static Back::SP Create(bool = true);
	Back();
	//-------------
	//�ύX���Ȃ�����
	//-------------
	bool Initialize();		//����������
	void UpDate();			//�X�V����
	void Render2D();		//�`�揈��
	bool Finalize();		//�������
};