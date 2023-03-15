#include<sstream>
#include<iostream>

#include "MainMenuState.h"
#include "Definitions.h"

namespace Nikunj
{
	MainMenuState::MainMenuState(GameDataRef data) :_data(data)
	{

	}

	void MainMenuState::Init()
	{
		this->_data->assetManager.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assetManager.LoadTexture("Title", MAIN_MENU_TITLE_FILEPATH);
		this->_data->assetManager.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		this->_data->assetManager.LoadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);

		this->_background.setTexture(this->_data->assetManager.GetTexture("Background"));
		this->_title.setTexture(this->_data->assetManager.GetTexture("Title"));
		this->_playButton.setTexture(this->_data->assetManager.GetTexture("Play Button"));
		this->_playButtonOuter.setTexture(this->_data->assetManager.GetTexture("Play Button Outer"));

		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height / 2));

		this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - (this->_playButtonOuter.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (this->_playButtonOuter.getGlobalBounds().height / 2));

		this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2),
			(this->_title.getGlobalBounds().height * 0.1f));
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;
		while (this->_data->renderWindow.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->renderWindow.close();
			}

			if (this->_data->inputManager.IsSpriteClicked(_playButton, sf::Mouse::Left, this->_data->renderWindow))
			{
				std::cout << "Go to Game screen"<<std::endl;
			}
		}
	}

	void MainMenuState::Update(float dt)
	{

	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->renderWindow.clear();
		
		this->_data->renderWindow.draw(_background);
		this->_data->renderWindow.draw(_title);
		this->_data->renderWindow.draw(_playButtonOuter);
		this->_data->renderWindow.draw(_playButton);

		this->_data->renderWindow.display();
	}

}
