#include<WApplication>
#include<Wbreak>
#include<WcontainerWidget>

#include <WLineEdit>
#include <WPushButton>
#include <WText>

using namespace Wt;

class HelloApp: public WApplication
{

public:
    HelloApp(const WEnvironment& env);

private:
    WlineEdit *nameEdit_;
    WText *greeting_;

    void greet();
};
