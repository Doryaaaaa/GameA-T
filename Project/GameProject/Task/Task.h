#pragma once
class TaskManager;

//重力加速度
#define GRAVITY (9.8f/20)
/// <summary>
/// オブジェクトの種類
/// </summary>
enum {
    eType_Game,
    eType_Field,
    eType_GameClear,
    eType_GameOver,
    eType_Title,
    eTyp_ShadowManager,
    eType_Score,
    eType_Portion1,
    eType_Portion1Manager,
    eType_Door,
    eType_AreaChange,
    eType_Player,
    eType_Enemy,
    eType_EnemyHp,
    eType_Enemywall,
    eType_Bullet,
    eType_Goal,
    eType_Player_Attack,
    eType_Enemy_Attack,
    eType_Effect,
    eType_Timer,
    eType_Scene,
    eType_Trapp1,
    eType_Trapp1Manager,
    eType_Trapp2,
    eType_Trapp2Manager,
    eType_Trapp3,
    eType_Trapp4,

};
//タスクの優先度
enum class TaskPrio
{
    Game,      //呼び出し
    Title,     //タイトル
    Field,     //フィールド
    Shadow,    //オブジェクトの影
    EnemyHp,   //エネミーのHPバー
    Timer,     //タイマー
    Object,    //ゲーム中のオブジェクト
    TrappManager,   //全てを呼び出す

    UI,        //画面に表示するHUDなどのUI

};
class Task
{
    friend TaskManager;

public:

    //オブジェクトの種類
    int m_type;
    //タスクの優先度
    int m_prio;
    //同じ優先度内の処理順番
    int m_sortOrder;
    //影のサイズ
    int m_ShadowSize;
    //
    int m_ShadowCenter;
    //タスクが有効かどうか
    bool m_isEnable;
    //タスクを描画するかどうか
    bool m_isShow;
    //影を描画するかどうか
    bool m_isShadow;
    //タスクの削除フラグ
    bool m_isKill;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Task(int type, int prio);
    /// <summary>
    /// デストラクタ
    /// </summary>
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
    int GetPriority() const;
    /// <summary>
    /// 処理順番を設定
    /// </summary>
    /// <param name="order">設定する処理順番</param>
    void SetSortOrder(int order);
    /// <summary>
    /// 処理順番を取得
    /// </summary>
    /// <returns></returns>
    int GetSortOrder() const;
    /// <summary>
    /// 有効かどうかを設定
    /// </summary>
    /// <param name="enable">trueならば有効</param>
    void SetEnable(bool enable);
    /// <summary>
    /// 有効かどうかを取得
    /// </summary>
    /// <returns>trueならば有効</returns>
    bool IsEnable() const;
    /// <summary>
    /// 表示するかどうかを設定
    /// </summary>
    /// <param name="show">tureならば表示する</param>
    void SetShow(bool show);
    /// <summary>
    /// 表示するかどうかを取得
    /// </summary>
    /// <returns>tureならば表示する</returns>
    bool IsShow() const;
    /// <summary>
    /// 影を表示するかどうかを設定
    /// </summary>
    /// <param name="shadw">tureならば表示する</param>
    void SetShadow(bool shadw);
    /// <summary>
    /// 影を表示するかどうかを取得
    /// </summary>
    /// <returns>tureならば表示する</returns>
    bool IsShadow() const;



    //タスクを消去
    void Kill();
    //タスクの消去フラグが立っているか
    bool IsKill();

    /// <summary>
    /// 更新処理
    /// </summary>
    virtual void Update();
    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void Draw();

    virtual void Collision(Task*);
};