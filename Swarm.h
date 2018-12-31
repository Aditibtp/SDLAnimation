#pragma once
#pragma once
#ifndef SWARM_H_
#define SWARM_H_

#include <SDL.h>
#include "Particle.h"

namespace animation {

	class Swarm {
		private:
			Particle * m_particles;
			int lastTime;
		public:
			const static int N_PARTICLES = 5000;

			const Particle * const getParticle() { return m_particles; }

			void update(int elapsed);
			Swarm();
			virtual ~Swarm();
	};

}

#endif