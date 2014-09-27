#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <set>
#include "Folder.h"

class Message
{
public:
	explicit Message(const std::string &str= "");
	Message(const Message &obj);
	Message& operator=(const Message &);
	void save();
	void remove();
	~Message();

private:
	void put_Msg_in_Folders(const std::set<Folder*> &);
	void remove_Msg_in_Folders();
	void addFldr(Folder*);
	void remFldr(Folder*);
	std::string content;
	std::set<Folder*> folders;
};

#endif