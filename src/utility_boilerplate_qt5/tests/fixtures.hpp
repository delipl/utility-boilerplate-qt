#include <gtest/gtest.h>

#include <QApplication>
#include <QMainWindow>

namespace ubTestSuit {

    class UiFixture : public ::testing::Test {
      protected:
        QApplication* app{};
        QMainWindow* window{};
        const char* argv[2] = {"--platform", "offscreen"};

        void SetUp() override {
            int arg = 2;
            app = new QApplication(arg, const_cast<char**>(argv));
            window = new QMainWindow();
        }

        void TearDown() override {
            delete window;
            delete app;
        }
    };

    template <typename T> T* findQWidgetByClass(QWidget* widget) {
        return widget->findChildren<T*>().first();
    }

}  // namespace ubTestSuit
