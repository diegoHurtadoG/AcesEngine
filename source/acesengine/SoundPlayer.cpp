#include "SoundPlayer.h"


namespace acesengine {

    SoundPlayer::SoundPlayer() {};

    void SoundPlayer::loadAudio(std::string uniqueName, std::string audioPath) {
        sf::Sound sound;
        sf::SoundBuffer buff;
        if (!buff.loadFromFile(audioPath)) {
            printf("Error loading audio");
        }
        this->buffers.emplace(uniqueName, buff);
        this->sounds.emplace(uniqueName, sound);
    }

    void SoundPlayer::playAudio(std::string uniqueName) {
        this->sounds.at(uniqueName).setBuffer(this->buffers.at(uniqueName));
        this->sounds.at(uniqueName).play();
    }

    void SoundPlayer::stopAudio(std::string uniqueName) {
        this->sounds.at(uniqueName).stop();
    }

    void SoundPlayer::setVolumeAudio(std::string uniqueName, int vol) {
        this->sounds.at(uniqueName).setVolume((float)vol);
    }

    float SoundPlayer::getVolumeAudio(std::string uniqueName) {
        return this->sounds.at(uniqueName).getVolume();
    }

    void SoundPlayer::setPitchAudio(std::string uniqueName, float value) {
        this->sounds.at(uniqueName).setPitch(value);
    }

    float SoundPlayer::getPitchAudio(std::string uniqueName) {
        return this->sounds.at(uniqueName).getPitch();
    }

    void SoundPlayer::setPlayingOffsetAudio(std::string uniqueName, float offset) {
        this->sounds.at(uniqueName).setPlayingOffset(sf::seconds(offset));
    }

    void SoundPlayer::loopAudio(std::string uniqueName) {
        this->sounds.at(uniqueName).setLoop(!this->sounds.at(uniqueName).getLoop());
    }

    // Music methods

    // This one throwing error with assimp (?)
    /*
    void loadMusic(std::string uniqueName, std::string musicPath) {
        sf::Music music;
        if (!music.openFromFile(musicPath)) {
            printf("Error loading music");
        }
        this->musics.emplace(uniqueName, music);
    }
    */

    void SoundPlayer::playMusic(std::string uniqueName) {
        this->musics.at(uniqueName).play();
    }

    void SoundPlayer::stopMusic(std::string uniqueName) {
        this->musics.at(uniqueName).stop();
    }

    void SoundPlayer::setVolumeMusic(std::string uniqueName, int vol) {
        this->musics.at(uniqueName).setVolume((float)vol);
    }

    float SoundPlayer::getVolumeMusic(std::string uniqueName) {
        return this->musics.at(uniqueName).getVolume();
    }

    void SoundPlayer::setPitchMusic(std::string uniqueName, float value) {
        this->musics.at(uniqueName).setPitch(value);
    }

    float SoundPlayer::getPitchMusic(std::string uniqueName) {
        return this->musics.at(uniqueName).getPitch();
    }

    void SoundPlayer::setPlayingOffsetMusic(std::string uniqueName, float offset) {
        this->musics.at(uniqueName).setPlayingOffset(sf::seconds(offset));
    }

    void SoundPlayer::loopMusic(std::string uniqueName) {
        this->musics.at(uniqueName).setLoop(!this->musics.at(uniqueName).getLoop());
    }

    void SoundPlayer::startRecordingSound() {
        if (!sf::SoundBufferRecorder::isAvailable())
        {
            printf("Audio capture not available in system");
        }
        this->recorder.start();
        this->recording = true;
    }

    void SoundPlayer::pauseRecordingSound() {
        this->recorder.stop();
        this->recording = false;
    }

    void SoundPlayer::resumeRecordingSound() {
        if (!sf::SoundBufferRecorder::isAvailable())
        {
            printf("Audio capture not available in system");
        }
        this->recorder.start();
        this->recording = true;
    }

    void SoundPlayer::stopRecordingSound(std::string uniqueName) {
        this->recorder.stop();
        this->recording = false;
        const sf::SoundBuffer& buffer = recorder.getBuffer();
        this->sounds.emplace(uniqueName, buffer);
    }

    void SoundPlayer::changeRecordingState() {
        this->recording = !this->recording;
    }

    bool SoundPlayer::getRecordingState() {
        return this->recording;
    }

};