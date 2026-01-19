#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

const int TILE_SIZE = 32;
const int GLOBAL_SCREEN_WIDTH = 3840;
const int GLOBAL_SCREEN_HEIGHT = 2160;

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
const sf::Color COLOR_GRAYSCALE_WHITE = sf::Color(255, 255, 255);
const sf::Color COLOR_GRAYSCALE_GHOST_WHITE = sf::Color(248, 248, 255);
const sf::Color COLOR_GRAYSCALE_SILVER = sf::Color(192, 192, 192);
const sf::Color COLOR_GRAYSCALE_LIGHT_GRAY = sf::Color(189, 189, 189);
const sf::Color COLOR_GRAYSCALE_GRAY = sf::Color(117, 117, 117);
const sf::Color COLOR_GRAYSCALE_SLATE_GRAY = sf::Color(112, 128, 144);
const sf::Color COLOR_GRAYSCALE_DARK_GRAY = sf::Color(66, 66, 66);
const sf::Color COLOR_GRAYSCALE_DEEP_CHARCOAL = sf::Color(33, 33, 33);
const sf::Color COLOR_GRAYSCALE_BLACK = sf::Color(20, 17, 21);
const sf::Color COLOR_GRAYSCALE_DENSE_WHITE = sf::Color(255, 255, 255, 25);
const sf::Color COLOR_GRAYSCALE_DENSE_GHOST_WHITE = sf::Color(248, 248, 255, 25);
const sf::Color COLOR_GRAYSCALE_DENSE_SILVER = sf::Color(192, 192, 192, 25);
const sf::Color COLOR_GRAYSCALE_DENSE_LIGHT_GRAY = sf::Color(189, 189, 189, 25);
const sf::Color COLOR_GRAYSCALE_DENSE_GRAY = sf::Color(117, 117, 117, 25);
const sf::Color COLOR_GRAYSCALE_DENSE_SLATE_GRAY = sf::Color(112, 128, 144, 25);
const sf::Color COLOR_GRAYSCALE_DENSE_DARK_GRAY = sf::Color(66, 66, 66, 25);
const sf::Color COLOR_GRAYSCALE_DENSE_DEEP_CHARCOAL = sf::Color(33, 33, 33, 25);
const sf::Color COLOR_GRAYSCALE_DENSE_BLACK = sf::Color(20, 17, 21, 25);
const sf::Color COLOR_GRAYSCALE_CLOUDY_WHITE = sf::Color(255, 255, 255, 100);
const sf::Color COLOR_GRAYSCALE_CLOUDY_GHOST_WHITE = sf::Color(248, 248, 255, 100);
const sf::Color COLOR_GRAYSCALE_CLOUDY_SILVER = sf::Color(192, 192, 192, 100);
const sf::Color COLOR_GRAYSCALE_CLOUDY_LIGHT_GRAY = sf::Color(189, 189, 189, 100);
const sf::Color COLOR_GRAYSCALE_CLOUDY_GRAY = sf::Color(117, 117, 117, 100);
const sf::Color COLOR_GRAYSCALE_CLOUDY_SLATE_GRAY = sf::Color(112, 128, 144, 100);
const sf::Color COLOR_GRAYSCALE_CLOUDY_DARK_GRAY = sf::Color(66, 66, 66, 100);
const sf::Color COLOR_GRAYSCALE_CLOUDY_DEEP_CHARCOAL = sf::Color(33, 33, 33, 100);
const sf::Color COLOR_GRAYSCALE_CLOUDY_BLACK = sf::Color(20, 17, 21, 100);
const sf::Color COLOR_GRAYSCALE_MILKY_WHITE = sf::Color(255, 255, 255, 200);
const sf::Color COLOR_GRAYSCALE_MILKY_GHOST_WHITE = sf::Color(248, 248, 255, 200);
const sf::Color COLOR_GRAYSCALE_MILKY_SILVER = sf::Color(192, 192, 192, 200);
const sf::Color COLOR_GRAYSCALE_MILKY_LIGHT_GRAY = sf::Color(189, 189, 189, 200);
const sf::Color COLOR_GRAYSCALE_MILKY_GRAY = sf::Color(117, 117, 117, 200);
const sf::Color COLOR_GRAYSCALE_MILKY_SLATE_GRAY = sf::Color(112, 128, 144, 200);
const sf::Color COLOR_GRAYSCALE_MILKY_DARK_GRAY = sf::Color(66, 66, 66, 200);
const sf::Color COLOR_GRAYSCALE_MILKY_DEEP_CHARCOAL = sf::Color(33, 33, 33, 200);
const sf::Color COLOR_GRAYSCALE_MILKY_BLACK = sf::Color(20, 17, 21, 200);

// --- Reds & Pinks ---
const sf::Color COLOR_RED_RED = sf::Color(255, 0, 0);
const sf::Color COLOR_RED_PURE_RED = sf::Color(255, 0, 0); // Alias
const sf::Color COLOR_RED_CRIMSON = sf::Color(183, 28, 28);
const sf::Color COLOR_RED_BURGUNDY = sf::Color(128, 0, 32);
const sf::Color COLOR_RED_ROSE = sf::Color(234, 128, 252);
const sf::Color COLOR_RED_HOT_PINK = sf::Color(240, 98, 146);
const sf::Color COLOR_RED_SALMON = sf::Color(250, 128, 114);
const sf::Color COLOR_RED_SUNSET = sf::Color(253, 94, 83);
const sf::Color COLOR_RED_DENSE_RED = sf::Color(255, 0, 0, 25);
const sf::Color COLOR_RED_DENSE_CRIMSON = sf::Color(183, 28, 28, 25);
const sf::Color COLOR_RED_DENSE_BURGUNDY = sf::Color(128, 0, 32, 25);
const sf::Color COLOR_RED_DENSE_ROSE = sf::Color(234, 128, 252, 25);
const sf::Color COLOR_RED_DENSE_HOT_PINK = sf::Color(240, 98, 146, 25);
const sf::Color COLOR_RED_DENSE_SALMON = sf::Color(250, 128, 114, 25);
const sf::Color COLOR_RED_DENSE_SUNSET = sf::Color(253, 94, 83, 25);
const sf::Color COLOR_RED_CLOUDY_RED = sf::Color(255, 0, 0, 100);
const sf::Color COLOR_RED_CLOUDY_CRIMSON = sf::Color(183, 28, 28, 100);
const sf::Color COLOR_RED_CLOUDY_BURGUNDY = sf::Color(128, 0, 32, 100);
const sf::Color COLOR_RED_CLOUDY_ROSE = sf::Color(234, 128, 252, 100);
const sf::Color COLOR_RED_CLOUDY_HOT_PINK = sf::Color(240, 98, 146, 100);
const sf::Color COLOR_RED_CLOUDY_SALMON = sf::Color(250, 128, 114, 100);
const sf::Color COLOR_RED_CLOUDY_SUNSET = sf::Color(253, 94, 83, 100);
const sf::Color COLOR_RED_MILKY_RED = sf::Color(255, 0, 0, 200);
const sf::Color COLOR_RED_MILKY_CRIMSON = sf::Color(183, 28, 28, 200);
const sf::Color COLOR_RED_MILKY_BURGUNDY = sf::Color(128, 0, 32, 200);
const sf::Color COLOR_RED_MILKY_ROSE = sf::Color(234, 128, 252, 200);
const sf::Color COLOR_RED_MILKY_HOT_PINK = sf::Color(240, 98, 146, 200);
const sf::Color COLOR_RED_MILKY_SALMON = sf::Color(250, 128, 114, 200);
const sf::Color COLOR_RED_MILKY_SUNSET = sf::Color(253, 94, 83, 200);

// --- Oranges & Yellows ---
const sf::Color COLOR_ORANGE_ORANGE = sf::Color(255, 61, 0);
const sf::Color COLOR_ORANGE_CORAL = sf::Color(255, 127, 80);
const sf::Color COLOR_ORANGE_TERRACOTTA = sf::Color(204, 78, 92);
const sf::Color COLOR_ORANGE_PEACH = sf::Color(255, 218, 185);
const sf::Color COLOR_ORANGE_AMBER = sf::Color(255, 193, 7);
const sf::Color COLOR_ORANGE_YELLOW = sf::Color(255, 255, 0);
const sf::Color COLOR_ORANGE_GOLD = sf::Color(255, 215, 0);
const sf::Color COLOR_ORANGE_DENSE_ORANGE = sf::Color(255, 61, 0, 25);
const sf::Color COLOR_ORANGE_DENSE_CORAL = sf::Color(255, 127, 80, 25);
const sf::Color COLOR_ORANGE_DENSE_TERRACOTTA = sf::Color(204, 78, 92, 25);
const sf::Color COLOR_ORANGE_DENSE_PEACH = sf::Color(255, 218, 185, 25);
const sf::Color COLOR_ORANGE_DENSE_AMBER = sf::Color(255, 193, 7, 25);
const sf::Color COLOR_ORANGE_DENSE_YELLOW = sf::Color(255, 255, 0, 25);
const sf::Color COLOR_ORANGE_DENSE_GOLD = sf::Color(255, 215, 0, 25);
const sf::Color COLOR_ORANGE_CLOUDY_ORANGE = sf::Color(255, 61, 0, 100);
const sf::Color COLOR_ORANGE_CLOUDY_CORAL = sf::Color(255, 127, 80, 100);
const sf::Color COLOR_ORANGE_CLOUDY_TERRACOTTA = sf::Color(204, 78, 92, 100);
const sf::Color COLOR_ORANGE_CLOUDY_PEACH = sf::Color(255, 218, 185, 100);
const sf::Color COLOR_ORANGE_CLOUDY_AMBER = sf::Color(255, 193, 7, 100);
const sf::Color COLOR_ORANGE_CLOUDY_YELLOW = sf::Color(255, 255, 0, 100);
const sf::Color COLOR_ORANGE_CLOUDY_GOLD = sf::Color(255, 215, 0, 100);
const sf::Color COLOR_ORANGE_MILKY_ORANGE = sf::Color(255, 61, 0, 200);
const sf::Color COLOR_ORANGE_MILKY_CORAL = sf::Color(255, 127, 80, 200);
const sf::Color COLOR_ORANGE_MILKY_TERRACOTTA = sf::Color(204, 78, 92, 200);
const sf::Color COLOR_ORANGE_MILKY_PEACH = sf::Color(255, 218, 185, 200);
const sf::Color COLOR_ORANGE_MILKY_AMBER = sf::Color(255, 193, 7, 200);
const sf::Color COLOR_ORANGE_MILKY_YELLOW = sf::Color(255, 255, 0, 200);
const sf::Color COLOR_ORANGE_MILKY_GOLD = sf::Color(255, 215, 0, 200);

// --- Greens ---
const sf::Color COLOR_GREEN_NEON_GREEN = sf::Color(198, 249, 31);
const sf::Color COLOR_GREEN_GREEN = sf::Color(198, 249, 31); // Alias
const sf::Color COLOR_GREEN_LIME = sf::Color(50, 205, 50);
const sf::Color COLOR_GREEN_EMERALD = sf::Color(80, 200, 120);
const sf::Color COLOR_GREEN_SEA_GREEN = sf::Color(46, 139, 87);
const sf::Color COLOR_GREEN_FOREST_GREEN = sf::Color(34, 139, 34);
const sf::Color COLOR_GREEN_DARK_GREEN = sf::Color(77, 144, 120);
const sf::Color COLOR_GREEN_JUNGLE_GREEN = sf::Color(26, 81, 71);
const sf::Color COLOR_GREEN_MINT_GREEN = sf::Color(178, 223, 219);
const sf::Color COLOR_GREEN_OLIVE = sf::Color(128, 128, 0);
const sf::Color COLOR_GREEN_DENSE_NEON_GREEN = sf::Color(198, 249, 31, 25);
const sf::Color COLOR_GREEN_DENSE_GREEN = sf::Color(198, 249, 31, 25);
const sf::Color COLOR_GREEN_DENSE_LIME = sf::Color(50, 205, 50, 25);
const sf::Color COLOR_GREEN_DENSE_EMERALD = sf::Color(80, 200, 120, 25);
const sf::Color COLOR_GREEN_DENSE_SEA_GREEN = sf::Color(46, 139, 87, 25);
const sf::Color COLOR_GREEN_DENSE_FOREST_GREEN = sf::Color(34, 139, 34, 25);
const sf::Color COLOR_GREEN_DENSE_DARK_GREEN = sf::Color(77, 144, 120, 25);
const sf::Color COLOR_GREEN_DENSE_JUNGLE_GREEN = sf::Color(26, 81, 71, 25);
const sf::Color COLOR_GREEN_DENSE_MINT_GREEN = sf::Color(178, 223, 219, 25);
const sf::Color COLOR_GREEN_DENSE_OLIVE = sf::Color(128, 128, 0, 25);
const sf::Color COLOR_GREEN_CLOUDY_NEON_GREEN = sf::Color(198, 249, 31, 100);
const sf::Color COLOR_GREEN_CLOUDY_GREEN = sf::Color(198, 249, 31, 100);
const sf::Color COLOR_GREEN_CLOUDY_LIME = sf::Color(50, 205, 50, 100);
const sf::Color COLOR_GREEN_CLOUDY_EMERALD = sf::Color(80, 200, 120, 100);
const sf::Color COLOR_GREEN_CLOUDY_SEA_GREEN = sf::Color(46, 139, 87, 100);
const sf::Color COLOR_GREEN_CLOUDY_FOREST_GREEN = sf::Color(34, 139, 34, 100);
const sf::Color COLOR_GREEN_CLOUDY_DARK_GREEN = sf::Color(77, 144, 120, 100);
const sf::Color COLOR_GREEN_CLOUDY_JUNGLE_GREEN = sf::Color(26, 81, 71, 100);
const sf::Color COLOR_GREEN_CLOUDY_MINT_GREEN = sf::Color(178, 223, 219, 100);
const sf::Color COLOR_GREEN_CLOUDY_OLIVE = sf::Color(128, 128, 0, 100);
const sf::Color COLOR_GREEN_MILKY_NEON_GREEN = sf::Color(198, 249, 31, 200);
const sf::Color COLOR_GREEN_MILKY_GREEN = sf::Color(198, 249, 31, 200);
const sf::Color COLOR_GREEN_MILKY_LIME = sf::Color(50, 205, 50, 200);
const sf::Color COLOR_GREEN_MILKY_EMERALD = sf::Color(80, 200, 120, 200);
const sf::Color COLOR_GREEN_MILKY_SEA_GREEN = sf::Color(46, 139, 87, 200);
const sf::Color COLOR_GREEN_MILKY_FOREST_GREEN = sf::Color(34, 139, 34, 200);
const sf::Color COLOR_GREEN_MILKY_DARK_GREEN = sf::Color(77, 144, 120, 200);
const sf::Color COLOR_GREEN_MILKY_JUNGLE_GREEN = sf::Color(26, 81, 71, 200);
const sf::Color COLOR_GREEN_MILKY_MINT_GREEN = sf::Color(178, 223, 219, 200);
const sf::Color COLOR_GREEN_MILKY_OLIVE = sf::Color(128, 128, 0, 200);

// --- Blues & Cyans ---
const sf::Color COLOR_BLUE_AQUA = sf::Color(0, 255, 255);
const sf::Color COLOR_BLUE_CYAN = sf::Color(0, 255, 255); // Alias
const sf::Color COLOR_BLUE_ICE_COLD = sf::Color(175, 238, 238);
const sf::Color COLOR_BLUE_ELECTRIC_BLUE = sf::Color(125, 249, 255);
const sf::Color COLOR_BLUE_CLEAR_BLUE = sf::Color(41, 182, 246);
const sf::Color COLOR_BLUE_SKY_BLUE = sf::Color(41, 182, 246); // Alias
const sf::Color COLOR_BLUE_STEEL_BLUE = sf::Color(70, 130, 180);
const sf::Color COLOR_BLUE_DEEP_BLUE = sf::Color(21, 101, 192);
const sf::Color COLOR_BLUE_NAVY_BLUE = sf::Color(0, 0, 128);
const sf::Color COLOR_BLUE_MIDNIGHT = sf::Color(25, 25, 112);
const sf::Color COLOR_BLUE_TEAL = sf::Color(0, 121, 107);
const sf::Color COLOR_BLUE_DENSE_AQUA = sf::Color(0, 255, 255, 25);
const sf::Color COLOR_BLUE_DENSE_CYAN = sf::Color(0, 255, 255, 25);
const sf::Color COLOR_BLUE_DENSE_ICE_COLD = sf::Color(175, 238, 238, 25);
const sf::Color COLOR_BLUE_DENSE_ELECTRIC_BLUE = sf::Color(125, 249, 255, 25);
const sf::Color COLOR_BLUE_DENSE_CLEAR_BLUE = sf::Color(41, 182, 246, 25);
const sf::Color COLOR_BLUE_DENSE_SKY_BLUE = sf::Color(41, 182, 246, 25);
const sf::Color COLOR_BLUE_DENSE_STEEL_BLUE = sf::Color(70, 130, 180, 25);
const sf::Color COLOR_BLUE_DENSE_DEEP_BLUE = sf::Color(21, 101, 192, 25);
const sf::Color COLOR_BLUE_DENSE_NAVY_BLUE = sf::Color(0, 0, 128, 25);
const sf::Color COLOR_BLUE_DENSE_MIDNIGHT = sf::Color(25, 25, 112, 25);
const sf::Color COLOR_BLUE_DENSE_TEAL = sf::Color(0, 121, 107, 25);
const sf::Color COLOR_BLUE_CLOUDY_AQUA = sf::Color(0, 255, 255, 100);
const sf::Color COLOR_BLUE_CLOUDY_CYAN = sf::Color(0, 255, 255, 100);
const sf::Color COLOR_BLUE_CLOUDY_ICE_COLD = sf::Color(175, 238, 238, 100);
const sf::Color COLOR_BLUE_CLOUDY_ELECTRIC_BLUE = sf::Color(125, 249, 255, 100);
const sf::Color COLOR_BLUE_CLOUDY_CLEAR_BLUE = sf::Color(41, 182, 246, 100);
const sf::Color COLOR_BLUE_CLOUDY_SKY_BLUE = sf::Color(41, 182, 246, 100);
const sf::Color COLOR_BLUE_CLOUDY_STEEL_BLUE = sf::Color(70, 130, 180, 100);
const sf::Color COLOR_BLUE_CLOUDY_DEEP_BLUE = sf::Color(21, 101, 192, 100);
const sf::Color COLOR_BLUE_CLOUDY_NAVY_BLUE = sf::Color(0, 0, 128, 100);
const sf::Color COLOR_BLUE_CLOUDY_MIDNIGHT = sf::Color(25, 25, 112, 100);
const sf::Color COLOR_BLUE_CLOUDY_TEAL = sf::Color(0, 121, 107, 100);
const sf::Color COLOR_BLUE_MILKY_AQUA = sf::Color(0, 255, 255, 200);
const sf::Color COLOR_BLUE_MILKY_CYAN = sf::Color(0, 255, 255, 200);
const sf::Color COLOR_BLUE_MILKY_ICE_COLD = sf::Color(175, 238, 238, 200);
const sf::Color COLOR_BLUE_MILKY_ELECTRIC_BLUE = sf::Color(125, 249, 255, 200);
const sf::Color COLOR_BLUE_MILKY_CLEAR_BLUE = sf::Color(41, 182, 246, 200);
const sf::Color COLOR_BLUE_MILKY_SKY_BLUE = sf::Color(41, 182, 246, 200);
const sf::Color COLOR_BLUE_MILKY_STEEL_BLUE = sf::Color(70, 130, 180, 200);
const sf::Color COLOR_BLUE_MILKY_DEEP_BLUE = sf::Color(21, 101, 192, 200);
const sf::Color COLOR_BLUE_MILKY_NAVY_BLUE = sf::Color(0, 0, 128, 200);
const sf::Color COLOR_BLUE_MILKY_MIDNIGHT = sf::Color(25, 25, 112, 200);
const sf::Color COLOR_BLUE_MILKY_TEAL = sf::Color(0, 121, 107, 200);

// --- Violets & Purples ---
const sf::Color COLOR_VIOLET_MAGENTA = sf::Color(255, 0, 255);
const sf::Color COLOR_VIOLET_CYBER_PURPLE = sf::Color(188, 19, 254);
const sf::Color COLOR_VIOLET_VIOLET = sf::Color(170, 0, 255);
const sf::Color COLOR_VIOLET_PURPLE = sf::Color(106, 27, 154);
const sf::Color COLOR_VIOLET_INDIGO = sf::Color(75, 0, 130);
const sf::Color COLOR_VIOLET_DARK_VIOLET = sf::Color(60, 27, 67);
const sf::Color COLOR_VIOLET_PLUM = sf::Color(221, 160, 221);
const sf::Color COLOR_VIOLET_LAVENDER = sf::Color(230, 230, 250);
const sf::Color COLOR_VIOLET_DENSE_MAGENTA = sf::Color(255, 0, 255, 25);
const sf::Color COLOR_VIOLET_DENSE_CYBER_PURPLE = sf::Color(188, 19, 254, 25);
const sf::Color COLOR_VIOLET_DENSE_VIOLET = sf::Color(170, 0, 255, 25);
const sf::Color COLOR_VIOLET_DENSE_PURPLE = sf::Color(106, 27, 154, 25);
const sf::Color COLOR_VIOLET_DENSE_INDIGO = sf::Color(75, 0, 130, 25);
const sf::Color COLOR_VIOLET_DENSE_DARK_VIOLET = sf::Color(60, 27, 67, 25);
const sf::Color COLOR_VIOLET_DENSE_PLUM = sf::Color(221, 160, 221, 25);
const sf::Color COLOR_VIOLET_DENSE_LAVENDER = sf::Color(230, 230, 250, 25);
const sf::Color COLOR_VIOLET_CLOUDY_MAGENTA = sf::Color(255, 0, 255, 100);
const sf::Color COLOR_VIOLET_CLOUDY_CYBER_PURPLE = sf::Color(188, 19, 254, 100);
const sf::Color COLOR_VIOLET_CLOUDY_VIOLET = sf::Color(170, 0, 255, 100);
const sf::Color COLOR_VIOLET_CLOUDY_PURPLE = sf::Color(106, 27, 154, 100);
const sf::Color COLOR_VIOLET_CLOUDY_INDIGO = sf::Color(75, 0, 130, 100);
const sf::Color COLOR_VIOLET_CLOUDY_DARK_VIOLET = sf::Color(60, 27, 67, 100);
const sf::Color COLOR_VIOLET_CLOUDY_PLUM = sf::Color(221, 160, 221, 100);
const sf::Color COLOR_VIOLET_CLOUDY_LAVENDER = sf::Color(230, 230, 250, 100);
const sf::Color COLOR_VIOLET_MILKY_MAGENTA = sf::Color(255, 0, 255, 200);
const sf::Color COLOR_VIOLET_MILKY_CYBER_PURPLE = sf::Color(188, 19, 254, 200);
const sf::Color COLOR_VIOLET_MILKY_VIOLET = sf::Color(170, 0, 255, 200);
const sf::Color COLOR_VIOLET_MILKY_PURPLE = sf::Color(106, 27, 154, 200);
const sf::Color COLOR_VIOLET_MILKY_INDIGO = sf::Color(75, 0, 130, 200);
const sf::Color COLOR_VIOLET_MILKY_DARK_VIOLET = sf::Color(60, 27, 67, 200);
const sf::Color COLOR_VIOLET_MILKY_PLUM = sf::Color(221, 160, 221, 200);
const sf::Color COLOR_VIOLET_MILKY_LAVENDER = sf::Color(230, 230, 250, 200);

// --- Earth & Browns ---
const sf::Color COLOR_BROWN_CREAM = sf::Color(212, 231, 158);
const sf::Color COLOR_BROWN_SAND = sf::Color(240, 230, 140);
const sf::Color COLOR_BROWN_TAN = sf::Color(210, 180, 140);
const sf::Color COLOR_BROWN_OCHRE = sf::Color(204, 119, 34);
const sf::Color COLOR_BROWN_BRONZE = sf::Color(205, 127, 50);
const sf::Color COLOR_BROWN_COFFEE = sf::Color(121, 85, 72);
const sf::Color COLOR_BROWN_BROWN = sf::Color(76, 43, 54);
const sf::Color COLOR_BROWN_MUD_BROWN = sf::Color(62, 39, 35);
const sf::Color COLOR_BROWN_DENSE_CREAM = sf::Color(212, 231, 158, 25);
const sf::Color COLOR_BROWN_DENSE_SAND = sf::Color(240, 230, 140, 25);
const sf::Color COLOR_BROWN_DENSE_TAN = sf::Color(210, 180, 140, 25);
const sf::Color COLOR_BROWN_DENSE_OCHRE = sf::Color(204, 119, 34, 25);
const sf::Color COLOR_BROWN_DENSE_BRONZE = sf::Color(205, 127, 50, 25);
const sf::Color COLOR_BROWN_DENSE_COFFEE = sf::Color(121, 85, 72, 25);
const sf::Color COLOR_BROWN_DENSE_BROWN = sf::Color(76, 43, 54, 25);
const sf::Color COLOR_BROWN_DENSE_MUD_BROWN = sf::Color(62, 39, 35, 25);
const sf::Color COLOR_BROWN_CLOUDY_CREAM = sf::Color(212, 231, 158, 100);
const sf::Color COLOR_BROWN_CLOUDY_SAND = sf::Color(240, 230, 140, 100);
const sf::Color COLOR_BROWN_CLOUDY_TAN = sf::Color(210, 180, 140, 100);
const sf::Color COLOR_BROWN_CLOUDY_OCHRE = sf::Color(204, 119, 34, 100);
const sf::Color COLOR_BROWN_CLOUDY_BRONZE = sf::Color(205, 127, 50, 100);
const sf::Color COLOR_BROWN_CLOUDY_COFFEE = sf::Color(121, 85, 72, 100);
const sf::Color COLOR_BROWN_CLOUDY_BROWN = sf::Color(76, 43, 54, 100);
const sf::Color COLOR_BROWN_CLOUDY_MUD_BROWN = sf::Color(62, 39, 35, 100);
const sf::Color COLOR_BROWN_MILKY_CREAM = sf::Color(212, 231, 158, 200);
const sf::Color COLOR_BROWN_MILKY_SAND = sf::Color(240, 230, 140, 200);
const sf::Color COLOR_BROWN_MILKY_TAN = sf::Color(210, 180, 140, 200);
const sf::Color COLOR_BROWN_MILKY_OCHRE = sf::Color(204, 119, 34, 200);
const sf::Color COLOR_BROWN_MILKY_BRONZE = sf::Color(205, 127, 50, 200);
const sf::Color COLOR_BROWN_MILKY_COFFEE = sf::Color(121, 85, 72, 200);
const sf::Color COLOR_BROWN_MILKY_BROWN = sf::Color(76, 43, 54, 200);
const sf::Color COLOR_BROWN_MILKY_MUD_BROWN = sf::Color(62, 39, 35, 200);

// Timer Color
const sf::Color COLOR_TIMER_BACKGROUND = COLOR_VIOLET_DARK_VIOLET;
const sf::Color COLOR_TIMER_PROGRESSBAR = COLOR_GREEN_DARK_GREEN;

// Dice Color
const std::vector<sf::Color> COLORS_DICE_ELEMENTS = {
    COLOR_RED_CRIMSON,
    COLOR_BLUE_ELECTRIC_BLUE,
    COLOR_BLUE_ICE_COLD};