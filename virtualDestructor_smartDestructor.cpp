
class Dog{
public:
    ~Dog(){cout<<"Dog destroyed"<<end;}
};

class YellowDog:public Dog{
public:
    ~YellowDog(){cout<<"YellowDog destroyed"<<end;}
};

class DogFactory{
public:
    static Dog* createYellowDog(){
        return (new YellowDog());
    }
};