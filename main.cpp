#include "./header/Game.h"
#include "./header/FontManager.h"

int main()
{

  FontManager::load("debugFont", "assets/fonts/arial.ttf");
  FontManager::load("first", "assets/fonts/PermanentMarker-Regular.ttf");
  FontManager::load("second", "assets/fonts/Quantico-Regular.ttf");
  FontManager::load("third", "assets/fonts/SyneMono-Regular.ttf");
  Game game = Game();
  game.run();
}