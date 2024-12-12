#ifndef IMAGEMANAGER_HPP
#define IMAGEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class ImageManager {
private:
    std::unordered_map<std::string, sf::Texture> textures;

public:
    const sf::Texture& loadImage(const std::string& filename);
};

#endif // IMAGEMANAGER_HPP
