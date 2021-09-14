#pragma once
#include "GameStateBase.h"
#include "ParallelBG.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class AnimationSprite;

enum class ANIMATION_STATE {
	IDLE = 0,
	MOVING_LEFT,
	MOVING_RIGHT,
	ATTACK,
	JUMP,
	ROLL
};

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;


	void	updateAnimation(float deltaTime);
	void	updateHP(int& HP);

	bool	checkCollisionCombat(std::shared_ptr<AnimationSprite> obj1, std::shared_ptr<AnimationSprite> obj2, GLfloat push,GLfloat hs1, GLfloat hs2);
	bool	checkCollisionPlatform(std::shared_ptr<AnimationSprite> obj1, std::shared_ptr<Sprite2D> obj2, GLfloat push, GLfloat hs1, GLfloat hs2, Vector3 direction);
	bool	checkCollisionPlatformE(std::shared_ptr<AnimationSprite> obj1, std::shared_ptr<Sprite2D> obj2, GLfloat push, GLfloat hs1, GLfloat hs2, Vector3 direction);

private:
	std::shared_ptr<ParallelBG>	m_background;
	std::shared_ptr<Text>		m_score;

	std::list<std::shared_ptr<GameButton>>	m_listButton;

	std::shared_ptr<AnimationSprite> m_mainchar;
	std::shared_ptr<AnimationSprite> m_enemyS;
	std::shared_ptr<AnimationSprite> m_enemyM;
	std::shared_ptr<AnimationSprite> m_boss;

	std::vector<std::shared_ptr<AnimationSprite>> m_listenemy;
	std::vector<std::shared_ptr<AnimationSprite>> m_listenemyM;

	std::shared_ptr<Sprite2D> m_platform;
	std::vector<std::shared_ptr<Sprite2D>> m_listplatform;

	std::shared_ptr<Camera> m_camera;

	int mapsizeX = 10;
	int mapsizeY = 10;
	int mainchar_hp = 20;
	int keyPressed = 0;
	int type = 0;

	bool moving = false;
	bool movingRight = true;

	bool jumping = false;
	bool falling = false;
	bool canJump = true;

	Vector3 direction;
	Vector3 nondirection;
	Vector3 velo;

	GLfloat jumpHeight = 150.0f;

	ANIMATION_STATE aniState;

	//tilesheet
	int lvl[100][10]= {
		{0,0,0,0,0,1,5,5,5,5},
		{0,0,0,0,0,1,5,5,5,5},
		{0,0,0,0,0,1,5,5,5,5},
		{0,0,0,0,0,3,4,5,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,8,0,1,5,5},
		{0,0,0,0,0,9,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,1,5,5,5},
		{0,0,0,0,0,1,5,5,5,5},
		{0,0,0,0,1,5,5,5,5,5},
		{0,0,0,0,1,5,5,5,5,5},
		{0,0,0,0,1,5,5,5,5,5},
		{0,0,0,0,1,5,5,5,5,5},
		{0,9,0,0,1,5,5,5,5,5},
		{0,0,0,0,1,5,5,5,5,5},
		{0,0,0,0,1,5,5,5,5,5},
		{0,0,0,0,0,1,5,5,5,5},
		{0,0,0,0,0,0,1,5,5,5},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,5,5,5,5},
		{0,0,0,0,1,5,5,5,5,5},
		{0,0,2,0,0,0,0,0,0,0},
		{0,0,2,8,1,5,5,5,5,5},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,5,5,5,5,5},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,9,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,1,0,5},
		{0,0,0,0,0,0,8,1,0,5},
		{0,0,0,0,0,0,0,1,0,5},
		{0,0,0,0,0,0,9,1,0,5},
		{0,0,0,0,0,0,0,1,0,5},
		{0,0,0,0,0,0,8,1,0,5},
		{0,0,0,0,0,0,0,1,0,5},
		{0,0,0,0,0,0,0,0,0,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,9,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,0,1,5},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,1,5,5,5},
		{0,0,0,0,0,1,5,5,5,5},
		{0,0,0,9,0,1,5,5,5,5},
		{0,0,0,0,0,1,5,5,5,5},
		{0,0,0,0,0,0,1,5,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{5,5,5,5,5,5,0,1,5,5},
		{5,5,5,5,5,5,0,1,5,5},
		{5,5,5,5,5,5,0,1,5,5},
		{5,5,5,5,5,5,0,1,5,5},
		{5,5,5,5,5,5,0,1,5,5},
		{5,5,5,5,5,5,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,10,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{0,0,0,0,0,0,0,1,5,5},
		{5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5}
	};
};

