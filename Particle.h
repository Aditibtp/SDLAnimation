#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SDL.h>

namespace animation {

	struct Particle {
		double m_x;
		double m_y;
		Particle();
		void update(int interval);
		
	private:
		double m_speed;
		double m_direction;

	private:
		void init();
	};
}

#endif