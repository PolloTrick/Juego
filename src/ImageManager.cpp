#include "ImageManager.hpp"
#include <iostream>

const sf::Texture& ImageManager::loadImage(const std::string& filename) {
    if (textures.find(filename) == textures.end()) {
        sf::Texture texture;
        if (!texture.loadFromFile(filename)) {
            std::cerr << "Error al cargar la imagen: " << filename << std::endl;
        } else {
            textures[filename] = texture;
        }
    }
    return textures[filename];
}
