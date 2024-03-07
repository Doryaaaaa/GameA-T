#pragma once

class TaskManager;

enum class TaskPrio {
    Field,//�t�B�[���h
	Shadow,//�I�u�W�F�N�g�̉e
    Object,//�Q�[�����I�u�W�F�N�g

    UI,//��ʂɕ\������HUD�Ȃǂ�UI
};


//�^�X�N�N���X
class Task {
public:
	//�R���X�g���N�^
	Task(int prio);
	//�f�X�g���N�^
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
	int GetPriority()const;
	/// <summary>
	/// �������Ԃ�ݒ�
	/// </summary>
	/// <param name="order">�ݒ肷�鏈������</param>
	void SetSortOrder(int order);
	/// <summary>
	/// �������Ԃ��擾
	/// </summary>
	/// <returns></returns>
	int GetSortOrder()const;
	/// <summary>
	/// �L�����ǂ����̐ݒ�
	/// </summary>
	/// <param name="enabie">true�Ȃ�ΗL��</param>
	void SetEnable(bool enabie);
	/// <summary>
	/// �L�����ǂ������擾
	/// </summary>
	/// <returns>true�Ȃ�ΗL��</returns>
	bool IsEnable()const;
	/// <summary>
	/// �\�����邩�ǂ�����ݒ�
	/// </summary>
	/// <param name="show">true�Ȃ�Ε\��</param>
	void SetShow(bool show);
	/// <summary>
	/// �\�����邩�ǂ������擾
	/// </summary>
	/// <returns>true�Ȃ�Ε\������</returns>
	bool IsShow()const;
	//�^�X�N���폜
	void Kill();
	//�^�X�N�̍폜�t���O�������Ă��邩
	bool IsKill()const;
	//�X�V
	virtual void Update();
	//�`��
	virtual void Render();
//private:
	int m_prio;//�^�X�N�D��x
	int m_sortOrder;//�����D��x���̏�������
	bool m_isEnable;//�^�X�N���L�����ǂ���
	bool m_isShow;//�^�X�N��`�悷�邩�ǂ���
	bool m_isKill;//�^�X�N�̍폜�t���O
};