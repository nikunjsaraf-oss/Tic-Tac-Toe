#include "Game.h"

namespace Nikunj
{
    Game::Game(int width, int height, std::string title)
    {
        _data->renderWindow.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

        this->Run();
    }

    void Game::Run()
    {
        float newTime, frameTime, interpolation;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->_data->renderWindow.isOpen())
        {
            this->_data->machine.ProcessStateChanges();
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 2.5f)
            {
                frameTime = 2.5f;
            }
            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator > frameRate)
            {
                this->_data->machine.GetActiveState()->HandleInput();
                this->_data->machine.GetActiveState()->Update(frameRate);
                accumulator -= frameRate;
            }

            interpolation = accumulator / frameRate;
            this->_data->machine.GetActiveState()->Draw(interpolation);
        }
    }
}
