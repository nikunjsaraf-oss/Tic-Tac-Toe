#pragma once

#include<SFML/Graphics.hpp>

#include "AI.h"
#include"State.h"
#include"Game.h"

namespace Nikunj
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:

		void InitGridPieces();
		void CheckAndPlacePiece();
		void CheckPlayerWon(int turn);
		void Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);

		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _pauseButton;
		sf::Sprite _gridSprite;
		sf::Sprite _gridPieces[3][3];

		int _gridArray[3][3];

		int _turn;
		int _gameState;
		int column, row;

		AI* ai;

		sf::Clock _clock;
	};
}

