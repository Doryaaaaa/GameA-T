#pragma once
#include"Task.h"

//ゲーム中のObjectのベースクラス
class ObjectBase :public Task {
public:
	//コンストラクタ
	ObjectBase(const CVector2D& pos);
	//デストラクタ
	virtual ~ObjectBase();

	/// <summary>
		/// オブジェクトの座標を取得
		/// </summary>
		/// <returns>オブジェクトの座標</returns>
	const CVector2D& GetPos() const;

	/// <summary>
	/// オブジェクトの座標を設定
	/// </summary>
	/// <param name="pos">設定する座標</param>
	void SetPos(const CVector2D& pos);

protected:
	CVector2D m_pos;//オブジェクトの座標
};
