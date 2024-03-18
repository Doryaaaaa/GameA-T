#pragma once
class TaskManager;

//�d�͉����x
#define GRAVITY (9.8f/20)
/// <summary>
/// �I�u�W�F�N�g�̎��
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
//�^�X�N�̗D��x
enum class TaskPrio
{
    Game,      //�Ăяo��
    Title,     //�^�C�g��
    Field,     //�t�B�[���h
    Shadow,    //�I�u�W�F�N�g�̉e
    EnemyHp,   //�G�l�~�[��HP�o�[
    Timer,     //�^�C�}�[
    Object,    //�Q�[�����̃I�u�W�F�N�g
    TrappManager,   //�S�Ă��Ăяo��

    UI,        //��ʂɕ\������HUD�Ȃǂ�UI

};
class Task
{
    friend TaskManager;

public:

    //�I�u�W�F�N�g�̎��
    int m_type;
    //�^�X�N�̗D��x
    int m_prio;
    //�����D��x���̏�������
    int m_sortOrder;
    //�e�̃T�C�Y
    int m_ShadowSize;
    //
    int m_ShadowCenter;
    //�^�X�N���L�����ǂ���
    bool m_isEnable;
    //�^�X�N��`�悷�邩�ǂ���
    bool m_isShow;
    //�e��`�悷�邩�ǂ���
    bool m_isShadow;
    //�^�X�N�̍폜�t���O
    bool m_isKill;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Task(int type, int prio);
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~Task();
    /// <summary>
    /// �D��x��ݒ�
    /// </summary>
    /// <param name="prio">�ݒ肷��D��x</param>
    void SetPriority(int prio);
    /// <summary>
    /// �D��x���擾
    /// </summary>
    /// <returns></returns>
    int GetPriority() const;
    /// <summary>
    /// �������Ԃ�ݒ�
    /// </summary>
    /// <param name="order">�ݒ肷�鏈������</param>
    void SetSortOrder(int order);
    /// <summary>
    /// �������Ԃ��擾
    /// </summary>
    /// <returns></returns>
    int GetSortOrder() const;
    /// <summary>
    /// �L�����ǂ�����ݒ�
    /// </summary>
    /// <param name="enable">true�Ȃ�ΗL��</param>
    void SetEnable(bool enable);
    /// <summary>
    /// �L�����ǂ������擾
    /// </summary>
    /// <returns>true�Ȃ�ΗL��</returns>
    bool IsEnable() const;
    /// <summary>
    /// �\�����邩�ǂ�����ݒ�
    /// </summary>
    /// <param name="show">ture�Ȃ�Ε\������</param>
    void SetShow(bool show);
    /// <summary>
    /// �\�����邩�ǂ������擾
    /// </summary>
    /// <returns>ture�Ȃ�Ε\������</returns>
    bool IsShow() const;
    /// <summary>
    /// �e��\�����邩�ǂ�����ݒ�
    /// </summary>
    /// <param name="shadw">ture�Ȃ�Ε\������</param>
    void SetShadow(bool shadw);
    /// <summary>
    /// �e��\�����邩�ǂ������擾
    /// </summary>
    /// <returns>ture�Ȃ�Ε\������</returns>
    bool IsShadow() const;



    //�^�X�N������
    void Kill();
    //�^�X�N�̏����t���O�������Ă��邩
    bool IsKill();

    /// <summary>
    /// �X�V����
    /// </summary>
    virtual void Update();
    /// <summary>
    /// �`�揈��
    /// </summary>
    virtual void Draw();

    virtual void Collision(Task*);
};