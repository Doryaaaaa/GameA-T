#include"Task.h"
#include"TaskManager.h"
//#include"Base.h"
Task::Task(int type, int prio)
    :m_type(type)
    , m_prio(prio)
    , m_sortOrder(0)
    , m_ShadowSize(0)
    , m_ShadowCenter(0)
    , m_isEnable(true)
    , m_isShow(true)
    , m_isKill(false)
    ,m_isShadow(true)
{
    //タスクの生成と同時にTaskManagerに自身を追加
    TaskManager::Add(this);
}

Task::~Task()
{
    //タスクの削除と同時にTaskManagerのリストから自身を取り除く
    TaskManager::Remove(this);
}

//優先度をを設定
void Task::SetPriority(int prio)
{
    m_prio = prio;
    //1回タスクのリストから自信を取り除き、
    //その後もう1度タスクリストに追加する関数を呼び出すことで
    //新しい優先度の場所にタスクを変更する
    TaskManager::Remove(this, true);
    TaskManager::Add(this, true);
}

//優先度を取得
int Task::GetPriority() const
{
    return m_prio;
}

//処理順番を設定
void Task::SetSortOrder(int order)
{
    //処理順番を変更後に、リスト内に並び替えも行う
    m_sortOrder = order;
    TaskManager::Remove(this, true);
    TaskManager::Add(this, true);
}

//処理順番を取得
int Task::GetSortOrder() const
{
    return m_sortOrder;
}

//有効かどうかを設定
void Task::SetEnable(bool enable)
{
    m_isEnable = enable;
}

//有効かどうかを取得
bool Task::IsEnable() const
{
    return m_isEnable;
}

//表示するかどうかを設定
void Task::SetShow(bool show)
{
    m_isShow = show;
}

//表示するかどうかを取得
bool Task::IsShow() const
{
    return m_isShow;
}
//影を表示するかどうかを設定
void Task::SetShadow(bool shadw)
{
    m_isShadow = shadw;
}
//影を表示するかどうかを取得
bool Task::IsShadow() const
{
    return m_isShadow;
}



//タスクを消去
void Task::Kill()
{
    m_isKill = true;
}

//タスクの消去フラグが立っているか
bool Task::IsKill()
{
    return m_isKill;
}




void Task::Update()
{

}

void Task::Draw()
{

}

void Task::Collision(Task*)
{
}