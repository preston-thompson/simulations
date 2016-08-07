# gravity

Naive two dimensional gravity simulation of particles. Uses the Euler method for integration.

## Building

Run `make all`

## Usage

The `gravity` program generates CSV data from the simulation. The `plot_gravity` program uses my graphics library to generate a video of the simulation.

```
./gravity | ./plot_gravity > output.avi
```
