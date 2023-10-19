#include <iostream>

// Facade design pattern
//
// The Facade design pattern is a structural design pattern that provides a simplified 
// interface to a complex system of classes, libraries, or APIs. 
// It's used to hide the complexities of the system and provide a unified interface 
// for the client code. The facade acts as a single entry point to access the underlying 
// subsystems.
//
// Example
// Let's consider a multimedia system that involves multiple subsystems, 
// such as video playback, audio playback, and subtitles. These subsystems have their 
// own complex interactions and initialization. We'll create a Facade to simplify the 
// client's interaction with the multimedia system.

// Video Player Subsystem
class VideoPlayer 
{
public:
    void initialize() 
    {
        std::cout << "Video Player initialized" << std::endl;
    }

    void playVideo(const std::string& video) 
    {
        std::cout << "Playing video: " << video << std::endl;
    }
};

// Audio Player Subsystem
class AudioPlayer 
{
public:
    void initialize() 
    {
        std::cout << "Audio Player initialized" << std::endl;
    }

    void playAudio(const std::string& audio) 
    {
        std::cout << "Playing audio: " << audio << std::endl;
    }
};

// Subtitles Subsystem
class Subtitles 
{
public:
    void initialize() 
    {
        std::cout << "Subtitles initialized" << std::endl;
    }

    void displaySubtitles(const std::string& subtitle) 
    {
        std::cout << "Displaying subtitles: " << subtitle << std::endl;
    }
};

// Multimedia Facade
class MultimediaFacade 
{
private:
    VideoPlayer videoPlayer;
    AudioPlayer audioPlayer;
    Subtitles subtitles;

public:
    void initializeSystem() 
    {
        videoPlayer.initialize();
        audioPlayer.initialize();
        subtitles.initialize();
    }

    void playMultimedia(const std::string& video, const std::string& audio, const std::string& subtitle) 
    {
        videoPlayer.playVideo(video);
        audioPlayer.playAudio(audio);
        subtitles.displaySubtitles(subtitle);
    }
};

int main() 
{
    MultimediaFacade multimedia;
    multimedia.initializeSystem();
    multimedia.playMultimedia("Movie.mp4", "Soundtrack.mp3", "English Subtitles");

    return 0;
}