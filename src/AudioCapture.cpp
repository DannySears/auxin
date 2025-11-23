#include "AudioCapture.h"
#include <iostream>

AudioCapture::AudioCapture(int sampleRate, int framesPerBuffer)
    : stream(nullptr), framesPerBuffer(framesPerBuffer) {
    Pa_Initialize();
    buffer.resize(framesPerBuffer);
}

AudioCapture::~AudioCapture() {
    stop();
    Pa_Terminate();
}

bool AudioCapture::start() {
    PaError err = Pa_OpenDefaultStream(&stream, 1, 0, paFloat32,
                                       44100, framesPerBuffer, audioCallback, this);
    if (err != paNoError) {
        std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << "\n";
        return false;
    }
    Pa_StartStream(stream);
    return true;
}

bool AudioCapture::stop() {
    if (stream) {
        Pa_StopStream(stream);
        Pa_CloseStream(stream);
        stream = nullptr;
    }
    return true;
}

int AudioCapture::audioCallback(const void* input, void*, unsigned long frameCount,
                                const PaStreamCallbackTimeInfo*, PaStreamCallbackFlags,
                                void* userData) {
    auto* self = static_cast<AudioCapture*>(userData);
    const float* in = static_cast<const float*>(input);
    if (in) {
        std::copy(in, in + frameCount, self->buffer.begin());
    }
    return paContinue;
}

const std::vector<float>& AudioCapture::getBuffer() const {
    return buffer;
}
