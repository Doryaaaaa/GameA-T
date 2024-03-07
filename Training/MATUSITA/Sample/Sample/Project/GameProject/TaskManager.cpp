#include "TaskManager.h"
#include "Task.h"
#include"ObjectBase.h"

//タスクのリストを定義
std::list<Task*>TaskManager::m_taskList;

//タスクのリストを定義
std::list<Task*>TaskManager::m_objectList;

TaskManager::TaskManager() {

}

TaskManager::~TaskManager() {

}

//タスクをリストに追加
void TaskManager::Add(Task* add, bool isSort) {
	//ソート時のタスク追加時の呼び出しでなければ
	if(!isSort){
		//追加するタスクの優先度がオブジェクトなら
		//オブジェクトリストに追加
		if (add->m_prio == (int)TaskPrio::Object) {
			m_objectList.push_back(add);
		}
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end) {
		Task* task = *itr;
		//追加するタスクの優先度＜現在のタスクの湯鮮度なら
		//その位置にタスクを追加
		if (add->m_prio < task->m_prio) {
			m_taskList.insert(itr, add);
			return;
		}
		//追加するタスクの優先度と現在のタスクの優先度が同じなら
		else if (add->m_prio==task->m_prio) {
			//処理順番が小さい順に並べる
			if (add->m_sortOrder < task->m_sortOrder) {
				m_taskList.insert(itr, add);
				return;
			}
		}
		itr++;
	}
	//最後まで追加する場所がなかったら
	//リストの最後尾に追加する
	m_taskList.push_back(add);
}

//タスクをリストに取り除く
void TaskManager::Remove(Task* remove, bool isSort) {
	
	//ソート呼び出しでない
	if (!isSort) {
		//優先度がオブジェクト用であればオブジェクトリストからも取り除く
		if (remove->m_prio == (int)TaskPrio::Object) {
			m_objectList.remove(remove);
		}
	}

	m_taskList.remove(remove);
}

//タスクを削除
void TaskManager::Delete(Task* del) {

	if (del->m_prio == (int)TaskPrio::Object) {
		m_objectList.remove(del);
	}

	//双方向リスト
	//削除するときは先にリスト取り除いてから削除する
	m_taskList.remove(del);
	delete del;
}
//リスト内のタスクを全て削除
void TaskManager::DeleteAll()
{
	//全て削除なのでオブジェクトリストの中身を全てクリアする
	m_objectList.clear();

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end) {
		Task* del = *itr;
		//リストから取り除いてからタスク削除
		itr = m_taskList.erase(itr);
		delete del;
	}
}


//リスト内の全タスクを更新処理を呼び出す
void TaskManager::Update() {
	//削除フラグが立っているタスク削除
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr!=end) {
		Task* task = *itr;
		//削除フラグが立っていたらタスク削除
		if (task->m_isKill) {
			itr = m_taskList.erase(itr);
			delete task;
		}
		//削除フラグが立ってなければ、次のタスク
		else {
			itr++;
		}
	}
		


	//全てのタスク更新
	 itr = m_taskList.begin();
	 end = m_taskList.end();
	while (itr != end) {
		Task* task = *itr;
		//タスクが有効であれば更新処理を呼び出す
		if (task->m_isEnable) {
			task->Update();
		}
		itr++;
	}
}
//リスト内の全タスクを描画処理を呼び出す
void TaskManager::Render()
{
	//オブジェクトリストの中のオブジェクトを
	//奥行きの座標で並び変える
	m_objectList.sort(
		//ラムダ式
		[](const Task* taskA,const Task* taskB) {

			const ObjectBase* objA = dynamic_cast<const ObjectBase*>(taskA);
			const ObjectBase* objB = dynamic_cast<const ObjectBase*>(taskB);
			return objA->GetPos().y < objB->GetPos().y;
		}
	);
	
	//オブジェクトリストの順番に処理順番の番号を設定する
	int sortOrder = 0;
	for (auto& obj : m_objectList) {
		obj->SetSortOrder(sortOrder);
		sortOrder++;
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end) {
		Task* task = *itr;
		//タスクが有効かつ表示する設定であれば描画処理を呼び出す
		if (task->m_isEnable && task->m_isShow) {
			task->Render();
		}
		itr++;
	}
}

