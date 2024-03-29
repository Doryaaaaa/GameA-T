#include "Task/Task.h"
#include"Task/TaskManager.h"
#include"Task/ShadowManager.h"
#include"Game/Title.h"
#include"Game/Explanation.h"
#include "Game/Player.h"
#include"Game/Enemy.h"
#include"Game/EnemyHp.h"
#include"Game/Field.h"
#include "Game/Portion1.h"
#include"Game/Timer.h"
#include"Game/Trapp1.h"
#include"Game/Trapp1Manager.h"
#include"Game/Trapp2.h"
#include"Game/Trapp2Manager.h"
#include"Game/Trapp3.h"

//--------------------------------------------
//グローバル変数領域
//--------------------------------------------
Enemy* p_enemy = nullptr;





void MainLoop(void) {
	//--------------------------------------------------------------
	//ゲーム中の動きはここに書く
	//ゲーム中はこの関数_を1秒間に60回呼び出している
	//--------------------------------------------------------------
	TaskManager::UpDate();
	TaskManager::CollisionAll();
	TaskManager::Draw();

}
void Init(void)
{

	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Z');
	CInput::SetButton(0, CInput::eButton2, 'X');
	CInput::SetButton(0, CInput::eButton3, 'C');
	CInput::SetButton(0, CInput::eButton4, 'V');
	CInput::SetButton(0, CInput::eButton5, VK_SPACE);//ジャンプ
	CInput::SetButton(0, CInput::eButton6, 'W');//上移動
	CInput::SetButton(0, CInput::eButton7, 'S');//下移動
	CInput::SetButton(0, CInput::eButton8, 'M');//攻撃（仮）
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, VK_UP);
	CInput::SetButton(0, CInput::eDown, VK_DOWN);
	CInput::SetButton(0, CInput::eLeft, VK_LEFT);
	CInput::SetButton(0, CInput::eRight, VK_RIGHT);
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);//攻撃
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);
	//	CInput::SetMouseInside(true);
	//	CInput::ShowCursor(false);
	CInput::Update();
	CInput::Update();



	SetCurrentDirectory("data");
	CSound::GetInstance();

	//-----------------------------------------------------
	//初期化の命令を書く
	//ゲーム起動時に一度だけ呼ばれる
	//-----------------------------------------------------
	//画像の読み込みと登録　”リソース名”　　　　”ファイル名” , アニメーションデータ , 幅 , 高さ
	ADD_RESOURCE("Player", CImage::CreateImage("Image/Player.png",player_anim_data,500,500));
	ADD_RESOURCE("Enemy", CImage::CreateImage("Image/Enemy.png", enemy_anim_data, 500, 610));
	//ADD_RESOURCE("Sky", CImage::CreateImage("Image/Sky.png"));
	//ADD_RESOURCE("Town", CImage::CreateImage("Image/Town.png"));
	ADD_RESOURCE("Field", CImage::CreateImage("Image/Field.png"));
	ADD_RESOURCE("Title", CImage::CreateImage("Image/Title.png"));
	ADD_RESOURCE("Explanation", CImage::CreateImage("Image/Explanation.png"));
	//ADD_RESOURCE("MapTip", CImage::CreateImage("Image/MapTip.png"));
	//ADD_RESOURCE("Effect_Slash", CImage::CreateImage("Image/Effect_Slash.png", effect_slash_anim_data, 128, 128));
	//ADD_RESOURCE("Effect_Smoke", CImage::CreateImage("Image/Effect_Smoke.png", effect_smoke_anim_data, 128, 128));
	//ADD_RESOURCE("Effect_Blood", CImage::CreateImage("Image/Effect_Blood.png", effect_blood_anim_data, 128, 128));
	//ADD_RESOURCE("Goal", CImage::CreateImage("Image/Goal.png"));
	//ADD_RESOURCE("Title", CImage::CreateImage("Image/Title.png"));
	ADD_RESOURCE("ShadowManager", CImage::CreateImage("Image/Shadow.PNG"));
	ADD_RESOURCE("EnemyHp", CImage::CreateImage("Image/HP(仮).png"));
	ADD_RESOURCE("Portion1", CImage::CreateImage("Image/Portion1.PNG"));
	ADD_RESOURCE("Trapp1", CImage::CreateImage("Image/Trapp3.png",Trapp1_anim_data, 500, 500));
	ADD_RESOURCE("Trapp2", CImage::CreateImage("Image/Trapp2.png", Trapp2_anim_data, 500, 500));
	ADD_RESOURCE("Trapp3", CImage::CreateImage("Image/Trapp1.png", Trapp3_anim_data, 500, 500));
	ADD_RESOURCE("Trapp4", CImage::CreateImage("Image/Trapp4.png"));
	ADD_RESOURCE("Bullet", CImage::CreateImage("Image/Bullet.png"));
	ADD_RESOURCE("GameClear", CImage::CreateImage("Image/GameClear.png"));
	ADD_RESOURCE("GameOver", CImage::CreateImage("Image/GameOver.png"));

	//Explanation
	//-----------------------------------------------------
	//初期化の命令を書く
	//ゲーム起動時に一度だけ呼ばれる
	//-----------------------------------------------------
	new Title();



}


void Release()
{
	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

	//画面解像度変動
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//画面解像度固定
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	CCamera::GetCamera()->Viewport(0, 0, w, h);
	CCamera::GetCurrent()->Perspective(DtoR(60.0), (float)w / (float)h, 1.0, 1000.0);

	glfwGetWindowPos(window, &GL::window_x, &GL::window_y);
	GL::UpdateWindowRect(GL::window_x, GL::window_y, w, h);
	CInput::UpdateClipCursor(true);

}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::window_x = x;
	GL::window_y = y;
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//フルスクリーン?ウインドウモードの切り替え
//Alt+Enterで切り替える
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(1);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	Init();
	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();


		CInput::Update();
		//各バッファーをクリア
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();


		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "summer");
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();




	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}