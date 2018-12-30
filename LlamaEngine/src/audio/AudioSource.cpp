#include "AudioSource.hpp"
#include <AL/al.h>
namespace engine {
	namespace audio {

		AudioSource::AudioSource() {
			alGenSources(1, &this->id);
		}

		AudioSource::~AudioSource() {
			alDeleteSources(1, &this->id);
		}

		void AudioSource::play(Audio* audio) {
			alSourcei(this->id, AL_BUFFER, audio->id);
			alSourcePlay(this->id);
		}
	}
}