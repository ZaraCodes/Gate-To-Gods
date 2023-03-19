#pragma once
#include <string>
class MessageBox
{
public:
	std::string* messages;
	int messageCount;
	int maxAmount;

	MessageBox();
	void InsertNewMessage(std::string message);
	std::string GetMessage(int index);
};

