#pragma once
#include "AudioData.hpp"
namespace engine {
	namespace audio {

		class AudioLoader {
		public:
			static AudioData* loadWAVFile(const char* file);
			static AudioData* loadWAV(char* data);
			static unsigned int getFormat(AudioData* data);
		};

	}
}