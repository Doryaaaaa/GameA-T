#include"Trapp3.h"
#include"Task/TaskManager.h"
#include"Task/Task.h"
//ƒgƒQ
TexAnim Trapp3_anim[] = {
	{0,6},
	{1,6},
	{2,6},
	{3,6},
};
TexAnimData Trapp3_anim_data[] = {
	ANIMDATA(Trapp3_anim),
};

//ƒgƒQ
Trapp3::Trapp3(const CVector3D& pos) :ObjectBase(eType_Trapp3) {
	m_pos = pos;
	m_img = COPY_RESOURCE("Trapp3", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(110, 160);
	m_rect = Rect3D(-100, -100, -50, 100, 30, 50);
	m_img.ChangeAnimation(0);
}
void Trapp3::Update() {
	if (m_pos.x < m_scroll.x -600) {
		Kill();
	}
	if (m_Damage == true) {
		cnt++;
		if (cnt > 60) {
			m_Damage = false;
			cnt = 0;
		}
	}
	//const int move_speed = 5;
	//m_pos.x -= move_speed;
	//m_vec.y += GRAVITY;
	//m_pos += m_vec;
	m_img.UpdateAnimation();
}
void Trapp3::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	/*Utility::DrawQuad(
		GetScreenPos(m_pos),
		CVector2D(200, 100),
		CVector4D(1, 0, 0, 0.5f));*/
	//DrawRect();
}
void Trapp3::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (ObjectBase* P1 = dynamic_cast<ObjectBase*>(b)) {
			if (m_Damage == false) {

				m_Damage = true;
			}
			break;

		}
	}
	switch (b->m_type) {
	case eType_Trapp2:
		if (ObjectBase* P1 = dynamic_cast<ObjectBase*>(b)) {
			if (ObjectBase::CollisionRect(this, P1)) {
				P1->Kill();
			}
		}
		break;
	}
	switch (b->m_type) {
	case eType_Portion1:
		if (ObjectBase* P1 = dynamic_cast<ObjectBase*>(b)) {
			if (ObjectBase::CollisionRect(this, P1)) {
				P1->Kill();
			}
		}
		break;
	}
}
//—Ž‚Æ‚µŒŠ
Trapp4::Trapp4(const CVector3D& pos) :ObjectBase(eType_Trapp4) {
	m_pos = pos;
	m_img = COPY_RESOURCE("Trapp4", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	m_rect = Rect3D(-100, -80, -50, 100, 80, 50);
}
void Trapp4::Update() {
	if (m_pos.x < m_scroll.x - 600) {
		Kill();
	}
	if (m_Damage == true) {
		cnt++;
		if (cnt > 60) {
			m_Damage = false;
			cnt = 0;
		}
	}
	//const int move_speed = 5;
	//m_pos.x -= move_speed;
	//m_vec.y += GRAVITY;
	//m_pos += m_vec;
}
void Trapp4::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	/*Utility::DrawQuad(
		GetScreenPos(m_pos),
		CVector2D(200, 100),
		CVector4D(1, 0, 0, 0.5f));*/
	//DrawRect();
}
void Trapp4::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (ObjectBase* P1 = dynamic_cast<ObjectBase*>(b)) {
			if (m_Damage == false) {

				m_Damage = true;
			}
			break;

		}
	}
	switch (b->m_type) {
	case eType_Trapp3:
		if (ObjectBase* P1 = dynamic_cast<ObjectBase*>(b)) {
			if (ObjectBase::CollisionRect(this, P1)) {
				P1->Kill();
			}
		}
		break;
	}
	switch (b->m_type) {
	case eType_Trapp2:
		if (ObjectBase* P1 = dynamic_cast<ObjectBase*>(b)) {
			if (ObjectBase::CollisionRect(this, P1)) {
				P1->Kill();
			}
		}
		break;
	}
	switch (b->m_type) {
	case eType_Portion1:
		if (ObjectBase* P1 = dynamic_cast<ObjectBase*>(b)) {
			if (ObjectBase::CollisionRect(this, P1)) {
				P1->Kill();
			}
		}
		break;
	}
}