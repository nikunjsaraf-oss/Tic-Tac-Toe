#pragma once

#include<SFML/Graphics.hpp>

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
		void CheckThreePiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);

		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _pauseButton;
		sf::Sprite _gridSprite;
		sf::Sprite _gridPieces[3][3];

		int gridArray[3][3];

		int turn;
		int gameState;
		int column, row;
	};
}

