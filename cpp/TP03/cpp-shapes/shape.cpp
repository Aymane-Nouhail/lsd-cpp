#include<iostream>

class Shape{
    public:
        float get_height(){return height;}
        float get_width(){return width;}
        void construct(float h, float w){
            height= h;
            width = w;
            return;
        }
    private:
        int height;
        int width;
};

class Rectangle : public Shape{
    public:
        float area(){
            return get_height()*get_width();
        }
        float perimeter(){
            return 2*(get_height()+get_width());
        }
};

class Triangle : public Shape{
    public:
        float area(){
            return get_height()*get_width()/2;
        }
};

int main(){
    int a;
    Rectangle rectangle;
    rectangle.construct(5,2);
    std::cout << rectangle.area()<<std::endl;
    Triangle triangle;
    triangle.construct(9,10);
    std::cout<<triangle.area()<<std::endl;
    std::cin>>a;
    return 0; 
}