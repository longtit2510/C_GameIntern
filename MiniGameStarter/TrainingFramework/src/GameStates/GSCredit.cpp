#include "GSCredit.h"
#include "GameButton.h"

GSCredit::GSCredit()
{
}


GSCredit::~GSCredit()
{
}



void GSCredit::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_credit.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);
	// credit text
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Caesar.otf");
	m_textGameName = std::make_shared<Text>(shader, font, "HIGH MEDIEVAL", Vector4(0.0f, 1.0f, 0.0f, 1.0f), 2.0f);
	m_textGameName->Set2DPosition(Vector2(80, 250));
	m_textCredit = std::make_shared<Text>(shader,font,"aurthor: TRAN NGOC LONG",Vector4(0.0f, 1.0f, 0.0f, 1.0f), 1.0f);
	m_textCredit->Set2DPosition(Vector2(100, 280));
	m_textDescription = std::make_shared<Text>(shader, font, "a 2D high-fantasy-insprired platform game", Vector4(0.0f, 1.0f, 0.0f, 1.0f), 1.0f);
	m_textDescription->Set2DPosition(Vector2(10, 310));
	
}

void GSCredit::Exit()
{
}


void GSCredit::Pause()
{
}

void GSCredit::Resume()
{
}


void GSCredit::HandleEvents()
{
}

void GSCredit::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSCredit::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSCredit::HandleMouseMoveEvents(int x, int y)
{
}

void GSCredit::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSCredit::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_textGameName->Draw();
	m_textCredit->Draw();
	m_textDescription->Draw();
}