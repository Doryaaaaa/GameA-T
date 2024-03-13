#include"Trapp3.h"
#include"Task/TaskManager.h"
#include"Task/Task.h"
//�g�Q
TexAnim Trapp3_anim[] = {
	{0,6},
	{1,6},
	{2,6},
	{3,6},
};
TexAnimData Trapp3_anim_data[] = {
	ANIMDATA(Trapp3_anim),
};

//�g�Q
Trapp3::Trapp3(const CVector3D& pos) :ObjectBase(eType_Trapp3) {
	m_pos = pos;
	m_img = COPY_RESOURCE("Trapp3", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(110, 160);
	m_rect = Rect3D(-100, -100, -50, 100, 30, 50);
	m_img.ChangeAnimation(0);
}
void Trapp3::Update() {
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
	DrawRect();
}
//���Ƃ���
Trapp4::Trapp4(const CVector3D& pos) :ObjectBase(eType_Trapp4) {
	m_pos = pos;
	m_img = COPY_RESOURCE("Trapp4", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	m_rect = Rect3D(-100, -80, -50, 100, 80, 50);
}
void Trapp4::Update() {
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
	DrawRect();
}