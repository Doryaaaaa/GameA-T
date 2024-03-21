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
    //‰e•`‰æƒNƒ‰ƒX‚Ì¶¬
    new ShadowManager();
    (new Enemy(CVector3D(2200, 2800, 0), true));
    new Timer(CVector2D());
}
Game::~Game()
{
}

void Game::Update()
{
    //“G€–S‚ÅƒQ[ƒ€ƒNƒŠƒA
    if (!TaskManager::FindObject(eType_Enemy)) {
        TaskManager::KillAll();
        (new GameClear());
        printf("\d",Timer::Cscore);
    }
    //“G‰æ–ÊŠO‚ÅƒQ[ƒ€ƒI[ƒo[
    /*if (!Task::FindObject(eType_Enemy)) {
        if () {
            (new GameOver());
        }
        
    }*/
}