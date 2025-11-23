cmake_minimum_required(VERSION 3.15)
project(MusicVisualizer)

set(CMAKE_CXX_STANDARD 17)

find_package(portaudio CONFIG REQUIRED)
find_package(FFTW3 CONFIG REQUIRED)
find_package(SFML COMPONENTS graphics window system REQUIRED)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(FFTW3 REQUIRED)
find_package(PortAudio REQUIRED)

add_executable(MusicVisualizer
    src/main.cpp
    src/AudioCapture.cpp
    src/FFTProcessor.cpp
    src/Visualizer.cpp
)

target_include_directories(MusicVisualizer PRIVATE
    ${FFTW3_INCLUDE_DIRS}
    ${PORTAUDIO_INCLUDE_DIRS}
)

target_link_libraries(MusicVisualizer
    sfml-graphics
    sfml-window
    sfml-systems
    ${FFTW3_LIBRARIES}
    ${PORTAUDIO_LIBRARIES}
    target_link_libraries(MusicVisualizer PRIVATE
    portaudio
    FFTW3::fftw3
    sfml-graphics
    sfml-window
    sfml-system
)

)
