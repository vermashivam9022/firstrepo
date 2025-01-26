#include<iostream>
#include<string>
using namespace std;

char max_char(string word)
{
    int maximum=0;
    char l='a';
    int letter[26]={0};
    for (int i = 0; i < word.length(); i++) {
        char ch=word[i];
        letter[ch-'a']++;

       if (letter[ch-'a'] > maximum) {
            maximum = letter[ch-'a'];
            l= ch;  // Update the most frequent character
        }
    }
    return l;

}

int main() {
    string word;
    cout << "Enter the word: ";
    cin >> word;
    cout << "The most frequent character is: " << max_char(word) << endl;
    return 0;
}