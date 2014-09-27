#ifndef __FOLDER_H__
#define __FOLDER_H__


#include <set>

class Message;
class Folder
{
public:
	void addMsg(Message* pMessage);
	void remMs(Message*);
private:
	std::set<Message*> messages;
};

#endif