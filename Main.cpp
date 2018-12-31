#include <iostream>
#include <Math.h>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"
using namespace std;
using namespace animation;

int main(int argc, char *argv[])
{
	Screen screen;

	srand(time(NULL));

	if (screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}

	Swarm swarm;

	while (true) {
		// Update particles
		// Draw particles
		// Check for messages/events
		int elapsed = SDL_GetTicks();

		//screen.clear();
		swarm.update(elapsed);

		unsigned char green = (1 + sin(elapsed * 0.001)) * 128;
		unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

		const Particle *const pParticles = swarm.getParticle();

		for (int i = 0; i < Swarm::N_PARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		/*
		

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, blue, green, red);
			}
		}

		screen.setPixel(400, 300, 255, 255, 255);
		*/
		// Draw the screen
		screen.update();
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}