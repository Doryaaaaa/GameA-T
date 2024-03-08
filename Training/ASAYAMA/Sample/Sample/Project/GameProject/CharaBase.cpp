#include"CharaBase.h"

CharaBase::CharaBase(const CVector2D& pos)
: ObjectBase(pos)
		,m_hp(100)
		,m_isDeath(false)
{

}
//�f�X�g���N�^
CharaBase::~CharaBase() {

}
//�_���[�W���󂯂�
void CharaBase::TakeDamage(int damage) {
	//���ł�HP���O�ł���΁A�_���[�W���������s���Ȃ�
	if (m_hp <= 0)return;
	//�c��HP����_���[�W�����Z
	m_hp -= damage;
	//�c��HP���O�ł����
	if (m_hp <= 0) {
		//���S����
		Death();
	}
}
//���S�������̏���
void CharaBase::Death() {
	//���S�t���O�𗧂Ă�
	m_isDeath = true;
}