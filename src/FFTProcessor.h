#pragma once
#include <vector>
#include <fftw3.h>

class FFTProcessor {
public:
    FFTProcessor(size_t size);
    ~FFTProcessor();

    void compute(const std::vector<float>& input);
    const std::vector<double>& getMagnitudes() const;

private:
    size_t size;
    std::vector<double> magnitudes;
    fftw_plan plan;
    double* in;
    fftw_complex* out;
};
