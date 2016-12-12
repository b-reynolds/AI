#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

namespace sf {
	class RenderWindow;
}

class TextUtil
{

public:

	static TextUtil* getInstance();
	~TextUtil();

	void drawText(const std::string &text, sf::RenderWindow &window, const sf::Vector2f &position, const float &size, const sf::Color &colour);

private:

	const std::string DEFAULT_FONT_PATH = "FantasqueSansMono-Regular.ttf";

	TextUtil();
	static TextUtil* instance;

	sf::Font fntDefault;
	sf::Text text;

};

