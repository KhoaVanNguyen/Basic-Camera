
#include "SceneMain.h"
int start = 0;
void SceneMain::CountTime() {
		if (GetTickCount() - start > 1000) {
			totalTime++;
			start = GetTickCount();
		}
}
void DrawBackground(LPDIRECT3DDEVICE9 d3ddv) {
	LPDIRECT3DSURFACE9 background;
	background = CreateSurfaceFromFile(d3ddv, "background.jpg");
	d3ddv->StretchRect(background, NULL, G_BackBuffer, NULL, D3DTEXF_NONE);
}
void SceneMain::InitLabels() {
	totalTime = 0;
	gui.Init();

	SetRect(&rScore1, 0, 0, 200, 400);
	SetRect(&rScore2, G_ScreenWidth - 50, 0, G_ScreenWidth, 50);
	SetRect(&rTimer, (G_ScreenWidth / 2 ) - 100, 0, ( G_ScreenWidth / 2 ) + 100, 50);
	gui.DrawLabel("0", rScore1, DT_LEFT);
	gui.DrawLabel("0", rScore2, DT_RIGHT);
	gui.DrawLabel(to_string(totalTime) + " s", rTimer, DT_CENTER);
}
SceneMain::SceneMain(int _nCmdShow): CGame(_nCmdShow)
{

}
void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	CountTime();
	//DrawBackground(d3ddv);
	d3ddv->ColorFill(G_BackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 12));
	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	

	ball.Draw();
	



	G_SpriteHandler->End();
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
		
	if (IsKeyDown(DIK_UPARROW)) {
		ball.y -= 5;
	}
	if (IsKeyDown(DIK_DOWNARROW)) {
		ball.y += 5;
	}
	if (IsKeyDown(DIK_LEFTARROW)) {
		ball.x -= 5;
	}
	if (IsKeyDown(DIK_RIGHTARROW)) {
		ball.x += 5;
	}
	

}
void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	srand(time(NULL));
	//DrawBackground(d3ddv);
	
	

	ball.Init("ball.bmp", 1, 1, 1);
	ball.InitPosition();
	
}
void SceneMain::OnKeyDown(int KeyCode)
{
}
SceneMain::~SceneMain(void)
{
}
