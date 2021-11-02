#include <QApplication>
#include <cmath>


#include "mainwindow.h"
#include "mdef"


i32 main (i32 argc, ch* argv[]) {
    QApplication app(argc, argv);
    MainWindow window;

    const std::function integral_function = [](f64 begin, f64 step) {
        return step * sin(2 * (begin + step / 2)) * cos(3 * (begin + step / 2));
    };

    window.setIntegral(integral_function);
    window.show();

    return app.exec();
}
