#include<iostream>
#include<string>
#include<memory>

class myClass
{
    private:
        std::string _text;
    public:
        myClass(){}
        myClass(std::string t){
            _text = t;
        }

        ~myClass(){
            std::cout<<"\n" << _text << " Destroyed";
        }

        void setText(std::string x)
        {
            _text = x;
        }

        std::string getText()
        {
            return _text;
        }
};

int main()
{
    // ***Unique pointer***
    std::unique_ptr<myClass> a(new myClass());
    std::unique_ptr<myClass> unique(new myClass("vaibhav"));

    unique->setText("V");
    *a = *unique;
    a->setText("Z");
    std::cout<<a->getText() << " " << unique->getText() << "\n";
    // .get() gives the location of the new instances created on the heap as unique and a are created on the stack
    // but new myclass() will allocate memory on the heap
    std::cout<<a.get() << " " << unique.get();

    // ***Shared and weak pointers***
    // Weak pointer can only be made from shared pointer or from another weak pointer - Doesn't effect reference count
    std::shared_ptr<int> s1(new int);
    std::cout<<"\nShared count = "<<s1.use_count()<<"\n";

    {
        std::shared_ptr<int> s2 = s1;
        std::weak_ptr<int> s3 = s2;
        std::weak_ptr<int> s4 = s3;
        std::cout<< "Shared count = " << s1.use_count()<<"\n";

        s2.reset(new int);  // Redirecting a shared pointer
        std::cout<< "Shared count = " << s1.use_count()<<"\n";

        
        if(s3.expired())    // when s2 got reset, s3 expires
        {
            std::cout<<"\ns3 expired\n";
        }
        else
        {
            std::cout<<"\ns3 not expired\n";
        }
        
    }
    
    

    std::cout<<"Shared count = "<<s1.use_count()<<"\n";


    // Copying pointers
    // Unique and weak pointers can be converted to shared pointers using std::move and .lock()

    // Unique to shared
    std::shared_ptr<int> c_shared = std::move(s1);

    std::weak_ptr<int> w_shared(c_shared);
    // Weak to shared
    std::shared_ptr<int> c_shared2 = w_shared.lock();   // Makes sure that the weak pointer remains in scope

    if(w_shared.expired())
    std::cout<<"\nWeak pointer expired\n";
    else
    std::cout<<"\nWeak pointer not expired\n";

    std::cout<<"\nCopying pointers shared usage : "<<w_shared.use_count() << "\n";


    int *r = c_shared.get();    // Calling delete on r not required because smart pointer will clear the memory anyway
}