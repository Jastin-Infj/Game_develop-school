#include "OGSystem\OGTask.h"
void OGTK::_myGameInitialize()
{
	//生成するWindow情報

	//GPG.exeに描画を合わせました
	OGge->SetWindow(1020, 1280, "WindowName", false);	
}

void OGTK::StartTaskObject()
{
	//タスクの初期化
	auto title = Title::Create();
}