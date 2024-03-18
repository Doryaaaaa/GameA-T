#include"Task.h"
#include"TaskManager.h"
//#include"Base.h"
Task::Task(int type, int prio)
    :m_type(type)
    , m_prio(prio)
    , m_sortOrder(0)
    , m_ShadowSize(0)
    , m_ShadowCenter(0)
    , m_isEnable(true)
    , m_isShow(true)
    , m_isKill(false)
    ,m_isShadow(true)
{
    //�^�X�N�̐����Ɠ�����TaskManager�Ɏ��g��ǉ�
    TaskManager::Add(this);
}

Task::~Task()
{
    //�^�X�N�̍폜�Ɠ�����TaskManager�̃��X�g���玩�g����菜��
    TaskManager::Remove(this);
}

//�D��x����ݒ�
void Task::SetPriority(int prio)
{
    m_prio = prio;
    //1��^�X�N�̃��X�g���玩�M����菜���A
    //���̌����1�x�^�X�N���X�g�ɒǉ�����֐����Ăяo�����Ƃ�
    //�V�����D��x�̏ꏊ�Ƀ^�X�N��ύX����
    TaskManager::Remove(this, true);
    TaskManager::Add(this, true);
}

//�D��x���擾
int Task::GetPriority() const
{
    return m_prio;
}

//�������Ԃ�ݒ�
void Task::SetSortOrder(int order)
{
    //�������Ԃ�ύX��ɁA���X�g���ɕ��ёւ����s��
    m_sortOrder = order;
    TaskManager::Remove(this, true);
    TaskManager::Add(this, true);
}

//�������Ԃ��擾
int Task::GetSortOrder() const
{
    return m_sortOrder;
}

//�L�����ǂ�����ݒ�
void Task::SetEnable(bool enable)
{
    m_isEnable = enable;
}

//�L�����ǂ������擾
bool Task::IsEnable() const
{
    return m_isEnable;
}

//�\�����邩�ǂ�����ݒ�
void Task::SetShow(bool show)
{
    m_isShow = show;
}

//�\�����邩�ǂ������擾
bool Task::IsShow() const
{
    return m_isShow;
}
//�e��\�����邩�ǂ�����ݒ�
void Task::SetShadow(bool shadw)
{
    m_isShadow = shadw;
}
//�e��\�����邩�ǂ������擾
bool Task::IsShadow() const
{
    return m_isShadow;
}



//�^�X�N������
void Task::Kill()
{
    m_isKill = true;
}

//�^�X�N�̏����t���O�������Ă��邩
bool Task::IsKill()
{
    return m_isKill;
}




void Task::Update()
{

}

void Task::Draw()
{

}

void Task::Collision(Task*)
{
}