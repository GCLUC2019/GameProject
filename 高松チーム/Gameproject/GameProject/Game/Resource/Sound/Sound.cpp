#include "Sound.h"

Sound::Sound() : Task (eSound)
{
	/*
		BGM
	*/
	SOUND("Enishi")->Load("../data/Sound/BGM/Enishi.wav");
	SOUND("ikusa_japan2")->Load("../data/Sound/BGM/ikusa_japan2.wav");
	SOUND("n32")->Load("../data/Sound/BGM/n32.wav");
	SOUND("n82")->Load("../data/Sound/BGM/n82.wav");
	SOUND("Tamashiinokaihou")->Load("../data/Sound/BGM/Tamashiinokaihou.wav");

	/*
		SE
	*/
	SOUND("aura1")->Load("../data/Sound/SE/aura1.wav");
	SOUND("beamgun3")->Load("../data/Sound/SE/beamgun3.wav");
	SOUND("beam-gun-charge1")->Load("../data/Sound/SE/beam-gun-charge1.wav");
	SOUND("bell01")->Load("../data/Sound/SE/bell01.wav");
	SOUND("cursor3")->Load("../data/Sound/SE/cursor3.wav");
	SOUND("dash1")->Load("../data/Sound/SE/dash1.wav");
	SOUND("dash2")->Load("../data/Sound/SE/dash2.wav");
	SOUND("dash3")->Load("../data/Sound/SE/dash3.wav");
	SOUND("decision18")->Load("../data/Sound/SE/decision18.wav");
	SOUND("highspeed-movement1")->Load("../data/Sound/SE/highspeed-movement1.wav");
	SOUND("incorrect2")->Load("../data/Sound/SE/incorrect2.wav");
	SOUND("landing")->Load("../data/Sound/SE/landing.wav");
	SOUND("magic-charge1")->Load("../data/Sound/SE/magic-charge1.wav");
	SOUND("magic-flame2")->Load("../data/Sound/SE/magic-flame2.wav");
	SOUND("magic-status-cure1")->Load("../data/Sound/SE/magic-status-cure1.wav");
	SOUND("nyu2")->Load("../data/Sound/SE/nyu2.wav");
	SOUND("punch-middle2")->Load("../data/Sound/SE/punch-middle2.wav");
	SOUND("punch-swing1")->Load("../data/Sound/SE/punch-swing1.wav");
	SOUND("se_011")->Load("../data/Sound/SE/se_011.wav");
	SOUND("se_027")->Load("../data/Sound/SE/se_027.wav");
	SOUND("se_030")->Load("../data/Sound/SE/se_030.wav");
	SOUND("se_033")->Load("../data/Sound/SE/se_033.wav");



}

void Sound::Update()
{
}
