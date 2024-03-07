#include "Player.h"

//�R���X�g���N�^
Player::Player()
	:CharaBase(CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f)) 
{
	m_hp = 200;

	//�v���C���[�̃A�j���[�V�����f�[�^�𐶐�
	int frame = 6;
	mp_animData = new TexAnimData[2]		
	{
			//�ҋ@
		{
				new TexAnim[6]
			{
				{0,frame},{1,frame},{2,frame},
				{3,frame},{4,frame},{5,frame},
			},
			6
		},
			//�ړ�
		{
			new TexAnim[6]
			{
					{6,frame},{7,frame},{8,frame},
					{9,frame},{10,frame},{11,frame},
			},
			6
		},
	};
	//�v���C���[�̉摜��ǂݍ���   
	mp_image = CImage::CreateImage("Player.png",mp_animData,384.0f, 384.0f);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(192.0f, 328.0f);
}

//�f�X�g���N�^
Player::~Player() {
	//�A�j���[�V�����f�[�^�̔z��폜
	for (int i = 0; i < 2; i++) {
		delete[] mp_animData[i].pData;
	}
	delete[] mp_animData;

	//�摜�f�[�^�폜
	delete mp_image;
}

void Player::Death() {
	//���N���X�̎��S�������Ăяo��
	CharaBase::Death();

	//���S�A�j���[�V�������Đ�
	//�����A�j���[�V�������I�������
	//�Q�[���I�[�o�[���
}

void Player::Update() {
	bool isMove = false;
	//���L�[�������Ă����
	if (HOLD(CInput::eLeft))
	{
		//���ړ�
		m_pos.x -= 5.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(true);
		isMove = true;
	}
	//�E�L�[�������Ă����
	else if (HOLD(CInput::eRight))
	{
		//�E�ړ�
		m_pos.x += 5.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(false);
		isMove = true;
	}
	if (HOLD(CInput::eUp))
	{
		//��ړ�
		m_pos.y -= 3.0f;
		mp_image->ChangeAnimation(1);
		isMove = true;
	}
	else if (HOLD(CInput::eDown))
	{
		//���ړ�
		m_pos.y += 3.0f;
		mp_image->ChangeAnimation(1);
		isMove = true;
	}

	//����ȊO
	if(!isMove)
	{
		//�ҋ@
		mp_image->ChangeAnimation(0);
	}
	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

void Player::Render() {
	mp_image->Draw();
}