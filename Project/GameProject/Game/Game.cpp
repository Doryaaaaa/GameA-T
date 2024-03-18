#include "Game.h"
#include "Game/Field.h"
#include "Game/Player.h"
#include "Task/Task.h"
#include "Game/Enemy.h"
#include"Task/ShadowManager.h"
#include "Game/Title.h"
#include"Game/Portion1.h"
#include"Game/Trapp1Manager.h"
#include"Game/Timer.h"
#include "Game/GameClear.h"
#include"Task/TaskManager.h"


Game::Game() :Task(eType_Game, (int)TaskPrio::Game)
{

    new Field();
    new Player(CVector3D(1200, 2800, -150));
    new Portion1Manager();
    new Trapp1Manager();
    //影描画クラスの生成
    new ShadowManager();
    (new Enemy(CVector3D(2200, 2800, 0), true));
    new Timer(CVector2D());
}
Game::~Game()
{
    //全てのオブジェクトを破棄
    Kill();
    //タイトルシーンへ
    (new Title());
}

void Game::Update()
{
    //敵死亡でゲームクリア
    if (!Task::FindObject(eType_Enemy)&&!Task::FindObject(eType_Title)) {
        Kill();
        (new GameClear());
    }
    //敵画面外でゲームオーバー
    /*if (!Task::FindObject(eType_Enemy)) {
        if () {
            (new GameOver());
        }
        
    }*/
}