#include"Effect.h"

Effect::Effect(const char* name, const CVector2D& pos, bool flip) :ObjectBase(eType_Effect) {
	m_img = COPY_RESOURCE(name, CImage);
	m_pos = pos;
	m_img.SetSize(128, 128);
	m_img.SetCenter(64, 64);
	m_img.ChangeAnimation(0, false);
}
void Effect::Update() {

}
void Effect::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}