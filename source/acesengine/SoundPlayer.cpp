#include "SoundPlayer.h"


namespace acesengine {

    class SoundPlayer {
        std::map<std::string, sf::Sound> sounds;
        std::map<std::string, sf::SoundBuffer> buffers;
        std::map<std::string, sf::Music> musics;
        sf::SoundBufferRecorder recorder;
        bool recording = false;

    public:

        SoundPlayer() {};

    public:
        void loadAudio(std::string uniqueName, std::string audioPath) {
            sf::Sound sound;
            sf::SoundBuffer buff;
            if (!buff.loadFromFile(audioPath)) {
                printf("Error loading audio");
            }
            this->buffers.emplace(uniqueName, buff);
            this->sounds.emplace(uniqueName, sound);
        }

        void playAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).setBuffer(this->buffers.at(uniqueName));
            this->sounds.at(uniqueName).play();
        }

        void stopAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).stop();
        }

        void setVolumeAudio(std::string uniqueName, int vol) {
            this->sounds.at(uniqueName).setVolume((float)vol);
        }

        float getVolumeAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).getVolume();
        }

        void setPitchAudio(std::string uniqueName, float value) {
            this->sounds.at(uniqueName).setPitch(value);
        }

        float getPitchAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).getPitch();
        }

        void setPlayingOffsetAudio(std::string uniqueName, float offset) {
            this->sounds.at(uniqueName).setPlayingOffset(sf::seconds(offset));
        }

        void loopAudio(std::string uniqueName) {
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

        void playMusic(std::string uniqueName) {
            this->musics.at(uniqueName).play();
        }

        void stopMusic(std::string uniqueName) {
            this->musics.at(uniqueName).stop();
        }

        void setVolumeMusic(std::string uniqueName, int vol) {
            this->musics.at(uniqueName).setVolume((float)vol);
        }

        float getVolumeMusic(std::string uniqueName) {
            this->musics.at(uniqueName).getVolume();
        }

        void setPitchMusic(std::string uniqueName, float value) {
            this->musics.at(uniqueName).setPitch(value);
        }

        float getPitchMusic(std::string uniqueName) {
            this->musics.at(uniqueName).getPitch();
        }

        float setPlayingOffsetMusic(std::string uniqueName, float offset) {
            this->musics.at(uniqueName).setPlayingOffset(sf::seconds(offset));
        }

        void loopMusic(std::string uniqueName) {
            this->musics.at(uniqueName).setLoop(!this->musics.at(uniqueName).getLoop());
        }

        void startRecordingSound() {
            if (!sf::SoundBufferRecorder::isAvailable())
            {
                printf("Audio capture not available in system");
            }
            this->recorder.start();
            this->recording = true;
        }

        void pauseRecordingSound() {
            this->recorder.stop();
            this->recording = false;
        }

        void resumeRecordingSound() {
            if (!sf::SoundBufferRecorder::isAvailable())
            {
                printf("Audio capture not available in system");
            }
            this->recorder.start();
            this->recording = true;
        }

        void stopRecordingSound(std::string uniqueName) {
            this->recorder.stop();
            this->recording = false;
            const sf::SoundBuffer& buffer = recorder.getBuffer();
            this->sounds.emplace(uniqueName, buffer);
        }

        void changeRecordingState() {
            this->recording = !this->recording;
        }

        bool getRecordingState() {
            return this->recording;
        }

    };
};