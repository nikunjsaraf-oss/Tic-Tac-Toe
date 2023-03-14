#pragma once

#include <memory>
#include<string.h>
#include<SFML/Graphics.hpp>

#include "InputManager.h"
#include "AssetManager.h"
#include "StateMachine.h"

namespace Nikunj
{
	
		struct GameData
		{
			StateMachine machine;
			sf::RenderWindow renderWindow;
			AssetManager assetManager;
			InputManager inputManager;
		};

		typedef std::shared_ptr<GameData> GameDataRef;

		class Game{
		public:
			Game(int width, int height, std::string title);

		private:
			const float frameRate = 1.0f / 60.0f;
			sf::Clock _clock;

			GameDataRef _data = std::make_shared<GameData>();
			void Run();
		};


}