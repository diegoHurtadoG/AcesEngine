#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>


namespace acesengine {
    /// Defines a sound player to well... play sounds
    /**
    * One sound player can contain multiple sounds and store them with a string unique key
    * If the unique key is repeated, the first one will be played, recorder is broken
    */
    class SoundPlayer {
        /// <summary>
        /// Contains every sound source
        /// </summary>
        std::map<std::string, sf::Sound> sounds;

        /// <summary>
        /// Store the sound buffers
        /// </summary>
        std::map<std::string, sf::SoundBuffer> buffers;

        /// <summary>
        /// Store the music buffers
        /// </summary>
        std::map<std::string, sf::Music> musics;

        /// <summary>
        /// Records sound from mic
        /// </summary>
        sf::SoundBufferRecorder recorder;

        /// <summary>
        /// True if recording, false otherwise
        /// </summary>
        bool recording = false;

    public:
        /// Default constructor
        /**
        *   Doesnt need to initialize anything
        */
        SoundPlayer();

    public:
        // Audio Methods
        /// Loads an audio to a buffer
        /**
        * @param uniqueName string defines the key of a sound
        * @param audioPath string tell where is the audio downloaded
        */
        void loadAudio(std::string uniqueName, std::string audioPath);

        /// Plays an audio buffer
        /**
        * @param uniqueName string to identify the audio
        */
        void playAudio(std::string uniqueName);

        /// Stops an audio buffer
        /**
        * @param uniqueName string to identify the audio
        */
        void stopAudio(std::string uniqueName);

        /// Set the volume of an audio buffer
        /**
        * @param uniqueName string to identify the audio
        * @param vol int from 0 to 100, where 100 is the original volume
        */
        void setVolumeAudio(std::string uniqueName, int vol);

        /// Gets volume of an audio buffer
        /**
        * @param uniqueName string to identify the audio
        * @returns float representing the actual volume
        */
        float getVolumeAudio(std::string uniqueName);

        /// Set the pitch of an audio buffer
        /**
        * @param uniqueName string to identify the audio
        * @param value float representing the pitch, 1 is the default
        */
        void setPitchAudio(std::string uniqueName, float value);

        /// Gets pitch of an audio buffer
        /**
        * @param uniqueName string to identify the audio
        * @returns float representing the actual pitch
        */
        float getPitchAudio(std::string uniqueName);

        /// Set the offset of an audio buffer
        /**
        * @param uniqueName string to identify the audio
        * @param value float representing the offset measured in seconds
        */
        void setPlayingOffsetAudio(std::string uniqueName, float offset);

        /// Set if the audio buffer is meant to loop
        /**
        * @param uniqueName string to identify the audio
        */
        void loopAudio(std::string uniqueName);


        // Music methods

        // This one throwing error with assimp (?)
        /*
        void loadMusic(std::string uniqueName, std::string musicPath);
        */

        /// Plays a music buffer
        /**
        * @param uniqueName string to identify the music
        */
        void playMusic(std::string uniqueName);

        /// Stops a music buffer
        /**
        * @param uniqueName string to identify the music
        */
        void stopMusic(std::string uniqueName);

        /// Set the volume of a music buffer
        /**
        * @param uniqueName string to identify the music
        * @param vol int from 0 to 100, where 100 is the original volume
        */
        void setVolumeMusic(std::string uniqueName, int vol);

        /// Gets volume of a music buffer
        /**
        * @param uniqueName string to identify the music
        * @returns float representing the actual volume
        */
        float getVolumeMusic(std::string uniqueName);

        /// Set the pitch of a music buffer
        /**
        * @param uniqueName string to identify the music
        * @param value float representing the pitch, 1 is the default
        */
        void setPitchMusic(std::string uniqueName, float value);

        /// Gets pitch of a music buffer
        /**
        * @param uniqueName string to identify the music
        * @returns float representing the actual pitch
        */
        float getPitchMusic(std::string uniqueName);

        /// Set the offset of a music buffer
        /**
        * @param uniqueName string to identify the music
        * @param value float representing the offset measured in seconds
        */
        float setPlayingOffsetMusic(std::string uniqueName, float offset);

        /// Set if the music buffer is meant to loop
        /**
        * @param uniqueName string to identify the music
        */
        void loopMusic(std::string uniqueName);

        /// Starts the recording
        void startRecordingSound();

        /// Pauses the recording, can resume
        void pauseRecordingSound();

        /// Resumes the paused recording
        void resumeRecordingSound();

        /// Finishes the recording
        /**
        * @param uniqueName string defines the name under the record will be saved in a buffer to play
        */
        void stopRecordingSound(std::string uniqueName);

        /// Switches the inner state of the recorder
        void changeRecordingState();

        /// Get the inner recording state
        /**
        * @returns bool representing if the recorder is active or not
        */
        bool getRecordingState();

    };
};