#ifndef GCR_FILE_H
#define GCR_FILE_H

#include <string>
#include <stdlib.h>
#include <vector>


namespace GCR
{
	

	class File
	{
	public:

		File();

		/// <summary>
		/// Reset all variables to their initial value
		/// </summary>
		void Clear();

		void SetArtistName(std::string name);
		void ClearArtistName();
		std::string GetArtistName();


		void SetSongName(std::string  name);
		void ClearSongName();
		std::string GetSongName();

		float GetBPM();
		float GetSPB();

		void SetBPM(float newBPM);




	private:
		float bpm = 0;
		float spb = 0;
		unsigned int offset;
		std::string artistName;
		std::string songName;






	};


}



#endif 
