#pragma once
#include "syge.h"
namespace sy
{
	class Application
	{
	public:
		void Initialize(WindowImplData data);
		void Run();
		void Update();
		void Render(HDC hdc);
		void Release();

		WindowImplData GetWindowImplData() { return mWindowData; }
	private:
		WindowImplData mWindowData;

		float x = 0;
		float y = 0;
	};
}