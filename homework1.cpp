#include <iostream>
#include "header.h"
//Anna Waldron

template<class T>
class MyArray: public Container<T> {
    private:
        T * data;
        int capacity;
        int size;

    public:
        // constructor
        MyArray(int capacity) : capacity(capacity), size(0) {
            data = new T[capacity];
        }

        // destructor
        virtual ~MyArray() {
            delete []data;
        }

        int count() const override {
            return size;
        }

        T & operator [](int index) {
            return data[index];
        }
//Uses if statement to decide if another element can be added to the
//array and increases the size of the array by 1.
        void add(T & val) override {
            if (size==capacity) {
                return;
            }
            if (size < capacity){
                data[size]=val;
                size++;
            }

        }
//Uses nested for loop to look at the elements and switch them with their
//nieghbor according to which element is greatter.
        void sort() override {

            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    if (data[i] < data[j]){
                        T temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }
            }
            return;
        }
//looks at the first element in the array and the last and creates a temp
//variable to hold the placements of the elments to then be switched.
        void reverse() override {
            int left = 0;
            int right = size-1;
            for (int i = 0; i < size/2; i++) {
                T temp = data[left];
                data[left] = data[right];
                data[right] = temp;
                left++;
                right--;
            }

            return;
        }
};

