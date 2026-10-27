#include <iostream>
using  std::cout;

class Box{
    private:
        int width;
        int height;
    public:
        Box(int w, int h){
            width = w;
            height = h;
        }
        void setWidth(int w){
            this->width = w;
        }
        void setHeight(int h){
            this->height = h;
        }

        int area(){
            return width*height;
        }
    };
int main(){
    Box b(5,2);
    cout << b.area(); 

    return 0;
}