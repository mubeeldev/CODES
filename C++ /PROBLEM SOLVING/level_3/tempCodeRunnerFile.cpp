

using namespace std;


int randomNUmbers(int from, int to){
    int ranNum = rand() % (to - from + 1 ) + from;
    return ranNum;
}