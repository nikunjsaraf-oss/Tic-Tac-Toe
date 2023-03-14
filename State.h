#pragma once

namespace Nikunj
{
	class State
	{
	public:
		virtual void Init() = 0;

		virtual void HandleInput() = 0;
		virtual void Update() = 0;
		virtual void Draw(float delta) = 0;
		virtual void Pause() = 0;
		virtual void Resume() = 0;
	};
}