#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "config.h"

struct Vector {
    float x, y;
};

struct Particle {
    struct Vector p;
    struct Vector v;
    struct Vector a;
    float m;
};

static struct Particle particles[NUM_PARTICLES];

/* Print the CSV header for the simulation data. */
void print_header() {
    int i;

    printf("t");
    for (i = 0; i < NUM_PARTICLES; i++)
        printf(",%d_p_x,%d_p_y", i, i);

    printf("\n");
}

float drand(    /* returns a random float between min and max */
    float min,
    float max
) {
    float rv = (float)rand() / RAND_MAX;
    return min + rv * (max - min);
}

/* Set up the initial conditions of all the particles. */
void randomize_particles() {
    int i;

    srand(time(NULL));

    particles[0].p.x = 0.0;
    particles[0].p.y = 0.0;
    particles[0].v.x = 0.0;
    particles[0].v.y = 0.0;
    particles[0].m = CENTER_M;

    for (i = 1; i < NUM_PARTICLES; i++) {
        particles[i].p.x = drand(INITIAL_MIN_P_X, INITIAL_MAX_P_X);
        particles[i].p.y = drand(INITIAL_MIN_P_Y, INITIAL_MAX_P_Y);
        particles[i].v.x = drand(INITIAL_MIN_V_X, INITIAL_MAX_V_X);
        particles[i].v.y = drand(INITIAL_MIN_V_Y, INITIAL_MAX_V_Y);
        particles[i].m = drand(MIN_M, MAX_M);
    }
}

int main(int argc, char **argv) {
    float t = 0.0;
    float d, dsq, dx, dy, F_g;
    float next_print_t = 0.0;
    int i, j;

    randomize_particles();

    print_header();

    while (t < T_FINAL) {
        for (i = 0; i < NUM_PARTICLES; i++) {
            particles[i].a.x = 0;
            particles[i].a.y = 0;

            for (j = 0; j < NUM_PARTICLES; j++) {
                /* Don't calculate this particle's gravitational influence
                   on itself. */
                if (i == j)
                    continue;

                dx = particles[j].p.x - particles[i].p.x;
                dy = particles[j].p.y - particles[i].p.y;
                dsq = pow(dx, 2) + pow(dy, 2);
                d = sqrt(dsq);

                /* Avoid dividing by zero. */
                if (dsq > 1E-3)
                    F_g = particles[i].m * particles[j].m / dsq;
                else
                    F_g = 0;

                particles[i].a.x += (F_g * dx / d) / particles[i].m;
                particles[i].a.y += (F_g * dy / d) / particles[i].m;
            }
        }

        /* Naive integration. */
        for (i = 0; i < NUM_PARTICLES; i++) {
            particles[i].v.x += particles[i].a.x * DT;
            particles[i].v.y += particles[i].a.y * DT;
            particles[i].p.x += particles[i].v.x * DT;
            particles[i].p.y += particles[i].v.y * DT;
        }

        if (t >= next_print_t) {
            /* Print a datapoint. */

            printf("%lf", t);

            for (i = 0; i < NUM_PARTICLES; i++)
                printf(",%lf,%lf", particles[i].p.x, particles[i].p.y);

            printf("\n");

            next_print_t += (T_FINAL / POINTS);
        }

        t += DT;
    }

    return 0;
}
