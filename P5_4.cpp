#include <iostream>
#include <queue>

using namespace std;

class fahrenheit;

class celsius {
public:
    float temperature;

    celsius() {
        temperature = 0;
    }

    celsius(float t) {
        temperature = t;
    }

    fahrenheit to_fahrenheit();

    bool operator==(celsius c) {
        return temperature == c.temperature;
    }
};

class fahrenheit {
public:
    float temperature;

    fahrenheit() {
        temperature = 32;
    }

    fahrenheit(float t) {
        temperature = t;
    }

    celsius to_celsius();

    bool operator==(fahrenheit f) {
        return temperature == f.temperature;
    }
};

fahrenheit celsius::to_fahrenheit() {
    return fahrenheit((temperature * 9.0 / 5.0) + 32);
}

celsius fahrenheit::to_celsius() {
    return celsius((temperature - 32) * 5.0 / 9.0);
}

int main() {
    cout << "=== Static Array (Celsius to Fahrenheit) ===" << endl;
    celsius c_array[3] = { celsius(0), celsius(37), celsius(100) };
    fahrenheit f_array[3];

    for (int i = 0; i < 3; i++) {
        f_array[i] = c_array[i].to_fahrenheit();
        cout << c_array[i].temperature << "°C = " << f_array[i].temperature << "°F" << endl;
    }

    cout << "\n=== Queue (FIFO) Example ===" << endl;
    queue<celsius> celsius_queue;
    celsius_queue.push(fahrenheit(32).to_celsius());
    celsius_queue.push(fahrenheit(212).to_celsius());

    while (!celsius_queue.empty()) {
        celsius c = celsius_queue.front();
        celsius_queue.pop();
        cout << "From Fahrenheit -> Celsius: " << c.temperature << "°C" << endl;
    }

    cout << "\n=== Comparison ===" << endl;
    celsius c1(100);
    fahrenheit f1(212);
    if (c1 == f1.to_celsius()) {
        cout << "100°C is equal to 212°F" << endl;
    } else {
        cout << "They are not equal." << endl;
    }

    return 0;
}