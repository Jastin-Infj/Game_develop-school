#pragma once
//�K�v�ǂݍ��݃t�@�C��
#include "OGSystem\OGsystem.h"

class Game : public TaskObject
{
	//-------------------------------------------
	//�e���Ő��삷��Ƃ��Ɏg�p������̂͂����ɋL�q����
	//-------------------------------------------
public:
private:

	//------------------
	//�Œ艻����Ă��鏈��
	//------------------
public:
	std::string taskName;
	virtual ~Game();
	typedef std::shared_ptr<Game> SP;
	static Game::SP Create(bool = true);
	Game();
	//-------------
	//�ύX���Ȃ�����
	//-------------
	bool Initialize();		//����������
	void UpDate();			//�X�V����
	void Render2D();		//�`�揈��
	bool Finalize();		//�������
};