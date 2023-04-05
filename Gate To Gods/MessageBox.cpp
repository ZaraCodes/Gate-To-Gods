#include "MessageBox.h"

MessageBox::MessageBox()
{
	maxAmount = 5;
	messages = new std::string[maxAmount];
	for (int i = 0; i < maxAmount; i++) {
		messages[0] = std::string();
	}
	messageCount = 0;
}

MessageBox::~MessageBox()
{
	if (messages != nullptr) {
		delete[] messages;
		messages = nullptr;
	}
}

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

std::string MessageBox::GetMessage(int index)
{
	if (index < messages->length()) {
		return messages[index];
	}
	return std::string();
}
