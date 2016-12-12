#include "TextUtil.h"
#include "SFML/Graphics/RenderWindow.hpp"

TextUtil* TextUtil::instance = nullptr;

TextUtil::TextUtil()
{
	if(!fntDefault.loadFromFile(DEFAULT_FONT_PATH))
	{
		printf("Error: failed to load \"%s\"\n", DEFAULT_FONT_PATH.c_str());
	}
	text.setFont(fntDefault);
	text.setCharacterSize(64);
}

TextUtil* TextUtil::getInstance()
{
	if(instance == nullptr)
	{
		instance = new TextUtil();
	}
	return instance;
}

TextUtil::~TextUtil()
{
	delete instance;
}

void TextUtil::drawText(const std::string& text, sf::RenderWindow& window, const sf::Vector2f& position, const float& size, const sf::Color &colour)
{
	this->text.setString(text);
	this->text.setScale(size, size);
	sf::FloatRect rectBounds = this->text.getLocalBounds();
	this->text.setOrigin(rectBounds.left + rectBounds.width / 2, rectBounds.top + rectBounds.height / 2);
	this->text.setPosition(position);
	this->text.setFillColor(colour);
	window.draw(this->text);
}
