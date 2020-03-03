class Base {
    public: int m_public;
    private: int m_private;
    protected: int m_protected; 
};

class Pub: public Base { // note: public inheritance means
    // Public inherited members stay public (so m_public is still public)
    // Protected inherited members stay protected (so m_protected is still protected)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    Pub() {
        m_public = 1; 
        // m_private = 2; // inaccessible - private Base member in Pub
        m_protected = 3; 
    }
};

int main() {
    // Outside access uses the access specifiers of the class being accessed.
    Base base;
    base.m_public = 1; 
    // base.m_private = 2; // private in Base
    // base.m_protected = 3; // protected in Base

    Pub pub;
    pub.m_public = 1; 
    // pub.m_private = 2; // inaccessible in Pub
    // pub.m_protected = 3; // protected in Pub
}