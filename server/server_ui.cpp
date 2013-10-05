#if 1

#include<Wt/WApplication>
#include<Wt/WBreak>
#include<Wt/WContainerWidget>

#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>

using namespace Wt;

class HelloApp: public WApplication
{

public:
    HelloApp(const WEnvironment& env);

private:
    WLineEdit *nameEdit_;
    WText *greeting_;

    void greet();
};

HelloApp::HelloApp(const WEnvironment& env)
    : WApplication(env)
{
    setTitle("Hello World");

    root()->addWidget(new WText("Your name,please ?"));

    nameEdit_= new WLineEdit(root());

    nameEdit_->setFocus();

    //WPushButton *b = new WPushButton("Great me.",root());

  //  b->setMargin(5, WWidget::Left);

    root()->addWidget(new WBreak());


    greeting_ = new WText(root());
    //->clicked.connect(SLOT(this, HelloApp::greet));

    nameEdit_->enterPressed.connect(SLOT(this, HelloApp::greet));

}

HelloApp::greet()
{
    greeting_->setText("Hello there," + nameEdit_->text());
}

WApplication *createApplication(const WEnvironment& env)
{
    return new HelloApp(env);
}

int main(int argc, char **argv)
{
    return WRun(argc,argv,&createApplication);
}

#endif
