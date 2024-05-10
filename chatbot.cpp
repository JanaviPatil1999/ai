#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define possible user greetings
const vector<string> GREETINGS = {"hello", "hi", "hey"};

// Define possible queries and corresponding responses
const vector<pair<string, string>> RESPONSES = {
    {"order status", "Your order is currently being processed."},
    {"delivery time", "Your order will be delivered within 2-3 business days."},
    {"product information", "Our product is of high quality and comes with a warranty."},
    {"contact information", "You can reach our customer service at support@example.com."}
};

// Function to convert input to lowercase
string toLowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to check if a string contains a given substring
bool containsSubstring(const string& str, const string& substr) {
    return str.find(substr) != string::npos;
}

int main() {
    cout << "Hello! I'm here to assist you. How can I help you today?" << endl;

    while (true) {
        string user_input;
        cout << "You: ";
        getline(cin, user_input);

        // Convert user input to lowercase
        user_input = toLowercase(user_input);

        // Check if user input is a greeting
        if (find(GREETINGS.begin(), GREETINGS.end(), user_input) != GREETINGS.end()) {
            cout << "Bot: Hello! How can I assist you today?" << endl;
        }

        // Check if user wants to end the conversation
        else if (user_input == "bye" || user_input == "goodbye" || user_input == "see you later") {
            cout << "Bot: Goodbye! Have a great day!" << endl;
            break;
        }

        else {
            // Check if user input matches any predefined queries
            bool found_response = false;
            for (const auto& pair : RESPONSES) {
                if (containsSubstring(user_input, pair.first)) {
                    cout << "Bot: " << pair.second << endl;
                    found_response = true;
                    break;
                }
            }

            // If no predefined response found, provide a generic response
            if (!found_response) {
                cout << "Bot: I'm sorry, I didn't understand. Can you please rephrase or ask something else?" << endl;
            }
        }
    }

    return 0;
}
