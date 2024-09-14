#include <math.h>
#include <stdio.h>

int main(void) {
    float alpha = 0.0;
    printf("Enter alpha: ");
    scanf("%f", &alpha);

    const float z1 = 2 * powf(sinf(3 * M_PI - 2 * alpha) * cosf(5 * M_PI + 2 * alpha), 2);
    const float z2 = 1.0f / 4 - 1.0f / 4 * sinf(5.0f / 2 * M_PI - 8 * alpha);

    printf("z1: %f\nz2: %f\n", z1, z2);

    return 0;
}
