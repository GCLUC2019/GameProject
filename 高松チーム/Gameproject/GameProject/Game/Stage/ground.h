#pragma once
#include "../GameProject/Base/Task.h"

class Stage01 : public Task {
private:
public:
	Stage01();

};

class Ground : public Task {
private:
    CImage m_img;
    CVector2D m_pos;
    float m_depth = -98;
public:
    Ground();
    void Update();
    void Draw();

};

class Bamboo : public Task {
private:
    CImage m_img;
    CVector2D m_pos;
    float m_depth = -99;
public:
    Bamboo();
    void Update();
    void Draw();
};

class SkyBlue : public Task {
private:
    CImage m_img;
    CVector2D m_pos;
    float m_depth = -100;
public:
    SkyBlue();
    void Update();
    void Draw();
};

class SkyRed : public Task {
private:
    CImage m_img;
    CVector2D m_pos;
    float m_depth = -100;
public:
    SkyRed();
    void Update();
    void Draw();
};