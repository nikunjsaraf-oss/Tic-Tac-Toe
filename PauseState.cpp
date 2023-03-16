#include<sstream>
#include<iostream>

#include "PauseState.h"
#include "Definitions.h"
#include "MainMenuState.h"
#include "GameState.h"

namespace Nikunj
{
	PauseState::PauseState(GameDataRef data) :_data(data)
	{

	}

	void PauseState::Init()
	{
		this->_data->assetManager.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assetManager.LoadTexture("Resume Button", RESUME_BUTTON);
		this->_data->assetManager.LoadTexture("Home Button", HOME_BUTTON);

		this->_background.setTexture(this->_data->assetManager.GetTexture("Pause Background"));
		this->_resumeButton.setTexture(this->_data->assetManager.GetTexture("Resume Button"));
		this->_homeButton.setTexture(this->_data->assetManager.GetTexture("Home Button"));

		this->_resumeButton.setPosition((this->_data->renderWindow.getSize().x/2.0f) - (this->_resumeButton.getLocalBounds().width/2.0f), 
			(this->_data->renderWindow.getSize().y / 3.0f) - (this->_resumeButton.getLocalBounds().height / 2.0f));

		this->_homeButton.setPosition((this->_data->renderWindow.getSize().x / 2.0f) - (this->_homeButton.getLocalBounds().width / 2.0f),
			(this->_data->renderWindow.getSize().y / 3.0f * 2.0f) - (this->_homeButton.getLocalBounds().height / 2.0f));
	}

	void PauseState::HandleInput()
	{
		sf::Event event;
		while (this->_data->renderWindow.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->renderWindow.close();
			}

			if (this->_data->inputManager.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->renderWindow))
			{
				this->_data->machine.RemoveState();
			}

			if (this->_data->inputManager.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->renderWindow))
			{
				this->_data->machine.RemoveState();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void PauseState::Update(float dt)
	{

	}

	void PauseState::Draw(float dt)
	{
		this->_data->renderWindow.clear();

		this->_data->renderWindow.draw(this->_background);
		this->_data->renderWindow.draw(this->_resumeButton);
		this->_data->renderWindow.draw(this->_homeButton);

		this->_data->renderWindow.display();
	}

}
