/////////////////////////////////////////////////////////
// Author:		Rob Zimmerman
// Description:	This header file implements a class that
//	will manage a single MP3 file. Simply load the file,
//	the start playing it!
//	
//	Usage: Feel free to modify this file however you like. 
//		Drop me a line at rzimmerm@23rdhour.com if you 
//		use this in any way just so I can see what it's 
//		being used for. No charge of course ;)
/////////////////////////////////////////////////////////

#ifndef _MP3_USING_MCI
#define _MP3_USING_MCI

#include <string>
#include <windows.h>
#include <mmsystem.h>
class CMP3_MCI
{
public:
	CMP3_MCI(){m_bPaused = false;}
	~CMP3_MCI(){Unload();}

	inline void Load(char *szFileName)
	{
		m_szFileName = szFileName;
		Load();
	}

	inline void Load(std::string szFileName)
	{
		m_szFileName = szFileName;
		Load();
	}

	inline void Play()
	{
		std::string szCommand = "play " + GetFileName() + " from 0";
		mciSendString(szCommand.c_str(), NULL, 0, 0);
	}

	inline void Stop()
	{
		std::string szCommand = "stop " + GetFileName();
		mciSendString(szCommand.c_str(), NULL, 0, 0);
	}

	inline void Pause()
	{
		std::string szCommand;
		if(IsPaused())
		{
			szCommand = "resume " + GetFileName();
			mciSendString(szCommand.c_str(), NULL, 0, 0);
			SetPaused(false);
		}
		else
		{
			szCommand = "pause " + GetFileName();
			mciSendString(szCommand.c_str(), NULL, 0, 0);		
			SetPaused(true);
		}
	}

	inline void Unload()
	{
		std::string szCommand = "close" + GetFileName();
		Stop();
		mciSendString(szCommand.c_str(), NULL, 0, 0);
	}

	//Accessor's for private members.
	inline std::string GetFileName()
	{return m_szFileName;}

	inline bool IsPaused()
	{return m_bPaused;}

	inline void SetPaused(bool bPaused)
	{m_bPaused = bPaused;}
private:
	inline void Load()
	{
		std::string szCommand = "open \"" + GetFileName() + "\" type mpegvideo alias " + GetFileName();		
		mciSendString(szCommand.c_str(), NULL, 0, 0);
	}

	std::string m_szFileName;
	bool m_bPaused;
};
#endif