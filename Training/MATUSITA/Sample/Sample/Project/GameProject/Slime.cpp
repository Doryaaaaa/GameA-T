#include "Slime.h"

//�R���X�g���N�^
Slime::Slime(int type,const CVector2D&pos) :CharaBase(pos),m_type(type)
{
	m_hp = 50;
	//�v���C���[�̃A�j���[�V�����f�[�^�𐶐�
	int f = 6;
	mp_animData = new TexAnimData[2]
	{
		//�ҋ@
		{
			new TexAnim[4]
				{
					{ 0, f}, { 1, f}, { 2, f}, { 3, f},
				},
				4
		},
	
	};
	//�v���C���[�̉摜��ǂݍ��� 
	std::string imagePath;
	if (m_type == 0)imagePath = "Slime_a.png";
	else if(m_type==1)imagePath = "Slime_b.png";
	else if (m_type == 2)imagePath = "Slime_c.png";
	mp_image = CImage::CreateImage(imagePath.c_str(), mp_animData, 256.0f, 256.0f);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(128.0f, 184.0f);
	mp_image->SetFlipH(true);
}

//�f�X�g���N�^
Slime::~Slime() {
	//�A�j���[�V�����f�[�^�̔z��폜
	for (int i = 0; i < 1; i++) {
		delete[] mp_animData[i].pData;
	}
	delete[] mp_animData;

	//�摜�f�[�^�폜
	delete mp_image;
}

void Slime::Update() {
	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

void Slime::Render() {
	mp_image->Draw();
}