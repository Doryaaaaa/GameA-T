#pragma once
#include"Task.h"

struct Rect3D {
    float left;
    float top;
    float front;
    float right;
    float bottom;
    float back;
    float width;
    float height;
    Rect3D() {
        memset(this, 0, sizeof(Rect3D));
    }
    Rect3D(float l, float t, float f, float r, float b, float bk) {
        left = l;
        top = t;
        front = f;
        right = r;
        bottom = b;
        back = bk;
        width = right - left;
        height = bottom - top;
    }
};
/// <summary>
/// ゲームオブジェクトの基底クラス
/// </summary>
class ObjectBase : public Task {
public:
    //座標データ
    CVector3D m_pos;
    //過去の位置
    CVector3D m_pos_old;
    //移動ベクトル
    CVector3D m_vec;
    //スクロール値
    static CVector3D m_scroll;
    //矩形
    Rect3D   m_rect;
public:
    /// <summary>
   /// コンストラクタ
   /// </summary>
    ObjectBase(int type);
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~ObjectBase();
    /// <summary>
    /// 更新処理
    /// </summary>
    virtual void Update();
    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void Draw();
    /// <summary>
    /// 画面内での位置を取得
    /// </summary>
    /// <param name="pos">キャラクターなどの座標</param>
    /// <returns>画面上での位置</returns>
    static CVector2D GetScreenPos(const CVector3D& pos);
    /// <summary>
   /// 全てのオブジェクト同士の組み合わせで当たり判定検証
   /// </summary>
   /// <summary>
   /// 矩形同士の判定
   /// </summary>
   /// <param name="b1">対象</param>
   /// <param name="b2">対象</param>
   /// <returns></returns>
    static bool CollisionRect(ObjectBase* b1, ObjectBase* b2);
    /// <summary>
    /// 矩形の表示
    /// </summary>
    virtual void Collision(ObjectBase* b);
    void DrawRect();
};