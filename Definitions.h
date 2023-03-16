#pragma once

#include "UUIDGenerator.h"

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

const auto X_PIECE = UUIDGenerator::generate_uuid();
const auto O_PIECE = UUIDGenerator::generate_uuid();
const auto EMPTY_PIECE = UUIDGenerator::generate_uuid();
const auto STATE_PLAYING = UUIDGenerator::generate_uuid();
const auto STATE_PAUSED = UUIDGenerator::generate_uuid();
const auto STATE_WON = UUIDGenerator::generate_uuid();
const auto STATE_LOSE = UUIDGenerator::generate_uuid();
const auto STATE_PLACING_PIECE = UUIDGenerator::generate_uuid();
const auto STATE_AI_PLAYING = UUIDGenerator::generate_uuid();
const auto STATE_DRAW = UUIDGenerator::generate_uuid();

constexpr auto PAUSE_BACKGROUND_FILEPATH = "./Resources/res/Main Menu Background.png";
constexpr auto RESUME_BUTTON = "./Resources/res/Resume Button.png";
constexpr auto HOME_BUTTON = "./Resources/res/Home Button.png";