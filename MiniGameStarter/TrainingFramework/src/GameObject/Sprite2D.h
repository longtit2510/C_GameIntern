#pragma once
#include "BaseObject.h"

class Sprite2D : public BaseObject
{
protected:
	GLint		m_iWidth;
	GLint		m_iHeight;
	GLuint		m_vboId;

	float m_movementspeed = 3.0f;
	Vector3 velo;

public:
	Sprite2D() : BaseObject(), m_iWidth(0), m_iHeight(0), m_vboId(0) {}
	Sprite2D(GLint id, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	Sprite2D(GLint id, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, Vector4 color);
	Sprite2D(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Sprite2D();

	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;

	void		Set2DPosition(GLfloat x, GLfloat y);
	void		Set2DPosition1(Vector2 position);
	void		SetSize(GLint width, GLint height);

};

