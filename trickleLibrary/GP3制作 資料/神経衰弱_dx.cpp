#include "DxLib.h"

//場のカードデータ
struct
{
	int mark;			//トランプのマーク
	int number;			//数字の番号
	bool reverse;		//裏返し処理
}cards[4][13];

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	int turns = 0;						//未確定のカードをめくった状態を表す
	int ox, oy, nx, ny;					//裏返したときの　1枚目の座標・2枚目の座標
	int remains = 52;					//裏がっている残りのカード数
	int start_time, elapsed_time;		//ゲーム開始時間・経過時間

	bool mouse_flag = false;			//mouseのフラグ
	int graph_cards[2], graph_marks[4], graph_number[13];
	//選択されているカード・トランプのマーク・ナンバー
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	//画像を分割して描画する
	LoadDivGraph("画像/card.png", 2, 2, 1, 40, 64, graph_cards);
	LoadDivGraph("画像/mark.png", 4, 4, 1, 28, 28, graph_marks);
	LoadDivGraph("画像/number.png", 13, 13, 1, 28, 28, graph_number);
	//ファイル名・分割数・横縦の分割数・１つあたり大きさ・int型ｍｐ配列へのポインタ


	//シャッフル
	bool deal[4][13] = {};			//既に配ったカードのチェック用
									//カードの枚数分
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 13; ++x)
		{
			int mk, no;
			do
			{ //乱数を生成してそこに代入する
				mk = GetRand(3); no = GetRand(12);
			} while (deal[mk][no]);		//配置する（メモリ）
			cards[y][x].mark = mk;		//1マスづつ配置していく	　種類	
			cards[y][x].number = no;	//1マスづつ配置していく　 番号
			cards[y][x].reverse = true;	//裏返しにする
			deal[mk][no] = true;		//配ったことを伝える
		}
	}
	start_time = GetNowCount();			//現在の時間を取得する
	while (!ProcessMessage())
	{
		//描かれているものを消去する
		ClearDrawScreen();
		//カードめくり処理
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{//左ボタンをクリックされたら
			if (!mouse_flag)
			{//mouseフラグがもしもないなら
				mouse_flag = true;		//マウスフラグ　on
			}
			if (turns == 2)//2枚をめくった状態になったら
			{
				cards[oy][ox].reverse = true;		//1枚目の座標を取り出し　カードをめくる
				cards[ny][nx].reverse = true;		//2枚目の座標を取り出し　カードをめくる
				turns = 0;							//元に戻す
			}
			else			//2枚めくっていないなら
			{
				//マウスの座標と取得する
				GetMousePoint(&nx, &ny);
				nx = (nx - 60) / 40;		//座標場所の配置を調整する
				ny = (ny - 96) / 64;		//座標場所の配置を調整する
			}
			if (nx >= 0 && nx <= 12 && ny >= 0 && ny <= 3 && cards[ny][nx].reverse)
			{//カードの番号がもしも　裏がっているなら
				cards[ny][nx].reverse = false;
				if (turns == 0)
				{//ゼロの場合
					ox = nx; oy = ny;
					turns = 1;
				}
				else
				{//それ以外
					if (cards[ny][nx].number == cards[oy][ox].number)
					{//2枚の座標が同じ番号なら
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
			mouse_flag = false;		//mouse　off
		}


		//場のカード表示
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 13; ++x)
			{
				int x2 = x * 40 + 60;	//カードの調整
				int y2 = y * 64 + 96;	//カードの調整
										//画像描画
				DrawGraph(x2, y2, graph_cards[cards[y][x].reverse], FALSE);
				if (!cards[y][x].reverse)//表ならば
				{
					//画像描画　表向き
					DrawGraph(x2 + 6, y2 + 5, graph_marks[cards[y][x].mark], FALSE);
					DrawGraph(x2 + 6, y2 + 32, graph_number[cards[y][x].number], FALSE);
				}
			}
		}

		//メッセージの表示
		int color = GetColor(255, 255, 255);		//色の指定
		if (remains <= 0)
		{//残っている数が0以下なら
			DrawString(8, 8, "クリア！", color);	//テキストの表示
		}
		else
		{
			//現在のタイムを測定する
			elapsed_time = (GetNowCount() - start_time) / 1000;
		}
		//UIの表示
		DrawFormatString(8, 450, color, "残り %d枚  経過時間 %d秒", remains, elapsed_time);
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}