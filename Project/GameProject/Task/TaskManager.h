#pragma once
#include<list>

class Task;

class TaskManager
{
public:
	/// <summary>
	///タスクをリストに追加 
	/// </summary>
	/// <param name="add">追加するタスクのポインター</param>
	/// <param name="isSort">ソート時の呼び出しかどうか</param>
	static void Add(Task* add, bool isSort = false);
	/// <summary>
	/// タスクをリストから取り除く
	/// </summary>
	/// <param name="remove">取り除くタスクのポインター</param>
	/// <param name="isSort">ソート時の呼び出しかどうか</param>
	static void Remove(Task* remove, bool isSort = false);

	/// <summary>
	/// タスクを削除
	/// </summary>
	/// <param name="del">削除するタスクのポインター</param>
	static void Delete(Task* del);
	//リスト内のタスクを全て削除
	static void DeleteAll();

	/// <summary>
	/// 全ての当たり判定を呼び出す
	/// </summary>
	static void CollisionAll();

	/// <summary>
	/// オブジェクトリストを取得
	/// </summary>
	/// <returns></returns>
	static const std::list<Task*>& GetObjctList();

	//リスト内の全タスクの更新処理を呼び出す
	static void UpDate();
	//リスト内の全タスクの描画処理を呼び出す
	static void Draw();

private:
	//コンストラクタ
	TaskManager();
	//デストラクタ
	~TaskManager();

	//現在生成されているタスクのリスト
	static std::list<Task*> m_taskList;
	//現在生成されているオブジェクトのリスト
	static std::list<Task*> m_objectList;
};