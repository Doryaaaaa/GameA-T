#include"Trapp1.h"
#include"Trapp3.h"
#include"Task/TaskManager.h"
#include"Task/Task.h"
//レバー
TexAnim Trapp1_anim_off[] = {
	{0,6},
};
TexAnim Trapp1_anim_on[] = {
	{0,6},
	{1,6},
};
TexAnimData Trapp1_anim_data[] = {
	ANIMDATA(Trapp1_anim_off),
	ANIMDATA(Trapp1_anim_on),
};


Trapp1::Trapp1(const CVector3D& pos) :ObjectBase(eType_Trapp1) {
	m_pos = pos;
	m_img = COPY_RESOURCE("Trapp1", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 200);
	m_rect = Rect3D(-100, -200, -100, 100, 0, 100);	
	m_img.ChangeAnimation(0);
	Trappflag = false;
}
void Trapp1::Update() {
	//const int move_speed = 5;
	//m_pos.x -= move_speed;
	//m_vec.y += GRAVITY;
	//m_pos += m_vec;
	m_img.UpdateAnimation();
}
void Trapp1::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	/*Utility::DrawQuad(
		GetScreenPos(m_pos),
		CVector2D(200, 100),
		CVector4D(1, 0, 0, 0.5f));*/
	DrawRect();
}

void Trapp1::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (ObjectBase* P1 = dynamic_cast<ObjectBase*>(b)) {
			if (ObjectBase::CollisionRect(this, P1)) {
				if (Trappflag == false) {
					m_cnt--;
					if (m_cnt <= 0) {
						//どこに配置するためのランダムな数字
						m_rcnt = Utility::Rand(0, 300);

						if (m_rcnt < 100) {
							//アイテム出現　上
							(new Trapp4(CVector3D(m_scroll.x + 2000, 1000, -310)));
						}
						else if (m_rcnt < 200) {
							//アイテム出現　真ん中
							(new Trapp4(CVector3D(m_scroll.x + 2000, 1000, -170)));
						}
						else {
							//アイテム出現 下
							(new Trapp4(CVector3D(m_scroll.x + 2000, 1000, -30)));
						}
						m_img.ChangeAnimation(1, false);
					}
					Trappflag = true;
				}
			}
			
			break;
		}
	}
}
