#pragma once
#include"Task.h"

/// <summary>
/// �Q�[���I�u�W�F�N�g�̊��N���X
/// </summary>
class ObjectBase : public Task {
public:
    //���W�f�[�^
    CVector3D m_pos;
    //�ߋ��̈ʒu
    CVector3D m_pos_old;
    //�ړ��x�N�g��
    CVector3D m_vec;
    //�X�N���[���l
    static CVector3D m_scroll;
    //��`
    CRect   m_rect;
public:
    /// <summary>
   /// �R���X�g���N�^
   /// </summary>
    ObjectBase(int type);
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~ObjectBase();
    /// <summary>
    /// �X�V����
    /// </summary>
    virtual void Update();
    /// <summary>
    /// �`�揈��
    /// </summary>
    virtual void Draw();
    /// <summary>
    /// ��ʓ��ł̈ʒu���擾
    /// </summary>
    /// <param name="pos">�L�����N�^�[�Ȃǂ̍��W</param>
    /// <returns>��ʏ�ł̈ʒu</returns>
    static CVector2D GetScreenPos(const CVector3D& pos);
    /// <summary>
   /// �S�ẴI�u�W�F�N�g���m�̑g�ݍ��킹�œ����蔻�茟��
   /// </summary>
   /// <summary>
   /// ��`���m�̔���
   /// </summary>
   /// <param name="b1">�Ώ�</param>
   /// <param name="b2">�Ώ�</param>
   /// <returns></returns>
    static bool CollisionRect(ObjectBase* b1, ObjectBase* b2);
    /// <summary>
    /// ��`�̕\��
    /// </summary>
    virtual void Collision(ObjectBase* b);
    void DrawRect();
};