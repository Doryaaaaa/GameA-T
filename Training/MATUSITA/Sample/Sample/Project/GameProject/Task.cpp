#include "Task.h"
#include "TaskManager.h"

Task::Task(int prio):
	m_prio(prio),
	m_sortOrder(0),
	m_isEnable(true),
	m_isShow(true),
	m_isKill(false){
	//タスクの生成と同時にタスクマネージャーのリストに自信を追加
	TaskManager::Add(this);
}

Task::~Task()
{
	//タスクの生成と同時にタスクマネージャーのリストに自信を取り除く
	TaskManager::Remove(this);
}

//優先度を設定
void Task::SetPriority(int prio)
{
	m_prio = prio;
	//一回タスクのリストから自身を取り除く
	//その後もう一度タスクのリストに追加する関数を呼び出す
	//新しい優先度の場所にタスクを変更する
	TaskManager::Remove(this,true);
	TaskManager::Add(this,true);
}

//優先度を取得
int Task::GetPriority() const
{
	return m_prio;
}

//処理順番を設定
void Task::SetSortOrder(int order)
{
	//処理順番を変更後にリストの並び替えも行う
	m_sortOrder = order;
	TaskManager::Remove(this, true);
	TaskManager::Add(this, true);
}

//処理順番を取得
int Task::GetSortOrder() const
{
	return m_sortOrder;
}

void Task::SetEnable(bool enable)
{
	m_isEnable = enable;
}

bool Task::IsEnable() const
{
	return m_isEnable;
}

void Task::SetShow(bool show)
{
	m_isShow = show;
}

bool Task::IsShow() const
{
	return m_isShow;
}

void Task::Kill()
{
	m_isKill = true;
}

void Task::Update()
{
	
}

void Task::Render()
{
}
