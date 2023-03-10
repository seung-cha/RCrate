#include "File.h"
#include <iostream>


namespace GCR
{

	File::File()
	{
		artistName.clear();
		songName.clear();
	}
	void File::Clear()
	{
		offset = 0;
		artistName.clear();
		songName.clear();
	}

	void File::SetArtistName(std::string  name)
	{
		artistName = name;
	}


	std::string File::GetArtistName()
	{
		 return artistName;
	}


	void File::SetSongName(std::string name)
	{
		songName = name;
	}


	std::string File::GetSongName()
	{
		return songName;
	}

	void File::ClearSongName()
	{
		songName.clear();
	}

	void File::ClearArtistName()
	{
		artistName.clear();
	}

}