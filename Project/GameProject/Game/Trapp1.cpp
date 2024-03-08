#include"Trapp1.h"
//スイッチ
Trapp1::Trapp1(const CVector3D& pos) :Base(eType_Trapp1) {
	m_pos = pos;
	m_img = COPY_RESOURCE("Trapp1", CImage);
	//m_img.SetSize(50, 32);

}
void Trapp1::Update() {
	const int move_speed = 5;
	m_pos.x -= move_speed;
}
void Trapp1::Draw() {
	m_img.SetPos(m_pos.x, m_pos.y);
	m_img.Draw();
	//DrawRect();
}