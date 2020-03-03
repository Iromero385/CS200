class Base {
    public: int m_public;
    private: int m_private;
    protected: int m_protected; 
};

class Pri: private Base { // note: private inheritance means
    // Public inherited members become private
    // Protected inherited members become private
    // Private inherited members stay inaccessible
public:
    Pri() {
        m_public = 1; // now private in Pri
        // m_private = 2; // inaccessible in Pri - private Base member 
        m_protected = 3; // now private in Pri
    }
};

int main() {
    Base base; // Outside access uses the access specifiers of the class.
    base.m_public = 1; 
    // base.m_private = 2; // private in Base
    // base.m_protected = 3; // protected in Base

    Pri pri;
    // pri.m_public = 1; // private in Pri
    // pri.m_private = 2; // inaccessible in Pri
    // pri.m_protected = 3; // private in Pri
}