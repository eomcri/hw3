#include <iostream>

using namespace std;
template <typename T>

class SimpleVector{
T* data;
int currentSize;
int currentCapacity;
public:
SimpleVector(){
    data = new T[10];
    currentSize = 0;
    currentCapacity = 10;
}
SimpleVector(int capacity){
    data = new T[capacity];
    currentSize = 0;
    currentCapacity = capacity; 
}
~SimpleVector(){
    delete[] data;
}
// copy constructor
SimpleVector(const SimpleVector& obj){
    data = new T[obj.currentCapacity];
    for (int i = 0; i < obj.currentSize; i++)
        data[i] = obj.data[i];
    currentSize = obj.currentSize;
    currentCapacity = obj.currentCapacity;
}

void push_back(const T& value){
    if(currentSize < currentCapacity){
        data[currentSize] = value;
        currentSize++;
    }
}
void pop_back(){
    if(currentSize != 0){
        data[currentSize-1] = NULL;
        currentSize--;
    }
}
int size(){
    return currentSize;
}
int capacity(){
    return currentCapacity;
}

};

int main(){
    SimpleVector<int> vector = SimpleVector<int>();
    cout << "Pop back. " << "Current size: "  << vector.size() << endl;
    for(int i = 0; i < 10; i++)
        vector.push_back(i);
    cout << "Push back 10 elements. " << "Current size: "  << vector.size() << endl;
    
    // copy vector
    SimpleVector<int> vectorCopy = SimpleVector<int>(vector);
    cout << "Current size: " << vectorCopy.size() << endl;
    vectorCopy.pop_back();
    cout << "vectorCopy current size: " << vectorCopy.size() << endl;
    cout << "vector current size: " << vector.size() << endl;

}
