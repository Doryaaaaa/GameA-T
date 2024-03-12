#include"Trapp2.h"
//スイッチ
TexAnim Trapp2_anim[] = {
	{0,6},
	{1,6},
};
TexAnimData Trapp2_anim_data[] = {
	ANIMDATA(Trapp2_anim),
};


Trapp2::Trapp2(const CVector3D& pos) :ObjectBase(eType_Trapp2) {
	m_pos = pos;
	m_img = COPY_RESOURCE("Trapp2", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 200);
	m_img.ChangeAnimation(0);
}
void Trapp2::Update() {
	//const int move_speed = 5;
	//m_pos.x -= move_speed;
	m_img.UpdateAnimation();
}
void Trapp2::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	Utility::DrawQuad(
		GetScreenPos(m_pos),
		CVector2D(200, 100),
		CVector4D(1, 0, 0, 0.5f));
	//DrawRect();
}