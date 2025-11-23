#include "AudioCapture.h"
#include "FFTProcessor.h"
#include "Visualizer.h"
#include <thread>
#include <chrono>

int main() {
    AudioCapture audio;
    FFTProcessor fft(1024);
    Visualizer vis;

    audio.start();

    while (true) {
        fft.compute(audio.getBuffer());
        vis.render(fft.getMagnitudes());
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60 FPS
    }

    audio.stop();
    return 0;
}
