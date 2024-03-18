#pragma once
#include<list>

class Task;

class TaskManager
{
public:

	/// <summary>
	///�^�X�N�����X�g�ɒǉ� 
	/// </summary>
	/// <param name="add">�ǉ�����^�X�N�̃|�C���^�[</param>
	/// <param name="isSort">�\�[�g���̌Ăяo�����ǂ���</param>
	static void Add(Task* add, bool isSort = false);
	/// <summary>
	/// �^�X�N�����X�g�����菜��
	/// </summary>
	/// <param name="remove">��菜���^�X�N�̃|�C���^�[</param>
	/// <param name="isSort">�\�[�g���̌Ăяo�����ǂ���</param>
	static void Remove(Task* remove, bool isSort = false);

	/// <summary>
	/// �^�X�N���폜
	/// </summary>
	/// <param name="del">�폜����^�X�N�̃|�C���^�[</param>
	static void Delete(Task* del);
	//���X�g���̃^�X�N��S�č폜
	static void DeleteAll();

	/// <summary>
	/// �S�Ă̓����蔻����Ăяo��
	/// </summary>
	static void CollisionAll();

	/// <summary>
	/// �S�I�u�W�F�N�g�̍폜
	/// </summary>
	static void KillAll();


	/// <summary>
	/// �I�u�W�F�N�g���X�g���擾
	/// </summary>
	/// <returns></returns>
	static const std::list<Task*>& GetObjctList();

	/// <summary>
/// ���X�g������I�u�W�F�N�g��T��
/// </summary>
/// <param name="type">���</param>
/// <returns>�ŏ��Ɍ������I�u�W�F�N�g</returns>
	static Task* FindObject(int type);

	/// <summary>
/// ���X�g������I�u�W�F�N�g��T��
/// </summary>
/// <param name="type">���</param>
/// <returns>�Y����ނ̃I�u�W�F�N�g�̃��X�g</returns>
	static std::list<Task*> FindObjects(int type);



	//���X�g���̑S�^�X�N�̍X�V�������Ăяo��
	static void UpDate();
	//���X�g���̑S�^�X�N�̕`�揈�����Ăяo��
	static void Draw();

private:
	//�R���X�g���N�^
	TaskManager();
	//�f�X�g���N�^
	~TaskManager();

	//���ݐ�������Ă���^�X�N�̃��X�g
	static std::list<Task*> m_taskList;
	//���ݐ�������Ă���I�u�W�F�N�g�̃��X�g
	static std::list<Task*> m_objectList;
};