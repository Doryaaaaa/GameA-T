#pragma once
#include"Task.h"

class ObjectBase:public Task {
public:
	ObjectBase(const CVector2D& pos);
	virtual~ObjectBase();


	void SetPos(const CVector2D& pos);
	const CVector2D&GetPos()const;

	


protected:
	CVector2D m_pos;
};