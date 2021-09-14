#pragma once
#include "Sprite2D.h"
#include "BaseObject.h"


class ParallelBG :
    public BaseObject
{
public:
    ParallelBG();
    ParallelBG(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, int speed);
    void		Init() override;
    void		Draw() override; 
    void		Update(GLfloat deltatime) override;


protected:
    std::shared_ptr<Sprite2D> m_background;
    std::shared_ptr<Sprite2D> m_background1;
    std::vector<std::shared_ptr<Sprite2D>> m_listbackground1;

    GLfloat m_speed;
};

