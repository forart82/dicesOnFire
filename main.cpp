#include "./header/Game.h"
#include "./header/FontManager.h"

int main()
{

  FontManager::load("arial", "assets/fonts/arial.ttf");
  FontManager::load("Pm", "assets/fonts/PermanentMarker-Regular.ttf");
  FontManager::load("Quantico", "assets/fonts/Quantico-Regular.ttf");
  FontManager::load("SyneMono", "assets/fonts/SyneMono-Regular.ttf");
  FontManager::load("Emoji", "assets/fonts/NotoEmoji-VariableFont_wght.ttf");
  FontManager::load("Barcode", "assets/fonts/LibreBarcode39Extended-Regular.ttf");
  FontManager::load("BarcodeText", "assets/fonts/LibreBarcode39ExtendedText-Regular.ttf");
  Game game = Game();
  game.run();
}