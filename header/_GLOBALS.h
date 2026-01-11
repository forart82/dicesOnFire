#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

const int TILE_SIZE = 32;
const float SCREEN_RATIO = 0.5625;
const int GLOBAL_SCREEN_WIDTH = 1920;
const int GLOBAL_SCREEN_HEIGHT = 1080;

const int START_ZONE_WIDTH = 600;
const int START_ZONE_HEIGHT = 400;
const int SCOREBOARD_HEIGHT = 50;
const int TEXT_SIZE = 16;

const float GAP_SIZE = 0.5f;
const float BUTTON_HEIGHT = 20.f;
const float BUTTON_WIDTH = 80.f;

// ####################################
// ### Web: https://htmlcolors.com/ ###
// Background
// --- Greyscale & UI Shades ---
const sf::Color COLOR_WHITE = sf::Color(255, 255, 255);
const sf::Color COLOR_GHOST_WHITE = sf::Color(248, 248, 255);
const sf::Color COLOR_SILVER = sf::Color(192, 192, 192);
const sf::Color COLOR_LIGHT_GRAY = sf::Color(189, 189, 189);
const sf::Color COLOR_GRAY = sf::Color(117, 117, 117);
const sf::Color COLOR_SLATE_GRAY = sf::Color(112, 128, 144);
const sf::Color COLOR_DARK_GRAY = sf::Color(66, 66, 66);
const sf::Color COLOR_DEEP_CHARCOAL = sf::Color(33, 33, 33);
const sf::Color COLOR_BLACK = sf::Color(20, 17, 21);
const sf::Color COLOR_BLUE_SHADE = sf::Color(0, 0, 255, 25);
const sf::Color COLOR_RED_SHADE = sf::Color(255, 0, 0, 25);
const sf::Color COLOR_YELLOW_SHADE = sf::Color(255, 255, 0, 25);
const sf::Color COLOR_GREEN_SHADE = sf::Color(0, 255, 0, 25);

// --- Reds & Pinks ---
const sf::Color COLOR_RED = sf::Color(255, 0, 0);
const sf::Color COLOR_PURE_RED = sf::Color(255, 0, 0); // Alias
const sf::Color COLOR_CRIMSON = sf::Color(183, 28, 28);
const sf::Color COLOR_BURGUNDY = sf::Color(128, 0, 32);
const sf::Color COLOR_ROSE = sf::Color(234, 128, 252);
const sf::Color COLOR_HOT_PINK = sf::Color(240, 98, 146);
const sf::Color COLOR_SALMON = sf::Color(250, 128, 114);
const sf::Color COLOR_SUNSET = sf::Color(253, 94, 83);

// --- Oranges & Yellows ---
const sf::Color COLOR_ORANGE = sf::Color(255, 61, 0);
const sf::Color COLOR_CORAL = sf::Color(255, 127, 80);
const sf::Color COLOR_TERRACOTTA = sf::Color(204, 78, 92);
const sf::Color COLOR_PEACH = sf::Color(255, 218, 185);
const sf::Color COLOR_AMBER = sf::Color(255, 193, 7);
const sf::Color COLOR_YELLOW = sf::Color(255, 255, 0);
const sf::Color COLOR_GOLD = sf::Color(255, 215, 0);

// --- Greens ---
const sf::Color COLOR_NEON_GREEN = sf::Color(198, 249, 31);
const sf::Color COLOR_GREEN = sf::Color(198, 249, 31); // Alias
const sf::Color COLOR_LIME = sf::Color(50, 205, 50);
const sf::Color COLOR_EMERALD = sf::Color(80, 200, 120);
const sf::Color COLOR_SEA_GREEN = sf::Color(46, 139, 87);
const sf::Color COLOR_FOREST_GREEN = sf::Color(34, 139, 34);
const sf::Color COLOR_DARK_GREEN = sf::Color(77, 144, 120);
const sf::Color COLOR_JUNGLE_GREEN = sf::Color(26, 81, 71);
const sf::Color COLOR_MINT_GREEN = sf::Color(178, 223, 219);
const sf::Color COLOR_OLIVE = sf::Color(128, 128, 0);

// --- Blues & Cyans ---
const sf::Color COLOR_AQUA = sf::Color(0, 255, 255);
const sf::Color COLOR_CYAN = sf::Color(0, 255, 255); // Alias
const sf::Color COLOR_ICE_COLD = sf::Color(175, 238, 238);
const sf::Color COLOR_ELECTRIC_BLUE = sf::Color(125, 249, 255);
const sf::Color COLOR_CLEAR_BLUE = sf::Color(41, 182, 246);
const sf::Color COLOR_SKY_BLUE = sf::Color(41, 182, 246); // Alias
const sf::Color COLOR_STEEL_BLUE = sf::Color(70, 130, 180);
const sf::Color COLOR_DEEP_BLUE = sf::Color(21, 101, 192);
const sf::Color COLOR_NAVY_BLUE = sf::Color(0, 0, 128);
const sf::Color COLOR_MIDNIGHT = sf::Color(25, 25, 112);
const sf::Color COLOR_TEAL = sf::Color(0, 121, 107);

// --- Violets & Purples ---
const sf::Color COLOR_MAGENTA = sf::Color(255, 0, 255);
const sf::Color COLOR_CYBER_PURPLE = sf::Color(188, 19, 254);
const sf::Color COLOR_VIOLET = sf::Color(170, 0, 255);
const sf::Color COLOR_PURPLE = sf::Color(106, 27, 154);
const sf::Color COLOR_INDIGO = sf::Color(75, 0, 130);
const sf::Color COLOR_DARK_VIOLET = sf::Color(60, 27, 67);
const sf::Color COLOR_PLUM = sf::Color(221, 160, 221);
const sf::Color COLOR_LAVENDER = sf::Color(230, 230, 250);

// --- Earth & Browns ---
const sf::Color COLOR_CREAM = sf::Color(212, 231, 158);
const sf::Color COLOR_SAND = sf::Color(240, 230, 140);
const sf::Color COLOR_TAN = sf::Color(210, 180, 140);
const sf::Color COLOR_OCHRE = sf::Color(204, 119, 34);
const sf::Color COLOR_BRONZE = sf::Color(205, 127, 50);
const sf::Color COLOR_COFFEE = sf::Color(121, 85, 72);
const sf::Color COLOR_BROWN = sf::Color(76, 43, 54);
const sf::Color COLOR_MUD_BROWN = sf::Color(62, 39, 35);
