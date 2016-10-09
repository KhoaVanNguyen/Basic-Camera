
#include "SceneMain.h"
int start = 0;
void SceneMain::CountTime() {
		if (GetTickCount() - start > 1000) {
			//totalTime++;
			start = GetTickCount();
		}
}
void DrawBackground(LPDIRECT3DDEVICE9 d3ddv) {
	LPDIRECT3DSURFACE9 background;
	background = CreateSurfaceFromFile(d3ddv, "background.jpg");
	d3ddv->StretchRect(background, NULL, G_BackBuffer, NULL, D3DTEXF_NONE);
}
void SceneMain::InitLabels() {
	
	gui.Init();

	SetRect(&rScore1, 0, 0, 200, 400);
	SetRect(&rScore2, G_ScreenWidth - 50, 0, G_ScreenWidth, 50);
	SetRect(&rTimer, (G_ScreenWidth / 2 ) - 100, 0, ( G_ScreenWidth / 2 ) + 100, 50);
	
}
SceneMain::SceneMain(int _nCmdShow): CGame(_nCmdShow)
{

}
void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	
	d3ddv->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,100,100), 1.0f, 0);

	if (camera)
	{
		camera->SetTransform(d3ddv);
	}
	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
	if (bg2 && bg2->IsInitialized()) {
		
		bg2->Init("bubbles-bg2.png", 1, 1, 1);
		bg2->x = 0;
		bg2->y = 0;
		bg2->Draw();
	}
	if (ball && ball->IsInitialized()) {
		ball->Init("ball.bmp", 1, 1, 1);
		ball->InitPosition();
		ball->Draw();
	}
	G_SpriteHandler->End();
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	if (camera)
	{
		if (!camera->IsFollowing())
		{
			camera->Follow(ball);
		}
		camera->Update();
	}
	if (IsKeyDown(DIK_UPARROW)) {
		ball->y -= 5;
	}
	if (IsKeyDown(DIK_DOWNARROW)) {
		ball->y += 5;
	}
	if (IsKeyDown(DIK_LEFTARROW)) {
		ball->x -= 5;
	}
	if (IsKeyDown(DIK_RIGHTARROW)) {
		ball->x += 5;
	}
}
void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	srand(time(NULL));
	
	bg2 = new GameObject();
	ball = new Ball();
	
	
}
void SceneMain::OnKeyDown(int KeyCode)
{
}
SceneMain::~SceneMain(void)
{
}
