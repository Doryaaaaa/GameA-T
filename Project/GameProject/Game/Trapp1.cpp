#include"Trapp1.h"
//ƒgƒQ
TexAnim Trapp1_anim[] = {
	{0,6},
	{1,6},
	{2,6},
	{3,6},
};
TexAnimData Trapp1_anim_data[] = {
	ANIMDATA(Trapp1_anim),
};


Trapp1::Trapp1(const CVector3D& pos) :ObjectBase(eType_Trapp1) {
	m_pos = pos;
	m_img = COPY_RESOURCE("Trapp1", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(0, 100);
	m_rect = CRect(-100,-200, 100, 0);
	m_img.ChangeAnimation(0);
}
void Trapp1::Update() {
	//const int move_speed = 5;
	//m_pos.x -= move_speed;
	m_img.UpdateAnimation();
}
void Trapp1::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	Utility::DrawQuad(
		GetScreenPos(m_pos),
		CVector2D(200, 100),
		CVector4D(1, 0, 0, 0.5f));
	DrawRect();
}