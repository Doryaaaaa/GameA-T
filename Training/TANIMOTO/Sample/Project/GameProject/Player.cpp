#include "Player.h"

// コンストラクタ
Player::Player()
	:m_pos(CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f))
	,m_hp(100)
	// 初期化子リスト
{
	//プレイヤーのアニメーションデータを生成
	int frame = 6;
	mp_animData = new TexAnimData[2]
	{
		//待機アニメーション
		{
			new TexAnim[6]
			{
				{0,frame},{1,frame},{2,frame},{3,frame},{4,frame},{5,frame},
			},
			6
		},
		//移動アニメーション
		{new TexAnim[6]
			{
				{6,frame},{7,frame},{8,frame},{9,frame},{10,frame},{11,frame},
			},
			6
		},
	};
	// プレイヤーの画像を読み込み
	mp_image = CImage::CreateImage(
		"player.png"	//画像ファイルのパス
		,mp_animData,	//アニメーションのデータ
		384.0f,384.0f	//1コマの幅と高さ
	);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(192.0f, 328.0f);
}

// デストラクタ
Player::~Player()
{
	// アニメーションデータの配列を削除
	for (int i = 0; i < 2; i++)
	{
		delete[] mp_animData[i].pData;
	}
	delete[] mp_animData;

	// 画像データを削除
	delete mp_image;
}

//プレイヤーの座標を取得
CVector2D Player::GetPos()
{
	return m_pos;
}

//プレイヤーの座標を設定
void Player::SetPos(CVector2D pos)
{
	m_pos = pos;
}

// 更新処理
void Player::Update()
{
	// 左キーを押している間
	if (HOLD(CInput::eLeft))
	{
		// 左方向へ移動
		m_pos.x -= 8.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(true);
	}
	// 右キーを押している間
	else if (HOLD(CInput::eRight))
	{
		// 右方向へ移動
		m_pos.x += 8.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(false);
	}
	// 左右キーどちらも押されていない場合
	else
	{
		// 待機アニメーションを再生
		mp_image->ChangeAnimation(0);
	}

	// イメージに座標を設定して、アニメーションを更新
	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

// 描画処理
void Player::Render()
{
	mp_image->Draw();
}