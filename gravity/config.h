/* How long to simulate. */
#define T_FINAL 500.0

/* Timestep. */
#define DT 0.1

/* How many datapoints to write. Each datapoint results in a video frame.
   Video runs at 30 FPS. */
#define POINTS 2000

/* How many particles to simulate. */
#define NUM_PARTICLES 64

/* Randomized initial conditions for the particles. */
#define INITIAL_MIN_P_X -20.0
#define INITIAL_MAX_P_X 20.0
#define INITIAL_MIN_P_Y -20.0
#define INITIAL_MAX_P_Y 20.0

#define INITIAL_MIN_V_X -4.0
#define INITIAL_MAX_V_X 4.0
#define INITIAL_MIN_V_Y -4.0
#define INITIAL_MAX_V_Y 4.0

/* Randomized masses for particles. */
#define MIN_M 1E-10
#define MAX_M 1E-9

/* First particle is special. It is set at the center of the universe with
   no velocity. Set its mass here. */
#define CENTER_M 1E2

/* Screen size. */
#define IMG_WIDTH 512
#define IMG_HEIGHT 512

/* Center of the screen is position (0,0). MAX_POS defines the coordinate of
   the right/left/top/bottom edges. */
#define MAX_POS 50.0

/* Colors! */
#define STAR_COLOR ((struct color){255, 255, 255})
#define BACKGROUND_COLOR ((struct color){0, 0, 0})
