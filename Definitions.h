#pragma once

#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE


constexpr auto SCREEN_WIDTH = 768;
constexpr auto SCREEN_HEIGHT = 960;

constexpr auto SPLASH_STATE_SHOW_TIME = 3;

constexpr auto SPLASH_SCENE_BACKGROUND_FILEPATH = "./Resources/res/Splash Background.png";

constexpr auto MAIN_MENU_BACKGROUND_FILEPATH = "./Resources/res/Main Menu Background.png";
constexpr auto MAIN_MENU_TITLE_FILEPATH = "./Resources/res/Game Title.png";
constexpr auto MAIN_MENU_PLAY_BUTTON = "./Resources/res/Play Button.png";
constexpr auto MAIN_MENU_PLAY_BUTTON_OUTER = "./Resources/res/Play Button Outer.png";

constexpr auto GAME_BACKGROUND_FILEPATH = "./Resources/res/Main Menu Background.png";
constexpr auto PAUSE_BUTTON = "./Resources/res/Pause Button.png";
constexpr auto X_PIECE_FILEPATH = "./Resources/res/X.png";
constexpr auto O_PIECE_FILEPATH = "./Resources/res/O.png";
constexpr auto X_WINNING_PIECE_FILEPATH = "./Resources/res/X Win.png";
constexpr auto O_WINNING_PIECE_FILEPATH = "./Resources/res/O Win.png";

const auto EMPTY_PIECE = -1;

constexpr auto X_PIECE = 8;
constexpr auto O_PIECE = 0;
constexpr auto STATE_PLAYING = 98;
constexpr auto STATE_PAUSED = 97;
constexpr auto STATE_WON = 96;
constexpr auto STATE_LOSE = 95;
constexpr auto STATE_PLACING_PIECE = 94;
constexpr auto STATE_AI_PLAYING = 93;
constexpr auto STATE_DRAW = 92;


constexpr auto PAUSE_BACKGROUND_FILEPATH = "./Resources/res/Main Menu Background.png";
constexpr auto RESUME_BUTTON = "./Resources/res/Resume Button.png";
constexpr auto HOME_BUTTON = "./Resources/res/Home Button.png";
constexpr auto RETRY_BUTTON = "./Resources/res/Retry Button.png";

constexpr auto GRID_SPRITE = "./Resources/res/Grid.png";