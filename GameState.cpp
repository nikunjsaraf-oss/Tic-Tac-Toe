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
		this->column = 0;
		this->row = 0;
	}

	void GameState::Init()
	{
		gameState = STATE_PLAYING;
		turn = PLAYER_PIECE;

		this->_data->assetManager.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		this->_data->assetManager.LoadTexture("Grid Sprite", GRID_SPRITE);
		this->_data->assetManager.LoadTexture("X Piece", X_PIECE_FILEPATH);
		this->_data->assetManager.LoadTexture("O Piece", O_PIECE_FILEPATH);

		this->_data->assetManager.LoadTexture("X Winning Piece", X_WINNING_PIECE_FILEPATH);
		this->_data->assetManager.LoadTexture("O Winning Piece", O_WINNING_PIECE_FILEPATH);

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
			else if (this->_data->inputManager.IsSpriteClicked(this->_gridSprite, sf::Mouse::Left, this->_data->renderWindow))
			{
				if (STATE_PLAYING == gameState)
				{
					this->CheckAndPlacePiece();
				}
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

	void GameState::CheckAndPlacePiece()
	{
		sf::Vector2i touchPoint = this->_data->inputManager.GetMousePosition(this->_data->renderWindow);
		sf::FloatRect gridSize = _gridSprite.getGlobalBounds();
		sf::Vector2f gapOutsideOfGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width) / 2, (SCREEN_HEIGHT - gridSize.height) / 2);

		sf::Vector2f gridLocalTouchPos = sf::Vector2f(touchPoint.x - gapOutsideOfGrid.x, touchPoint.y - gapOutsideOfGrid.y);

		sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.width / 3, gridSize.height / 3);

		// Check which this->column the user has clicked
		if (gridLocalTouchPos.x < gridSectionSize.x) // First this->column
		{
			this->column = 1;
		}
		else if (gridLocalTouchPos.x < gridSectionSize.x * 2) // Second this->column
		{
			this->column = 2;
		}
		else if (gridLocalTouchPos.x < gridSize.width) // Third this->column
		{
			this->column = 3;
		}

		// Check which this->row the user has clicked
		if (gridLocalTouchPos.y < gridSectionSize.y) // First this->row
		{
			this->row = 1;
		}
		else if (gridLocalTouchPos.y < gridSectionSize.y * 2) // Second this->row
		{
			this->row = 2;
		}
		else if (gridLocalTouchPos.y < gridSize.height) // Third this->row
		{
			this->row = 3;
		}


		if (gridArray[this->column - 1][this->row - 1] == EMPTY_PIECE)
		{
			gridArray[this->column - 1][this->row - 1] = turn;

			if (PLAYER_PIECE == turn)
			{
				_gridPieces[this->column - 1][this->row - 1].setTexture(this->_data->assetManager.GetTexture("X Piece"));
				this->CheckPlayerWon(turn);
				turn = AI_PIECE;
			}
			else if (AI_PIECE == turn)
			{
				_gridPieces[this->column - 1][this->row - 1].setTexture(this->_data->assetManager.GetTexture("O Piece"));
				this->CheckPlayerWon(turn);
				turn = PLAYER_PIECE;
			}

			_gridPieces[this->column - 1][this->row - 1].setColor(sf::Color(255, 255, 255, 255));
		}
	}

	void GameState::CheckPlayerWon(int turn)
	{
		CheckThreePiecesForMatch(0, 0, 1, 0, 2, 0, turn);
		CheckThreePiecesForMatch(0, 1, 1, 1, 2, 1, turn);
		CheckThreePiecesForMatch(0, 2, 1, 2, 2, 2, turn);
		CheckThreePiecesForMatch(0, 0, 0, 1, 0, 2, turn);
		CheckThreePiecesForMatch(1, 0, 1, 1, 1, 2, turn);
		CheckThreePiecesForMatch(2, 0, 2, 1, 2, 2, turn);
		CheckThreePiecesForMatch(0, 0, 1, 1, 2, 2, turn);
		CheckThreePiecesForMatch(0, 2, 1, 1, 2, 0, turn);

		int emptyNum = 9;

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (EMPTY_PIECE != this->gridArray[x][y])
				{
					emptyNum--;
				}
			}
		}

		if (emptyNum == 0 && (STATE_WON != gameState) && (STATE_LOSE != gameState))
		{
			gameState = STATE_DRAW;
		}

		if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
		{
			std::cout << "Game Over" << std::endl;
		}

		std::cout << gameState << std::endl;
	}

	void GameState::CheckThreePiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck)
	{
		if (pieceToCheck == this->gridArray[x1][y1] &&
			pieceToCheck == this->gridArray[x2][y2] &&
			pieceToCheck == this->gridArray[x3][y3])
		{
			std::string winningPieceStr;

			winningPieceStr = O_PIECE == pieceToCheck ? "O Winning Piece" : "X Winning Piece";

			_gridPieces[x1][y1].setTexture(this->_data->assetManager.GetTexture(winningPieceStr));
			_gridPieces[x2][y2].setTexture(this->_data->assetManager.GetTexture(winningPieceStr));
			_gridPieces[x3][y3].setTexture(this->_data->assetManager.GetTexture(winningPieceStr));

			gameState = PLAYER_PIECE == pieceToCheck ? STATE_WON : STATE_LOSE;
		}
	}
}
