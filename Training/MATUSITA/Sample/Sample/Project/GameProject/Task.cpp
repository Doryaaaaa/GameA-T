#include "Task.h"
#include "TaskManager.h"

Task::Task(int prio):
	m_prio(prio),
	m_sortOrder(0),
	m_isEnable(true),
	m_isShow(true),
	m_isKill(false){
	//�^�X�N�̐����Ɠ����Ƀ^�X�N�}�l�[�W���[�̃��X�g�Ɏ��M��ǉ�
	TaskManager::Add(this);
}

Task::~Task()
{
	//�^�X�N�̐����Ɠ����Ƀ^�X�N�}�l�[�W���[�̃��X�g�Ɏ��M����菜��
	TaskManager::Remove(this);
}

//�D��x��ݒ�
void Task::SetPriority(int prio)
{
	m_prio = prio;
	//���^�X�N�̃��X�g���玩�g����菜��
	//���̌������x�^�X�N�̃��X�g�ɒǉ�����֐����Ăяo��
	//�V�����D��x�̏ꏊ�Ƀ^�X�N��ύX����
	TaskManager::Remove(this,true);
	TaskManager::Add(this,true);
}

//�D��x���擾
int Task::GetPriority() const
{
	return m_prio;
}

//�������Ԃ�ݒ�
void Task::SetSortOrder(int order)
{
	//�������Ԃ�ύX��Ƀ��X�g�̕��ёւ����s��
	m_sortOrder = order;
	TaskManager::Remove(this, true);
	TaskManager::Add(this, true);
}

//�������Ԃ��擾
int Task::GetSortOrder() const
{
	return m_sortOrder;
}

void Task::SetEnable(bool enable)
{
	m_isEnable = enable;
}

bool Task::IsEnable() const
{
	return m_isEnable;
}

void Task::SetShow(bool show)
{
	m_isShow = show;
}

bool Task::IsShow() const
{
	return m_isShow;
}

void Task::Kill()
{
	m_isKill = true;
}

void Task::Update()
{
	
}

void Task::Render()
{
}
