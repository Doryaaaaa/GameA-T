#include"Trapp1.h"
#include"Trapp2.h"
#include"Trapp3.h"
#include"Player.h"
//スイッチ
TexAnim Trapp2_anim_off[] = {
	{0,6},
};
TexAnim Trapp2_anim_on[] = {
	{0,6},
	{1,6},
};
TexAnimData Trapp2_anim_data[] = {
	ANIMDATA(Trapp2_anim_off),
	ANIMDATA(Trapp2_anim_on),
};


Trapp2::Trapp2(const CVector3D& pos) :ObjectBase(eType_Trapp2) {
	m_pos = pos;
	m_img = COPY_RESOURCE("Trapp2", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 130);
	m_rect = Rect3D(-100,-80,-50,100,80,50);
	m_img.ChangeAnimation(0);
	Trappflag = false;
	m_isShadow = false;
}
void Trapp2::Update() {
	if (m_pos.x < m_scroll.x - 600) {
		Kill();
	}
	//const int move_speed = 5;
	//m_pos.x -= move_speed;
	m_img.UpdateAnimation();
}
void Trapp2::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	/*Utility::DrawQuad(
		GetScreenPos(m_pos),
		CVector2D(200, 100),
		CVector4D(1, 0, 0, 0.5f));*/
	//DrawRect();
}
void Trapp2::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (ObjectBase* P1 = dynamic_cast<ObjectBase*>(b)) {
			if (ObjectBase::CollisionRect(this, P1)) {
				if (Trappflag == false) {
					(new Trapp3(m_pos + CVector3D(2000, 0, 0)));
					m_img.ChangeAnimation(1, false);
				}
				Trappflag = true;
			}
			break;

		}
	}
}