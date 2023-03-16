#include<iostream>
#include<sstream>

#include "Definitions.h" 
#include "GameState.h"
#include "PauseState.h"


namespace Nikunj
{
	GameState::GameState(GameDataRef data) : _data(data)
	{
	}

	void GameState::Init()
	{
		gameState = STATE_PLAYING;
		turn = PLAYER_PIECE;

		this->_data->assetManager.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		this->_data->assetManager.LoadTexture("Pause Button", PAUSE_BUTTON);
		this->_background.setTexture(this->_data->assetManager.GetTexture("Game Background"));
		_pauseButton.setTexture(this->_data->assetManager.GetTexture("Pause Button"));

		_pauseButton.setPosition(this->_data->renderWindow.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);

	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->renderWindow.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->renderWindow.close();
			}
			if (this->_data->inputManager.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->renderWindow))
			{
				this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
			}
		}
	}

	void GameState::Update(float dt)
	{
	}

	void GameState::Draw(float dt)
	{
		this->_data->renderWindow.clear();
		
		this->_data->renderWindow.draw(this->_background);
		this->_data->renderWindow.draw(this->_pauseButton)
;
		this->_data->renderWindow.display();
	}
}
