#pragma once
#include "AudioData.hpp"
namespace engine {
	namespace audio {

		class AudioLoader {
		public:
			static AudioData* loadWAVFile(const char* file);
			static AudioData* loadWAV(char* data);
		}; ////////////////////// TO DO: USE WEBSITE TO LOOK AT FORMAT AND THEN BIND THE DAMMN BUFFER. ALSO USE THE NEW AUDIODATA STRUCT THER PLEASE

	}
}