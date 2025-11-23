#pragma once
#include <vector>
#include <portaudio.h>

class AudioCapture {
public:
    AudioCapture(int sampleRate = 44100, int framesPerBuffer = 1024);
    ~AudioCapture();

    bool start();
    bool stop();
    const std::vector<float>& getBuffer() const;

private:
    static int audioCallback(const void* input, void* output,
                             unsigned long frameCount,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void* userData);

    std::vector<float> buffer;
    PaStream* stream;
    int framesPerBuffer;
};
