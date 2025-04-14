#include<iostream>
using namespace std;

template<typename T>
void input_data(T* data, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> data[i];
    }
}
template<typename T>
T get_elements(int size, T* data)
{
    int count;
    if (count >= 0 && count < size)
    {
        return data[count];
    }
}
template<typename T>
T find_max(int size, T* data)
{
    T max_value = data[0];
    for (int i = 1; i < size; ++i)
    {
        if (data[i] > max_value)
        {
            max_value = data[i];
        }
    }
    return max_value;
}
template<typename T>
void reverse_data(int size, T* data)
{
    for (int start = 0, end = size - 1; start < end; ++start, --end)
    {
        T temp = data[start];
        data[start] = data[end];
        data[end] = temp;
    }
}
template<typename T>
void display_data(int size, T* data)
{
    for (int i = 0; i < size; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
template<typename T>
void perform_operations(int size)
{
    T* data;
    data = new T[size];
    input_data(data, size);
    cout << "Entered data: ";
    display_data(size, data);
    T max_value = find_max(size, data);
    cout << "Max Value: " << max_value << endl;
    cout << "Reversed Data: ";
    reverse_data(size, data);
    display_data(size, data);
    delete[] data;
}

int main()
{
    int size;
    cout << "Enter the no. of elements: ";
    cin >> size;
    char data_type;
    cout << "Enter the data type (i = int, f = float, c = char): ";
next:
    cin >> data_type;
    if (data_type == 'i')
    {
        perform_operations<int>(size);
    }
    else if (data_type == 'f')
    {
        perform_operations<float>(size);
    }
    else if (data_type == 'c')
    {
        perform_operations<char>(size);
    }
    else
    {
        cout << "Invalid data type! re-enter data type: ";
        goto next;
    }
    cout << "24CE082 Jenil Patel." << endl;
    return 0;
}