// All possible global variable declaration
int a = 1;
int b;
float c = 3.14;
float d;
string e = "E";
bool f = true;
bool g;

// All possible declaration with constant
void func1(){
    int a;
    int b = 1;
    int c = 2.0;

    float d;
    float e = 1.0;
    float f = 2;

    bool g = true;
    bool h = false;

    string i = "I";
}

void func2(){
    int b = 1 + 2.0;
    float g = 1.0 * 2;

    int i = 3 % 5;
    float j = 3 % 5;

    // a = 1 + 2 - 3 * 4 / 5;
    b = (1 + 2) - (3 * 4) / 5;
    i = ((1 + 2) - 3) * 4 / 5;
}
