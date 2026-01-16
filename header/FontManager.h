#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class FontManager
{
private:
  static std::map<std::string, sf::Font> s_fonts;

public:
  static sf::Font &get(std::string name);

  static void load(std::string name, std::string path);
};