#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Input verification
bool valid_input(string str){
    int dot_count = 0;
    int minus_count = 0;
    int plus_count = 0;
    bool start = true;
    bool stop = false;
    char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (char& number : str){
        if (number == '+') {
            if (!start){
                cout << "'+' in wrong position." << endl;
                return false;
            }
            plus_count++;
            if (plus_count > 1){
                cout << "Multiple '+'" << endl;
                return false;
            }
        } else if (number == '-') {
            if (!start){
                cout << "'-' in wrong position." << endl;
                return false;
            }
            minus_count++;
            if (minus_count > 1){
                cout << "Multiple '-'" << endl;
                return false;
            }
        } else if (number == '.') {
            dot_count++;
            if (dot_count > 1){
                cout << "Multiple '.'" << endl;
                return false;
            }
        } else {
            //Checks if input is 0,1,2,3,4,5,6,7,8,9
            for (int i = 0; i < 10; i++){
                if (number == nums[i]){
                    stop = true;
                    break;
                }
            }
            if (stop){
                stop = false;
            } else if (!stop){
                return false;
            }
        }
        //After first number, it's not the start
        start = false;
    }
    //If theres a minus and a plus, input is invalid
    if ((minus_count && plus_count) == 1){
        cout << "'+' and '-' in expression." << endl;
        return false;
    }
    //else return true
    return true;
}


//gets the number from the string
double extractNumeric(string str) {
    //Get string size and position of decimal
    int length = 0;
    int decimal_place = 0;

    //Checks where decimal is
    bool is_decimal = false;
    for (char& number : str) {
        if (number == '.') {
            decimal_place = length;
            is_decimal = true;
        } else if (!is_decimal){
            length++;
        }
    }

    //Position of numbers, ex 512, position 5 would be at the 100 position
    double count = 1;
    for (int i = 1; i < length; i++){
        count = count*10;
    }

    double output = 0;
    int minus_count = 0;
    bool start = true;
    //If multiple minus, plus, or decimals then input is invalid
    for (char& number : str) {

        //Find what number is in the string then add it to the double
        if (number == '1'){
            output = output + (1*count);
        } else if (number == '2'){
            output = output + (2*count);
        } else if (number == '3'){
            output = output + (3*count);
        } else if (number == '4'){
            output = output + (4*count);
        } else if (number == '5'){
            output = output + (5*count);
        } else if (number == '6'){
            output = output + (6*count);
        } else if (number == '7'){
            output = output + (7*count);
        } else if (number == '8'){
            output = output + (8*count);
        } else if (number == '9'){
            output = output + (9*count);
    
        //Marks if number is negative
        } else if (number == '-'){
            minus_count++;
        }
        
        //Checks if number is '.' and if not divides count by 10
        if (number != '.'){
            count = count/10;
        } else {
            //In case input is .1 and not 0.1, divide count by 10
            if (start){
                count = count/10;
            }
        }
        start = false;
    }

    //If input is negative, make output negative
    if (minus_count > 0) {
        output = output*(-1.0);
    }
    return output;
}

int main() {
        string input;
        while (true) {
            cout << "Enter a string ( or 'END' to quit): ";
            cin >> input;

            if (input == "END") {
                break;
            }
        double number = extractNumeric(input);
        if (valid_input(input)){
            if (number != -999999.99) {
                cout << "The input is " << fixed << setprecision(4) << number << endl;
            } else {
                cout << "The input is invalid." << endl;
            }
        } else {
                cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

