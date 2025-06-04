#include <fftw3.h>
#include <omp.h>
#include <vector>

void parallelFFT(std::vector<double>& input, std::vector<double>& output, int n) {
    fftw_complex* in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * n);
    fftw_complex* out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * n);
    fftw_plan plan = fftw_plan_dft_1d(n, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

#pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        in[i][0] = input[i]; in[i][1] = 0;
        fftw_execute(plan);
        output[i] = out[i][0];
    }

    fftw_destroy_plan(plan);
    fftw_free(in); fftw_free(out);
}

int main() {
    int n = 1000;
    std::vector<double> input(n, 1.0), output(n);
    parallelFFT(input, output, n);
    std::cout << "FFT computed successfully\n";
    return 0;
}