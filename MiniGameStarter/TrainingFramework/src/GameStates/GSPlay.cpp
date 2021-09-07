#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "AnimationSprite.h"
#include <string>

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}



void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu1.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	//main character
	texture = ResourceManagers::GetInstance()->GetTexture("MC_attack_large.tga");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.2f);
	m_mainchar->Set2DPosition(200, (float)Globals::screenHeight / 2);
	m_mainchar->SetSize(150, 150);

	//enemy
	texture = ResourceManagers::GetInstance()->GetTexture("enemyTextures/knight_attack1.tga");
	m_enemy1 = std::make_shared<AnimationSprite>(model, shader, texture, 8, 0.2f);
	m_enemy1->Set2DPosition(1000, (float)Globals::screenHeight - 240);
	m_enemy1->SetSize(250, 250);

	// score
	std::string s = std::to_string(mainchar_hp);
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Caesar.otf");
	m_score = std::make_shared<Text>(shader, font, s+"/20HP", TextColor::PURPLE, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed == true) {
		switch (key) {
		case 'A':
			keyPressed |= KEY_MOVE_LEFT;
		case 'D':
			keyPressed |= KEY_MOVE_RIGHT;
		case 'J':
			keyPressed |= KEY_ATTACK;
		case 'K':
			keyPressed |= KEY_JUMP;
		case 'L':
			keyPressed |= KEY_ROLL;
		default:
			break;
		}
	}
	else {
		switch (key) {
		case 'A':
			keyPressed ^= KEY_MOVE_LEFT;
		case 'D':
			keyPressed ^= KEY_MOVE_RIGHT;
		case 'J':
			keyPressed ^= KEY_ATTACK;
		case 'K':
			keyPressed ^= KEY_JUMP;
		case 'L':
			keyPressed ^= KEY_ROLL;
		default:
			break;
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{

}

void GSPlay::Update(float deltaTime)
{
	m_mainchar->updatePhysics(5.0f);
	m_mainchar->Update(deltaTime);

	this->aniState = ANIMATION_STATE::IDLE;
	//handle key events
	if (keyPressed & KEY_MOVE_LEFT) {
		m_mainchar->move(-1.0f,0.0f);
		this->aniState = ANIMATION_STATE::MOVING_LEFT;
		movingRight = false;
	}
	else if (keyPressed & KEY_MOVE_RIGHT) {
		m_mainchar->move(1.0f, 0.0f);
		this->aniState = ANIMATION_STATE::MOVING_RIGHT;
		movingRight = true;
	}

	else if (keyPressed & KEY_ATTACK) {
		this->aniState = ANIMATION_STATE::ATTACK;
	}
	else if (keyPressed & KEY_JUMP) {
		this->aniState = ANIMATION_STATE::JUMP;
		if (movingRight && canJump) {
			m_mainchar->jump(0.5f, -1.0f, deltaTime,100.0f,500.0f);
		}
		else {
			m_mainchar->jump(-0.5f, -1.0f, deltaTime, 100.0f, 500.0f);
		}
	}
	else if (keyPressed & KEY_ROLL) {
		this->aniState = ANIMATION_STATE::ROLL;
		if (movingRight) {
			m_mainchar->move(3.0f, 0.0f);
		}
		else {
			m_mainchar->move(-3.0f, 0.0f);
		}
	}

	//switch mainchar animation
	this->updateAnimation();

	//update Health Points
	this->updateCollision(mainchar_hp);
	std::string s = std::to_string(mainchar_hp);
	auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Caesar.otf");
	m_score = std::make_shared<Text>(shader, font, s + "/20HP", TextColor::PURPLE, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	m_mainchar->Update(deltaTime);
	m_enemy1->Update(deltaTime);

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}


void GSPlay::updateCollision(int &HP) {
	if (m_mainchar->GetPosition().x == m_enemy1->GetPosition().x) {
		HP--;
		std::cout << "HIT" << std::endl;
	}
}

void GSPlay::updateAnimation() {
	if (this->aniState == ANIMATION_STATE::IDLE) {
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("MC_idle.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.2f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(150, 150);
		canJump = true;
	}
	else if (this->aniState == ANIMATION_STATE::MOVING_LEFT) {
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("MC_idle_left.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.1f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(150, 150);
	}
	else if (this->aniState == ANIMATION_STATE::MOVING_RIGHT) {
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("MC_move.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.1f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(150, 150);
	}
	else if (this->aniState == ANIMATION_STATE::ATTACK) {
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("MC_attack_large.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.1f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(200, 180);
	}
	else if (this->aniState == ANIMATION_STATE::JUMP) {
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("MC_jump.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 5, 0.1f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(150, 150);
	}
	else if (this->aniState == ANIMATION_STATE::ROLL) {
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("MC_roll.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.1f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(150, 150);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_score->Draw();
	m_enemy1->Draw();
	m_mainchar->Draw();

	for (auto it : m_listButton)
	{
		it->Draw();
	}
}