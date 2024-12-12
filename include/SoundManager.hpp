#ifndef SOUNDMANAGER_HPP
#define SOUNDMANAGER_HPP

#include <SFML/Audio.hpp>
#include <string>
#include <unordered_map>

class SoundManager {
private:
    std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
    std::unordered_map<std::string, sf::Sound> sounds;

public:
    void playSound(const std::string& filename);
};

#endif // SOUNDMANAGER_HPP
