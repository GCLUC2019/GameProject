#include "Enemy01.h"
#include "../GameProject/Game/Character/Player.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Game/GameData/GameData.h"
#include "../GameProject/Game/CollitionBase.h"

#define MOVE_SPEED 2.0f
#define DEP_N 1200

Enemy01::Enemy01() : EnemyBase(CharacterData::eEnemy01),
m_hover(0.0f),
m_search_flg (false)
{
    m_img = COPY_RESOURCE("Enemy01", CAnimImage*);
    m_shadow = COPY_RESOURCE("Shadow", CImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.SetFlipH(m_flip);
    m_img.ChangeAnimation(eEMove01);
    m_pos = CVector2D(200, 200);
    m_vec = CVector2D(0, 0);
    m_dir = CVector2D(0, 0);
    m_state=eSearch;
    m_depth = (m_pos.y - DEP_N) / 3.5;
}

Enemy01::Enemy01(CVector2D & _pos) : EnemyBase(eEnemy01),
m_hover(0.0f),
m_search_flg(false)
{
    m_img = COPY_RESOURCE("Enemy01", CAnimImage*);
    m_shadow = COPY_RESOURCE("Shadow", CImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.SetFlipH(m_flip);
    m_img.ChangeAnimation(eEMove01);
    m_pos = _pos;
    m_state=eSearch;
	m_hp = 100;
    length = 0;
    m_vec = CVector2D(0, 0);
    m_dir = CVector2D(0, 0);
    m_rect = CRect(-IMAGE_SIZE / 2, -IMAGE_SIZE / 2, IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_depth = (m_pos.y - DEP_N) / 3.5;
}

void Enemy01::Update()
{
    
    m_vec = CVector2D(0, 0);
    switch (m_state) {
    case eMove:
        Move();
        break;
    case eSearch:
        Search();
        break;
    case eAttack:
        Attack();
        break;
    case eDamage:
        Damage();
        break;
    default:
        break;
    }
    m_depth =(m_pos.y - DEP_N) / 3.5;
    m_pos += m_vec;
    MoveControl();
    m_img.UpdateAnimation();
#ifdef _DEBUG
    if (CInput::GetState(0, CInput::ePush, CInput::eMouseL)) {
        CVector2D mouse_pos = CInput::GetMousePoint();
        printf("%f,%f,%f,%f\n", mouse_pos.x- g_game_data.m_scroll.x,mouse_pos.y- g_game_data.m_scroll.y,g_game_data.m_scroll.x, g_game_data.m_scroll.y);

    }
        
#endif
}

void Enemy01::Draw()
{
#ifdef _DEBUG//デバッグ表示　見れない場合は背景をなくしてください
    Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
    Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
    Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
    Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
    Utility::DrawQuad(CVector2D(m_pos.x , m_pos.y ), CVector2D(4, 4), CVector4D(1, 1, 0, 1));

#endif//DEBUG
    m_shadow.SetSize(SAIZE_SD + m_depth / 5, 50);
    m_shadow.SetCenter((SAIZE_SD + m_depth / 5) / 2, 50 / 2);
    m_shadow.SetPos(CVector2D(m_pos.x - g_game_data.m_scroll.x, m_pos.y - g_game_data.m_scroll.y / 3 ));
    m_shadow.Draw();

    m_hover += 0.1f;//リセットしたほうがいい？
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.SetPos(CVector2D(m_pos.x - g_game_data.m_scroll.x, m_pos.y + sin(m_hover)*10.0f - g_game_data.m_scroll.y / 3 - IMAGE_SIZE / 2));
    m_img.SetFlipH(m_flip);
    m_rect = CRect(-IMAGE_SIZE / 2 - g_game_data.m_scroll.x, -IMAGE_SIZE / 2, IMAGE_SIZE / 2 - g_game_data.m_scroll.x, IMAGE_SIZE / 2);
	m_img.Draw();

}

void Enemy01::Move()
{
    m_img.ChangeAnimation(eEMove01);
    m_vec = m_dir;
    m_state = eSearch;
    Task*t = TaskManager::FindObject(ePlayer);
    Player*p = dynamic_cast<Player*>(t);
    m_dir = p->GetPos() - m_pos;
    length = m_dir.Length();
    if (length < IMAGE_SIZE/2) {
        m_dir = m_dir.GetNormalize();
        m_state = eAttack;
    }
}

void Enemy01::Search()
{
    m_img.ChangeAnimation(eEMove01);
    if (m_flip == true) {
        m_vec.x = MOVE_SPEED;
        if (m_pos.x > 1280 - IMAGE_SIZE / 2)
            m_flip = false;
    }
    else {
        m_vec.x = -MOVE_SPEED;
        if (m_pos.x < IMAGE_SIZE / 2)
            m_flip = true;
    }
    Task*t = TaskManager::FindObject(ePlayer);
    Player*p = dynamic_cast<Player*>(t);
    m_dir = p->GetPos() - m_pos;
    length = m_dir.Length();
    if (length < IMAGE_SIZE) {
        m_dir = m_dir.GetNormalize();
        m_state = eMove;
    }
}

void Enemy01::Attack()
{
    m_img.ChangeAnimation(eEAttack03, false);

    if (m_img.CheckAnimationEnd()) {
        m_state = eSearch;
    }
       
}
void Enemy01::Damage()
{
	m_vec.x = 0;
	if (m_hp <= 0) {
		m_img.ChangeAnimation(Enemy01Anim::eEDeath01, false);
		if (m_img.CheckAnimationEnd()) {
            Player* n = dynamic_cast<Player*>(TaskManager::FindObject(CharacterData::ePlayer));
            if (n != nullptr)
                n->SpecialPuls(5);
			g_game_data.m_dead_cnt++;
			SetKill();
			
		}
	}
	else {
		m_img.ChangeAnimation(Enemy01Anim::eEDamage01, false);
		if (m_img.CheckAnimationEnd())
			m_state = Enemy01State::eSearch;
	}

	
}
void Enemy01::MoveControl()
{
}
void Enemy01::HitCheck()
{
	if (CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectLongAttack, 60.0f)) {
		SOUND("punch-middle2")->Play();
		m_hp -= 1;
		m_state = Enemy01State::eDamage;
	}
}
//2019/3/11タスクの探索処理ができ次第実装可能　田中
bool Enemy01::PlayerCheck(Player*p, Task*e, float _l)
{
    /*CVector2D vec= p->GetPos() - m_pos;
    float length = sqrt(vec.x*vec.x + vec.y*vec.y);
    if (length <= _l)
        return true;
    else
        return false;*/
    return false;
}
