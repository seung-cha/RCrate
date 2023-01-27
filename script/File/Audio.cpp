#include "Audio.h"


namespace GCR
{
	irrklang::ISoundEngine*  Audio::engine = NULL;


	Audio::Audio(const char* filePath)
	{
		if (engine == NULL)
			engine = irrklang::createIrrKlangDevice();


		int size = strlen(filePath);
		path = filePath;



		std::cout << path << std::endl;


		audio = engine->play2D(path.c_str(), false, true);



		if (audio == NULL)
		{
			std::cout << "An error occurred while importing a new audio!" << std::endl;
			return;
		}

			lengthMillis = audio->getPlayLength();
			isPaused = true;
		

	}


	void Audio::Play()
	{
		if (autoReset && IsDone())
		{
			audio->drop();
			audio = engine->play2D(path.c_str(), false, true);
			audio->setVolume(volume);
		}


		isPaused = false;
		audio->setIsPaused(false);
	}

	void Audio::Pause()
	{
		isPaused = true;
		audio->setIsPaused(true);
	}


	void Audio::ToStart()
	{
		Pause();
		audio->setPlayPosition(0);
	}

	void Audio::Reset()
	{
		audio->drop();
		audio = engine->play2D(path.c_str(), false, true);
		audio->setVolume(volume);
		isPaused = true;

	}

	bool Audio::IsPaused()
	{
		return isPaused;
	}

	bool Audio::IsDone()
	{
		return audio->isFinished();
	}

	int Audio::LengthMillis()
	{
		return audio->getPlayLength();
	}

	int Audio::CurrentMillis()
	{
		return audio->getPlayPosition();
	}

	float Audio::ToSeconds(unsigned int millisecond)
	{
		return millisecond / (float)1000;
	}
	float Audio::LengthSeconds()
	{
		return audio->getPlayLength() / (float)1000;

	}

	float Audio::CurrentSeconds()
	{
		return audio->getPlayPosition() / (float)1000;
	}


	void Audio::SetCurrent(int position)
	{
		audio->setPlayPosition(position);
	}

	void Audio::SetVolume(float value)
	{
		volume = value;
		audio->setVolume(value);
	}


	void Audio::AutoReset(bool value)
	{
		autoReset = value;
	}


	float Audio::GetVolume()
	{
		return volume;
	}


	bool Audio::IsASafeObject()
	{
		return audio;
	}
}