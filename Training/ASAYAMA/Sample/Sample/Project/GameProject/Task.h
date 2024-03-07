#pragma once

class TaskManager;

enum class TaskPrio {
    Field,//フィールド
	Shadow,//オブジェクトの影
    Object,//ゲーム内オブジェクト

    UI,//画面に表示するHUDなどのUI
};


//タスククラス
class Task {
public:
	//コンストラクタ
	Task(int prio);
	//デストラクタ
	virtual ~Task();
	/// <summary>
	/// 優先度を設定
	/// </summary>
	/// <param name="prio">設定する優先度</param>
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
	/// 有効かどうかの設定
	/// </summary>
	/// <param name="enabie">trueならば有効</param>
	void SetEnable(bool enabie);
	/// <summary>
	/// 有効かどうかを取得
	/// </summary>
	/// <returns>trueならば有効</returns>
	bool IsEnable()const;
	/// <summary>
	/// 表示するかどうかを設定
	/// </summary>
	/// <param name="show">trueならば表示</param>
	void SetShow(bool show);
	/// <summary>
	/// 表示するかどうかを取得
	/// </summary>
	/// <returns>trueならば表示する</returns>
	bool IsShow()const;
	//タスクを削除
	void Kill();
	//タスクの削除フラグが立っているか
	bool IsKill()const;
	//更新
	virtual void Update();
	//描画
	virtual void Render();
//private:
	int m_prio;//タスク優先度
	int m_sortOrder;//同じ優先度内の処理順番
	bool m_isEnable;//タスクが有効かどうか
	bool m_isShow;//タスクを描画するかどうか
	bool m_isKill;//タスクの削除フラグ
};