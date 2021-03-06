#pragma once
#include "SongInfo.h"
class CPlaylist
{
public:
	enum Type			//播放列表格式
	{
		PL_PLAYLIST,	//MusicPlayer2播放列表
		PL_M3U,			//m3u播放列表
		PL_M3U8			//m3u8播放列表
	};

    CPlaylist();
    ~CPlaylist();
    void LoadFromFile(const wstring& file_path);
    void SaveToFile(const wstring& file_path, Type type = PL_PLAYLIST) const;
    vector<SongInfo> GetPlaylist() const;
    void AddFiles(const vector<wstring>& files);
    void AddFiles(const vector<SongInfo>& files);
    void FromSongList(const vector<SongInfo>& song_list);
    void ToSongList(vector<SongInfo>& song_list);
    bool IsFileInPlaylist(const SongInfo& file);
    void RemoveFile(const wstring& file);

private:
    vector<SongInfo> m_playlist;
};

