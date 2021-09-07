#pragma once
#include "GameStateBase.h"

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
	void	updateAnimation();
	void	updateCollision(int& HP);

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Text>		m_score;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<AnimationSprite> m_mainchar;
	std::shared_ptr<AnimationSprite> m_enemy1;


	int mainchar_hp = 20;
	int keyPressed = 0;
	bool moving = false;
	bool movingRight = true;
	bool canJump = true;

	ANIMATION_STATE aniState;
};

