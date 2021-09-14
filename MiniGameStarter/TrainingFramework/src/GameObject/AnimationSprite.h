#pragma once
#include "Sprite2D.h"


class AnimationSprite :
    public Sprite2D
{
public:
    AnimationSprite();
    AnimationSprite(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, int numFrames, float frameTime);
    void		Init() override;
    void		Draw() override; 
    void		Update(GLfloat deltatime) override;

    void        UpdateFlip(GLfloat deltaTime);
    void        UpdateEnemy(GLfloat deltaTime);
    void        setCurrentFrame(int a) {
        this->m_currentFrame = a;
    };

    void        move(GLfloat vx, GLfloat vy,GLfloat deltaTime);
    void        updatePhysics(GLfloat gravity,GLfloat deltaTime);
    void        jump(GLfloat deltaTime,GLfloat gravity,GLfloat jumpHeight);

    void        enemyPatrol(GLfloat deltaTime);

protected:
    int m_numFrames;
    int m_currentFrame;
    float m_frameTime;
    float m_currentframeTime;

    float m_movementspeed = 100.0f;
    GLfloat s = 0.0f;

    Vector3 velo;
    Vector3 dire;
    Vector3 original;
};

