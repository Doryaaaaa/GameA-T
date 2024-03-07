#include "TaskManager.h"
#include "Task.h"
#include"ObjectBase.h"

//�^�X�N�̃��X�g���`
std::list<Task*>TaskManager::m_taskList;

//�^�X�N�̃��X�g���`
std::list<Task*>TaskManager::m_objectList;

TaskManager::TaskManager() {

}

TaskManager::~TaskManager() {

}

//�^�X�N�����X�g�ɒǉ�
void TaskManager::Add(Task* add, bool isSort) {
	//�\�[�g���̃^�X�N�ǉ����̌Ăяo���łȂ����
	if(!isSort){
		//�ǉ�����^�X�N�̗D��x���I�u�W�F�N�g�Ȃ�
		//�I�u�W�F�N�g���X�g�ɒǉ�
		if (add->m_prio == (int)TaskPrio::Object) {
			m_objectList.push_back(add);
		}
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end) {
		Task* task = *itr;
		//�ǉ�����^�X�N�̗D��x�����݂̃^�X�N�̓��N�x�Ȃ�
		//���̈ʒu�Ƀ^�X�N��ǉ�
		if (add->m_prio < task->m_prio) {
			m_taskList.insert(itr, add);
			return;
		}
		//�ǉ�����^�X�N�̗D��x�ƌ��݂̃^�X�N�̗D��x�������Ȃ�
		else if (add->m_prio==task->m_prio) {
			//�������Ԃ����������ɕ��ׂ�
			if (add->m_sortOrder < task->m_sortOrder) {
				m_taskList.insert(itr, add);
				return;
			}
		}
		itr++;
	}
	//�Ō�܂Œǉ�����ꏊ���Ȃ�������
	//���X�g�̍Ō���ɒǉ�����
	m_taskList.push_back(add);
}

//�^�X�N�����X�g�Ɏ�菜��
void TaskManager::Remove(Task* remove, bool isSort) {
	
	//�\�[�g�Ăяo���łȂ�
	if (!isSort) {
		//�D��x���I�u�W�F�N�g�p�ł���΃I�u�W�F�N�g���X�g�������菜��
		if (remove->m_prio == (int)TaskPrio::Object) {
			m_objectList.remove(remove);
		}
	}

	m_taskList.remove(remove);
}

//�^�X�N���폜
void TaskManager::Delete(Task* del) {

	if (del->m_prio == (int)TaskPrio::Object) {
		m_objectList.remove(del);
	}

	//�o�������X�g
	//�폜����Ƃ��͐�Ƀ��X�g��菜���Ă���폜����
	m_taskList.remove(del);
	delete del;
}
//���X�g���̃^�X�N��S�č폜
void TaskManager::DeleteAll()
{
	//�S�č폜�Ȃ̂ŃI�u�W�F�N�g���X�g�̒��g��S�ăN���A����
	m_objectList.clear();

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end) {
		Task* del = *itr;
		//���X�g�����菜���Ă���^�X�N�폜
		itr = m_taskList.erase(itr);
		delete del;
	}
}


//���X�g���̑S�^�X�N���X�V�������Ăяo��
void TaskManager::Update() {
	//�폜�t���O�������Ă���^�X�N�폜
	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr!=end) {
		Task* task = *itr;
		//�폜�t���O�������Ă�����^�X�N�폜
		if (task->m_isKill) {
			itr = m_taskList.erase(itr);
			delete task;
		}
		//�폜�t���O�������ĂȂ���΁A���̃^�X�N
		else {
			itr++;
		}
	}
		


	//�S�Ẵ^�X�N�X�V
	 itr = m_taskList.begin();
	 end = m_taskList.end();
	while (itr != end) {
		Task* task = *itr;
		//�^�X�N���L���ł���΍X�V�������Ăяo��
		if (task->m_isEnable) {
			task->Update();
		}
		itr++;
	}
}
//���X�g���̑S�^�X�N��`�揈�����Ăяo��
void TaskManager::Render()
{
	//�I�u�W�F�N�g���X�g�̒��̃I�u�W�F�N�g��
	//���s���̍��W�ŕ��ѕς���
	m_objectList.sort(
		//�����_��
		[](const Task* taskA,const Task* taskB) {

			const ObjectBase* objA = dynamic_cast<const ObjectBase*>(taskA);
			const ObjectBase* objB = dynamic_cast<const ObjectBase*>(taskB);
			return objA->GetPos().y < objB->GetPos().y;
		}
	);
	
	//�I�u�W�F�N�g���X�g�̏��Ԃɏ������Ԃ̔ԍ���ݒ肷��
	int sortOrder = 0;
	for (auto& obj : m_objectList) {
		obj->SetSortOrder(sortOrder);
		sortOrder++;
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end) {
		Task* task = *itr;
		//�^�X�N���L�����\������ݒ�ł���Ε`�揈�����Ăяo��
		if (task->m_isEnable && task->m_isShow) {
			task->Render();
		}
		itr++;
	}
}

