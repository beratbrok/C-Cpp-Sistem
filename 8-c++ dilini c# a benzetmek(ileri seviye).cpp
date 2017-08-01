#include<iostream>
#include<string>
using namespace std;

class Console {
private:static string ifade2;

public:  

	static void WriteLine(string ifade) {

		cout << ifade << endl;
	}
	static void Write(string ifade) {

		cout << ifade;
	}

	static string ReadLine(string ifade2) {

		return ifade2;
	}

};
class Convert {
public:
	static int toInt32(string deger) {	// 1234
		int sayi = 0;
		if (deger[0] != '-') {
			for (int i = 0; i < deger.length(); i++) {
				sayi = sayi + ((int)(deger[i])-48)*pow(10, deger.length() - 1 - i);
			}
			return sayi;
		}
		else if (deger[0] == '-') {
			for (int i = 1; i < deger.length(); i++) {
				sayi = sayi + ((int)(deger[i]) - 48) * pow(10, deger.length() - 1-i);
			}
			return -sayi;
		}
		else { cout << "Tip donusturme hatasi"; 
		return 0;
		}
	}
};

int main() {
	
	Console::WriteLine("merhaba");
	string isim = Console::ReadLine("osman");
	Console::WriteLine(isim);

	int sayi = Convert::toInt32(Console::ReadLine("-123"));
	cout << sayi;

	getchar();
	return 0;
}