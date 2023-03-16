#include<iostream>
#include<sstream>

#include "Definitions.h" 
#include "GameState.h"
#include "PauseState.h"
#include "GameOverState.h"


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

		this->_data->assetManager.LoadTexture("Grid Sprite", GRID_SPRITE);
		this->_data->assetManager.LoadTexture("X Piece", X_PIECE_FILEPATH);
		this->_data->assetManager.LoadTexture("O Piece", O_PIECE_FILEPATH);

		this->_data->assetManager.LoadTexture("Pause Button", PAUSE_BUTTON);

		this->_background.setTexture(this->_data->assetManager.GetTexture("Game Background"));
		this->_pauseButton.setTexture(this->_data->assetManager.GetTexture("Pause Button"));

		this->_gridSprite.setTexture(this->_data->assetManager.GetTexture("Grid Sprite"));


		this->_pauseButton.setPosition(this->_data->renderWindow.getSize().x - _pauseButton.getLocalBounds().width,
			_pauseButton.getPosition().y);

		this->_gridSprite.setPosition((SCREEN_WIDTH / 2.0f) - (this->_gridSprite.getGlobalBounds().width / 2.0f),
			(SCREEN_HEIGHT / 2.0f) - (this->_gridSprite.getGlobalBounds().height / 2.0f));

		InitGridPieces();

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				gridArray[x][y] = EMPTY_PIECE;
			}
		}
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
		this->_data->renderWindow.draw(this->_pauseButton);
		this->_data->renderWindow.draw(this->_gridSprite);

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++) 
			{
				this->_data->renderWindow.draw(this->_gridPieces[x][y]);
			}
		}

		this->_data->renderWindow.display();
	}

	void GameState::InitGridPieces()
	{
		sf::Vector2u tempSpriteSize = this->_data->assetManager.GetTexture("X Piece").getSize();

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				_gridPieces[x][y].setTexture(this->_data->assetManager.GetTexture("X Piece"));
				_gridPieces[x][y].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x * x) - 7,
					_gridSprite.getPosition().y + (tempSpriteSize.y * y) - 7);

				_gridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));
			}
		}
	}
}
