#include "CharacterBase.h"

CharaBase::CharaBase(const CVector2D&pos)
	:ObjectBase(pos)
	,m_hp(100)
	,m_isDeath(false)
{

}

CharaBase::~CharaBase()
{

}
//�_���[�W���󂯂�
void CharaBase::TakeDamage(int damage) {
	//����HP��0�Ȃ�_���[�W��������Ȃ�
	if (m_hp <= 0) return;

	//�_���[�W�v�Z
	m_hp -= damage;
	//�����O�Ȃ�
	if (m_hp <= 0) {
		//���S
		Death();
	}
}
//���S�������̏���
void CharaBase::Death() {
	//���S�t���O�𗧂Ă�
	m_isDeath = true;
}