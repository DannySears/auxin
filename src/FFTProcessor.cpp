#include "FFTProcessor.h"
#include <cmath>

FFTProcessor::FFTProcessor(size_t size) : size(size) {
    in = (double*) fftw_malloc(sizeof(double) * size);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * (size / 2 + 1));
    plan = fftw_plan_dft_r2c_1d(size, in, out, FFTW_MEASURE);
    magnitudes.resize(size / 2);
}

FFTProcessor::~FFTProcessor() {
    fftw_destroy_plan(plan);
    fftw_free(in);
    fftw_free(out);
}

void FFTProcessor::compute(const std::vector<float>& input) {
    for (size_t i = 0; i < size; i++)
        in[i] = i < input.size() ? input[i] : 0.0;

    fftw_execute(plan);

    for (size_t i = 0; i < size / 2; i++)
        magnitudes[i] = std::sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
}

const std::vector<double>& FFTProcessor::getMagnitudes() const {
    return magnitudes;
}
