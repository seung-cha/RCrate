#ifndef GCR_FILE_H
#define GCR_FILE_H

#include <string>
#include <stdlib.h>

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



	private:
		int offset = 0;
		std::string artistName;
		std::string songName;





	};


}



#endif 
