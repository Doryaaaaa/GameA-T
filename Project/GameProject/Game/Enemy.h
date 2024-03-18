#pragma once
#include"../Task/ObjectBase.h"
#include"EnemyHp.h"

class Enemy :public ObjectBase{
public:
	Enemy(const CVector3D&pos, bool flip);

	void Update();
	void Draw();
	void Collision(Task* b);

private:
	CImage m_img;
	int m_hp;
	EnemyHp* m_hpGeag;
	int m_cnt;
	int cnt;
	bool m_is_ground;
	bool m_Damage;
	bool m_flip;
};
extern TexAnimData enemy_anim_data[];
/*class Enemywall :public ObjectBase {
public:
	Enemywall(const CVector3D& pos);

	void Update();
	void Draw();
	//void Collision(Task* b);

private:
	CImage m_img;
	int m_cnt;
	int cnt;
};*/