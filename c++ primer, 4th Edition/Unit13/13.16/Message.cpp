#include <iostream>
#include <set>
#include <string>
#include "Folder.h"
#include "Message.h"

Message::Message(const std::string &str):content (str) { }

Message::Message(const Message &obj):content(obj.content), folders(obj.folders)
{
	put_Msg_in_Folders(folders);
}

Message& Message::operator=(const Message &obj)
{
	if (&obj != this)
	{
		remove_Msg_in_Folders();
		content = obj.content;
		folders = obj.folders;
		put_Msg_in_Folders(folders);
	}
	return *this;
}

void Message::put_Msg_in_Folders(const std::set<Folder*>& rhs)
{
	for (std::set<Folder*>::iterator it = rhs.begin(); it != rhs.end(); ++it)
	{
		//(*it)->addMsg(this);
	}
}

void Message::remove_Msg_in_Folders()
{
	for (std::set<Folder*>::iterator it = folders.begin(); it != folders.end(); ++it)
	{
		//(*it)->addMsg(this);
	}
}

Message::~Message()
{
	std::cout << 1;
	remove_Msg_in_Folders();
}

void Message::addFldr(Folder *pfdr)
{
	folders.insert(pfdr);
}

void Message::remFldr(Folder *pfdr)
{
	if(folders.find(pfdr) != folders.end())
	{
		std::set<Folder*>::iterator it = folders.find(pfdr);
		folders.erase(it);
	}
} 

void Message::save()
{
	std::cout << 1 << std::endl;
	std::cout << content << std::endl;
	std::cout << 1 << std::endl;
}

void Message::remove()
{
	
}
