#define NOMINMAX

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
#include "Application.h"

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
	m_background = std::make_shared<ParallelBG>(model, shader, texture,100.0f);
	
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
	texture = ResourceManagers::GetInstance()->GetTexture("mcTextures/knight_downatk.tga");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 7, 0.1f);
	m_mainchar->Set2DPosition(200, (float)Globals::screenHeight / 2);
	m_mainchar->SetSize(200, 200);
	this->aniState = ANIMATION_STATE::IDLE;

	//camera
	m_camera = m_mainchar->GetCamera();
	
	//map initialization
	for (int row = 0; row < 100; row++) {
		for (int column = 0; column < 10; column++) {
			type = lvl[row][column];
			//type 0: nothing
			if (type == 0) {
				std::cout << "NO TEXTURES";
			}
			//type 1-5: platform
			if (type == 1) {
				shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
				texture = ResourceManagers::GetInstance()->GetTexture("tileset/grass03.tga");
				m_platform = std::make_shared<Sprite2D>(model, shader, texture);
				m_platform->Set2DPosition(row * 80, column * 80);
				m_platform->SetSize(80, 80);
				m_listplatform.push_back(m_platform);
			}
			 if (type == 2) {
				shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
				texture = ResourceManagers::GetInstance()->GetTexture("tileset/grass01.tga");
				m_platform = std::make_shared<Sprite2D>(model, shader, texture);
				m_platform->Set2DPosition(row * 80, column * 80);
				m_platform->SetSize(80, 80);
				m_listplatform.push_back(m_platform);
			}
			 if (type == 3) {
				 shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
				 texture = ResourceManagers::GetInstance()->GetTexture("tileset/grass20.tga");
				 m_platform = std::make_shared<Sprite2D>(model, shader, texture);
				 m_platform->Set2DPosition(row * 80, column * 80);
				 m_platform->SetSize(80, 80);
				 m_listplatform.push_back(m_platform);
			 }
			 if (type == 4) {
				 shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
				 texture = ResourceManagers::GetInstance()->GetTexture("tileset/grass24.tga");
				 m_platform = std::make_shared<Sprite2D>(model, shader, texture);
				 m_platform->Set2DPosition(row * 80, column * 80);
				 m_platform->SetSize(80, 80);
				 m_listplatform.push_back(m_platform);
			 }
			 if (type == 5) {
				 shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
				 texture = ResourceManagers::GetInstance()->GetTexture("tileset/grass27.tga");
				 m_platform = std::make_shared<Sprite2D>(model, shader, texture);
				 m_platform->Set2DPosition(row * 80, column * 80);
				 m_platform->SetSize(80, 80);
				 m_listplatform.push_back(m_platform);
			 }
			 //type 6-7: unknown
			 if (type == 6) {
			 }
			 if (type == 7) {
			 }
			 //type 8-10: enemy
			 if (type == 8) {
				 //stand enemy
				 shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
				 texture = ResourceManagers::GetInstance()->GetTexture("enemyTextures/skeleton_atk.tga");
				 m_enemyS = std::make_shared<AnimationSprite>(model, shader, texture, 18, 0.05f);
				 m_enemyS->Set2DPosition(row * 80, column * 80);
				 m_enemyS->SetSize(80, 80);
				 m_listenemy.push_back(m_enemyS);
			 }
			 if (type == 9) {
				 //moving enemy
				 shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
				 texture = ResourceManagers::GetInstance()->GetTexture("enemyTextures/skeleton_walk.tga");
				 m_enemyM = std::make_shared<AnimationSprite>(model, shader, texture, 13, 0.1f);
				 m_enemyM->Set2DPosition(row * 80, column * 80);
				 m_enemyM->SetSize(80, 80);
				 m_listenemyM.push_back(m_enemyM);
			 }
			 if (type == 10) {
				 //boss
				 shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
				 texture = ResourceManagers::GetInstance()->GetTexture("enemyTextures/king_fullcombo.tga");
				 m_boss = std::make_shared<AnimationSprite>(model, shader, texture, 58, 0.01f);
				 m_boss->Set2DPosition(row * 80, column * 80);
				 m_boss->SetSize(200, 400);
			 }
		}
	}

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
	//gravity update
	m_mainchar->updatePhysics(100.0f, deltaTime);
	m_boss->updatePhysics(100.0f, deltaTime);

	//handle key events
	if (keyPressed & KEY_MOVE_LEFT) {
		m_mainchar->move(-1.0f, 0.0f, deltaTime);
		this->aniState = ANIMATION_STATE::MOVING_LEFT;
		movingRight = false;
		m_camera->MoveLeft(deltaTime * 10.0f);
	}
	else if (keyPressed & KEY_MOVE_RIGHT) {
		m_mainchar->move(1.0f, 0.0f, deltaTime);
		this->aniState = ANIMATION_STATE::MOVING_RIGHT;
		movingRight = true;
		m_camera->MoveLeft(-deltaTime * 10.0f);
	}
	else if (keyPressed & KEY_JUMP && canJump == true) {
		canJump = false;
		m_mainchar->jump(deltaTime, 10.0f, jumpHeight);
		this->aniState = ANIMATION_STATE::JUMP;
	}
	else if (keyPressed & KEY_ATTACK) {
		this->aniState = ANIMATION_STATE::ATTACK;
	}
	else if (keyPressed & KEY_ROLL) {
		this->aniState = ANIMATION_STATE::ROLL;
	}
	else {
		this->aniState = ANIMATION_STATE::IDLE;
	}
	
	/*switch mainchar animation
	this->updateAnimation(deltaTime);*/

	//update Health Points

	//list update
	m_mainchar->Update(deltaTime);
	m_boss->Update(deltaTime);

	for (auto it : m_listenemy)
	{
			it->updatePhysics(100.0f, deltaTime);
			it->Update(deltaTime);
			for (auto pl : m_listplatform) {
				checkCollisionPlatformE(it, pl, 0.0f,2.0f,2.0f, direction);
			}
		
	}
	for (auto it : m_listenemyM)
	{
		it->updatePhysics(100.0f, deltaTime);
		it->Update(deltaTime);
		it->enemyPatrol(deltaTime);
		for (auto pl : m_listplatform) {
			checkCollisionPlatformE(it, pl, 0.0f, 2.0f, 2.0f, direction);
		}

	}

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listplatform) {
		checkCollisionPlatform(m_mainchar, it, 0.0f,5.0f,2.0f,direction);
		checkCollisionPlatformE(m_boss, it, 0.0f, 10.0f, 2.0f, direction);
	}
	
}


bool GSPlay::checkCollisionCombat(std::shared_ptr<AnimationSprite> obj1, std::shared_ptr<AnimationSprite> obj2, GLfloat push,GLfloat hs1,GLfloat hs2) {

	Vector3 Pos1 = obj1->GetPosition();
	Vector3 HalfSize1 = obj1->GetScale().operator/(hs1);
	Vector3 Pos2 = obj2->GetPosition();
	Vector3 HalfSize2 = obj2->GetScale().operator/(hs2);

	GLfloat dX = Pos1.x - Pos2.x;
	GLfloat dY = Pos1.y - Pos2.y;
	GLfloat iX = abs(dX) - (HalfSize1.x + HalfSize2.x);
	GLfloat iY = abs(dY) - (HalfSize1.y + HalfSize2.y);

	if (iX < 0.0f && iY < 0.0f) {
		return true; 
		
	}
	return false;
}
bool GSPlay::checkCollisionPlatform(std::shared_ptr<AnimationSprite> obj1, std::shared_ptr<Sprite2D> obj2, GLfloat push, GLfloat hs1, GLfloat hs2, Vector3 direction) {

	Vector3 Pos1 = obj1->GetPosition();
	Vector3 HalfSize1 = obj1->GetScale().operator/(hs1);
	Vector3 Pos2 = obj2->GetPosition();
	Vector3 HalfSize2 = obj2->GetScale().operator/(hs2);

	GLfloat dX = Pos1.x - Pos2.x;
	GLfloat dY = Pos1.y - Pos2.y;
	GLfloat iX = abs(dX) - (HalfSize1.x + HalfSize2.x);
	GLfloat iY = abs(dY) - (HalfSize1.y + HalfSize2.y);

	if (iX < 0.0f && iY < 0.0f) {
		push = std::min(std::max(0.0f, push), 1.0f);
		if (abs(iX) < abs(iY)) {
			if (dX > 0.0f) {
				obj1->Set2DPosition(Pos1.x + (-iX * (1.0f - push)), Pos1.y);
				obj2->Set2DPosition(Pos2.x + (iX * push), Pos2.y);
				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else {
				obj1->Set2DPosition(Pos1.x + (iX * (1.0f - push)), Pos1.y);
				obj2->Set2DPosition(Pos2.x + (-iX * push), Pos2.y);
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else {
			if (dY > 0.0f) {
				obj1->Set2DPosition(Pos1.x, Pos1.y + (-iY * (1.0f - push)));
				obj2->Set2DPosition(Pos2.x, Pos2.y + (iY * push));
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else {
				obj1->Set2DPosition(Pos1.x, Pos1.y + (iY * (1.0f - push)));
				obj2->Set2DPosition(Pos2.x, Pos2.y + (-iY * push));
				direction.x = 0.0f;
				direction.y = -1.0f;
				canJump = true;
			}
		}
		return true;
	}
	return false;
}
bool GSPlay::checkCollisionPlatformE(std::shared_ptr<AnimationSprite> obj1, std::shared_ptr<Sprite2D> obj2, GLfloat push, GLfloat hs1, GLfloat hs2, Vector3 direction) {

	Vector3 Pos1 = obj1->GetPosition();
	Vector3 HalfSize1 = obj1->GetScale().operator/(hs1);
	Vector3 Pos2 = obj2->GetPosition();
	Vector3 HalfSize2 = obj2->GetScale().operator/(hs2);

	GLfloat dX = Pos1.x - Pos2.x;
	GLfloat dY = Pos1.y - Pos2.y;
	GLfloat iX = abs(dX) - (HalfSize1.x + HalfSize2.x);
	GLfloat iY = abs(dY) - (HalfSize1.y + HalfSize2.y);

	if (iX < 0.0f && iY < 0.0f) {
		push = std::min(std::max(0.0f, push), 1.0f);
		if (abs(iX) < abs(iY)) {
			if (dX > 0.0f) {
				obj1->Set2DPosition(Pos1.x + (-iX * (1.0f - push)), Pos1.y);
				obj2->Set2DPosition(Pos2.x + (iX * push), Pos2.y);
				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else {
				obj1->Set2DPosition(Pos1.x + (iX * (1.0f - push)), Pos1.y);
				obj2->Set2DPosition(Pos2.x + (-iX * push), Pos2.y);
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else {
			if (dY > 0.0f) {
				obj1->Set2DPosition(Pos1.x, Pos1.y + (-iY * (1.0f - push)));
				obj2->Set2DPosition(Pos2.x, Pos2.y + (iY * push));
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else {
				obj1->Set2DPosition(Pos1.x, Pos1.y + (iY * (1.0f - push)));
				obj2->Set2DPosition(Pos2.x, Pos2.y + (-iY * push));
				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		return true;
	}
	return false;
}

void GSPlay::updateHP(int &HP) {

}

void GSPlay::updateAnimation(GLfloat deltaTime) {
	if (this->aniState == ANIMATION_STATE::IDLE) {
		m_mainchar->setCurrentFrame(0);
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("mcTextures/Knight_idle.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 15, 0.2f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(150, 150);
		canJump = true;
	}
	else if (this->aniState == ANIMATION_STATE::MOVING_LEFT) {
		m_mainchar->setCurrentFrame(0);
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("MC_idle_left.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.1f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(150, 150);
	}
	else if (this->aniState == ANIMATION_STATE::MOVING_RIGHT) {
		m_mainchar->setCurrentFrame(0);
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("mcTextures/knight_move_right.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 8, 0.1f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(150, 150);
	}
	else if (this->aniState == ANIMATION_STATE::ATTACK) {
		m_mainchar->setCurrentFrame(0);
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("mcTextures/knight_downatk.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.1f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(200, 180);
	}
	else if (this->aniState == ANIMATION_STATE::JUMP) {
		m_mainchar->setCurrentFrame(0);
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("MC_jump.tga");
		auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
		Vector3 vec = m_mainchar->GetPosition();
		m_mainchar = std::make_shared<AnimationSprite>(model, shader, texture, 5, 0.1f);
		m_mainchar->Set2DPosition(vec.x, vec.y);
		m_mainchar->SetSize(150, 150);
	}
	else if (this->aniState == ANIMATION_STATE::ROLL) {
		m_mainchar->setCurrentFrame(0);
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
	m_mainchar->Draw();
	m_boss->Draw();

	for (auto it : m_listenemy) {
		it->Draw();
	}
	for (auto it : m_listenemyM) {
		it->Draw();
	}

	for (auto it : m_listplatform) {
		it->Draw();
	}

	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_score->Draw();
}