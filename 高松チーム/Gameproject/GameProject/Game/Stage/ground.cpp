#include "ground.h"
#include "../Stage/ground.h"

Ground::Ground() : Task(eGround)
{
	m_img = COPY_RESOURCE("Ground", CImage*);
}

void Ground::Update()
{

}

void Ground::Draw()
{
	m_img.SetSize(4000, 1400);
	m_img.SetPos(0,-680);
	m_img.Draw();
}



Bamboo::Bamboo() : Task(eBamboo)
{
	m_img = COPY_RESOURCE("Bamboo", CImage*);
}

void Bamboo::Update()
{
}

void Bamboo::Draw()
{
	m_img.SetSize(2000, 700);
	m_img.SetPos(0, 0);
	m_img.Draw();
}
