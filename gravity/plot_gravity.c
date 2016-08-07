#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../graphics/graphics.h"
#include "config.h"

int main() {
    char buf[4096];
    char* token;
    int particles = 0, i, x, y;
    struct image* img = new_image(IMG_WIDTH, IMG_HEIGHT);

    /* Parse the CSV header and find out how many particles there are. */
    fgets(buf, sizeof(buf), stdin);
    token = strtok(buf, ",");
    while (token != NULL) {
        particles++;
        token = strtok(NULL, ",");
    }
    particles = (particles - 1) / 2;

    write_y4m_header(img, stdout);

    while(1) {
        fill_image(img, BACKGROUND_COLOR);

        fgets(buf, sizeof(buf), stdin);
        if (feof(stdin))
            break;

        token = strtok(buf, ",");

        for (i = 0; i < particles; i++) {
            token = strtok(NULL, ",");
            x = (IMG_WIDTH / 2);
            x += (int)(atof(token) * (((float)IMG_WIDTH / 2) / MAX_POS) + 0.5);
            token = strtok(NULL, ",");
            y = (IMG_HEIGHT / 2);
            y += (int)(atof(token) * (((float)IMG_HEIGHT / 2) / MAX_POS) + 0.5);
            set_pixel(img, STAR_COLOR, x, y);
        }

        write_y4m_frame(img, stdout);
    }

    free_image(img);
    return 0;
}
