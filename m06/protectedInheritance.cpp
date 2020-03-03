class Base {
    public: int m_public;
    private: int m_private;
    protected: int m_protected; 
};

class Pro: protected Base { // note: protected inheritance means
    // Public inherited members become protected
    // Protected inherited members become protected
    // Private inherited members stay inaccessible
public:
    Pro() {
        m_public = 1; // now protected in Pri
        // m_private = 2; // inaccessible in Pri - private Base member 
        m_protected = 3; // now protected in Pri
    }
};

int main() {
    Base base; // Outside access uses the access specifiers of the class.
    base.m_public = 1; 
    // base.m_private = 2; // private in Base
    // base.m_protected = 3; // protected in Base

    Pro pro;
    // pro.m_public = 1; // private in Pri
    // pro.m_private = 2; // inaccessible in Pri
    // pro.m_protected = 3; // private in Pri
}