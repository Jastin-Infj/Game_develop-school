#include "Kard.h"
#include <time.h>
using namespace std;
Kard::Kard()
{
	FilePath = "Card.png";
	objectTag = "Kard";
	srand((unsigned)time(NULL));

	int size_x = 300;		//�摜����X���W
	int size_y = 400;		//�摜����Y���W

	//�J�[�h�̉摜���̏��𑗂�
	for (int i = 1; i <= 6; ++i) 
	{
		number[i] = Vec2(size_x * (i - 1), 0);
	}
	number[0] = Vec2(size_x * 6, 0);

	//�J�[�h�̃A�j���[�V����
	for (int i = 0; i < 4; ++i)//7-10
	{
		number[7 + i] = Vec2(size_x * i, size_y);
	}
}
Kard::~Kard()
{

}
void Kard::Initialize()
{
	image.TextureCreate(FilePath);
	p_pointa = nullptr;
	moveCnt = 0;
	Random = rand() % 6 + 1;
}
void Kard::Create(Vec2 pos , Vec2 scale,Vec2 src_scale)
{
	CreateObject(Cube, pos, scale, 0);
	Src_Pos = number[0];   //�J�[�h�������
	Src_Scale = src_scale;
	state = State::NON;		//�J�[�h�̂߂����Ă��Ȃ�
	this->Corsol = false;	//�J�[�\���ƐڐG���Ă���
}
void Kard::Update()
{
	//�J�[�\���ƐڐG�����Ă�����E�E�E�@�܂��̓J�[�\�������̍��W�l�܂ł�����E�E�E

	//����{�^���������ꂽ��E�E�Enumber�̔z�u��ω�������
}
void Kard::Render()
{
	Box2D draw(position, Scale);
	draw.OffsetSize();
	Box2D src(Src_Pos,Src_Scale);
	src.OffsetSize();
	image.Draw(draw, src);
}
void Kard::Finalize()
{
	image.Finalize();
}
void Kard::Set_Pointa(Object* obj)
{
	if (obj->objectTag != "Player")
	{
		return;
	}
	p_pointa = (Player*)obj;
}
bool Kard::CheckHit()
{
	if (position.x == p_pointa->position.x && position.y == p_pointa->position.y)
	{
		Corsol = true;
		return true;
	}
	Corsol = false;
	return false;
}
void Kard::Set_State(Kard::State s_)
{
	state = s_;
}
Kard::State Kard::Get_State()
{
	return state;
}
void Kard::Kard_Open()
{
	int anime = 7;
	if (Corsol)
	{
		while (1)
		{
			moveCnt++;
			if (moveCnt >= 400)
			{
				break;
			}
			if (moveCnt < 100)
			{
				Src_Pos = number[7];
				anime++;
				/*Src_Pos = number[Random];
				moveCnt = 0;
				break;*/
			}
			else if (moveCnt < 150)
			{
				//�A�j���[�V��������
			}
		}
	}
}
//�����@�ǂݍ��݂���X�^�[�g����@false