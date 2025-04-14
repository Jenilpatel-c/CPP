#include<iostream>
using namespace std;

int calculate_sum_of_digits(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
int calculate_super_digit(int number)
{
    if (number < 10)
    {
        return number;
    }
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return calculate_super_digit(sum);
}

int main()
{
    int num, num_repeat;
    cout << "Enter number(n): ";
    cin >> num;
    cout << "Enter the number of repetitions(k): ";
    cin >> num_repeat;
    int sum = calculate_sum_of_digits(num);
    int total_sum = sum * num_repeat;
    int super_digit = calculate_super_digit(total_sum);
    cout << "Super digit: " << super_digit << endl;
    cout << "24CE082 Jenil Patel." << endl;
    return 0;
}