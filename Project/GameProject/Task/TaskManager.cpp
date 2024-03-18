#include"TaskManager.h"
#include"Task.h"
#include"ObjectBase.h"

//タスクのリストを定義
std::list<Task*> TaskManager::m_taskList;
//オブジェクトのリストを定義
std::list<Task*> TaskManager::m_objectList;

//コンストラクタ
TaskManager::TaskManager()
{
}

//デストラクタ
TaskManager::~TaskManager()
{
}

//タスクをリストに追加 
void TaskManager::Add(Task* add, bool isSort)
{
	//ソート時のタスク追加の呼び出しでなければ、
	if (!isSort)
	{
		//追加するタスクの優先度がオブジェクト用であれば、
		//オブジェクトに追加
		if (add->m_prio == (int)TaskPrio::Object)
		{
			m_objectList.push_back(add);
		}
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* task = *itr;
		//追加するタスクの優先度　＜　現在のタスクの優先度ならば、
		//その位置にタスクを追加
		if (add->m_prio < task->m_prio)
		{
			m_taskList.insert(itr, add);
			return;
		}
		//追加するタスクの優先度と現在のタスクの優先度が同じならば、
		else if (add->m_prio == task->m_prio)
		{
			//処理順番が小さい順に並べる
			if (add->m_sortOrder < task->m_sortOrder)
			{
				m_taskList.insert(itr, add);
				return;
			}
		}
		itr++;
	}

	//最後まで追加する場所が見つからなかった場合、
	//リストの最後尾に追加する
	m_taskList.push_back(add);
}

//タスクをリストから取り除く
void TaskManager::Remove(Task* remove, bool isSort)
{
	//ソート時の呼び出しではない
	if (!isSort)
	{
		//優先度がオブジェクト用であれば、オブジェクトリストからも取り除く
		if (remove->m_prio == (int)TaskPrio::Object)
		{
			m_objectList.remove(remove);
		}
	}

	m_taskList.remove(remove);
}

//タスクを削除
void TaskManager::Delete(Task* del)
{
	//除外するタスクがオブジェクトであれば、オブジェクトリストから取り除く
	if (del->m_prio == (int)TaskPrio::Object)
	{
		m_objectList.remove(del);
	}

	//削除する場合は、先にリストから取り除いてから削除する
	m_taskList.remove(del);
	delete del;
}

//リスト内のタスクを全て削除
void TaskManager::DeleteAll()
{
	//全てを削除するので、オブジェクトリストの中身を全てクリアする
	m_objectList.clear();

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* del = *itr;
		//リストから取り除いてから、タスクを削除
		itr = m_taskList.erase(itr);
		delete del;
	}
}

//オブジェクトリストを取得
const std::list<Task*>& TaskManager::GetObjctList()
{
	return m_objectList;
}

Task* TaskManager::FindObject(int type)
{
	//リストをループ
	for (auto& b : m_taskList) {
		//対象のオブジェクトを見つけたら、それを返す
		if (b->m_type == type)
			return b;
	}
	return nullptr;

}

std::list<Task*> TaskManager::FindObjects(int type)
{
	std::list<Task*> ret;
	//リストをループ
	for (auto& b : m_taskList) {
		//対象のオブジェクトを見つけたら、返却用リストに追加
		if (b->m_type == type)
			ret.push_back(b);
	}
	return ret;
}

//全て削除
void TaskManager::KillAll()
{
	for (auto& b : m_taskList) {
		b->Kill();
	}
}



//リスト内の全タスクの更新処理を呼び出す
void TaskManager::UpDate()
{
	//削除フラグが立っているタスクを削除
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* task = *itr;
		//削除フラグが立っていたら削除
		if (task->m_isKill)
		{
			itr = m_taskList.erase(itr);
			delete task;
		}
		//削除フラグが立っていなければ、次のタスクへ
		else
		{
			itr++;
		}
	}

	//全てのタスクを更新
	itr = m_taskList.begin();
	end = m_taskList.end();
	while (itr != end)
	{
		Task* task = *itr;
		//タスクが有効であれば、更新処理を呼び出す
		if (task->m_isEnable)
		{
			task->Update();
		}
		itr++;
	}
}

//リスト内の全タスクの描画処理を呼び出す
void TaskManager::Draw()
{
	//オブジェクトリストの中のオブジェクトを
	//奥行の座標で並び変える
	m_objectList.sort
	(
		//ラムダ式
		[](const Task* taskA, const Task* taskB)
		{
			const ObjectBase* objA = dynamic_cast<const ObjectBase*>(taskA);
			const ObjectBase* objB = dynamic_cast<const ObjectBase*>(taskB);
			return objA->m_pos.z < objB->m_pos.z;
		}
	);

	//オブジェクトリストの順番に処理順番の番号を設定する
	int sortOrder = 0;
	for (auto& obj : m_objectList)
	{
		obj->SetSortOrder(sortOrder);
		sortOrder++;
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* task = *itr;
		//タスクが有効かつ、表示するのであれば、
		//描画処理を呼び出す。
		if (task->m_isEnable)
		{
			task->Draw();
		}
		itr++;
	}
}

//全ての当たり判定を呼び出す
void TaskManager::CollisionAll()
{
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end) {
		auto itr2 = itr;
		itr2++;
		while (itr2 != end) {
			(*itr)->Collision(*itr2);
			(*itr2)->Collision(*itr);
			itr2++;
		}
		itr++;
	}
}