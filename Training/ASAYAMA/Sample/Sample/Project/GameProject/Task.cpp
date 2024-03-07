#include"Task.h"
#include"TaskManager.h"
//コンストラクタ
Task::Task(int prio)
	:m_prio(prio)
	,m_sortOrder(0)
	, m_isEnable(true)
	, m_isShow(true)
	,m_isKill(false)
{
	//タスクの生成と同時にTaskManagerのリストに自身を追加
	TaskManager::Add(this);
}
//デストラクタ
Task::~Task() {
	//タスクの削除と同時にTaskManagerのリストから自信を取り除く
	TaskManager::Remove(this);
}
//優先度を設定
void Task::SetPriority(int prio) {
	m_prio = prio;
	//一回タスクのリストから自信を取り除き
	//その後もう一度タスクのリストに追加する関数を呼び出すことで
	//新しい優先度の場所にタスクを変更する
	TaskManager::Remove(this,true);
	TaskManager::Add(this);
}
//優先度を取得
int Task::GetPriority()const {
	return m_prio;
}
//処理順番を設定
void Task::SetSortOrder(int order) {
	//処理順番を変更後に、リスト内の並び替えも行なう
	m_sortOrder = order;
	TaskManager::Remove(this, true);
	TaskManager::Add(this, true);
}
//処理順番を取得
int Task::GetSortOrder()const {
	return m_sortOrder;
}

// 有効かどうかを設定
void Task::SetEnable(bool enable) {
	m_isEnable = enable;
}
//有効かどうかを取得
bool Task::IsEnable()const {
	return m_isEnable;
}
//表示するかどうかを設定
void Task::SetShow(bool Show) {
	m_isShow = Show;
}
//表示するかどうか取得
bool Task::IsShow()const {
	return m_isShow;
}
//タスクを削除
void Task::Kill() {
	m_isKill = true;
}
//タスクの削除フラグが立っているか
bool Task::IsKill()const {
	return m_isKill;
}

void Task::Update() {

}

void Task::Render() {

}