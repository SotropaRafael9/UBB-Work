#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

class Encoder
{
public:	
	virtual string encode(string msg) = 0;

};

class AlienEncoder : public Encoder
{
	string header;
public:
	string encode(string msg) override
	{
		return header + " " + msg;
	}
};

class MorseEncoder : public Encoder
{
public:
	string encode(string msg) override
	{
		string cnt = " ";
		for (char c : msg)
			cnt += '.';
		return cnt;

	}
};

class Mixer : public Encoder
{
private:
	Encoder* e1;
	Encoder* e2;
public :
	string encode(string msg) override
	{
		int cnt = msg.length();
		int i = 0;
		string result = "";
		string enc1mes = e1->encode(msg);
		string enc2mes = e2->encode(msg);
		while (i < cnt)
		{
			if (i % 2 == 0)
			{
				result = result + enc1mes.at(i);

			}
			else {
				result = result + enc2mes.at(i);
			}
		}
		return result;

	}
};

class Communication
{
private:
	vector <Encoder*> messages;
public:
	void addMessages(Encoder* msg)
	{
		messages.push_back(msg);
	}

	void communicate()
	{
		// Sort the messages vector alphabetically based on the encoded messages
		sort(messages.begin(), messages.end(), [](Encoder* a, Encoder* b) {
			return a->encode("") < b->encode("");
			});

		// Encode each message in the sorted vector
		for (Encoder* message : messages)
		{
			string encodedMessage = message->encode("");
			// You may modify the encode function in each Encoder subclass to accept the actual message to encode
			// For simplicity, an empty string is passed as a placeholder in this example
			// Modify the encode function signature in each Encoder subclass to: string encode(const string& msg)
			// and pass the actual message to encode as an argument

			// Print the encoded message
			cout << encodedMessage << endl;
		}

	}
};
int main()
{
	MorseEncoder* morseecoder = new MorseEncoder();

	Communication comm1;
	comm1.addMessages(morseecoder);
	comm1.addMessages(new MorseEncoder());
	comm1.addMessages(new AlienEncoder());

	comm1.communicate();

	Mixer* mixer = new Mixer();
	mixer->e1 = new AlienEncoder();
	mixer->e2 = new MorseEncoder();



	
}
