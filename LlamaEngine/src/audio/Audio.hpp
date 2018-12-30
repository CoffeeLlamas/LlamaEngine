#pragma once
#include <AL/alc.h>
#include "AudioData.hpp"
namespace engine {
	namespace audio {

		class Audio {
		public:
			static ALCdevice* device;
			static ALCcontext* context;
			unsigned int id;
			AudioData* source;
			static void init();
			static void deinit();
			Audio(AudioData* data);
			~Audio();
		};

	}
}