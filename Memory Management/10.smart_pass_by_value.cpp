#include<iostream>
#include<memory>

class myClass
{
    private:
        int _val;

    public:

        myClass(int v)
        {
            _val = v;
        }
        int getVal()
        {
            return _val;
        }
};

void f(std::unique_ptr<myClass> x)
{
    std::cout<<&x << x->getVal() << "\n";
}

int main()
{
    std::unique_ptr<myClass> m = std::make_unique<myClass>(23); // Use shared pointer or weak pointer to keep reference
    std::cout<<&m<<m->getVal()<<"\n";                           // std::move might not be required
    f(std::move(m));

    if(m)
    std::cout<<&m<<m->getVal()<<"\n";   // wont execute

}