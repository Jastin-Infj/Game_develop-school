#include "DxLib.h"

//��̃J�[�h�f�[�^
struct
{
	int mark;			//�g�����v�̃}�[�N
	int number;			//�����̔ԍ�
	bool reverse;		//���Ԃ�����
}cards[4][13];

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	int turns = 0;						//���m��̃J�[�h���߂�������Ԃ�\��
	int ox, oy, nx, ny;					//���Ԃ����Ƃ��́@1���ڂ̍��W�E2���ڂ̍��W
	int remains = 52;					//�������Ă���c��̃J�[�h��
	int start_time, elapsed_time;		//�Q�[���J�n���ԁE�o�ߎ���

	bool mouse_flag = false;			//mouse�̃t���O
	int graph_cards[2], graph_marks[4], graph_number[13];
	//�I������Ă���J�[�h�E�g�����v�̃}�[�N�E�i���o�[
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	//�摜�𕪊����ĕ`�悷��
	LoadDivGraph("�摜/card.png", 2, 2, 1, 40, 64, graph_cards);
	LoadDivGraph("�摜/mark.png", 4, 4, 1, 28, 28, graph_marks);
	LoadDivGraph("�摜/number.png", 13, 13, 1, 28, 28, graph_number);
	//�t�@�C�����E�������E���c�̕������E�P������傫���Eint�^�����z��ւ̃|�C���^


	//�V���b�t��
	bool deal[4][13] = {};			//���ɔz�����J�[�h�̃`�F�b�N�p
									//�J�[�h�̖�����
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 13; ++x)
		{
			int mk, no;
			do
			{ //�����𐶐����Ă����ɑ������
				mk = GetRand(3); no = GetRand(12);
			} while (deal[mk][no]);		//�z�u����i�������j
			cards[y][x].mark = mk;		//1�}�X�Âz�u���Ă���	�@���	
			cards[y][x].number = no;	//1�}�X�Âz�u���Ă����@ �ԍ�
			cards[y][x].reverse = true;	//���Ԃ��ɂ���
			deal[mk][no] = true;		//�z�������Ƃ�`����
		}
	}
	start_time = GetNowCount();			//���݂̎��Ԃ��擾����
	while (!ProcessMessage())
	{
		//�`����Ă�����̂���������
		ClearDrawScreen();
		//�J�[�h�߂��菈��
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{//���{�^�����N���b�N���ꂽ��
			if (!mouse_flag)
			{//mouse�t���O���������Ȃ��Ȃ�
				mouse_flag = true;		//�}�E�X�t���O�@on
			}
			if (turns == 2)//2�����߂�������ԂɂȂ�����
			{
				cards[oy][ox].reverse = true;		//1���ڂ̍��W�����o���@�J�[�h���߂���
				cards[ny][nx].reverse = true;		//2���ڂ̍��W�����o���@�J�[�h���߂���
				turns = 0;							//���ɖ߂�
			}
			else			//2���߂����Ă��Ȃ��Ȃ�
			{
				//�}�E�X�̍��W�Ǝ擾����
				GetMousePoint(&nx, &ny);
				nx = (nx - 60) / 40;		//���W�ꏊ�̔z�u�𒲐�����
				ny = (ny - 96) / 64;		//���W�ꏊ�̔z�u�𒲐�����
			}
			if (nx >= 0 && nx <= 12 && ny >= 0 && ny <= 3 && cards[ny][nx].reverse)
			{//�J�[�h�̔ԍ����������@�������Ă���Ȃ�
				cards[ny][nx].reverse = false;
				if (turns == 0)
				{//�[���̏ꍇ
					ox = nx; oy = ny;
					turns = 1;
				}
				else
				{//����ȊO
					if (cards[ny][nx].number == cards[oy][ox].number)
					{//2���̍��W�������ԍ��Ȃ�
						remains -= 2;
						turns = 0;
					}
					else
					{
						turns = 2;
					}
				}
			}
		}
		else
		{
			mouse_flag = false;		//mouse�@off
		}


		//��̃J�[�h�\��
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 13; ++x)
			{
				int x2 = x * 40 + 60;	//�J�[�h�̒���
				int y2 = y * 64 + 96;	//�J�[�h�̒���
										//�摜�`��
				DrawGraph(x2, y2, graph_cards[cards[y][x].reverse], FALSE);
				if (!cards[y][x].reverse)//�\�Ȃ��
				{
					//�摜�`��@�\����
					DrawGraph(x2 + 6, y2 + 5, graph_marks[cards[y][x].mark], FALSE);
					DrawGraph(x2 + 6, y2 + 32, graph_number[cards[y][x].number], FALSE);
				}
			}
		}

		//���b�Z�[�W�̕\��
		int color = GetColor(255, 255, 255);		//�F�̎w��
		if (remains <= 0)
		{//�c���Ă��鐔��0�ȉ��Ȃ�
			DrawString(8, 8, "�N���A�I", color);	//�e�L�X�g�̕\��
		}
		else
		{
			//���݂̃^�C���𑪒肷��
			elapsed_time = (GetNowCount() - start_time) / 1000;
		}
		//UI�̕\��
		DrawFormatString(8, 450, color, "�c�� %d��  �o�ߎ��� %d�b", remains, elapsed_time);
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}