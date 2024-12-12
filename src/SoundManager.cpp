#include "SoundManager.hpp"
#include <iostream>

void SoundManager::playSound(const std::string& filename) {
    if (soundBuffers.find(filename) == soundBuffers.end()) {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(filename)) {
            std::cerr << "Error al cargar el sonido: " << filename << std::endl;
            return;
        }
        soundBuffers[filename] = buffer;
    }

    sf::Sound sound;
    sound.setBuffer(soundBuffers[filename]);
    sounds[filename] = sound;
    sounds[filename].play();
}
