#include "Player.h"

//コンストラクタ
Player::Player()
	:CharaBase(CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f)) 
{
	m_hp = 200;

	//プレイヤーのアニメーションデータを生成
	int frame = 6;
	mp_animData = new TexAnimData[2]		
	{
			//待機
		{
				new TexAnim[6]
			{
				{0,frame},{1,frame},{2,frame},
				{3,frame},{4,frame},{5,frame},
			},
			6
		},
			//移動
		{
			new TexAnim[6]
			{
					{6,frame},{7,frame},{8,frame},
					{9,frame},{10,frame},{11,frame},
			},
			6
		},
	};
	//プレイヤーの画像を読み込み   
	mp_image = CImage::CreateImage("Player.png",mp_animData,384.0f, 384.0f);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(192.0f, 328.0f);
}

//デストラクタ
Player::~Player() {
	//アニメーションデータの配列削除
	for (int i = 0; i < 2; i++) {
		delete[] mp_animData[i].pData;
	}
	delete[] mp_animData;

	//画像データ削除
	delete mp_image;
}

void Player::Death() {
	//基底クラスの死亡処理も呼び出す
	CharaBase::Death();

	//死亡アニメーションを再生
	//もしアニメーションが終わったら
	//ゲームオーバー画面
}

void Player::Update() {
	bool isMove = false;
	//左キーを押している間
	if (HOLD(CInput::eLeft))
	{
		//左移動
		m_pos.x -= 5.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(true);
		isMove = true;
	}
	//右キーを押している間
	else if (HOLD(CInput::eRight))
	{
		//右移動
		m_pos.x += 5.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(false);
		isMove = true;
	}
	if (HOLD(CInput::eUp))
	{
		//上移動
		m_pos.y -= 3.0f;
		mp_image->ChangeAnimation(1);
		isMove = true;
	}
	else if (HOLD(CInput::eDown))
	{
		//下移動
		m_pos.y += 3.0f;
		mp_image->ChangeAnimation(1);
		isMove = true;
	}

	//それ以外
	if(!isMove)
	{
		//待機
		mp_image->ChangeAnimation(0);
	}
	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

void Player::Render() {
	mp_image->Draw();
}