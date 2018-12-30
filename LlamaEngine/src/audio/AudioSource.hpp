#pragma once
#include "Audio.hpp"
namespace engine {
	namespace audio {

		class AudioSource {
		public:
			unsigned int id;
			AudioSource();
			~AudioSource();
			void play(Audio* audio);
		};

	}
}