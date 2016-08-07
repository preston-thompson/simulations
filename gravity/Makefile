all: gravity plot_gravity

gravity: gravity.c
	cc -o gravity gravity.c -lm

plot_gravity: plot_gravity.c
	cc -o plot_gravity plot_gravity.c ../graphics/graphics.c

clean:
	rm -f gravity
	rm -f plot_gravity
