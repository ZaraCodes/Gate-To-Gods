#include "MessageBox.h"

/// <summary>Initializes the messagebox</summary>
MessageBox::MessageBox()
{
	maxAmount = 5;
	messages = new std::string[maxAmount];
	for (int i = 0; i < maxAmount; i++) {
		messages[0] = std::string();
	}
	messageCount = 0;
}

/// <summary>Destructs the class</summary>
MessageBox::~MessageBox()
{
	if (messages != nullptr) {
		delete[] messages;
		messages = nullptr;
	}
}

/// <summary>Inserts a new message into the messagebox</summary>
/// <param name="message"></param>
void MessageBox::InsertNewMessage(std::string message)
{
	if (messageCount < maxAmount) {
		messages[messageCount] = message;
		messageCount++;
	}
	else {
		for (int i = 0; i < messageCount - 1; i++) {
			messages[i] = messages[i + 1];
		}
		messages[messageCount - 1] = message;
	}
}

/// <summary>Searches for a message at the given index</summary>
/// <param name="index">message index</param>
/// <returns>a message</returns>
std::string MessageBox::GetMessage(int index)
{
	if (index < messages->length()) {
		return messages[index];
	}
	return std::string();
}
