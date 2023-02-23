#include "syApplication.h"
#include "syTime.h"
#include "syInput.h"

namespace sy
{
	void Application::Initialize(WindowImplData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(mWindowData.hWnd);

		Time::Initialize();
		Input::Initialize();
	}
	void Application::Run()
	{
		Update();
		Render(mWindowData.hdc);
	}
	void Application::Update()
	{
		Time::Update();
		Input::Update();
	}
	void Application::Render(HDC hdc)
	{
		if (Input::GetKeyState(eKeyCode::LEFT) == eKeyState::PRESSED)
		{
			x -= (200.0f * Time::DeltaTime());
		}

		if (Input::GetKeyState(eKeyCode::RIGHT) == eKeyState::PRESSED)
		{
			x += 200.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::UP) == eKeyState::PRESSED)
		{
			y -= 200.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::DOWN) == eKeyState::PRESSED)
		{
			y += 200.0f * Time::DeltaTime();
		}
		Rectangle(hdc, x+100, y+100, x+200, y+200);
		Time::Render(hdc);
	}
	void Application::Release()
	{

	}
}