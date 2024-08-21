#include <cstdio>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <cmath>
#include <array>

float frand() {
    
    constexpr const float v = 1.0f / RAND_MAX * 2;
    return (float)std::rand() * v - 1;
}

struct Star {
    std::array<float, 50> px;
    std::array<float, 50> py;
    std::array<float, 50> pz;
    std::array<float, 50> vx;
    std::array<float, 50> vy;
    std::array<float, 50> vz;
    std::array<float, 50> mass;
};

Star stars;

void init() {
    for (int i = 0; i < 48; i++) {
        stars.px[i] = frand();
        stars.py[i] = frand();
        stars.pz[i] = frand();
        stars.vx[i] = frand();
        stars.vy[i] = frand();
        stars.vz[i] = frand();
        stars.mass[i] = frand() + 1;
    }
}

float G = 0.001;
float eps = 0.001;
float dt = 0.01;

void step() {
    size_t N = stars.px.size();
    const float eps2 = eps * eps;
    float tmp1, tmp2, tmp3;

    for (size_t i = 0; i < N; i++) {
        float px = stars.px[i], py = stars.py[i], pz = stars.pz[i];
        tmp1 = tmp2 = tmp3 = 0;
        for (size_t j = 0; j < N; j++) {
            float dx = stars.px[j] - px;
            float dy = stars.py[j] - py;
            float dz = stars.pz[j] - pz;
            float d2 = dx * dx + dy * dy + dz * dz + eps2;
            d2 *= std::sqrt(d2);
            tmp1 += dx * stars.mass[j] * G * dt / d2;
            tmp2 += dy * stars.mass[j] * G * dt / d2;
            tmp3 += dz * stars.mass[j] * G * dt / d2;
        }

        stars.vx[i] += tmp1;
        stars.vy[i] += tmp2;
        stars.vz[i] += tmp3;
    }

    #pragma omp simd
    for (size_t i = 0; i < N; i++) {
        stars.px[i] += stars.vx[i] * dt;
        stars.py[i] += stars.vy[i] * dt;
        stars.pz[i] += stars.vz[i] * dt;
    }
}

float calc() {
    float energy = 0;
    float half_G = G * 0.5;
    size_t N = stars.px.size();
    const float eps2 = eps * eps;

    #pragma omp simd
    for (size_t i = 0; i < N; i++) {
        float px = stars.px[i], py = stars.py[i], pz = stars.pz[i];
        float v2 = stars.vx[i] * stars.vx[i] + stars.vy[i] * stars.vy[i] + stars.vz[i] * stars.vz[i];
        energy += stars.mass[i] * v2 * 0.5;
        float v = stars.mass[i] * half_G;

        for (size_t j = 0; j < N; j++) {
            float dx = stars.px[j] - px;
            float dy = stars.py[j] - py;
            float dz = stars.pz[j] - pz;
            float d2 = dx * dx + dy * dy + dz * dz + eps2;
            energy -= stars.mass[j] * v / std::sqrt(d2) ;
        }
    }
    return energy;
}

template <class Func>
long benchmark(Func const &func) {
    auto t0 = std::chrono::steady_clock::now();
    func();
    auto t1 = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);
    return dt.count();
}

int main() {
    init();
    printf("Initial energy: %f\n", calc());
    auto dt = benchmark([&] {
        for (int i = 0; i < 100000; i++)
            step();
    });
    printf("Final energy: %f\n", calc());
    printf("Time elapsed: %ld ms\n", dt);
    return 0;
}
