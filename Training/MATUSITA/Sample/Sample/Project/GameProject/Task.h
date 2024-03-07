#pragma once

class TaskManager;

//タスクの優先度
enum class TaskPrio {
	Field,
	Object,

	UI,
};

class Task {
	friend TaskManager;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="prio">優先度</param>
	Task(int prio);
	//デストラクタ
	virtual ~Task();

	/// <summary>
	/// 優先度を設定
	/// </summary>
	/// <param name="prio">設定する優先度</param>
	/// <returns></returns>
	void SetPriority(int prio);

	/// <summary>
	/// 優先度を取得
	/// </summary>
	/// <returns></returns>
	int GetPriority()const;

	/// <summary>
	/// 処理順番を設定
	/// </summary>
	/// <param name="order">設定する処理順番</param>
	void SetSortOrder(int order);

	/// <summary>
	/// 処理順番を取得
	/// </summary>
	/// <returns></returns>
	int GetSortOrder()const;


	/// <summary>
	/// 有効かどうかを設定
	/// </summary>
	/// <param name="enable">trueなら有効</param>
	void SetEnable(bool enable);

	/// <summary>
	/// 有効かどうかを取得
	/// </summary>
	/// <param name="enable">trueなら有効</param>
	bool IsEnable()const;

	/// <summary>
	/// 表示するかどうかを設定
	/// </summary>
	/// <param name="enable">trueなら表示</param>
	void SetShow(bool show);

	/// <summary>
	/// 表示するかどうかを取得
	/// </summary>
	/// <param name="enable">trueなら表示</param>
	bool IsShow()const;

	//タスク削除
	void Kill();

	virtual void Update();

	virtual void Render();

private:
	int m_prio;//タスクの優先度
	int m_sortOrder;//同じ処理優先の処理順番
	bool m_isEnable;//タスクが有効かどうか
	bool m_isShow;//タスクを描画するかどうか
	bool m_isKill;//タスクの削除フラグ
};
