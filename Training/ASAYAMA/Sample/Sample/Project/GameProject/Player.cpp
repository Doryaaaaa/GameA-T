#include"Player.h"
//コンストラクタ
Player::Player()
	: m_pos(CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f))
	,m_hp(100)
	{
	m_pos = CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f);
	int frame = 6;
	m_animData=new TexAnimData[2]
	{
		//待機アニメーション
		{
		new TexAnim[6]
		{
			{0,frame},{1,frame},{2,frame},
			{3,frame},{4,frame},{5,frame},
			},
			6
	},
		//移動アニメーション
	{
		new TexAnim[6]
		{
			{0,frame},{1,frame},{2,frame},
			{3,frame},{4,frame},{5,frame,}
			},
		6
	},
};
	m_img = CImage::CreateImage
	("player.png",
		m_animData,
		384.0f, 384.0f);
	m_img->ChangeAnimation(0);
	m_img->SetCenter(192.0f, 328.0f);
}
//デストラクタ
Player::~Player() {
	for (int i= 0; i < 2; i++) {
		delete[] m_animData[i].pData;
	}
	delete[]m_animData;
	delete m_img;
}
//プレイヤー座標取得
const CVector2D& Player::GetPos()const{
	return m_pos;
}
void Player::SetPos(const CVector2D& pos){
	m_pos = pos;
}
//更新処理
void Player::Update() {
	bool isMove = false;
	if (HOLD(CInput::eLeft))
	{
		m_pos.x -= 8.0f;
		m_img->ChangeAnimation(1);
		m_img->SetFlipH(true);
		isMove = true;
	}
	else if (HOLD(CInput::eRight))
	{
		m_pos.x += 8.0f;
		m_img->ChangeAnimation(1);
		m_img->SetFlipH(false);
		isMove = true;
	}
	if (HOLD(CInput::eUp))
	{
		m_pos.y -= 3.0f;
		m_img->ChangeAnimation(1);
		m_img->SetFlipH(false);
		isMove = true;
	}
	else if (HOLD(CInput::eDown))
	{
		m_pos.y += 3.0f;
		m_img->ChangeAnimation(1);
		m_img->SetFlipH(false);
		isMove = true;
	}
	else
	{
		m_img->ChangeAnimation(0);
	}
	m_img->SetPos(m_pos);
	m_img->UpdateAnimation();
}
//描画処理
void Player::Render() {
	m_img->Draw();
}
