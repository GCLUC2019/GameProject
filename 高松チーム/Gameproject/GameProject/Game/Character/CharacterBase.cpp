#include "CharacterBase.h"

CharacterBase::CharacterBase(int _type) : Task(CharacterData::eCharacterBase)
{
	m_type = _type;
}

void CharacterBase::Update()
{
}

void CharacterBase::Draw()
{
}

void CharacterBase::Damage(int _damage)
{
}
