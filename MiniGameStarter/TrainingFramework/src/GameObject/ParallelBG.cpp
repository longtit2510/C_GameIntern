#include "ParallelBG.h"
#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Texture.h"
#include "Application.h"

ParallelBG::ParallelBG() : m_speed(0.0f)
{}
ParallelBG::ParallelBG(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, int speed) : BaseObject(0,model,shader,texture), m_speed(speed) {
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	m_listbackground1.push_back(m_background);
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth + Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	m_listbackground1.push_back(m_background);
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth + Globals::screenWidth / 2 + Globals::screenWidth, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	m_listbackground1.push_back(m_background);
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth + Globals::screenWidth / 2 + 2 * Globals::screenWidth , Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	m_listbackground1.push_back(m_background);
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth + +Globals::screenWidth / 2 + 3 * Globals::screenWidth, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	m_listbackground1.push_back(m_background);
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth + +Globals::screenWidth / 2 + 4 *Globals::screenWidth , Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	m_listbackground1.push_back(m_background);
}
void ParallelBG::Init()
{
	SetCamera(Application::GetInstance()->GetCamera());
	CalculateWorldMatrix();
}

void ParallelBG::Draw()
{
	for (auto it : m_listbackground1) {
		it->Draw();
	}
}

void ParallelBG::Update(GLfloat deltatime)
{
	Vector2 deltaMove = Vector2(1, 0) * m_speed * deltatime;
	m_background->Set2DPosition(m_background->GetPosition().x + deltaMove.x, m_background->GetPosition().y + deltaMove.y);
	if (m_background->GetPosition().x < -Globals::screenWidth / 2) {
		m_background->Set2DPosition(Globals::screenWidth + Globals::screenWidth / 2, m_background->GetPosition().y);
	}
	m_background1->Set2DPosition(m_background1->GetPosition().x + deltaMove.x, m_background1->GetPosition().y + deltaMove.y);
	if (m_background1->GetPosition().x < -Globals::screenWidth / 2) {
		m_background1->Set2DPosition(Globals::screenWidth + Globals::screenWidth / 2, m_background1->GetPosition().y);
	}

}



